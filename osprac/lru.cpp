#include<bits/stdc++.h>
using namespace std;
 


int main(){
    int n;
    cout<<"enter the no of frames availaible : ";cin >> n;
    int m ;
    cout <<"enter the no of frames availaible : ";cin>>m;
    vector<int>frames(m);
    unordered_map<int,int>mem;
    cout <<"enter frames :";
    for(int i = 0 ; i<m;i++)cin >> frames[i];
    int time = 0,pf = 0 ;
    for(int p : frames){
        time ++;
        if(mem.find(p) == mem.end()){
            pf++;
            if(mem.size() == n){
                int t = 999;
                int pg;
                for(auto i : mem){
                    if (i.second < t){
                        t = i.second;
                        pg = i.first;
                    }
                }
                mem.erase(pg);
            }
        }
        mem[p] = time;
        for(auto i : mem){
            cout <<i.first << " ";
        }
        cout <<"\n---------- "<<pf<<endl;
    }     

    cout <<"the no of page faults is : "<<pf<<endl;
    return 0;
}