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
            if(arr[j].at > arr[j+1].at || (arr[j].at == arr[j+1].at && arr[j].id > arr[j+1].id)){
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
    
    cout <<"\nID\tAT\tBT\tST\tCT\tTAT\tWT\n";
    int curr = 0 ;
    float atat = 0 , awt = 0;
    for(int i = 0 ; i< n;i++){
        arr[i].st = curr;
        arr[i].ct = curr + arr[i].bt;
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        atat += arr[i].tat;
        awt += arr[i].wt;
        curr = arr[i].ct;
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t");
    }
    cout <<"GANTT CHART"<<endl;

    for(int i = 0 ;i<n;i++){
        cout << "P"<<arr[i].id<<" ("<<arr[i].ct <<") |";
    }
    cout << "\n\n average tat = "<< atat/n<<endl;
    cout << "average wt = "<< awt/n<<endl;

}