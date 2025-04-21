#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        cout << v[i] << endl;
    }
 
    return 0;
}