#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll p2v(pll p1, pll p2){
    return {p2.X - p1.X, p2.Y - p1.Y};
}

int ccw(pll v1, pll v2){
    
    ll cross = v1.X * v2.Y - v2.X * v1.Y;
    
    if(cross > 0) return 1;
    if(cross < 0) return -1;
    return 0;
}

bool cross(pll a, pll b, pll c, pll d){
    int cc1 = ccw(p2v(a, b), p2v(b, d)) * ccw(p2v(a, b), p2v(b, c));
    int cc2 = ccw(p2v(c, d), p2v(d, a)) * ccw(p2v(c, d), p2v(d, b));
    
    if(!cc1 && !cc2){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        if(a > c){
            swap(a, c);
            swap(b, d);
        }
        return c <= b;
    }
    return cc1 <= 0 && cc2 <= 0;
}
    
bool on_line(pll a, pll b, pll p){
    if(a > b) swap(a, b);
    return !ccw(p2v(a, b), p2v(b, p)) && a<=p && p<=b;
}

int bin_search(vector<pll> P, int L, int R, pll point){
    if(L+1 == R) return L;
    int M = (L + R) / 2;
    if(ccw(p2v(P[0], P[M]), p2v(P[0], point)) > 0){
        return bin_search(P, M, R, point);
    } 
    else{
        return bin_search(P, L, M, point);
    }
}

bool Point_In_Convex(vector<pll>& P, pll S){
    if(ccw(p2v(P[0], P[1]), p2v(P[0], S))<0 
    || ccw(p2v(P[0], P[P.size()-1]), p2v(P[0], S))>0){ 
        return 0;
    } 
    //int idx = bin_search(P, 1, P.size()-1, S);
    int L=1, R=P.size()-1;
    while(L+1 != R){
        int M = (L + R) / 2;
        if(ccw(p2v(P[0], P[M]), p2v(P[0], S)) > 0) L = M;
        else R = M;
    }
    if(ccw(p2v(P[L], S), p2v(S, P[L+1]))>0) return 0;
    else return 1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int cnt = 0;
    int n, m, k;
    ll x, y;
    vector<pll> A, B;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        A.push_back({x, y});
    }
    for(int i=0; i<m; i++){
        cin >> x >> y;
        B.push_back({x, y});
    }
    for(int i=0; i<k; i++){
        cin >> x >> y;
        if(!Point_In_Convex(A, {x, y}) || Point_In_Convex(B, {x, y})) cnt++;
    }
    
    if(!cnt) cout << "YES";
    else cout << cnt;

    return 0;
}







