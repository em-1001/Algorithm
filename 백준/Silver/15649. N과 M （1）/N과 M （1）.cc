#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

bool promising(int i){
    for(int j=0; j<v.size()-1; j++){
        if(v[j] == i) return 0;
    }
    return 1;
}

void backtrack(int cdx){
    
    if(cdx == m){
        for(int j=0; j<v.size(); j++) cout << v[j] << " ";
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