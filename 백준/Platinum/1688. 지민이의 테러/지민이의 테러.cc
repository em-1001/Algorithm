#include <iostream>
#include <utility>
#include <vector>
#include <limits.h>
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

bool on_line(pll a, pll b, pll p){
    if(a>b) swap(a, b);
    return !ccw(a, b, p) && a<=p && p<=b; 
}

bool Point_In_Concave(vector<pll> C, pll P){
    int cnt = 0;
    for(int i=0; i<C.size();i++){
        if(on_line(C[i], C[(i+1)%C.size()], P)) return true;
        if(cross(C[i], C[(i+1)%C.size()], P, {INT_MAX, P.Y+1})) cnt++;
    }
    return cnt%2;
}

int main()
{
    int n;
    pll p;
    vector<pll> C;
    bool cover[3];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p.X >> p.Y;
        C.push_back(p);
    }
    for(int i=0; i<3; i++){
        cin >> p.X >> p.Y;
        cover[i] = Point_In_Concave(C, p);
    }
    for(int i=0; i<3; i++){
        cout << cover[i] << endl;
    }
    
    return 0;
}
