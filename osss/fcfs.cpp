#include<stdio.h>
typedef struct fcfs{
    int id,at,bt;
    int tat,wt,st,ct,rt;
} fcfs;
int sort(fcfs arr[], int n);
int main(){
    int n,temp;
    float awt=0,atat=0;
    printf("Enter number of process ");
    scanf("%d",&n);
    fcfs arr[n];
    for(int i=0;i<n;i++){
        arr[i].id=i;
        printf("Enter Brust Time & Arrival Time for process %d : " , arr[i].id);
        scanf("%d %d", &arr[i].bt, &arr[i].at);        
    }  
    sort(arr,n);
    printf("\nID\tAT\tBT\tST\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        if(i==0)
            arr[i].st=arr[i].at;
        else
            arr[i].st=(arr[i].at>arr[i-1].ct)?arr[i].at:arr[i-1].ct;

        arr[i].ct=arr[i].st+arr[i].bt;
        arr[i].tat=arr[i].ct-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
        awt+=arr[i].wt;
        atat+=arr[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].id,arr[i].at,arr[i].bt,arr[i].st,arr[i].ct,arr[i].wt,arr[i].tat);
    }
    printf("\nAverage Waiting Time -> %f",awt/n);
    printf("\nAverage Turn Around Time -> %f",atat/n);

    printf("\nGantt Chart\n");
    for(int i=0;i<n;i++){
        printf("P%d |",arr[i].id);
    }
    return 0;
}

int sort(fcfs arr[],int n){
    fcfs k;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j].at<arr[i].at){
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }
                
        }
    }
    return 0;
}