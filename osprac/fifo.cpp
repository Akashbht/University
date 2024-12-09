#include<bits/stdc++.h>
using namespace std;
 

int main(){
    int n ;
    cout <<"enter no of frames availaible :";
    cin >> n;    
    int m ;
      cout <<"enter no. of requests :"; cin >> m;

    unordered_set<int>mem;
    vector<int>requests(m);
    cout <<"enter the frames :";
    for(int i = 0 ;i<m;i++){
        cin >> requests[i];
    }

    queue<int>q;
    int pf = 0;
    for(int i : requests){
        if(mem.find(i) == mem.end()){
            pf++;

            if(mem.size() == n){
                int temp = q.front();
                q.pop();
                mem.erase(temp);
            }

            mem.insert(i);
            q.push(i);



        }   
        for(int i : mem){
            cout << i << " " ;
        }
        cout << "\n---------   "<<pf<<endl;

    }
    cout << "the no of page faults " <<pf;


}