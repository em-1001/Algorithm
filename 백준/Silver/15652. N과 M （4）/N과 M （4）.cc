#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

vector<int> v;
int n, m;

bool promising(int i){
    for(int j=0; j<v.size()-1; j++){
        if(i < v[j]) return 0;
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
    
    for(int i=1; i<=n; i++){
        v.push_back(i);
        if(promising(i)){
            backtrack(cdx + 1);
        }
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    
    backtrack(0);

    return 0;
}