#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int board[10][10] = {0,};
int l[20] = {0,};
int r[20] = {0,};
int n, cnt=0, max_bishop=0;


bool promising(int x, int y, int rank){
    if(board[y][x] && !l[rank] && !r[n-(x-y)]) return 1;
    return 0;
}

void backtrack(int rank){
    if(rank == 2*n){
        if(cnt > max_bishop) max_bishop = cnt;
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
            backtrack(rank+1);
            cnt--;
            l[rank]=0;
            r[n-(x-y)]=0;
        }
    }
    if(!flag) backtrack(rank+1);
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
    backtrack(1);
    cout << max_bishop;

    return 0;
}