#include<stdio.h>
typedef struct sjfs{
    int id,bt,at;
    int tat,wt,st,ct;
}sjfs;
int sort(sjfs arr[],int n){
    sjfs k;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(arr[i].at>arr[j].at||(arr[i].at==arr[j].at&&arr[i].bt>arr[j].bt)){
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }
        }
    }
    return 0;
}
int main(){
    int n,c=0,curr=0;
    float awt=0,atat=0;
    printf("Enter Number of process : ");
    scanf("%d",&n);
    sjfs arr[n];
    int is_com[n];
    for(int i=0;i<n;i++){
        arr[i].id=i;
        printf("Enter Arrival Time & Brust Time for process %d : ",arr[i].id);
        scanf("%d %d",&arr[i].at,&arr[i].bt);
        is_com[i]=0;
    }
    sort(arr,n);
    printf("\nGantt Chart\n");
    while(c<n){
        int min_bt = 999;
        int idx =-1;
        for(int i=0;i<n;i++){
            if(arr[i].at<=curr&&is_com[i]==0){
                if(arr[i].bt<min_bt){
                    min_bt=arr[i].bt;
                    idx=i;
                }   
            }
        }
        if(idx!=-1){
            arr[idx].st=curr;
            arr[idx].ct=arr[idx].st+arr[idx].bt;
            arr[idx].tat=arr[idx].ct-arr[idx].at;
            arr[idx].wt=arr[idx].tat-arr[idx].bt;
            
            
            printf("P%d |",arr[idx].id);

            awt+=arr[idx].wt;
            atat+=arr[idx].tat;
            curr=arr[idx].ct;
            is_com[idx]=1;
            c++;
        }
        else
            curr++;
    }
    
    printf("\nPID\tAT\tBT\tST\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].id, arr[i].at, arr[i].bt, arr[i].st, arr[i].ct, arr[i].wt, arr[i].tat);
    }
    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}