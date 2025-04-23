#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n; 
    char a;
    long long hash=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        hash += (int(a) - 96) * pow(31, i); 
    }
    hash = hash % 1234567891;
   
    cout << int(hash);

    return 0;
}