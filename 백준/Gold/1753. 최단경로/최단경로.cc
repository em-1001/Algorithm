#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>

using namespace std;

long dist[20001];
int n, m, s, e;
long d;
vector<pair<long, int>> graph[20001];

void dijkstra(int s){
    dist[s] = 0;
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        long d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(dist[v] < d) continue;
        for(int i=0; i<graph[v].size(); i++){
            long nd = d + graph[v][i].second;
            int nv = graph[v][i].first;
            if(nd < dist[nv]){
                dist[nv] = nd;
                pq.push(make_pair(nd, nv));
            }
        }
    }
}

int main()
{
    int start; 
    
    cin >> n >> m;
    
    cin >> start;
    
    for(int i=0; i<m; i++){
        cin >> s >> e >> d;
        graph[s].push_back(make_pair(e, d));
    }
    
    for(int i=1; i<=n; i++) dist[i] = 987654321;
    
    dijkstra(start);
    
    for(int i=1; i<=n; i++){
        if(dist[i] == 987654321) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}