#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> v, g;
vector<int>::iterator ptr;
int n, m;

bool compare(int a, int b){
    return a < b;
}

bool promising(int i){
    for(int j=0; j<v.size()-1; j++){
        if(i == v[j]) return 0;
    }
    return 1;
}

void backtrack(int cdx){
    if(cdx == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<g.size(); i++){
        v.push_back(g[i]);
        if(promising(g[i])){
            backtrack(cdx + 1);
        }
        v.pop_back();
    }
}

int main()
{
    int p;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> p;
        g.push_back(p);
    }
    sort(g.begin(), g.end(), compare);
    
    backtrack(0);

    return 0;
}