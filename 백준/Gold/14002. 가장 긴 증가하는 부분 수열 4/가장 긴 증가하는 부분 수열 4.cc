#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

int dp[1001];
int in[1001];
vector<int> lis;


int main()
{
    int n;
    stack<int> s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
        dp[i]=1;
    }
  
    int max_idx=0, max_dp=1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(in[i]>in[j]){ 
                dp[i]=max(dp[i], dp[j]+1);
            }
            if(dp[i]>max_dp){
                max_dp=dp[i];
                max_idx=i;
            }
        }
    }
    
    s.push(in[max_idx]);
    int cur=max_idx;
    for(int i=max_idx-1; i>=0; i--){
        if(in[i]<in[cur] && dp[i]+1==dp[cur]){
            cur=i;
            s.push(in[i]);
        }
    }
    
    cout << max_dp << "\n";
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
