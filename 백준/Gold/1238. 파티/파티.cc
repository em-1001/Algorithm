#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std; 

vector<pair<int, int>> route[1001];
vector<pair<int, int>> rev_route[1001];
int dist[1001];
int rev_dist[1001];

int n, m, x, max_dist=0;

void dijkstra(int s, bool rev){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    dist[s]=0; 
    rev_dist[s]=0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int d=pq.top().first;
        int v=pq.top().second; 
        pq.pop(); 
        if(!rev && dist[v]<d) continue;
        if(rev && rev_dist[v]<d) continue;
        if(!rev){
            for(int i=0; i<route[v].size(); i++){
                int nv = route[v][i].second; 
                int nd = route[v][i].first + d; 
                if(nd<dist[nv]){
                    dist[nv]=nd;
                    pq.push(make_pair(nd, nv));
                }
            }
        }
        else{ // reverse
            for(int i=0; i<rev_route[v].size(); i++){
                int nv = rev_route[v][i].second; 
                int nd = rev_route[v][i].first + d; 
                if(nd<rev_dist[nv]){
                    rev_dist[nv]=nd;
                    pq.push(make_pair(nd, nv));
                }
            }
        }
    }
}

int main()
{
    int a, b, d;
    cin >> n >> m >> x; 
    for(int i=0; i<m; i++){
        cin >> a >> b >> d; 
        route[a].push_back(make_pair(d, b));
        rev_route[b].push_back(make_pair(d, a));
    }
    
    for(int i=1; i<=n; i++){
        dist[i]=INT_MAX; 
        rev_dist[i]=INT_MAX;
    }
    
    dijkstra(x, 0); 
    dijkstra(x, 1); // reverse dijkstra
    
    /*
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << "\n";
    for(int i=1; i<=n; i++) cout << rev_dist[i] << " ";
    cout << "\n";*/
    
    for(int i=1; i<=n; i++){
        if(dist[i]+rev_dist[i]>max_dist) max_dist=dist[i]+rev_dist[i];
    }
    
    cout << max_dist; 

    return 0;
}