#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

int capacity[501][501] = {0, };
int flow[501][501] = {0, }; 
int pre[501];
vector<int> line[501];
int n, m, s, e; 

int Max_Flow(int s, int e){
    int min_cut = 0;
    while(1){
        queue<int> q;
        q.push(s);
        memset(pre, -1, sizeof(pre));
        while(!q.empty()){ //bfs
            int cur = q.front();
            q.pop();
            for(int i=0; i<line[cur].size(); i++){
                int next = line[cur][i];
                if(capacity[cur][next]-flow[cur][next]>0 && pre[next]==-1){
                    q.push(next);
                    pre[next] = cur; 
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
        min_cut += maxflow;
    }
    return min_cut;
}

int main()
{
    int a, b, c;
    
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        line[a].push_back(b);
        line[b].push_back(a);
        capacity[a][b] = c;
        capacity[b][a] = c;
    }
    
    cin >> s >> e;
    
    int min_cut = Max_Flow(s, e);
    
    cout << min_cut;

    return 0;
}