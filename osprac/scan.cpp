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
    thm += abs(head - dsize);
    head = dsize;
    for(int i = p-1 ;i>=0;i--){
        thm += abs(arr[i]-head);
        head = arr[i];
    }

    cout<<"total head movement is : "<<thm<<endl;



    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     int dsize = 200; // Maximum disk size
//     cout << "Enter the number of disk requests: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter the disk requests: ";
//     for (int i = 0; i < n; i++) 
//         cin >> arr[i];
    
//     int head;
//     cout << "Enter the initial head position: ";
//     cin >> head;

//     sort(arr.begin(), arr.end());

//     int p = 0; 
//     int thm = 0; // Total head movement

//     // Find the first request >= head
//     while (p < n && arr[p] < head) {
//         p++;
//     }

//     // Process requests forward (towards the end of the disk)
//     for (int i = p; i < n; i++) {
//         thm += abs(arr[i] - head);
//         head = arr[i];
//     }

//     // Move to the end of the disk
//     thm += abs(head - dsize);
//     head = dsize;

//     // Process requests backward (towards the start of the disk)
//     for (int i = p - 1; i >= 0; i--) {
//         thm += abs(arr[i] - head);
//         head = arr[i];
//     }

//     cout << "Total head movement is: " << thm << endl;
//     return 0;
// }
