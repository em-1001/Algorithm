#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring> 
#include <string>

using namespace std;

vector<string> maze;
vector<int> adj[10001];
int dist[10001] = {0,};
int n, m;

void bfs(int s){
    queue<int> q;
    dist[s] = 1;
    q.push(s);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<adj[v].size(); i++){
            int y = adj[v][i];
            if(!dist[y]){
                dist[y] = dist[v] + 1;
                if(y == n*m-1){
                    cout << dist[y];
                    return;
                }
                q.push(y);
            }
        }
    }
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    string in;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> in;
        maze.push_back(in);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j] == '0') continue;
            for(int dir=0; dir<4; dir++){
                int ni = i + dy[dir];
                int nj = j + dx[dir];
                if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
                if(maze[ni][nj]=='1'){
                    adj[i*m+j].push_back(ni*m+nj);
                }
            }
        }
    }
    
    bfs(0);
    
    return 0;
}