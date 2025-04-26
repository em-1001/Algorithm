#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

queue<int> q;
vector<int> graph[1000000], ripe;
int day[1000000] = {0,};
int tmt[1000][1000];
int tot_day=1;


int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(vector<int>& ripe){
    for(int i=0; i<ripe.size(); i++){
        day[ripe[i]] = 1;
        q.push(ripe[i]);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<graph[v].size(); i++){
            int y = graph[v][i];
            if(!day[y]){
                day[y] = day[v] + 1;
                if(tot_day < day[y]) tot_day = day[y];
                q.push(y);
            }
        }
    }
}

int main()
{
	//ios::sync_with_stdio(0);
    //cin.tie(0);
    int m, n;
    
    cin >> m >> n;
    
    int in;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in;
            tmt[i][j] = in;
            if(in == -1) day[i*m+j] = -1;
            if(in == 1) ripe.push_back(i*m+j);
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmt[i][j]==-1) continue;
            int node=i*m+j;
            if((node+1)%m!=0 && tmt[i][j+1]!=-1){
                graph[node].push_back(node+1);
                graph[node+1].push_back(node);
            }
            if((node+m)<(n*m) && tmt[i+1][j]!=-1){
                graph[node].push_back(node+m);
                graph[node+m].push_back(node);
            }
        }
    }
    
    bfs(ripe);
    
    for(int i=0; i<n*m; i++){
        if(day[i] == 0){
            cout << -1;
            return 0;
        }
    }
    cout << tot_day-1;
    
    return 0;
}