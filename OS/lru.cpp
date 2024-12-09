#include<bits/stdc++.h>
using namespace std;
 

// int LRUPageReplacement(const vector<int>& arr, int capacity) {
//     unordered_map<int, int> mem;  
//     int pf = 0;

//     for (int i = 0; i < arr.size(); i++) {
//         int page = arr[i];

//         if (mem.find(page) == mem.end()) {
//             pf++;

//             if (mem.size() == capacity) {
//                 int lru = -1, min_time = i;
//                 for (auto& p : mem) {
//                     if (p.second < min_time) {
//                         min_time = p.second;
//                         lru = p.first;
//                     }
//                 }
//                 mem.erase(lru);  
//             }
//         }

        
//         mem[page] = i;
//     }

//     return pf;
// }

// int main() {
//     int capacity;
//     cout << "Enter mem capacity: ";
//     cin >> capacity;

//     int n;
//     cout << "Enter number of page references: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter page references: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int pf = LRUPageReplacement(arr, capacity);
//     cout << "Total page faults: " << pf << endl;

//     return 0;
// }

int main(){
    int t;
    cout <<"enter the lenght of string "<<endl;
    cin>>t;
    int arr[t];
    cout <<"enter the numbers one by one : ";
    for(int i = 0 ;i<t;i++){
        cin >> arr[i];
    }
    int n = t;

    for(int i : arr){
        cout << i<<" "; 
    }
    int frame;
    cout <<"enter the number of frames : ";
    cin >> frame;
    int lru = arr[0];
     
    unordered_map<int, int> mem;  
    int pf = 0;

    for (int i = 0; i <n; i++) {
        int page = arr[i];
        int flag = 0 ;
        if (mem.find(page) == mem.end()) {
            pf++;
            flag = 1;

            if (mem.size() == frame) {
                int lru = -1, min_time = i;
                for (auto& p : mem) {
                    if (p.second < min_time) {
                        min_time = p.second;
                        lru = p.first;
                    }
                }
                
        
                mem.erase(lru);  
            }
        }
        
        mem[page] = i;
        if(flag == 1){
        for(auto i : mem){
            cout << i.first << " ";

        }
        cout << "\n--------\n";
        }
    }
    cout << pf<<endl;
    return pf;
  
}