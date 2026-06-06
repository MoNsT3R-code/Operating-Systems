#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define MAX_CPUS 64
#define PROC_STAT "/proc/stat"
#define DEFAULT_WORK 2000000000LL

typedef struct {
    int id;
    long user, nice, system, idle, iowait, irq, softirq, steal;
    long load;
} cpu_stat_t;


/* elapsed time */
static double elapsed_sec(struct timespec *start, struct timespec *end)
{
    return (end->tv_sec - start->tv_sec)
         + (end->tv_nsec - start->tv_nsec) / 1e9;
}


/* parse /proc/stat */
int parse_proc_stat(cpu_stat_t cpu[], int max_cpus)
{
    FILE *f = fopen(PROC_STAT, "r");
    if (!f) {
        perror("fopen /proc/stat");
        exit(1);
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), f))
    {
        /* skip aggregate cpu line */
        if (strncmp(line, "cpu ", 4) == 0)
            continue;

        if (strncmp(line, "cpu", 3) != 0)
            continue;

        cpu_stat_t tmp;

        int ok = sscanf(
            line,
            "cpu%d %ld %ld %ld %ld %ld %ld %ld %ld",
            &tmp.id,
            &tmp.user,
            &tmp.nice,
            &tmp.system,
            &tmp.idle,
            &tmp.iowait,
            &tmp.irq,
            &tmp.softirq,
            &tmp.steal
        );

        if (ok < 8 || count >= max_cpus)
            continue;

        tmp.load =
            tmp.user + tmp.nice + tmp.system +
            tmp.irq + tmp.softirq;

        cpu[count++] = tmp;
    }

    fclose(f);
    return count;
}


/* CPU workload */
long long do_work(long long iterations)
{
    long long sum = 0;

    for (long long i = 0; i < iterations; i++)
    {
        sum += (i % 97);
        sum ^= (i << 1);
        if (i % 1000 == 0)
            sum += sqrt(i % 10000);
    }

    return sum;
}


/* pin CPU */
void pin_to_cpu(int cpu_id)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(cpu_id, &set);

    if (sched_setaffinity(0, sizeof(set), &set) != 0)
    {
        perror("sched_setaffinity");
        exit(1);
    }
}


/* run workload */
double run_on_cpu(int cpu_id, long long iterations)
{
    pin_to_cpu(cpu_id);

    struct timespec s, e;
    clock_gettime(CLOCK_MONOTONIC, &s);

    volatile long long r = do_work(iterations);
    (void)r;

    clock_gettime(CLOCK_MONOTONIC, &e);

    return elapsed_sec(&s, &e);
}


int main(int argc, char *argv[])
{
    long long iterations = DEFAULT_WORK;

    /* parse argument */
    if (argc == 3 && strcmp(argv[1], "--workload") == 0)
        iterations = atoll(argv[2]);

    cpu_stat_t cpus[MAX_CPUS];
    int n = parse_proc_stat(cpus, MAX_CPUS);

    if (n < 2)
    {
        printf("Need at least 2 CPUs\n");
        return 1;
    }

    int cpu_max = 0, cpu_min = 0;

    for (int i = 1; i < n; i++)
    {
        if (cpus[i].load > cpus[cpu_max].load)
            cpu_max = i;

        if (cpus[i].load < cpus[cpu_min].load)
            cpu_min = i;
    }

    printf("[INFO] %d CPUs found\n", n);
    printf("[INFO] Most-loaded  : cpu%d (load=%ld)\n",
           cpus[cpu_max].id, cpus[cpu_max].load);
    printf("[INFO] Least-loaded : cpu%d (load=%ld)\n",
           cpus[cpu_min].id, cpus[cpu_min].load);
    printf("[INFO] Workload iterations: %lld\n\n", iterations);

    printf("Running workload on cpu%d (most loaded)...\n", cpus[cpu_max].id);
    double t_max = run_on_cpu(cpus[cpu_max].id, iterations);

    printf("Running workload on cpu%d (least loaded)...\n", cpus[cpu_min].id);
    double t_min = run_on_cpu(cpus[cpu_min].id, iterations);

    printf("\nCPU                  Load       Turnaround (s)\n");
    printf("-------------------- ---------- --------------\n");

    printf("cpu%-2d (most loaded)  %-10ld %.6f\n",
           cpus[cpu_max].id, cpus[cpu_max].load, t_max);

    printf("cpu%-2d (least loaded) %-10ld %.6f\n",
           cpus[cpu_min].id, cpus[cpu_min].load, t_min);

    double diff = (t_max > t_min) ? (t_max - t_min) : (t_min - t_max);
    double pct = (diff / t_max) * 100.0;

    if (t_min < t_max)
        printf("\n[RESULT] cpu%d was faster by %.6f s (%.2f%% improvement)\n",
               cpus[cpu_min].id, diff, pct);
    else
        printf("\n[RESULT] cpu%d was faster by %.6f s (%.2f%% improvement)\n",
               cpus[cpu_max].id, diff, pct);

    return 0;
}