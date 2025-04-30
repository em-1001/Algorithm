#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <limits.h>
#include <string.h>
#include <cstdlib>
using namespace std;

int w, h;
char map[101][101];
int mirror_cnt[101][101];
vector<int> C;
typedef tuple<int, int, int> t;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dijkstra(int s){
    int y = s/w;
    int x = s%w;
    mirror_cnt[y][x] = 0;
    priority_queue<t, vector<t>, greater<t>> pq;
    for(int i=0; i<4; i++){
        int next_y = (s/w)+dy[i];
        int next_x = (s%w)+dx[i];
        if(next_x<0 || next_x>=w || next_y<0 || next_y>=h || map[next_y][next_x]=='*') continue;
        pq.push(make_tuple(0, next_y*w+next_x, i));
    }
    while(!pq.empty()){
        int mirror = get<0>(pq.top());
        int cord = get<1>(pq.top());
        int dir = get<2>(pq.top());
        int y = cord/w;
        int x = cord%w;
        pq.pop();
        if(cord==C[1]) break;
        if(mirror_cnt[y][x] < mirror) continue;
        for(int i=0; i<4; i++){
            if(abs(dir-i)==2) continue;
            int next_y = y+dy[i];
            int next_x = x+dx[i];
            int next_mirror = mirror;
            if(dir != i) next_mirror++;
            while(1){
                if(map[next_y][next_x]=='.' || map[next_y][next_x]=='C'){
                    if(next_mirror < mirror_cnt[next_y][next_x]){
                        mirror_cnt[next_y][next_x] = next_mirror;
                        pq.push(make_tuple(next_mirror, next_y*w+next_x, i));
                    }
                    next_y += dy[i];
                    next_x += dx[i];
                }
                else break;
            }
        }
    }
    return;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    char p;
    
    cin >> w >> h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> p;
            if(p=='C') C.push_back(i*w+j);
            map[i][j] = p;
            memset(mirror_cnt[i], 0x3f, sizeof(mirror_cnt[i]));
        }
    }
    
    dijkstra(C[0]);
    
    cout << mirror_cnt[C[1]/w][C[1]%w];

    return 0;
}