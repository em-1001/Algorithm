#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <string.h>

using namespace std;

int dp[16][65536];
int map[16][16];
int n, inf=pow(10,9);

int TSP(int here, int visited){
    if(visited==(1<<n)-1) return (map[here][0])?map[here][0]:inf;
    if(dp[here][visited]!=-1) return dp[here][visited];
    for(int i=0; i<n; i++){
        if(!(visited&(1<<i)) && map[here][i]!=0){
            if(dp[here][visited]==-1) dp[here][visited]=map[here][i]+TSP(i, visited|(1<<i));
            else dp[here][visited]=min(map[here][i]+TSP(i, visited|(1<<i)), dp[here][visited]);
        }
    }
    if(dp[here][visited]==-1) dp[here][visited]=inf;
    return dp[here][visited];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp)); 
    cin >> n; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    cout << TSP(0, 1);

    return 0;
}