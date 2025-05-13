#include <iostream>
#include <queue>

using namespace std;

int main()
{
    bool zero_flag=0;
    int n, a, p_sum=0, m_sum=0;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> mq;
    
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> a;
        if(a>0) pq.push(a); 
        else if(a==0) zero_flag=1;
        else mq.push(a); 
    }
    
    while(!pq.empty() && pq.size()!=1){
        int a, b;
        a=pq.top(); 
        pq.pop(); 
        b=pq.top(); 
        pq.pop();
        p_sum+=((a*b)>=(a+b))?(a*b):(a+b);
    }
    if(pq.size()==1) p_sum+=pq.top();
    
    while(!mq.empty() && mq.size()!=1){
        int a, b; 
        a=mq.top();
        mq.pop();
        b=mq.top();
        mq.pop();
        m_sum+=(a*b);
    }
    if(mq.size()==1 && zero_flag==0) m_sum+=mq.top();
    
    cout << p_sum+m_sum;
    
    return 0;
}