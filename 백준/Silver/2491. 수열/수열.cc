#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std; 

vector<int> v; 
vector<int> dp, revdp; 

int main()
{
    int n, k; 
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k); 
    }
    
    int idx=0, M=1, cnt=1;
    for(int j=0; j<n-1; j++){
        if(v[j]<=v[j+1]) cnt++; 
        else{
            cnt=1;
            idx=j+1; 
        }
        if(cnt>M) M=cnt;
    }
    
    idx=0;
    cnt=1;
    int revM=1;
    for(int j=0; j<n-1; j++){
        if(v[j]>=v[j+1]) cnt++; 
        else{
            cnt=1;
            idx=j+1; 
        }
        if(cnt>revM) revM=cnt;
    }
    
    int ans = max(M, revM);
    
    cout << ans; 

    return 0;
}