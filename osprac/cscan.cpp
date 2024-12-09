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
    cout <<"enter inital position of head ";cin>>head;

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
    thm += abs(head - dsize);
    head = dsize;
    thm += abs(head - 0);
    head = 0;
    for(int i = 0 ;i<p;i++){
        thm += abs(arr[i]-head);
        head = arr[i];
    }

    cout<<"total head movement is : "<<thm<<endl;
 
    return 0;
}

 