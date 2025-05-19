#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; 

void merge(int s, int e){
    if(s==e) return; 
    int m=s+e>>1;
    merge(s, m); 
    merge(m+1, e); 
    vector<int> tmp;
    for(int i=s,j=m+1,k=0;k<=e-s;k++){
        if(j>e || (i<=m && arr[i]<arr[j])) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }
    for(int i=0; i<=e-s; i++) arr[s+i]=tmp[i];
    return; 
}

int main()
{
    int n, a; 
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> a; 
        arr.push_back(a);
    }
    merge(0, n-1);
    for(int i=0; i<arr.size(); i++) cout << arr[i] << "\n";
    return 0;
}