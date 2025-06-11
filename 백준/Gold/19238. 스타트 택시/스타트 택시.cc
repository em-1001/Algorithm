#include <iostream>
#include <vector>
#include <queue>
#include <tuple> 
#include <string.h>

using namespace std; 

int map[20][20]={0,}; 
int visited[20][20]={0,}; 
int dy[]={-1,1,0,0}; 
int dx[]={0,0,-1,1}; 
int n, m, fuel, to_cus=0, to_targ=0, remain; 
vector<int> cus, targ; 

int bfs2cus(int c){
    int cnt=0; 
    if(map[c/n][c%n]>1) return c; //idx of customer
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    queue<int> q; 
    q.push(c); 
    visited[c/n][c%n]=1;
    while(!q.empty()){
        if(cnt==remain) break; 
        int cur=q.front(); 
        q.pop(); 
        int cy=cur/n, cx=cur%n;
        for(int i=0; i<4; i++){
            int ny=cy+dy[i], nx=cx+dx[i]; 
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if(map[ny][nx]==0 && visited[ny][nx]==0){
                visited[ny][nx]=visited[cy][cx]+1; 
                q.push(ny*n+nx); 
            }
            if(map[ny][nx]>1 && visited[ny][nx]==0){
                visited[ny][nx]=visited[cy][cx]+1; 
                q.push(ny*n+nx);
                pq.emplace(visited[ny][nx]-1, ny, nx); //dist, row, col
                cnt++;
            }
        }
    }
    if(cnt!=remain) return -1; 
    auto [dist, row, col]=pq.top(); 
    to_cus=dist; 
    return row*n+col; //idx of customer 
}

int bfs2targ(int c, int cus_idx){
    int target=targ[cus_idx]; 
    if(c==target) return c; 
    queue<int> q; 
    q.push(c); 
    visited[c/n][c%n]=1; 
    while(!q.empty()){
        int cur=q.front(); 
        q.pop(); 
        int cy=cur/n, cx=cur%n;
        for(int i=0; i<4; i++){
            int ny=cy+dy[i], nx=cx+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue; 
            if(ny*n+nx==target){
                to_targ=visited[cy][cx];
                return target; 
            }
            if((map[ny][nx]==0 || map[ny][nx]>1) && visited[ny][nx]==0){
                visited[ny][nx]=visited[cy][cx]+1; 
                q.push(ny*n+nx); 
            }
        }
    }
    if(to_targ==0) return -1; 
}

int solve(int c){
    int cord=c; 
    for(int i=0; i<m; i++){
        cord=bfs2cus(cord); 
        if(cord==-1) return -1; 
        memset(visited, 0, sizeof(visited)); 
        int idx=map[cord/n][cord%n]-2;
        map[cord/n][cord%n]=0; 
        fuel-=to_cus;
        if(fuel<0) return -1; 
        to_cus=0; 
        cord=bfs2targ(cord, idx);
        if(cord==-1) return -1; 
        memset(visited, 0, sizeof(visited)); 
        fuel-=to_targ;
        if(fuel<0) return -1; 
        fuel+=to_targ*2; 
        to_targ=0; 
        remain--; 
    }
    return fuel; 
}

int main()
{
    memset(map, -1, sizeof(map)); 
    int ty, tx, a, b, c, d; 
    cin >> n >> m >> fuel; 
    remain=m; 
   
    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            cin >> map[i][j]; 
        }
    }
   
    cin >> ty >> tx; 
    
    for(int i=0; i<m; i++){
        cin >> a >> b >> c >> d; 
        map[a-1][b-1]=i+2;
        targ.push_back((c-1)*n+d-1); 
    }
    
    cout << solve((ty-1)*n+tx-1); 
    
    return 0;
}