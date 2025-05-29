#include <iostream>

using namespace std; 

long arr[1000001];
long tree[4000001];
long lazy[4000001]; 

long init(int node, int s, int e){
    if(s==e) return tree[node]=arr[s];
    int m=s+e>>1; 
    return tree[node]=init(node*2,s,m)+init(node*2+1,m+1,e); 
}

void prop(int node, int s, int e){
    tree[node]+=lazy[node]*(e-s+1); //해당 노드의 값에 lazy값을 업데이트 
    if(s!=e) for(int i : {node*2, node*2+1}) lazy[i]+=lazy[node]; //lazy값을 자식 노드에 propagation       
    lazy[node]=0; 
    return;
}

long update(int node, int s, int e, int i, int j, long v){
    if(lazy[node]) prop(node,s,e); //lazy값이 존재한다면 propagation
    if(i>e || j<s) return tree[node]; //탐색범위에 포함되지 않는다면 노드값 리턴 
    if(i<=s && e<=j){ //탐색하는 범위에 완전히 포함되는 경우 
        lazy[node]=v; //lazy값 갱신
        prop(node,s,e); //lazy값 propagation
        return tree[node]; //node값 리턴 
    }
    int m=s+e>>1; 
    return tree[node]=update(node*2,s,m,i,j,v)+update(node*2+1,m+1,e,i,j,v); 
}

long query(int node, int s, int e, int i, int j){
    if(lazy[node]) prop(node,s,e); //lazy값이 존재한다면 propagation 
    if(i>e || j<s) return 0; //탐색하는 범위에 포함되지 않는다면 0리턴 
    if(i<=s && e<=j) return tree[node]; //탐색하는 범위에 완전히 포함된다면 노드값 리턴 
    int m=s+e>>1; 
    return query(node*2,s,m,i,j)+query(node*2+1,m+1,e,i,j);
}

int main()
{
    int n, m, k; 
    int a, b, c;
    long d; 
    cin >> n >> m >> k; 
    for(int i=1; i<=n; i++) cin >> arr[i]; 
    init(1,1,n);
    while(m!=0 || k!=0){
        cin >> a >> b >> c; 
        if(a==1){
            cin >> d; 
            update(1,1,n,b,c,d);
            m--;
        }
        else{
            cout << query(1,1,n,b,c) <<"\n";
            k--;
        }
    }

    return 0;
}
