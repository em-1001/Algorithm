#include <iostream>


using namespace std;

int main()
{
    int n, m;
    int a, b, c;
    cin >> n >> m;
    int* list = new int[n];
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        for(int j=a; j<=b; j++){
            list[j-1] = c;
        }
    }
    for(int i=0; i<n; i++){
        cout << list[i] << " ";
    }
    delete[] list;
    
}