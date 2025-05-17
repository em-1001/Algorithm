#include <iostream>
#include <string.h>
#include <cmath>

using namespace std; 

//arr은 입력받을 배열, tree는 구간합을 처리할 배열로 사이즈는 4*n이면 충분하다.
long tree[4000001], arr[1000001]; 

//node는 트리에서의 현재 노드의 인덱스. s,e는 arr에서 노드가 담당하는 부분의 좌측, 우측 끝 인덱스. 
long init(int node, int s, int e){
    if(s==e) return tree[node]=arr[s]; //leaf node 
    int m=s+e>>1;
    return tree[node]=init(node*2,s,m)+init(node*2+1,m+1,e);
}

long query(int node, int s, int e, int i, int j){
    if(s>j || e<i) return 0; //탐색 범위를 벗어나면 0리턴 
    if(s>=i && e<=j) return tree[node]; //탐색 범위에 포함되면 해당 노드의 값 리턴
    int m=s+e>>1; 
    return query(node*2,s,m,i,j)+query(node*2+1,m+1,e,i,j);
}

long update(int node, int s, int e, int i, long v){
    if(i<s || i>e) return tree[node]; //탐색하는 범위에 포함되지 않는다면, 해당 노드의 값 리턴
    if(s==e) return tree[node]=v; //리프 노드라면 update 후 리턴
    int m=s+e>>1; 
    return tree[node]=update(node*2,s,m,i,v)+update(node*2+1,m+1,e,i,v); 
}


int main()
{
    int cnt=0;
    int n, m, k; 
    int a, b;
    long c;
    memset(arr, 0, sizeof(arr));
    cin >> n >> m >> k; 
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    while(n=n>>1) cnt++;
    n=pow(2, cnt+1);
    init(1,1,n);
    while(m || k){
        cin >> a >> b >> c; 
        if(a==1){
            m--; 
            update(1,1,n,b,c);
        }
        else if(a==2){
            k--; 
            cout << query(1,1,n,b,c) << "\n";
        }
    }

    return 0;
}
