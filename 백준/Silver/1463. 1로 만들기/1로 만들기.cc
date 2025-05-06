#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std; 
int n; 
int dp[1000001];

int MakeOne(int i){
    if(i==1) return 0; 
    if(dp[i]>0) return dp[i];
    if(i%3==0 && i%2==0) return dp[i] = min(1+MakeOne(i/3), 1+MakeOne(i/2));
    else if(i%3==0) return dp[i] = min(1+MakeOne(i/3), 1+MakeOne(i-1));
    else if(i%2==0) return dp[i] = min(1+MakeOne(i/2), 1+MakeOne(i-1));
    else return dp[i] = 1+MakeOne(i-1);
}

int main()
{
    cin >> n; 
    memset(dp, 0, sizeof(dp));
    dp[1] = 0; 
    dp[2] = 1; 
    dp[3] = 1; 
    dp[4] = 2; 
    
    int ans = MakeOne(n);
    
    /*
    for(int i=1; i<=n; i++){
        cout << dp[i] << " "; 
    }*/
    
    cout << ans; 

    return 0;
}