#include<stdio.h>
typedef struct rr{
    int id,bt,at;
    int wt,tat,ct,st;
}rr;
void calculaterr(rr arr[],int n , int quanta){
    float awt=0,atat=0;
    int rt[n],isfirstrun[n];
    for(int i=0;i<n;i++){
        rt[i]=arr[i].bt;
        isfirstrun[i]=0;
    }
    int c=0,time=0;
    printf("\nGantt Chart\n");
    while(c<n){
        int done=0;
        for(int i=0;i<n;i++){
            if(arr[i].at<=time&&rt[i]>0){
                done =1;
                if(!isfirstrun[i]){
                    arr[i].st=time;
                    isfirstrun[i]=1;
                }
                if(rt[i]>quanta){
                    time+=quanta;
                    rt[i]-=quanta;
                }
                else{
                    time+=rt[i];
                    arr[i].ct=time;
                    arr[i].tat=arr[i].ct-arr[i].at;
                    arr[i].wt=arr[i].tat-arr[i].bt;

                    awt+=arr[i].wt;
                    atat+=arr[i].tat;
                    rt[i]=0;
                    c++;
                }
                printf("P%d |",arr[i].id);
            }
        }
    if(!done)
        time++;
    }
    printf("\n");
    printf("ID\tAT\tBT\tST\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].id,arr[i].at,arr[i].bt,arr[i].st,arr[i].ct,arr[i].tat,arr[i].wt);
    }
    printf("Average Waiting Time -> %f\n",awt/n);
    printf("Average Turn Around Time -> %f\n",atat/n);
}

int main(){
    int n;
    printf("Enter Number of process : ");
    scanf("%d",&n);
    rr arr[n];
    for(int i=0;i<n;i++){
        arr[i].id=i;
        printf("Enter Arrival Time & Brust Time for P%d : ",arr[i].id);
        scanf("%d %d",&arr[i].at,&arr[i].bt);
    }
    int q;
    printf("Enter Time Quanta : ");
    scanf("%d",&q);
    calculaterr(arr,n,q);
    return 0;
}