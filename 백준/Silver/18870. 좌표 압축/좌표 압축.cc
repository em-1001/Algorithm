#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int rk = 0;

int main()
{
    int n, c;
    vector<pair<int, int>> cord;
    
    cin >> n; 
    
    int* list = new int[n];
    
    for (int i=0; i<n; i++){
        cin >> c;
        cord.push_back({i, c});
    }
    
    sort(cord.begin(), cord.end(), 
        [](const auto& a, const auto& b){
            return a.second < b.second;
        }
    );
    
    int pv = cord[0].second;
    list[0] = rk;
    for (size_t i=1; i<cord.size(); i++){   
        if (cord[i].second != pv) rk++;
        pv = cord[i].second;
        list[cord[i].first] = rk;
    }
    
    for (int i=0; i<n; i++){
        cout << list[i] << " ";
    }
    
    delete[] list;
    
    return 0;
}
