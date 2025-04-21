#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v, g;
int n, m;

bool compare(int a, int b){
    return a < b;
}

bool promising(int k){
    return 1;
}


void backtrack(int rank){
    if(rank == m){
        for(int i=0; i<g.size(); i++){
            cout << g[i] << " ";
        }
        cout << "\n";
        return;
    }
    int pv = -1;
    for(int i=0; i<v.size(); i++){
        int cur = v[i];
        if(cur != pv){
            g.push_back(cur);
            v.erase(v.begin()+i);
            backtrack(rank+1);
            g.pop_back();
            v.insert(v.begin()+i, cur);
        }
        pv = cur;
    }

}

int main()
{
    int k;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end(), compare);
    
    backtrack(0);
        
    return 0;
}