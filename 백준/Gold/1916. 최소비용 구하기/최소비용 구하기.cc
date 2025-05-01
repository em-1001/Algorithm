#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>

using namespace std;

int dist[1001];
int n, m, s, e, d;
vector<pair<int, int>> graph[1001];

void dijkstra(int s){
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(dist[v] < d) continue;
        for(int i=0; i<graph[v].size(); i++){
            int nd = d + graph[v][i].second;
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
    cin >> n; 
    cin >> m; 
    for(int i=0; i<m; i++){
        cin >> s >> e >> d;
        graph[s].push_back(make_pair(e, d));
    }
    cin >> s >> e; 
    
    memset(dist, 0x3f, sizeof(dist));
    
    dijkstra(s);

    cout << dist[e];

    return 0;
}