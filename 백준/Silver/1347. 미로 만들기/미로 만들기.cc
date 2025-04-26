#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define U 2
#define D 0
#define L 1
#define R 3
using namespace std;

int dir = D;
string map;

int rx[51] = {0, };
int ry[51] = {0, };
bool track[51][51] = {0,};
int cx=0, cy=0;
int F_cnt = 0;
int max_x=0, min_x=0, max_y=0, min_y=0;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    int l;
    cin >> l;
    cin >> map;
    rx[0] = 0;
    ry[0] = 0;
    for(int i=0; i<l; i++){
        if(map[i] == 'L') dir = dir?(dir-1):3;
        else if(map[i] == 'R') dir = (dir+1)%4;
        else{
            if(dir == U) cy -= 1;
            else if(dir == D) cy += 1;
            else if(dir == L) cx -= 1;
            else cx += 1;
            F_cnt++;
            rx[F_cnt] = cx;
            ry[F_cnt] = cy;
            if(max_x < cx) max_x = cx;
            if(min_x > cx) min_x = cx;
            if(max_y < cy) max_y = cy;
            if(min_y > cy) min_y = cy;
        } 
    }
    if(min_x < 0){
        for(int i=0; i<=F_cnt; i++){
            rx[i] -= min_x;
        }
        max_x -= min_x;
    }
    if(min_y < 0){
        for(int i=0; i<=F_cnt; i++){
            ry[i] -= min_y;
        }
        max_y -= min_y;
    }
    for(int i=0; i<=F_cnt; i++){
        track[ry[i]][rx[i]] = 1;
    }
    
    bool flag=1;
    for(int i=0; i<=max_y; i++){
        for(int j=0; j<=max_x; j++){
            if(track[i][j]) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
	
    return 0;
}
