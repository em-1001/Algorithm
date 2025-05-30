#include <iostream>
#include <vector>

using namespace std; 

int ord=0;
int lazy[400001], tree[400001]={0,};
int in[100001], out[100001];
vector<vector<int>> grp; 

void prop(int node, int s, int e){
    tree[node]+=lazy[node]*(e-s+1); 
    if(s!=e) for(int i : {node*2, node*2+1}) lazy[i]+=lazy[node]; 
    lazy[node]=0; 
    return; 
}

int update(int node, int s, int e, int i, int j, int v){
    if(lazy[node]) prop(node,s,e); 
    if(i>e || j<s) return tree[node]; 
    if(i<=s && e<=j){
        lazy[node]=v;
        prop(node,s,e); 
        return tree[node];
    }
    int m=s+e>>1; 
    return tree[node]=update(node*2,s,m,i,j,v)+update(node*2+1,m+1,e,i,j,v); 
}

int query(int node, int s, int e, int i, int j){
    if(lazy[node]) prop(node, s, e); 
    if(i>e || j<s) return 0; 
    if(i<=s && e<=j) return tree[node];
    int m=s+e>>1; 
    return query(node*2,s,m,i,j)+query(node*2+1,m+1,e,i,j);
}

void ETT(int cur, int par){
    in[cur]=++ord; 
    for(auto i:grp[cur]) if(i!=par) ETT(i,cur); 
    out[cur]=ord; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int a, b, c; 
    cin >> n >> m; 
    grp.resize(n+1);
    cin >> a;
    for(int i=2; i<=n; i++){
        cin >> a; 
        grp[a].push_back(i); 
    }
    ETT(1,1);
    for(int i=0; i<m; i++){
        cin >> a >> b; 
        if(a==1){
            cin >> c; 
            update(1,1,n,in[b],out[b],c);
        }
        else{
            cout << query(1,1,n,in[b],in[b]) << "\n";
        }
    }

    return 0;
}