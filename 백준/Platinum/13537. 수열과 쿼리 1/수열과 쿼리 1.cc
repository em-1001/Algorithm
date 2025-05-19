#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;

long arr[100001];

vector<vector<long>> tree(400001); 

void init(int node, int s, long e){
    if(s==e){
        tree[node].push_back(arr[s]);
        return; 
    }
    int m=s+e>>1; 
    init(node*2,s,m);
    init(node*2+1,m+1,e); 
    tree[node].resize(tree[node*2].size()+tree[node*2+1].size());
    merge(tree[node*2].begin(), tree[node*2].end(), 
          tree[node*2+1].begin(), tree[node*2+1].end(), tree[node].begin()
    );
    return; 
}

int query(int node, int s, int e, int i, int j, long v){
    if(s>j || e<i) return 0; 
    if(s>=i && e<=j) return tree[node].end()-upper_bound(tree[node].begin(), tree[node].end(), v);
    int m=s+e>>1; 
    return query(node*2,s,m,i,j,v)+query(node*2+1,m+1,e,i,j,v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(arr, 0, sizeof(arr));
    int n, q, a, b;
    long c;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cin >> q; 
    init(1,1,n);
    for(int i=0; i<q; i++){
        cin >> a >> b >> c; 
        cout << query(1,1,n,a,b,c) << "\n";
    }
    
    return 0;
}