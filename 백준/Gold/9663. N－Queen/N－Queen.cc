#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int v[15] = {-1, };
int n, cnt=0;

bool promising(int cdx){
    for(int i=0; i<cdx; i++){
        if((v[cdx] == v[i]) || ((cdx - i) == abs(v[cdx] - v[i]))) return 0;
    }
    return 1;
}

void backtrack(int cdx){
    if(cdx == n){
        cnt++;
        return;
    }
    
    for(int i=0; i<n; i++){
        v[cdx] = i;
        if(promising(cdx)){
            backtrack(cdx + 1);
        }
        v[cdx] = -1;
    }
}

int main()
{
    cin >> n;
    
    backtrack(0);
    
    cout << cnt << endl;

    return 0;
}