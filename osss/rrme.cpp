#include<stdio.h>

struct rr{
    int at,id,bt;
    int wt,st,tat,ct;

};

int main(){
    int n;
    printf ("enter the number of proccess :");
    scanf("%d",&n);
    struct rr p[n];
    printf("enter the arrival time and burst time :");
    int rt[n];
    int firstrun[n];
    for(int i = 0 ;i<n;i++){
        p[i].id = i;
        
        scanf("%d %d",&p[i].at,&p[i].bt);
        rt[i] = p[i].bt;
        firstrun[i] = 0;
    }
    int q;
    float awt = 0, atat = 0 ;
    int c = 0 ,time = 0 ;
    printf("enter time quanta :");
    scanf("%d",&q);



    printf("GANNT CHArt \n");
    while(c<n){
        int done = 0 ;
        for(int i = 0;i<n;i++){
            if(p[i].at<=time && rt[i]>0){
                done = 1;
                if(firstrun[i] == 0){
                    p[i].st = time;
                    firstrun[i] = 1;
                }
                if(rt[i]>q){
                    rt[i]-=q;
                    time += q;
                }
                else{
                    time += rt[i];
                    rt[i] = 0;

                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat -p[i].bt;

                    awt += p[i].wt;
                    atat += p[i].tat;
                    c++;

                }
                printf("P%d (%d)|",p[i].id,time);
            }
        }

        if(!done) time++;
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("\n");
    printf("Average Waiting Time: %.2f\n", (float)awt / n);
    printf("Average Turnaround Time: %.2f\n", (float)atat / n);
} 