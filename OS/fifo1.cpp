#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int fifo( vector<int>& pages, int capacity) {
    unordered_set<int> mem; 
    queue<int> q;      
    int pf = 0;

    for (int page : pages) {
         
        if (mem.find(page) == mem.end()) {
            pf++;

             
            if (mem.size() == capacity) {
                int oldest_page = q.front();
                q.pop();
                mem.erase(oldest_page); 
            }

             
            mem.insert(page);
            q.push(page);
        }
        for(int i : mem){
            cout << i << " ";
        }
        cout <<" \n--------\n";
    }
   
    return pf;
}

int main() {
    int capacity;
    cout << "enter frame availaible";
    cin >> capacity;

    int n;
    cout << "Enter lenght of string  ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter pages ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    int pf = fifo(pages, capacity);
    cout << "total faults " << pf << endl;

    return 0;
}
