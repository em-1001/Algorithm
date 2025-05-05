#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits.h>

using namespace std; 

int val[301]={0,};
int dp[301]={0,};

int RevStep(int i){
    if(dp[i]>0) return dp[i];
    return dp[i]=max(val[i-1]+RevStep(i-3), RevStep(i-2))+val[i]; 
}

int main()
{
    int n; 
    cin >> n; 
    for(int i=1; i<=n; i++){
        cin >> val[i];
    }
    
    dp[1] = val[1]; 
    dp[2] = max(val[1]+val[2], val[2]); 
    dp[3] = max(val[1]+val[3], val[2]+val[3]);
    
    int ans = RevStep(n);
    
    cout << dp[n];

    return 0;
}