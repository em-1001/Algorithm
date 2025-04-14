#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
 
    int tc;
    int x1, y1, r1, x2, y2, r2;
    double distance;

    cin >> tc;

    int *noc = new int[tc];

    for (int i=0; i<tc; i++){
        cin >> x1;
        cin >> y1;
        cin >> r1;
        cin >> x2;
        cin >> y2;
        cin >> r2;

        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (distance == 0)
        {
            if (r1 == r2) noc[i] = -1;
            else noc[i] = 0;
        }
        else if (r1 <= distance && r2 <= distance){
            if (r1 + r2 > distance) noc[i] = 2;
            else if (r1 + r2 == distance) noc[i] = 1;
            else noc[i] = 0;
        }
        else {
            if (abs(r1 - r2) < distance) noc[i] = 2;
            else if (abs(r1 - r2) == distance) noc[i] = 1;
            else noc[i] = 0;
        }
    }

    for (int i=0; i<tc; i++){
        cout << noc[i] << endl;
    }


    return 0;

}