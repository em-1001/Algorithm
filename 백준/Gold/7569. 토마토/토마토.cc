#include <iostream>
#include <queue>
#include <tuple>

using namespace std; 

int m, n, h, cnt=0, max_day=0;
int box[100][100][100];
int day[100][100][100]={0, };
queue<tuple<int, int, int>> q;

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {-1, 1, 0, 0, 0, 0}; 
int dz[] = {0, 0, 0, 0, 1, -1};

void bfs(){
    while(!q.empty()){
        int ci=get<0>(q.front()), cj=get<1>(q.front()), ck=get<2>(q.front()); 
        q.pop(); 
        //cout << ci << " " << cj << " " << ck << " "  << endl;
        for(int d=0; d<6; d++){
            int ni=ci+dz[d], nj=cj+dy[d], nk=ck+dx[d];
            if(ni<0 || ni>h-1 || nj<0 || nj>n-1 || nk<0 || nk>m-1) continue;
            if(box[ni][nj][nk]==0 && day[ni][nj][nk]==0){
                cnt-=1; 
                day[ni][nj][nk] = day[ci][cj][ck]+1;
                if(day[ni][nj][nk]>max_day) max_day=day[ni][nj][nk];
                q.push(make_tuple(ni, nj, nk));
            }
        }
    }
    return;
}

int main()
{
    cin >> m >> n >> h; 
    cnt=m*n*h;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> box[i][j][k];
                if(box[i][j][k]==1){
                    q.push(make_tuple(i, j, k));
                    cnt-=1; 
                }
                if(box[i][j][k]==-1) cnt-=1;
            }
        }
    }
    
    bfs(); 
    
    if(!cnt) cout << max_day; 
    else cout << -1;

    return 0;
}