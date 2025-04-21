#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main()
{
    int n, k;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        cout << v[i] << "\n";
    }
 
    return 0;
}