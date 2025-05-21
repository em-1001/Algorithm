#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int n, w; 
vector<pair<int, int>> inc; 
stack<int> rec; 
int dp[1001][1001];
int bt[1001][1001]={0,};

int dynamic(int p1, int p2, int c1, int c2, int rank){
    if(rank==w+1) return 0;
    if(dp[p1][p2]!=-1) return dp[p1][p2]; 
    int c1y=c1/n, c1x=c1%n;
    int c2y=c2/n, c2x=c2%n; 
    int cur_c=inc[rank].first*n+inc[rank].second; 
    int t1=(abs(inc[rank].first-c1y)+abs(inc[rank].second-c1x)
            +dynamic(rank,p2,cur_c,c2,rank+1));
    int t2=(abs(inc[rank].first-c2y)+abs(inc[rank].second-c2x)
            +dynamic(p1,rank,c1,cur_c,rank+1));  
    bt[rank][p2]=t1;
    bt[p1][rank]=t2;
    /*   
    if(t1<=t2){
        rec.push(1); 
        return dp[p1][p2]=t1;
    }        
    else{
        rec.push(2);
        return dp[p1][p2]=t2;
    }*/
            
    //int ans=min(t1, t2);
    //cout << p1 << " " << p2 << " " << ans << endl;
    return dp[p1][p2]=min(t1, t2);
}

void backtrack(int p1, int p2, int c1, int c2, int rank){
    if(rank==w+1) return;
    int c1y=c1/n, c1x=c1%n;
    int c2y=c2/n, c2x=c2%n;
    int cur_c=inc[rank].first*n+inc[rank].second;
    int d1=abs(inc[rank].first-c1y)+abs(inc[rank].second-c1x);
    int d2=abs(inc[rank].first-c2y)+abs(inc[rank].second-c2x);
    if(d1+dp[rank][p2]<d2+dp[p1][rank]){
        cout << 1 << "\n";
        backtrack(rank,p2,cur_c,c2,rank+1);
    }
    else{
        cout << 2 << "\n";
        backtrack(p1,rank,c1,cur_c,rank+1);
    }
}

int main()
{
    int a, b;
    cin >> n; 
    cin >> w; 
    inc.push_back(make_pair(-1, -1));
    for(int i=0; i<w; i++){
        cin >> a >> b; 
        inc.push_back(make_pair(a-1, b-1));
    }
    memset(dp, -1, sizeof(dp));
    cout << dynamic(0,0,0,n*n-1,1) << "\n";
    backtrack(0,0,0,n*n-1,1);
    /*
    for(int i=0; i<=w; i++){
        for(int j=0; j<=w; j++){
            cout << bt[i][j] << " ";
        }
        cout << "\n";
    }*/
    
    /*
    int l=0,r=0, cnt=1;
    while(cnt<w+1){
        if(bt[cnt][r]<bt[l][cnt]){
            cout << 1 << "\n";
            l=cnt;
        }
        else{
            cout << 2 << "\n";
            r=cnt;
        }
        cnt++;
    }*/
    
    return 0;
}

