#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring> 

using namespace std;

vector<int> node[1001];
bool visited[1001] = {0,};

void dfs(int n){
    visited[n] = true;
    cout << n << " ";
    for(int i=0; i<node[n].size(); i++){
        int y = node[n][i];
        if(!visited[y]) dfs(y);
    }
    return;
}

void bfs(int n){
    queue<int> q;
    visited[n] = true;
    cout << n << " ";
    q.push(n);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<node[v].size(); i++){
            int y = node[v][i];
            if(!visited[y]){
                visited[y] = true;
                cout << y << " ";
                q.push(y);
            }
        }
    }
}


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, v; 
    int e1, e2;
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        cin >> e1 >> e2;
        node[e1].push_back(e2);
        node[e2].push_back(e1);
    }
    for(int i=1; i<=n; i++){
        sort(node[i].begin(), node[i].end());
    }
    dfs(v);
    cout << "\n";
    memset(visited, 0, n+1);
    bfs(v);
    

    return 0;
}