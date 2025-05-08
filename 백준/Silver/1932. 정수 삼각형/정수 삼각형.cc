#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;
vector<int> tree[501];
vector<int> dp[501];

int main()
{
    int n, a;
    cin >> n; 
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> a;
            tree[i].push_back(a);
        }
    }
    
    if(n==1){
        cout << tree[0][0];
        return 0;
    }        
    
    dp[0].push_back(tree[0][0]);
    dp[1].push_back(tree[1][0]+tree[0][0]);
    dp[1].push_back(tree[1][1]+tree[0][0]);
    
    if(n==2){
        cout<< max(dp[1][0], dp[1][1]);    
        return 0;
    } 
    
    int ans=0;
    for(int i=2; i<n; i++){
        dp[i].push_back(tree[i][0]+dp[i-1][0]);
        if(i==n-1 && dp[i][0]>ans) ans=dp[i][0];
        for(int j=1; j<i; j++){
            int next=max(dp[i-1][j-1], dp[i-1][j])+tree[i][j];
            dp[i].push_back(next);
            if(i==n-1 && dp[i][j]>ans) ans=dp[i][j];
        }
        dp[i].push_back(tree[i][i]+dp[i-1][i-1]);
        if(i==n-1 && dp[i][i]>ans) ans=dp[i][i];
    }
    
    cout << ans;

    return 0;
}
