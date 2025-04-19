#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(int a, int b){
    return a > b;
}


int main()
{
    vector<int> e(3);
    cin >> e[0] >> e[1] >> e[2];
    while(e[0] || e[1] || e[2]){
        sort(e.begin(), e.end(), compare);
        if(pow(e[0],2) == pow(e[1],2) + pow(e[2],2)) cout << "right" << endl;
        else cout << "wrong" << endl;
        cin >> e[0] >> e[1] >> e[2];
    }
        
    return 0;
}