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

bool cross(pll a, pll b, pll c, pll d){
    int ct1 = ccw(a, b, d) * ccw(a, b, c);
    int ct2 = ccw(c, d, a) * ccw(c, d, b);
    
    if(!ct1 && !ct2){
        if(min(a.X, b.X) > max(c.X, d.X)
        || max(a.X, b.X) < min(c.X, d.X))
        return false;
        if(min(a.Y, b.Y) > max(c.Y, d.Y)
        || max(a.Y, b.Y) < min(c.Y, d.Y))
        return false;
    }
    
    return ct1<=0 && ct2<=0;
}

int main()
{
    ll x1, y1, x2, y2;
    pll point[4];
    int ret;
    
    for(int i=0; i<2; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        point[2*i] = {x1, y1};
        point[2*i+1] = {x2, y2};
    }
    
    ret = cross(point[0], point[1], point[2], point[3]);
    
    cout << ret;
    
    return 0;
}
