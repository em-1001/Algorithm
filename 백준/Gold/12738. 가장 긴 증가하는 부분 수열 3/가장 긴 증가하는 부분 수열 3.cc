#include <iostream>
#include <algorithm>

using namespace std;

long long in[1000001];
long long dp[1000001];
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
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
        dp[i]=1;
    }
    
    bs[0]=in[0];
    int i=1, j=0;
    while(i<n){
        if(in[i]>bs[j]){
            bs[j+1]=in[i];
            dp[j+1]=dp[j]+1;
            j++;
        }
        else{
            int idx=BinarySearch(0, j, in[i]);
            bs[idx]=in[i]; 
        }
        i++;
    }
    
    cout << dp[j];

    return 0;
}