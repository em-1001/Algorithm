#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, string> p; 

int main()
{
    int t, r;
    string str; 
    vector<p> vec;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> r >> str;
        vec.push_back({r, str});
    }
    
    for(int i=0; i<t; i++){
        for(int j=0; j<vec[i].second.size(); j++){
            for(int k=0; k<vec[i].first; k++){
                cout << vec[i].second[j] << "";
            }
        }
        cout << "\n";
    }
    return 0;
}