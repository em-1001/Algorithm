#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n; 
    char a;
    long long hash=0, r=1;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        hash += ((long(a)-96)*r)%1234567891;
        r = (r*31)%1234567891; 
    }
   
    cout << hash%1234567891;

    return 0;
}