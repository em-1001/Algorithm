#include <iostream>
#include <string>

using namespace std; 

int img[64][64];

string DnQ(int a, int b, int c, int d){
    int sum=0;
    for(int i=a; i<b; i++){
        for(int j=c; j<d; j++){
            sum+=img[i][j];
        }
    }
    if(sum==0) return to_string(0);
    else if(sum==(b-a)*(d-c)) return to_string(1); 
    string ret = "(";
    ret+=DnQ(a,a+b>>1,c,c+d>>1);
    ret+=DnQ(a,a+b>>1,c+d>>1,d);
    ret+=DnQ(a+b>>1,b,c,c+d>>1);
    ret+=DnQ(a+b>>1,b,c+d>>1,d);
    ret+=")";
    return ret;
}

int main()
{
    int n; 
    string str; 
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> str; 
        for(int j=0; j<n; j++){
            img[i][j]=str[j]-'0'; 
        }
    }

    cout << DnQ(0,n,0,n);
    
    return 0;
}