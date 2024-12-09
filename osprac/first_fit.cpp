
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
    

    for(int i = 0 ;i< p;i++){
        for(int j = 0 ;j<n;j++){
           if(!isalloc[j] && blocks[j]-pro[i]>=0 ){
            res[pro[i]] = j+1;
            isalloc[j] = 1;
            break;
           } 
        }
    }


    cout <<"allocaiton blocks \n";
    for(int i = 0 ;i<p;i++){
        if(res[pro[i]]!= 0 ){
         cout << pro[i] << " "<<res[pro[i]]<<endl;
        }else cout << pro[i] << " NOt allocated "<<endl;
    }
    




    return 0;

}