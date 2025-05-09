#include <iostream>
#include <string.h>

using namespace std;

int dp[41]; 
int dp2[41];

int zero_cnt=0;
int one_cnt=0; 

int zero_fibo(int n){
    if(n==0){
        return dp[0]=1;
    }
    else if(n==1){
        return dp[1]=0;
    }
    if(dp[n]>=0) return dp[n]; 
    return dp[n]=zero_fibo(n-1)+zero_fibo(n-2);
}

int one_fibo(int n){
    if(n==0){
        return dp2[0]=0;
    }
    else if(n==1){
        return dp2[1]=1;
    }
    if(dp2[n]>=0) return dp2[n]; 
    return dp2[n]=one_fibo(n-1)+one_fibo(n-2);
}

int main()
{
    int n, a; 
    cin >> n;
    for(int i=0; i<n; i++){
        memset(dp, -1, sizeof(dp)); 
        memset(dp2, -1, sizeof(dp2));
        cin >> a; 
        zero_fibo(a);
        one_fibo(a); 
        cout << dp[a] << " " << dp2[a] << "\n";
    }

    return 0;
}