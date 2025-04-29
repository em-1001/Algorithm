#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<bool> ward;
vector<pair<int, int>> route[100001];
long dist[100001];
long inf = LONG_MAX;

void dijkstra(int s){
    dist[s] = 0;
    priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        long d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < d) continue;
        for(int i=0; i<route[cur].size(); i++){
            long next_d = d + route[cur][i].second;
            int next = route[cur][i].first;
            if(next_d < dist[next]){
                dist[next] = next_d;
                pq.push(make_pair(next_d, next));
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    bool w;
    int v, e;
    int a, b, d;
    cin >> v >> e;
    
    for(int i=0; i<v; i++){
        cin >> w;
        ward.push_back(w);
        dist[i] = inf;
    }
    ward.pop_back();
    ward.push_back(0); //nexus -> 0
    
    for(int i=0; i<e; i++){
        cin >> a >> b >> d;
        if(!ward[a] && !ward[b]){
            route[a].push_back(make_pair(b, d));
            route[b].push_back(make_pair(a, d));
        }
    }
    
    dijkstra(0);
    
    if(dist[v-1] == inf) cout << -1;
    else cout << dist[v-1];
    
    return 0;
}