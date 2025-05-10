#include <iostream>
#include <queue>

using namespace std; 

struct Compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        if(a.second==b.second) return a.first > b.first; 
        return a.second > b.second;
    }
};

int main()
{
    int n, s, e; 
    int etime=-1, cnt=0;
    pair<int, int> cur; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> s >> e; 
        pq.push(make_pair(s, e)); 
    }
    
    
    while(!pq.empty()){
        cur=pq.top(); 
        if(cur.first >= etime){
            cnt++;
            etime=cur.second;
        }
        pq.pop();
    }
    
    cout << cnt;
    
    return 0;
}