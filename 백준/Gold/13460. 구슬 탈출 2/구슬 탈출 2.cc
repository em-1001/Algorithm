#include <iostream>
#include <string>

using namespace std; 

int n, m, tot_min=9999; 
int red_x, red_y, blue_x, blue_y; 
char map[11][11];  
string a; 
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0}; 

int beam(int i, int r, int b, bool red){
    int x, y, tmp_x, tmp_y; 
    int red_y=r/m, red_x=r%m, blue_y=b/m, blue_x=b%m; 
    if(red){
        x=red_x; 
        y=red_y; 
        tmp_x=blue_x;
        tmp_y=blue_y;
    }
    else{
        x=blue_x;
        y=blue_y;
        tmp_x=red_x;
        tmp_y=red_y;
    }
    while(map[y+dy[i]][x+dx[i]]!='#' && !(y+dy[i]==tmp_y && x+dx[i]==tmp_x)){
        y+=dy[i];
        x+=dx[i];
        if(!red && map[y][x]=='O') return -1; 
    }
    return y*m+x; 
}

int promising(int r, int b, int i){
    bool blue=0; 
    red_y=r/m, red_x=r%m, blue_y=b/m, blue_x=b%m; 
    int ny=red_y+dy[i], nx=red_x+dx[i]; 
    
    //one step
    if(map[ny][nx]=='#') return 0; 
    if(ny==blue_y && nx==blue_x){
        if(map[ny+dy[i]][nx+dx[i]]=='#') return 0; 
        else blue=1;
    }
    if(map[ny][nx]=='O') return 3;
    
    while(1){
        ny+=dy[i];
        nx+=dx[i];
        if(ny==blue_y && nx==blue_x) blue=1; 
        if(map[ny][nx]=='#') break; 
        if(map[ny][nx]=='O'){
            if(blue) return -1; 
            else return 3; 
        } 
    }
    if(blue) return 2; //blue first 
    else return 1; 
}


void backtrack(int r, int b, int rank){
    if(rank>10) return;
    for(int i=0; i<4; i++){
        int res=promising(r,b,i); 
        if(res==0){
            int blue=beam(i,r,b,0); 
            if(blue==-1) continue;
            if(blue==b) continue;
            backtrack(r, blue, rank+1); 
        }
        if(res==1){ //red first
            int red=beam(i,r,b,1);
            int blue=beam(i,red,b,0); 
            if(blue==-1) continue;
            backtrack(red, blue, rank+1); 
        }
        else if(res==2){ //blue first
            int blue=beam(i,r,b,0);
            int red=beam(i,r,blue,1); 
            backtrack(red, blue, rank+1); 
        }
        else if(res==3){
            int blue=beam(i,r,b,0);
            if(blue/m+dy[i]==r/m && blue%m+dx[i]==r%m) continue;
            if(rank<tot_min) tot_min=rank; 
            return; 
        }
    }
    
}

int main()
{
    int r, b; 
    cin >> n >> m; 
    
    for(int i=0; i<n; i++){
        cin >> a; 
        for(int j=0; j<m; j++){
            map[i][j]=a[j]; 
            if(a[j]=='R'){
                r=i*m+j;
            }
            if(a[j]=='B'){
                b=i*m+j;
            }
        }
    }
    
    backtrack(r,b,1); 
    
    if(tot_min>10) cout << -1; 
    else cout << tot_min; 
    
    return 0;
}