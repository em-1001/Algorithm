#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m;
int cnt=0;
vector<int> net[101];
bool visited[101];

void dfs(int i){
    visited[i] = 1;
    cnt++;
    for(int j=0; j<net[i].size(); j++){
        int y = net[i][j];
        if(!visited[y]){
            dfs(y);
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        net[a].push_back(b);
        net[b].push_back(a);
    }
    
    dfs(1);
    
    cout << cnt-1;
    
    return 0;
}