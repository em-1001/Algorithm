#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std; 

vector<int> v[32001];
int n, m, indgree[32001];

void topologysort(){
    int ans[32001]={0,};
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indgree[i]==0){
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++){
        if(q.empty()) return; 
        int cur = q.front(); 
        ans[i]=cur;
        q.pop(); 
        for(int j=0; j<v[cur].size(); j++){
            int nxt = v[cur][j];
            if(--indgree[nxt]==0) q.push(nxt);
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    return;
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

    return 0;
}