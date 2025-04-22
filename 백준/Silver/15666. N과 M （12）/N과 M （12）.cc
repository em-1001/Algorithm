#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, max_num=-1;
vector<int> v, g;

bool promising(int idx, int visited){
    if(v[idx]!=visited && v[idx] >= max_num){
        return 1;
    }
    return 0;
}

void backtrack(int rank){
    int visited = -1;
    if(rank==m){
        for(int i=0; i<g.size(); i++){
            cout << g[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(promising(i, visited)){
            g.push_back(v[i]);
            visited = v[i];
            max_num = v[i];
            backtrack(rank+1);
            g.pop_back();
            max_num = v[i];
        }
    }
}

int main(){
    int k;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    
    backtrack(0);
    return 0;
}