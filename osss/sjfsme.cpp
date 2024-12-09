#include<stdio.h>
#include<math.h>


struct sjfs{
    int id,at,bt;
    int wt,ct,st,tat;
};

sjfs* sort(sjfs arr[],int n){
    for(int i = 0 ; i<n;i++){
        for(int j = 0 ; j< n;j++){
            if(arr[i].at < arr[j].at || ((arr[i].at == arr[j].at) &&(arr[i].bt > arr[j].bt))){
                sjfs temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
int main(){
    int n,i,j;
    printf("enter no of processes :");
    scanf("%d",&n);
    sjfs arr[n];
    int iscom[n];
    printf("enter arrival time and burst time for processes :");
    for(int i = 0 ; i< n;i++){
        scanf("%d %d",&arr[i].at,&arr[i].bt);
        arr[i].id = i;
        iscom[i] = 0;
    }
    int atat = 0;
    int awt = 0 ;

    sort(arr,n);

    printf("GANNT CHART \n");

    int c = 0 , curr = 0;
    while(c<n){
        int min_bt = 999;
        int idx = -1;
        for(int i = 0 ; i< n;i++){
            if(arr[i].at <=curr && iscom[i] != 1){
                if(arr[i].bt < min_bt){
                    min_bt = arr[i].bt;
                    idx = i;
                }
            }
        }

        if(idx != -1){
            arr[idx].st = curr;
            arr[idx].ct = curr+ arr[idx].bt;
            arr[idx].tat = arr[idx].ct - arr[idx].at;
            arr[idx].wt = arr[idx].tat - arr[idx].bt;
            iscom[idx] = 1;
            atat += arr[idx].tat;
            awt += arr[idx].wt;

            printf("P%d (%d)|",arr[idx].id,curr);
            curr = arr[idx].ct;
            c++;
        }else{
            curr++;
        }
    } 
    printf("\nID\tAT\tBT\tCT\tST\tTAT\tWT\n");
    for(int i = 0 ; i< n ;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].id,arr[i].at,arr[i].bt,arr[i].ct,arr[i].st,arr[i].tat,arr[i].wt);
    }

    printf("average waiting time : %f",awt*1.0/n);
    printf("average turn around time :%f",atat*1.0/n);


}