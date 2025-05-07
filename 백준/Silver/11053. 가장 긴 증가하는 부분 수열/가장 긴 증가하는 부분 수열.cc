#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int in[1001];
int dp[1001];

int main()
{
    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
        dp[i]=1;
    }
    
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(in[i]>in[j]) dp[i]=max(dp[j]+1, dp[i]);
        }
    }
    
    int max=1;
    for(int i=1; i<n; i++){
        if(dp[i]>max) max=dp[i];
    }
    
    cout << max;

    return 0;
}