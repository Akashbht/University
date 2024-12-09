#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int id;              
    int at;     
    int bt;       
    int rt;   
    int ct;  
    int tat;  
    int wt;     
} Process;
void calculateSJFPreemptive(Process p[], int n) {
    int totalwt = 0, totaltat = 0;
    int time = 0, completed = 0;
    bool isCompleted[n];
    for (int i = 0; i < n; i++) {
        p[i].rt = p[i].bt;
        isCompleted[i] = false;
    }
    while (completed < n) {
        int idx = -1;
        int minbt = 9999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && !isCompleted[i] && p[i].rt < minbt) {
                minbt = p[i].rt;
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
            continue;
        }
        printf(" P%d |", p[idx].id);
        p[idx].rt--;
        time++;
        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            totalwt += p[idx].wt;
            totaltat += p[idx].tat;
            isCompleted[idx] = true;
            completed++;
        }
    }
    printf("\n");
    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("\n");
    printf("Average Waiting Time: %.2f\n", (float)totalwt / n);
    printf("Average Turnaround Time: %.2f\n", (float)totaltat / n);
}
int main() {
    int n;
    printf("Enter number of p: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i; 
        printf("Enter Burst Time and arrival Time for Process P%d: ", i);
        scanf("%d %d", &p[i].bt, &p[i].at);
    }
    calculateSJFPreemptive(p, n);
    return 0;
}