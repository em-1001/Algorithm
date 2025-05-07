#include <iostream>
#include <algorithm> 

int dp[1001];

using namespace std; 


int main()
{
    int n; 
    cin >> n; 
    
    dp[1]=1; 
    dp[2]=2;
    dp[3]=1;
    for(int i=4; i<=n; i++){
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);
    }
    if(dp[n]%2!=0) cout << "SK";
    else cout << "CY";

    return 0;
}