#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int cnt=0, max_cnt=-1;
vector<int> graph[10001]; 
int result[10001];
bool visited[10001];

void dfs(int x){
    visited[x] = true;
    cnt++;
    for (int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if (!visited[y]) dfs(y);
    }
}

int main(){
    
    int node_num, link_num, A, B;

    cin >> node_num;
    cin >> link_num;


    for (int i=0; i<link_num; i++){
        cin >> A;
        cin >> B;
        graph[B].push_back(A);
    }

    for (int i=1; i<node_num+1; i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        result[i] = cnt;
        max_cnt = max(max_cnt, cnt);
        cnt = 0;
    }
    
    for (int i=1; i<node_num+1; i++){
        if (result[i] == max_cnt) cout << i << " ";
    }
    

    return 0;
}