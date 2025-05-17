#include <iostream>
#include <cmath>

using namespace std; 

int main()
{
    int n, a, b, dist, k=0, cnt=0; 
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> a >> b; 
        dist=b-a;
        int lim=sqrt(dist);
        for(int j=0; j<=lim; j++){
            if(dist-(k+1)*2>0){
                dist-=(k+1)*2;
                cnt+=2;
                k++;
            }
            else if(dist-(k+1)*2==0){
                cnt+=2; 
                break; 
            }
            else{
                if(dist-(k+1)>0){
                    cnt+=2; 
                    break; 
                }
                else{
                    cnt+=1;
                    break;
                }
            }
        }
        cout << cnt << "\n";
        cnt=0;
        k=0;
    }

    return 0;
}