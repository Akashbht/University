// #include<bits/stdc++.h>
// using namespace std;

 
// struct fcfs{

//     int id,at;
//     int bt,wt,tat,ct,st;
// };
// fcfs* sorter(fcfs arr[],int n ){
//     for(int i = 0 ;i<n;i++){
//         for(int j = 0 ; j<n-1;j++){
//             if(arr[j].at > arr[j+1].at){
//                 fcfs temp = arr[j+1];
//                 arr[j+1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     return arr;
// }
// int main(){
//     int n;
//     printf("enter number of processes :");
//     scanf("%d",&n);
//     fcfs arr[n];
//     for(int i = 0 ;i<n;i++){
//         printf("enter process bt and at :");
//         arr[i].id = i;
//         scanf("%d %d",&arr[i].bt,&arr[i].at);
//     }
//     sorter(arr,n);
//     float awt = 0,atat = 0;
//     printf("\nID\tAT\tBT\tST\tCT\tWT\tTAT\n");
//     for(int i = 0;i<n;i++){
//         if(i==0){
//             arr[i].st = arr[i].at;
//         }else{
//             arr[i].st = (arr[i].at>arr[i-1].ct)?arr[i].at : arr[i-1].ct ; 
//         }

//         arr[i].ct = arr[i].st + arr[i].bt;
//         arr[i].tat = arr[i].ct - arr[i].at;
//         arr[i].wt = arr[i].tat - arr[i].bt;
//         awt += arr[i].wt;
//         atat += arr[i].tat;
//         printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].id,arr[i].at,arr[i].bt,arr[i].st,arr[i].ct,arr[i].wt,arr[i].tat);
//     }


//     printf("average waiting time is : %f",awt/n);
//     printf("average turn around time is : %f",atat/n);


//     printf("\nGANTT CHart");
//     for(int i = 0 ; i<n;i++){
//         printf("P%d |",arr[i].id);
//     }
// }



#include<stdio.h>
#include<stdlib.h>

struct fcfs{
    int at,bt,id;
    int st,ct,wt,tat;
};

struct sjf{
    int at,bt,id;
    int st,ct,wt,tat,iscom ;
};

fcfs* sort(fcfs arr[],int n ){
    for(int i = 0 ; i<n;i++){
        for(int j = 0 ; j<n;j++){
            if(arr[j].at>arr[j+1].at || ((arr[j].at == arr[j+1].at) && arr[j].id > arr[j+1].id)){
                fcfs temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }          
        }
    }
    return arr;
}
void fcfsd(fcfs arr[],int n){
    int awt = 0,atat = 0;
    sort(arr,n);
    printf("Gantt chart");
    for(int i = 0 ; i<n;i++){
        printf("P%d |",arr[i].id);
    }
    for(int i = 0 ; i< n;i++){
        if(i==0){
            arr[i].st = arr[i].at;
            arr[i].ct = arr[i].bt;
        }else{
            arr[i].st = (arr[i].at > arr[i-1].ct)?arr[i].at:arr[i-1].ct;
        }

        arr[i].tat = arr[i].ct-arr[i].at;
        arr[i].wt =arr[i].tat - arr[i].bt;
        awt += arr[i].wt;
        atat += arr[i].tat;

        
    }

    for(int i =0;i<n;i++){
        printf("\nProcess %d \n",arr[i].id);

    }
}


void sjf()
int main(){
    int n;
    printf("enter number of proceses; ");
    scanf("%d",&n);

    printf("enter process : arricval and burst time ");
    fcfs arr[n];
    for(int i = 0 ; i< n;i++){
        arr[i].id = i;
        
        scanf("%d %d",&arr[i].at,&arr[i].bt);
    }

    fcfsd(arr,n);
    sjf(arr,n);
}