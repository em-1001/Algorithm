#include <iostream>
using namespace std;

int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << "\n";
    cout << stoi(A + B) - stoi(C);
    return 0;
}