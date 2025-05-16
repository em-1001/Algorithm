#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std; 

int n, indgree[1001], d[1001];
int dp[1001]={0, }; 

int topologysort(vector<int>* v, int w){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indgree[i]==0){
            q.push(i);
            dp[i]=d[i];
        }
    }
    for(int i=1; i<=n; i++){
        if(q.empty()) return -1; 
        int cur = q.front(); 
        q.pop(); 
        for(int j=0; j<v[cur].size(); j++){
            int nxt = v[cur][j];
            int nxt_dp = dp[cur]+d[nxt];
            if(nxt_dp>dp[nxt]) dp[nxt]=nxt_dp;
            if(--indgree[nxt]==0) q.push(nxt);
        }
    }
    return dp[w];
}

int main()
{
    int t, k, x, y, w; 
    cin >> t; 
    for(int i=0; i<t; i++){
        vector<int> v[1001];
        cin >> n >> k;
        for(int j=1; j<=n; j++) cin >> d[j];
        for(int j=0; j<k; j++){
            cin >> x >> y; 
            v[x].push_back(y); 
            indgree[y]++; 
        }
        cin >> w;
        memset(dp, 0, sizeof(dp));
        cout << topologysort(v, w) << "\n";
        memset(indgree, 0, sizeof(indgree));
        //cout << "\n";
        //for(int i=1; i<=n; i++) cout << dp[i] << " ";
        //cout << "\n";
    }

    return 0;
}