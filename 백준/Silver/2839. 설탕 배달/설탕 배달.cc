#include <iostream>
#include <vector>

using namespace std; 

vector<int> dp;

int main()
{
    int n; 
    cin >> n; 
    if(n<5){
        if(n%3!=0){
            cout << -1; 
            return 0;
        }
        else{
            cout << 1;
            return 0; 
        }
    }
    
    for(int i=0; i<=n/5; i++){
        if((n-i*5)%3==0) dp.push_back(i+(n-i*5)/3); 
    }
    
    if(dp.size()==0){
        cout << -1; 
        return 0; 
    }
    
    cout << dp.back(); 

    return 0;
}