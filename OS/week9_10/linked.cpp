#include <bits/stdc++.h>

using namespace std;


struct File {
    string name;
    int startBlock;
    int numBlocks;
    vector<int> blocks; 
};

void searchFile( unordered_map<string, File>& files, const string& fileName) {
    if (files.find(fileName) != files.end()) {
        const File& file = files.at(fileName);
        cout << "File Name: " << file.name << "\n";
        cout << "Start Block: " << file.startBlock << "\n";
        cout << "Number of Blocks: " << file.numBlocks << "\n";
        cout << "Blocks Occupied: ";
        for (int i = 0; i < file.blocks.size(); i++) {
            cout << file.blocks[i];
            if (i != file.blocks.size() - 1) cout << ", ";
        }
        cout << "\n";
    } else {
        cout << "File not found.\n";
    }
}

int main() {
    
    unordered_map<string, File> files;
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        File file;
        cout << "Enter file " << i << " name: ";
        cin >> file.name;
        cout << "Enter starting block of file " << i << ": ";
        cin >> file.startBlock;
        cout << "Enter no of blocks in file " << i << ": ";
        cin >> file.numBlocks;

        cout << "Enter blocks for file " << i << ": ";
        for (int j = 0; j < file.numBlocks; j++) {
            int block;
            cin >> block;
            file.blocks.push_back(block);
        }
        files[file.name] = file;
    }

    string search_file;
    cout << "Enter the file name to be searched: ";
    cin >> search_file;

    searchFile(files, search_file);  

    return 0;
}
