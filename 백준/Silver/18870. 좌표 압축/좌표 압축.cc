#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

int main()
{
    int n, c;
    vector<pair<int, int>> cord;
    
    cin >> n; 
    
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
    cord[0].second = 0;
    for (size_t i=1; i<cord.size(); i++){   
        if (cord[i].second != pv) cnt++;
        pv = cord[i].second;
        cord[i].second = cnt;
    }
    
    sort(cord.begin(), cord.end(), 
        [](const auto& a, const auto& b){
            return a.first < b.first;
        }
    );
    
    for (const auto& [index, value] : cord){
        cout << value << " ";
    }
    
    return 0;
}
