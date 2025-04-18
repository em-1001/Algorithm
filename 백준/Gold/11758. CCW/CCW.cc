#include <iostream>
#include <utility>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
    ll v1_x = b.X - a.X;
    ll v1_y = b.Y - a.Y;
    ll v2_x = c.X - b.X;
    ll v2_y = c.Y - b.Y;
    
    ll cross = v1_x * v2_y - v1_y * v2_x;
    
    if(cross > 0) return 1;
    if(cross < 0) return -1;
    return 0; 
}

int main()
{
    ll x, y;
    pll point[3];
    int ret;
    
    for(int i=0; i<3; i++){
        cin >> x >> y;
        point[i] = {x, y};
    }
    
    ret = ccw(point[0], point[1], point[2]);
    
    cout << ret;
    
    return 0;
}