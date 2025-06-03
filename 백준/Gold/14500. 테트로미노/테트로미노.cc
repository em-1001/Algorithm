#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int n, m, tot_max=-1; 
int mat[501][501]={0,};
bool visited[501][501]={0,};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dfs(int idx, int rank, int sum){
    if(rank==4){
        if(sum>tot_max) tot_max=sum; 
        return; 
    }
    int y=idx/m; 
    int x=idx%m; 
    visited[y][x]=1; 
    sum+=mat[y][x]; 
    for(int i=0; i<4; i++){
        int ny=y+dy[i]; 
        int nx=x+dx[i]; 
        if(ny>=0 && ny<n && nx>=0 && nx<m && visited[ny][nx]==0){
            dfs(ny*m+nx, rank+1, sum); 
            visited[ny][nx]=0; 
        }
    }
    visited[y][x]=0;
}

void pol5(int idx){
    int tmp=0; 
    int y=idx/m; 
    int x=idx%m; 
    if(x-1>=0 && x+1<m){
        if(y-1>=0) tmp=max(tmp, mat[y][x]+mat[y][x-1]+mat[y][x+1]+mat[y-1][x]);
        if(y+1<n) tmp=max(tmp, mat[y][x]+mat[y][x-1]+mat[y][x+1]+mat[y+1][x]);
    }
    if(y-1>=0 && y+1<n){
        if(x-1>=0) tmp=max(tmp, mat[y][x]+mat[y-1][x]+mat[y+1][x]+mat[y][x-1]);
        if(x+1<m) tmp=max(tmp, mat[y][x]+mat[y-1][x]+mat[y+1][x]+mat[y][x+1]);
    }
    if(tmp>tot_max) tot_max=tmp; 
    return;
}

int main()
{
    cin >> n >> m; 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
    
    for(int i=0; i<n*m; i++) dfs(i,0,0); 
    for(int i=0; i<n*m; i++) pol5(i);
    
    cout << tot_max; 

    return 0;
}