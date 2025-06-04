#include <iostream>
#include <queue>
#include <deque>

using namespace std; 

int n; 
int cur_d=0; 
int dx[]={1,0,-1,0}; 
int dy[]={0,1,0,-1}; 
int visited[101][101]={0,}; 
queue<pair<int, char>> q; 
deque<pair<int, int>> dq; 

int solve(){
    int t=1;
    int a, x=0, y=0;
    char c;
    while(1){
        if(!q.empty()){
            a=q.front().first; 
            c=q.front().second;
            q.pop(); 
        }
        else a=101; 
    
        for(; t<=a; t++){
            //cout << t << endl; 
            int nx=x+dx[cur_d]; 
            int ny=y+dy[cur_d];
            //cout << ny << " " << nx << " " << visited[ny][nx] << endl; 
            if(nx<0 || nx>=n || ny<0 || ny>=n) return t; 
            if(visited[ny][nx]==1) return t;
            if(visited[ny][nx]!=2){
                int by=dq.back().first;
                int bx=dq.back().second; 
                visited[by][bx]=0; 
                dq.pop_back(); 
            }
            visited[ny][nx]=1; 
            dq.push_front(make_pair(ny, nx)); 
            x=nx; 
            y=ny;
        }
        if(c=='D') cur_d=(cur_d+1)%4;
        else cur_d=(cur_d-1)<0?3:(cur_d-1);
    }
    return t;
}

int main()
{
    visited[0][0]=1; 
    dq.push_front(make_pair(0,0));
    int a, b, k, l, x; 
    char c;
    cin >> n >> k; 
    for(int i=0; i<k; i++){
        cin >> a >> b; 
        visited[a-1][b-1]=2; 
    }
    cin >> l; 
    for(int i=0; i<l; i++){
        cin >> x >> c;
        q.push(make_pair(x, c)); 
    }
    
    cout << solve(); 

    return 0;
}