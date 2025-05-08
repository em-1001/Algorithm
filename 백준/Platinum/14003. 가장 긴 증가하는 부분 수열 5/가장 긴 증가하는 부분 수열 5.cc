#include <iostream>
#include <algorithm>
#include <stack> 

using namespace std;

long long in[1000001];
long long dp[1000001];
long long dp2[1000001];
long long bs[1000001];

int BinarySearch(int l, int r, int t){
    int m;
    while(l<r){
        m = l+r>>1;
        if(t==bs[m]) return m;
        else if(t>bs[m-1] && t<bs[m]) return m;
        else if(t>bs[m]) l=m+1;
        else r=m-1;
    }
    return l;
}

int main()
{
    int n; 
    stack<int> s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
        dp[i]=1;
    }
    
    bs[0]=in[0];
    dp2[0]=1; 
    int i=1, j=0, max_idx=0, max_dp=1;
    while(i<n){
        if(in[i]>bs[j]){
            bs[j+1]=in[i];
            dp[j+1]=dp[j]+1;
            dp2[i]=dp[j]+1;
            j++;
        }
        else{
            int idx=BinarySearch(0, j, in[i]);
            bs[idx]=in[i]; 
            dp2[i]=dp[idx];
        }
        if(dp2[i]>=max_dp){
            max_dp=dp2[i];
            max_idx=i; 
        }
        i++;
    }
    
    cout << dp[j] << "\n";
    
    /*
    for(int i=0; i<n; i++){
        cout << dp2[i] << " ";
    }
    
    //cout << "\n" << max_idx << " " << max_dp << "\n";*/

    int prev=in[max_idx];
    s.push(prev);
    max_dp--;
    for(int i=max_idx-1; i>=0; i--){
        if(dp2[i]==max_dp && in[i]<prev){
            prev=in[i]; 
            s.push(prev);
            max_dp--; 
            if(max_dp==0) break; 
        }
    }
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}