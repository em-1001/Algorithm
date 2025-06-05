#include <iostream>
#include <vector> 

using namespace std; 

int n, wei[200001], num[200001], dep[200001], top[200001], par[200001], ord=0; 
int tree[800001]={0,}; 
vector<vector<int>> grp; 

int seg_sum(int node, int s, int e, int i, int j){
    if(s>j || e<i) return 0;
    if(i<=s && e<=j) return tree[node]; 
    int m=s+e>>1; 
    return seg_sum(node*2,s,m,i,j)+seg_sum(node*2+1,m+1,e,i,j);
}

int seg_update(int node, int s, int e, int i, int v){
    if(i<s || i>e) return tree[node]; 
    if(s==e) return tree[node]=v;
    int m=s+e>>1; 
    return tree[node]=seg_update(node*2,s,m,i,v)+seg_update(node*2+1,m+1,e,i,v);
}

void dfs1(int cur){
    wei[cur]=1; 
    for(auto &i:grp[cur]){
        if(i==par[cur]) continue; 
        dep[i]=dep[cur]+1; 
        par[i]=cur; 
        dfs1(i); 
        wei[cur]+=wei[i]; 
        if(grp[cur][0]==par[cur] || wei[grp[cur][0]]<wei[i]) swap(grp[cur][0], i); 
    }
}

void dfs2(int cur){
    num[cur]=++ord; 
    for(auto &i:grp[cur]){
        if(i==par[cur]) continue; 
        top[i]=i==grp[cur][0]?top[cur]:i;
        dfs2(i); 
    }
}

void HLD(int root){
    dfs1(root); 
    top[1]=1; 
    dfs2(root); 
}

void query(int i, int j, bool k){
    int res=0; 
    int mem_i=i, mem_j=j; 
    while(top[i]!=top[j]){
        if(dep[top[i]]<dep[top[j]]) swap(i, j); 
        res+=seg_sum(1,1,n,num[top[i]]+1,num[i]);
        i=par[top[i]]; 
    }
    if(num[i]>num[j]) swap(i,j); 
    res+=seg_sum(1,1,n,num[i]+1,num[j]); 
    
    if(res==0){
        cout << "YES" << "\n";
        if(k) seg_update(1,1,n,num[mem_i],-1);
    }
    else{
        cout << "NO" << "\n"; 
        if(k) seg_update(1,1,n,num[mem_j],-1);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, a, b, c, d; 
    cin >> n >> q; 
    grp.resize(n+1); 
    for(int i=2; i<=n; i++){
        cin >> a; 
        grp[i].push_back(a); 
        grp[a].push_back(i); 
    }

    HLD(1); 
    
    for(int i=0; i<q; i++){
        cin >> b >> c >> d; 
        query(b,c,d); 
    }
    
    return 0;
}
