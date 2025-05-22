#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> graph[100001];
int dp[100001];
bool visited[100001]={0,}; 
int n, r, q;

int dfs(int s){
    for(int i=0; i<graph[s].size(); i++){
        int y=graph[s][i];
        if(!visited[y]){
            visited[y]=1;
            dp[s]+=dfs(y); 
        }
    }
    return dp[s]; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int a, b; 
    cin >> n >> r >> q;  
    for(int i=1; i<=n; i++) dp[i]=1; 
    for(int i=0; i<n-1; i++){
        cin >> a >> b; 
        graph[a].push_back(b); 
        graph[b].push_back(a);
    }
    visited[r]=1;
    dfs(r);
    for(int i=0; i<q; i++){
        cin >> a; 
        cout << dp[a] << "\n";
    }
    
    return 0;
}