
#include<bits/stdc++.h>
using namespace std;
 



int main(){
    int n,p ;
    cout<<"enter hte number of blocks";cin >> n;
    vector<int>blocks(n);
    cout <<"enter the size of blocks ; ";
    vector<int>isalloc(n,0);
    for(int i = 0 ;i<n;i++) cin >>blocks[i];
    unordered_map<int,int>res;

    cout <<"enter the number of process : ";cin>>p;
    vector<int>pro(p);
    cout <<"enter proceses ";
    
    for(int i  = 0 ;i<p;i++)cin>>pro[i];

    for(int pr : pro){
        int mindiff = 0;
        int idx = -1;
        for(int i = 0 ;i< n ;i++){
            if(!isalloc[i] && (blocks[i]- pr)>0&& (blocks[i]- pr) > mindiff){
                mindiff = blocks[i]- pr;
                idx = i;
            }
        }
        if(idx != -1){
            isalloc[idx] = 1;
            res[pr] = blocks[idx];
            // cout << "process "<< pr <<" is allocated to block "<< blocks[idx] << endl;
        }

    }
    cout <<"allocaiton blocks \n";
    for(int pr : pro){
         cout << pr << " "<<res[pr]<<endl;
    }
    




    return 0;

}