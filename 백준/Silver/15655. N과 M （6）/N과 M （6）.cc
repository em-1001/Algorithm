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
    for(int i=0; i<g.size()-1; i++){
        if(k <= g[i]) return 0;
    }
    return 1;
}

void backtrack(int cdx){
    if(cdx == m){
        for(int i=0; i<g.size(); i++){
            cout << g[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        g.push_back(v[i]);
        if(promising(v[i])){
            backtrack(cdx+1);
        }
        g.pop_back();
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