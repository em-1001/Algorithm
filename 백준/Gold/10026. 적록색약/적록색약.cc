#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<int> adj[10001];
bool visited[10001];
string str[101];
int n, cnt=0, blind_cnt=0;

void dfs(int i, int j, bool blind){
    int node = i*n+j;
    visited[node] = 1;
    for(int k=0; k<adj[node].size(); k++){
        int next = adj[node][k];
        int y = next/n;
        int x = next%n;
        if(blind && str[i][j]!='B'){
            if(!visited[next] && 'B'!=str[y][x]) dfs(y, x, blind);
        }
        else{
            if(!visited[next] && str[i][j]==str[y][x]) dfs(y, x, blind);
        }
    }
    return;
}


int main()
{
    int c;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int node = i*n+j;
            if((node+1)%n){
                adj[node].push_back(node+1);
                adj[node+1].push_back(node);
            }
            if((node+n)<(n*n)){
                adj[node].push_back(node+n);
                adj[node+n].push_back(node);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i*n+j]){
                dfs(i, j, false);
                cnt++;
            }
        }
    }
    
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i*n+j]){
                dfs(i, j, true);
                blind_cnt++;
            }
        }
    }
    
    cout << cnt << " " << blind_cnt;

    return 0;
}