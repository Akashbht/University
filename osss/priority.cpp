// #include <stdio.h>
// typedef struct {
//     int id;
//     int bt;
//     int at;
//     int wt;
//     int tat;
//     int ct;
//     int priority;
// } Process;
// void calculatePriority(Process processes[], int n) {



//     int totalwt = 0, totaltat = 0;
//     int completed = 0, time = 0;



//     printf("Gantt Chart (Priority):\n|");


//     while (completed < n) {
//         int idx = -1, maxPriority = -1;


//         for (int i = 0; i < n; i++) {
//             if (processes[i].at <= time && processes[i].ct == 0) {
//                 if (processes[i].priority > maxPriority) {
//                     maxPriority = processes[i].priority;
//                     idx = i;
//                 }
//             }
//         }

//         if (idx == -1) {
//             time++;
//             continue;
//         }
//         time += processes[idx].bt;
//         processes[idx].ct = time;
//         processes[idx].tat = processes[idx].ct - processes[idx].at;
//         processes[idx].wt = processes[idx].tat - processes[idx].bt;
//         printf(" P%d |", processes[idx].id);
//         totalwt += processes[idx].wt;
//         totaltat += processes[idx].tat;
//         completed++;
//     }
  
//     printf("\n");
//     printf("\nPID\tAT\tBT\tPRI\tCT\tWT\tTAT\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].at, processes[i].bt,processes[i].priority, processes[i].ct, processes[i].wt, processes[i].tat);
//     }
//     printf("\n");
//     printf("Average Waiting Time (Priority): %.2f\n", (float)totalwt / n);
//     printf("Average Turnaround Time (Priority): %.2f\n", (float)totaltat / n);
// }
// int main() {
//     int n;
//     printf("Enter number of processes: ");
//     scanf("%d", &n);
//     Process processes[n];
//     printf("Enter Burst Times: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &processes[i].bt);
//         processes[i].id = i;
//         processes[i].ct = 0;
//     }
//     printf("Enter Arrival Times: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &processes[i].at);
//     }
//     printf("Enter Priorities: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &processes[i].priority);
//     }
//     calculatePriority(processes, n);
//     return 0;
// }




#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include<math.h>
#include<limits.h>
struct process{ 
    int pid, at, bt, st, ct, rt, tat, wt, btRem,priority; 
}; 
typedef struct process process; 
int main()
{ 
    int n; 
    printf("Enter number of process : "); 
    scanf("%d", &n); 
    process p[n]; 
    for(int i = 0; i < n; i++){ 
        printf("For process %d enter arrival , burst time and priority : ", i+1); 
        scanf("%d %d", &p[i].at, &p[i].bt); 
        scanf("%d",&p[i].priority);
        p[i].btRem = p[i].bt; 
        p[i].pid = i; 
    } 
    int currT = 0, completed = 0; 
    float totalWt = 0.0, totalTat = 0.0, totalBt = 0.0, cpu, throughput;    
    printf("Gantt's chart : |");    
    while(completed < n){ 
        int selected = -1, maxP=INT_MIN; 
        for(int i = 0; i < n; i++){ 
            if(p[i].at <= currT && p[i].btRem > 0 && p[i].priority > maxP){ 
                selected = i; 
               maxP=p[i].priority;
            } 
        } 
        if(selected == -1)currT++; 
        else{ 
            printf(" P%d | ", p[selected].pid);
            p[selected].btRem--; 
            if(p[selected].bt == p[selected].btRem + 1){ 
                p[selected].st = currT; 
            } 
            else if(p[selected].btRem == 0){ 
                p[selected].ct = currT+1; 
                p[selected].rt = p[selected]. st - p[selected].at; 
                p[selected].tat = p[selected].ct - p[selected].at; 
                p[selected].wt = p[selected].tat - p[selected].bt; 
                totalBt += p[selected].bt; 
                totalTat += p[selected].tat; 
                totalWt += p[selected].wt; 
                completed++;                 
            } 
            currT++; 
        } 
    } 
cpu = (totalBt/currT)*100; 
throughput = (float)n/currT; 
printf("\n\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n"); 
for (int i = 0; i < n; i++) 
{ 
printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, 
p[i].wt, p[i].rt); 
} 
}
