#include<bits/stdc++.h>
using namespace std;
 

struct File {
    string name;
    int numblocks;
    int firstblock;
    vector<int>blocks;

};
int main(){
    int n ;
    cout <<"enter no. of files :";cin>>n;
    unordered_map<string,File>mp;
    string name;
    int firstblock;
    int numblocks;
    for(int i = 0 ;i< n;i++){
        
        
        cout <<"enter file name "<< i+1 << " :";
        cin >> name;
        cout <<"enter first block : ";cin >> firstblock;
        cout<<"enter no. of blocks :";cin >> numblocks;
        File temp;
        temp.name = name;
        temp.firstblock = firstblock;
        temp.numblocks = numblocks;
        cout<<"enter blocks : \n";
        int t;
        for(int i = 0 ;i<numblocks;i++){
            cin >> t;
            temp.blocks.push_back(t);
        }
        mp[name] = temp;
    }

    string na;
    cout <<"enter the file to be searched :";cin >> na;

    cout <<"first block :"<< mp[na].firstblock <<endl;

    cout <<"block allocated : \n";
    for(int i = 0 ;i < mp[na].numblocks;i++){
        cout << mp[na].blocks[i] << " ";
    }
    cout <<endl;

}