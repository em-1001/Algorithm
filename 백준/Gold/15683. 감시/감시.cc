#include <iostream>
#include <vector>

using namespace std; 

int n, m, cnt=0, tot_min=64; 
int map[9][9];
int wad[9][9]={0,};
int dx[]={0, 1, 0, -1}; 
int dy[]={-1, 0, 1, 0}; 
vector<int> cctv;


int beam(int y, int x, int d, bool wd){
    int new_c=0; 
    y+=dy[d]; 
    x+=dx[d];
    while(y>=0 && x>=0 && y<n && x<m && map[y][x]!=6){
        if(wad[y][x]==0) new_c++; 
        if(wd==0) wad[y][x]+=1;
        else if(wd==1) wad[y][x]-=1;
        y+=dy[d];
        x+=dx[d];
    }
    return new_c; 
}

void backtrack(int rank){
    int tmp;
    if(rank==cctv.size()){
        if(n*m-cnt < tot_min) tot_min=n*m-cnt;
        return; 
    }
    int c_y=cctv[rank]/m;
    int c_x=cctv[rank]%m;

    if(map[c_y][c_x]==1){
        for(int d=0; d<4; d++){
            tmp=beam(c_y, c_x, d, 0); 
            cnt+=tmp; 
            backtrack(rank+1);
            beam(c_y, c_x, d, 1);
            cnt-=tmp; 
        }
    }
    else if(map[c_y][c_x]==2){
        for(int d=0; d<2; d++){
            tmp=beam(c_y, c_x, d, 0); 
            tmp+=beam(c_y, c_x, d+2, 0); 
            cnt+=tmp; 
            backtrack(rank+1);
            beam(c_y, c_x, d, 1);
            beam(c_y, c_x, d+2, 1); 
            cnt-=tmp; 
        }
    }
    else if(map[c_y][c_x]==3){
        for(int d=0; d<4; d++){
            tmp=beam(c_y, c_x, d, 0); 
            tmp+=beam(c_y, c_x, (d+1)%4, 0); 
            cnt+=tmp; 
            backtrack(rank+1);
            beam(c_y, c_x, d, 1);
            beam(c_y, c_x, (d+1)%4, 1); 
            cnt-=tmp; 
        }
    }
    else if(map[c_y][c_x]==4){
        for(int d=0; d<4; d++){
            tmp=beam(c_y, c_x, d, 0); 
            tmp+=beam(c_y, c_x, (d+1)%4, 0); 
            tmp+=beam(c_y, c_x, (d+2)%4, 0); 
            cnt+=tmp; 
            backtrack(rank+1);
            beam(c_y, c_x, d, 1);
            beam(c_y, c_x, (d+1)%4, 1); 
            beam(c_y, c_x, (d+2)%4, 1); 
            cnt-=tmp;
        }
    }
    else if(map[c_y][c_x]==5){
        tmp=beam(c_y, c_x, 0, 0); 
        tmp+=beam(c_y, c_x, 1, 0); 
        tmp+=beam(c_y, c_x, 2, 0); 
        tmp+=beam(c_y, c_x, 3, 0); 
        cnt+=tmp; 
        backtrack(rank+1);
        beam(c_y, c_x, 0, 1);
        beam(c_y, c_x, 1, 1); 
        beam(c_y, c_x, 2, 1); 
        beam(c_y, c_x, 3, 1);
        cnt-=tmp;
    }
}

int main()
{
    int a;
    cin >> n >> m; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a; 
            map[i][j]=a;
            if(a>0 && a<6){
                cctv.push_back(i*m+j); 
                wad[i][j]=1;
                cnt++; 
            }
            if(a==6) cnt++; 
        }
    }
    
    backtrack(0); 
    
    cout << tot_min;
    
    return 0;
}