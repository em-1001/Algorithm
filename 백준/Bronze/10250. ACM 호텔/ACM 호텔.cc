#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, h, w, n; 
    int p, r;
    vector<int> v;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> h >> w >> n;
        if(!(n%h)){
            p = n / h;
            r = h;
            v.push_back(r*100+p);
        }
        else {
            p = n / h + 1;
            r = n % h;
            v.push_back(r*100+p);
        }
    }  

    for(int i=0; i<t; i++){
        cout << v[i] << endl;
    }
    return 0;
}