// #include<stdio.h>
// #include<math.h>
#include<bits/stdc++.h>
using namespace std;

struct p{
    int id , at ,bt;
    int st,ct,wt,tat;

};


p* sort(p* arr,int n ){
    for(int i = 0 ; i< n;i++){
        for(int j = 0 ;j<n;j++){
            if(arr[j].at > arr[j+1].at){
                p temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}
int main(){
    int n;
    cout <<" enter no of processes :";
    cin >> n;
    p arr[n];
    int iscom[n];
    cout << "enter p at and bt ";
    for (int i = 0 ; i< n;i++){
        iscom[i] = 0;
        arr[i].id = i+1;
        cin >> arr[i].at >>arr[i].bt;
    }

    sort(arr, n);
    

    int c = 0 ;
    int curr =0;
    float atat = 0 , awt = 0;
    cout <<"GANTT CHART : \n";
    while(c <n){
        
        int min = 999;
        int idx = -1;
        for(int i = 0 ; i<n;i++){
            if(arr[i].at <= curr && iscom[i]!= 1 && arr[i].bt < min ){
                min = arr[i].bt;
                idx = i;
            }
        }
        if(idx != -1){  
            arr[idx].st = curr;
            arr[idx].ct = curr + arr[idx].bt;
            arr[idx].tat = arr[idx].ct - arr[idx].at;
            arr[idx].wt = arr[idx].tat - arr[idx].bt;

            iscom[idx] = 1;
            atat += arr[idx].tat;
            awt += arr[idx].wt;

            printf("P%d (%d)",arr[idx].id,arr[idx].ct);
            curr = arr[idx].ct;
            c++;
        }else{
            curr++;
        }
    }

    cout <<"\nID\tAT\tBT\tST\tCT\tTAT\tWT\n";
    for(auto i : arr){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i.id,i.at,i.bt,i.st,i.ct,i.tat,i.wt);
    }

    cout << " average tat = "<< atat/n<<endl;
    cout << "average wt = "<< awt/n<<endl;

}