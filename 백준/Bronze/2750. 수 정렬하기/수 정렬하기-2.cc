#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int* heap, int a, int b){
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}

void build_heap(int* heap, int cur_idx){
    while(cur_idx>1){
        int parent_idx = cur_idx/2;
        if(heap[cur_idx] > heap[parent_idx]){
            swap(heap, parent_idx, cur_idx);
            cur_idx = parent_idx;
        }
        else break;
    }
}

void heapify(int* heap, int cur_idx, int n){
    int cur=cur_idx, left=cur_idx*2, right=cur_idx*2+1;
    if((left<=n)&&(heap[left]>heap[cur])) cur=left;
    if((right<=n)&&(heap[right]>heap[cur])) cur=right;
    
    if(cur_idx!=cur){
        swap(heap, cur, cur_idx);
        heapify(heap, cur, n);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n;
    int* heap = new int[n+1];
    for(int i=1; i<=n; i++){
        cin >> k;
        heap[i] = k;
        build_heap(heap, i);
    }
    for(int i=n; i>=2; i--){
        swap(heap, 1, i);
        heapify(heap, 1, i-1);
    }
    for(int i=1; i<=n; i++){
        cout << heap[i] << endl;
    }
    
    delete[] heap;
    return 0;
}
