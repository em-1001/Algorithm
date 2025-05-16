#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std; 

vector<int> v[1001];
int n, m, indgree[1001];
int dp[1001]={0, }; 

int topologysort(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indgree[i]==0){
            q.push(i);
            dp[i]=1;
        }
    }
    for(int i=1; i<=n; i++){
        if(q.empty()) return -1; 
        int cur = q.front(); 
        q.pop(); 
        for(int j=0; j<v[cur].size(); j++){
            int nxt = v[cur][j];
            int nxt_dp = dp[cur]+1;
            if(nxt_dp>dp[nxt]) dp[nxt]=nxt_dp;
            if(--indgree[nxt]==0) q.push(nxt);
        }
    }
    return 0; 
}

int main()
{
    int a, b;
    cin >> n >> m; 
    for(int i=0; i<m; i++){
        cin >> a >> b; 
        v[a].push_back(b);
        indgree[b]++; 
    }
    
    topologysort(); 
    
    for(int i=1; i<=n; i++) cout << dp[i] << " ";

    return 0;
}