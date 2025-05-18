#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m; 
int map[9][9]={0, };
bool infected[9][9]={0, };
int dx[]={0, 0, -1, 1};
int dy[]={-1, 1, 0, 0};
vector<int> virus;
int inf_cnt=0, max_left=0, ini=0;


int bfs(){
    queue<int> q;
    for(int i=0; i<virus.size(); i++) q.push(virus[i]);
    while(!q.empty()){
        int cur=q.front();
        //cout << cur << " ";
        q.pop(); 
        int cy=cur/m; 
        int cx=cur%m;
        for(int d=0; d<4; d++){
            int ny=cy+dy[d];
            int nx=cx+dx[d];
            if(ny<0 || ny>n || nx<0 || nx>m) continue;
            if(map[ny][nx]==0 && infected[ny][nx]==0){
                inf_cnt++;
                infected[ny][nx] = 1;
                q.push(ny*m+nx);
            }
        }
    }
    return ini-inf_cnt;
}

void backtrack(int rank, int prev){
    if(rank==3){
        int left=bfs();
        inf_cnt=0;
        memset(infected, 0, sizeof(infected));
        if(left>max_left) max_left=left;
        return;
    }
    
    for(int i=prev; i<n*m; i++){
        int y=i/m;
        int x=i%m; 
        if(map[y][x]==0){
            //cout << y << " " << x << " ";
            map[y][x]=1;
            backtrack(rank+1, y*m+x);
            map[y][x]=0;
        }
    }
}

int main()
{
    memset(map, -1, sizeof(map));
    cin >> n >> m; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j]; 
            if(map[i][j]==2) virus.push_back(i*m+j);
            if(map[i][j]==0) ini++;
        }
    }
    
    backtrack(0, 0);
    
    cout << max_left-3;

    return 0;
}