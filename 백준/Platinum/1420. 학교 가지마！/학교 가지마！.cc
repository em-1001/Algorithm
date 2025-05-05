#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <string.h>

using namespace std;

int inf=INT_MAX;
int n, m;
// R D L U
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char map[101][101];

struct Edge{
    int v, w, cap, flow;
    Edge* rev;
    
    Edge(int _v, int _w, int _c) : v(_v), w(_w), cap(_c), flow(0) {}
    
    int Residual() const{
        return cap-flow;
    }
    
    void AddFlow(int amount){
        flow+=amount;
        rev->flow-=amount;
    }
};

vector<Edge*> line[25000];

void AddLine(int source, int sink, int capacity){
    Edge* E=new Edge(source, sink, capacity);
    Edge* revE=new Edge(sink, source, 0);
    E->rev=revE;
    revE->rev=E;
    line[source].push_back(E);
    line[sink].push_back(revE);
}

int Max_Flow(int K, int H){
    int min_cut=0;
    while(1){
        vector<Edge*> pre(25000, nullptr);
        queue<int> q;
        q.push(K);
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0; i<line[cur].size(); i++){
                int next=line[cur][i]->w; 
                // if [in] -> [out] flow is 1(residual==0), it means visited
                if(line[cur][i]->Residual()>0 && pre[next]==nullptr){
                    q.push(next);
                    pre[next]=line[cur][i];
                }
            }
        }
        if(pre[H]==nullptr) break; 
        
        for(int i=H; i!=K; i=pre[i]->v){
            //H: [in] of sink, K+1: [in] of vertex before source
            if(i!=H && i!=K+1) pre[i]->AddFlow(1); 
        }
        min_cut++; 
    }
    return min_cut;
}

int main()
{
    int K=-1, H=-1;
    cin >> n >> m; 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            AddLine((i*m+j)*2, (i*m+j)*2+1, 1); //vertex split [in] -> [out]
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j]; 
            if(map[i][j]=='K') K=(i*m+j)*2+1; //start: [out] of source
            if(map[i][j]=='H') H=(i*m+j)*2; //end: [in] of sink   
        }
    }
    
    if(K==-1 || H==-1){
        cout << -1;
        return 0;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]=='#') continue; 
            if(map[i][j]=='K'){
                for(int d=0; d<4; d++){
                    if(map[i+dy[d]][j+dx[d]]=='H'){
                        cout << -1;
                        return 0; 
                    }
                }
            }
            // doubly linked
            if(j+1<m && map[i][j+1]!='#'){
                AddLine((i*m+j)*2+1, (i*m+j+1)*2, inf); //v [out] -> w [in] 
                AddLine((i*m+j+1)*2+1, (i*m+j)*2, inf); //w [out] -> v [in]
            }
            if(i+1<n && map[i+1][j]!='#'){
                AddLine((i*m+j)*2+1, ((i+1)*m+j)*2, inf); //v [out] -> w [in]
                AddLine(((i+1)*m+j)*2+1, (i*m+j)*2, inf); //w [out] -> v [in]
            }
        }
    }
    
    int min_cut = Max_Flow(K, H);
    
    cout << min_cut;

    return 0;
}
