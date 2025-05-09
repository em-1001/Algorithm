#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, flag=0; 
char map[6][6];
int ward[6][6]={0,}; 
vector<int> stu; 
vector<int> tch; 
vector<pair<int, int>> serlist[36]; 
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void update(int s, int t, bool block, bool initial){
    int s_y=s/n, s_x=s%n;
    int t_y=t/n, t_x=t%n; 
    if(s_y==t_y){
        if(s_x<t_x){
            for(int i=s_x; i<t_x; i++){
                if(block) ward[s_y][i]-=1;
                else{
                    if(initial) serlist[s_y*n+i].push_back(make_pair(s, t));
                    ward[s_y][i]+=1;
                }
            }
        }
        else if(s_x>t_x){
            for(int i=t_x+1; i<=s_x; i++){
                if(block) ward[s_y][i]-=1; 
                else{
                    if(initial) serlist[s_y*n+i].push_back(make_pair(s, t));
                    ward[s_y][i]+=1; 
                }
            } 
        }
    }
    else if(s_x==t_x){
        if(s_y<t_y){
            for(int i=s_y; i<t_y; i++){
                if(block) ward[i][s_x]-=1; 
                else{
                    if(initial) serlist[i*n+s_x].push_back(make_pair(s, t));
                    ward[i][s_x]+=1;
                }
            }
        }
        else if(s_y>t_y){
            for(int i=t_y+1; i<=s_y; i++){
                if(block) ward[i][s_x]-=1;
                else{
                    if(initial) serlist[i*n+s_x].push_back(make_pair(s, t));
                    ward[i][s_x]+=1;
                }
            }
        }
    }
    else return; 
}

bool issuccess(){
    for(int i=0; i<stu.size(); i++){
        if(ward[stu[i]/n][stu[i]%n]>0) return 0; 
    }
    flag=1;
    return 1; 
}

bool promising(int i){
    int y=i/n;
    int x=i%n; 
    if(map[y][x]=='X' && ward[y][x]>0) return 1;
    else return 0; 
}

void backtrack(int rank, int prev){
    if(flag) return; 
    if(rank==3){
        issuccess();  
    }
    
    for(int i=prev+1; i<n*n; i++){
        if(promising(i)){
            map[i/n][i%n]='O';
            for(int j=0; j<serlist[i].size(); j++){
                update(serlist[i][j].first, serlist[i][j].second, 1, 0);
            }
            if(rank<3 && issuccess()) break; 
            backtrack(rank+1, i); 
            map[i/n][i%n]='X';
            for(int j=0; j<serlist[i].size(); j++){
                update(serlist[i][j].first, serlist[i][j].second, 0, 0);
            }
        }
    }
}


int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j]=='S') stu.push_back(i*n+j); 
            if(map[i][j]=='T') tch.push_back(i*n+j); 
        }
    }
    
    for(int i=0; i<stu.size(); i++){
        int y=stu[i]/n;
        int x=stu[i]%n;
        for(int d=0; d<4; d++){
            if(map[y+dy[d]][x+dx[d]]=='T'){
                cout << "NO"; 
                return 0;
            }
        }
    }
    
    for(int i=0; i<stu.size(); i++){
        for(int j=0; j<tch.size(); j++){
            update(stu[i], tch[j], 0, 1);
        }
    }

    backtrack(0, -1); 
    
    if(flag) cout << "YES";
    else cout << "NO";
    
    return 0;
}
