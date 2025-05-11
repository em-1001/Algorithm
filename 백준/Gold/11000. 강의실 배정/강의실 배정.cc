#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, s, t; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2; 

int main()
{
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> s >> t; 
        pq1.push(make_pair(s, t)); 
    }
    pq2.push(pq1.top().second); 
    pq1.pop(); 
    while(!pq1.empty()){
        if(pq2.top()<=pq1.top().first) pq2.pop(); 
        pq2.push(pq1.top().second);
        pq1.pop(); 
    }
    
    cout << pq2.size(); 

    return 0;
}