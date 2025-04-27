#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int board[10][10] = {0,};
int l[20] = {0,};
int r[20] = {0,};
int n, black_cnt=0, white_cnt=0, cnt=0;


bool promising(int x, int y, int rank){
    if(board[y][x] && !l[rank] && !r[n-(x-y)]) return 1;
    return 0;
}

void black_backtrack(int rank){
    if(rank > 2*n-1){
        if(cnt > black_cnt) black_cnt = cnt;
        return;
    }
    
    int x, y;
    bool flag=0;
    int lim = (rank>n) ? 2*n-rank : rank;
    int begin = (rank>n) ? (rank-n+1)*n-1 : rank-1;
    for(int j=0; j<lim; j++){
        int idx = begin + (n-1)*j;
        y = idx/n;
        x = idx%n;
        if(promising(x, y, rank)){
            flag=1;
            cnt++;
            l[rank]=1;
            r[n-(x-y)]=1;
            black_backtrack(rank+2);
            cnt--;
            l[rank]=0;
            r[n-(x-y)]=0;
        }
    }
    if(!flag) black_backtrack(rank+2);
}

void white_backtrack(int rank){
    if(rank > 2*n-1){
        if(cnt > white_cnt) white_cnt = cnt;
        return;
    }
    
    int x, y;
    bool flag=0;
    int lim = (rank>n) ? 2*n-rank : rank;
    int begin = (rank>n) ? (rank-n+1)*n-1 : rank-1;
    for(int j=0; j<lim; j++){
        int idx = begin + (n-1)*j;
        y = idx/n;
        x = idx%n;
        if(promising(x, y, rank)){
            flag=1;
            cnt++;
            l[rank]=1;
            r[n-(x-y)]=1;
            white_backtrack(rank+2);
            cnt--;
            l[rank]=0;
            r[n-(x-y)]=0;
        }
    }
    if(!flag) white_backtrack(rank+2);
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    black_backtrack(1);
    cnt=0;
    white_backtrack(2);
    cout << black_cnt+white_cnt;

    return 0;
}