#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

int capacity[123][123]={0, }; 
int flow[123][123]={0, };
int pre[123];
vector<int> pipe[701];

int MaxFlow(int s, int e){
    int ret=0;
    while(1){
        queue<int> q; 
        memset(pre, -1, sizeof(pre));
        q.push(s);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0; i<pipe[cur].size(); i++){
                int next = pipe[cur][i];
                if(capacity[cur][next]-flow[cur][next]>0 && pre[next]==-1){
                    pre[next] = cur; 
                    q.push(next);
                    if(next==e) break; 
                }
            }
        }
        if(pre[e]==-1) break; 
        int maxflow = INT_MAX;
        for(int i=e; i!=s; i=pre[i]) maxflow=min(maxflow, capacity[pre[i]][i]-flow[pre[i]][i]);
        for(int i=e; i!=s; i=pre[i]){
            flow[pre[i]][i] += maxflow;
            flow[i][pre[i]] -= maxflow;
        }
        ret += maxflow;
    }
    return ret;
}

int main()
{
    int n, c; 
    char s, e;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s >> e >> c;
        pipe[int(s)].push_back(int(e));
        pipe[int(e)].push_back(int(s));
        if(capacity[int(s)][int(e)]!=0){
            capacity[int(s)][int(e)] += c;
            capacity[int(e)][int(s)] += c;
        }
        else{
            capacity[int(s)][int(e)] = c;
            capacity[int(e)][int(s)] = c;
        }
    }
    
    int ret = MaxFlow(int('A'), int('Z'));
    
    cout << ret;
    
    return 0;
}