#include<bits/stdc++.h>
using namespace  std;



int main(){
    int n ;
    cout<<"enter the number of disk requests : ";cin >> n;
    vector<int>arr(n);
    cout <<"enter :";
    for(int i = 0 ;i< n;i++)cin >> arr[i];
    int head = arr[0];

    int thm = 0;
    for(int i = 1; i<arr.size();i++){
        thm += abs(arr[i] -arr[i-1]);
    }

    cout<<"total head movement is : "<<thm<<endl;



    return 0;
}