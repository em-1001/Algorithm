#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;


int main()
{
    int idx, n, max=-1;
    for(int i=0; i<9; i++){
        cin >> n;
        if(n > max){
            max = n;
            idx = i+1;
        }
    }
    cout << max << endl;
    cout << idx;
    return 0;
}