#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std; 

vector<pair<int, int>> graph[801]; 
long dist[801];
long inf=pow(10,15);

void dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s]=0; 
    while(!pq.empty()){
        int cur=pq.top().second;
        int d=pq.top().first; 
        pq.pop();
        if(dist[cur]<d) continue; 
        for(int i=0; i<graph[cur].size(); i++){
            int nxt=graph[cur][i].second; 
            long nd=d+graph[cur][i].first; 
            if(nd<dist[nxt]){
                dist[nxt]=nd; 
                pq.push(make_pair(nd, nxt));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long ans1=0, ans2=0; 
    int n, e, v1, v2; 
    int a, b, c; 
    
    cin >> n >> e; 
    
    for(int i=1; i<=n; i++) dist[i]=inf; 
    
    for(int i=0; i<e; i++){
        cin >> a >> b >> c; 
        graph[a].push_back(make_pair(c, b)); 
        graph[b].push_back(make_pair(c, a));
    }
    
    cin >> v1 >> v2; 
    
    dijkstra(1);
    ans1+=dist[v1]; 
    for(int i=1; i<=n; i++) dist[i]=inf; 
    dijkstra(v1);
    ans1+=dist[v2]; 
    for(int i=1; i<=n; i++) dist[i]=inf; 
    dijkstra(v2); 
    ans1+=dist[n]; 
    for(int i=1; i<=n; i++) dist[i]=inf;  
    
    dijkstra(1);
    ans2+=dist[v2]; 
    for(int i=1; i<=n; i++) dist[i]=inf;  
    dijkstra(v2);
    ans2+=dist[v1]; 
    for(int i=1; i<=n; i++) dist[i]=inf; 
    dijkstra(v1); 
    ans2+=dist[n]; 
    for(int i=1; i<=n; i++) dist[i]=inf;         

    if(v2==n){
        if(ans1>=inf){
            cout << -1; 
            return 0;
        }
        cout << ans1; 
        return 0; 
    }
    
    long ans=min(ans1, ans2); 
    if(ans>=inf){
        cout << -1;
        return 0; 
    }
    
    cout << ans; 
    
    return 0;
}