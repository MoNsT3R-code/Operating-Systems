/*
 * Course: COMP301 – Operating Systems
 * Name: <Your Name>
 * Roll No: <Your Roll Number>
 * Date: 15 May 2026
 *
 * proc_monitor.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX_LEN 64

typedef struct {
    char name[128];
    char state[32];
    long vm_rss_kb;
    long vm_peak_kb;
    int threads;
    long vol_ctxt;
    long nonvol_ctxt;
} proc_status_t;

typedef struct {
    long utime;
    long stime;
    int priority;
    int nice;
} proc_stat_t;

/* /proc/<pid>/status */
int parse_status(int pid, proc_status_t *out) {
    char path[PATH_MAX_LEN];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);

    FILE *f = fopen(path, "r");
    if (!f) {
        perror("status file");
        return -1;
    }

    char line[256];

    while (fgets(line, sizeof(line), f)) {

        if (strncmp(line, "Name:", 5) == 0)
            sscanf(line, "Name: %127s", out->name);

        else if (strncmp(line, "State:", 6) == 0)
            sscanf(line, "State: %31[^\n]", out->state);

        else if (strncmp(line, "VmRSS:", 6) == 0)
            sscanf(line, "VmRSS: %ld", &out->vm_rss_kb);

        else if (strncmp(line, "VmPeak:", 7) == 0)
            sscanf(line, "VmPeak: %ld", &out->vm_peak_kb);

        else if (strncmp(line, "Threads:", 8) == 0)
            sscanf(line, "Threads: %d", &out->threads);

        else if (strncmp(line, "voluntary_ctxt_switches:", 25) == 0)
            sscanf(line, "voluntary_ctxt_switches: %ld", &out->vol_ctxt);

        else if (strncmp(line, "nonvoluntary_ctxt_switches:", 28) == 0)
            sscanf(line, "nonvoluntary_ctxt_switches: %ld", &out->nonvol_ctxt);
    }

    fclose(f);
    return 0;
}

/* /proc/<pid>/stat */
int parse_stat(int pid, proc_stat_t *out) {
    char path[PATH_MAX_LEN];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    FILE *f = fopen(path, "r");
    if (!f) {
        perror("stat file");
        return -1;
    }

    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), f)) {
        fclose(f);
        return -1;
    }

    /* skip first 13 fields safely */
    sscanf(buffer,
        "%*d %*s %*c %*d %*d %*d %*d %*d "
        "%*u %*u %*u %*u %*u "
        "%ld %ld "
        "%*d %*d "
        "%d %d",
        &out->utime,
        &out->stime,
        &out->priority,
        &out->nice
    );

    fclose(f);
    return 0;
}

void print_snapshot(int pid, proc_status_t *s, proc_stat_t *t) {

    printf("\n====================================\n");
    printf(" Process Snapshot (PID %d)\n", pid);
    printf("====================================\n");

    printf("Name            : %s\n", s->name);
    printf("State           : %s\n", s->state);
    printf("VmRSS           : %ld KB\n", s->vm_rss_kb);
    printf("VmPeak          : %ld KB\n", s->vm_peak_kb);
    printf("Threads         : %d\n", s->threads);

    printf("utime/stime     : %ld / %ld\n", t->utime, t->stime);
    printf("Priority        : %d\n", t->priority);
    printf("Nice            : %d\n", t->nice);

    printf("Vol ctx switch  : %ld\n", s->vol_ctxt);
    printf("Nonvol ctx sw   : %ld\n", s->nonvol_ctxt);

    printf("====================================\n\n");
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (pid <= 0) {
        printf("Invalid PID\n");
        return 1;
    }

    proc_status_t s = {0};
    proc_stat_t t = {0};

    if (parse_status(pid, &s) != 0) return 1;
    if (parse_stat(pid, &t) != 0) return 1;

    print_snapshot(pid, &s, &t);
    return 0;
}