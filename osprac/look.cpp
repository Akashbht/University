#include<bits/stdc++.h>
using namespace  std;



int main(){
    int n ;
    int dsize = 199;
    cout<<"enter the number of disk requests : ";cin >> n;
    vector<int>arr(n);
    cout <<"enter :";
    for(int i = 0 ;i< n;i++)cin >> arr[i];
    int head = arr[0];

    sort(arr.begin(),arr.end());

    int p = 0 ;
    int thm = 0 ;
    while(p<n && arr[p] < head){
        p++;
    }
    for(int i = p;i<n;i++){
        thm += abs(arr[i]-head);
        head = arr[i];
    }
    
    for(int i = p-1 ;i>=0;i--){
        thm += abs(arr[i]-head);
        head = arr[i];
    }

    cout<<"total head movement is : "<<thm<<endl;
 
    return 0;
}
 