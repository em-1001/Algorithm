#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>

using namespace std; 

queue<string> num;
queue<string> pun; 

void tokenize(const string& expr){
    vector<string> tokens;
    string number="";
    
    for(char ch : expr){
        if(isdigit(ch)){
            number+=ch;
        }
        else{
            if(!number.empty()){
                num.push(number);
                number="";
            }
        }
        if(ch==' ') continue;
        if(ispunct(ch)){
            pun.push(string(1, ch)); 
        }
    }
    if(!number.empty()){
        num.push(number);
    }
    return;
}

int main()
{
    bool mflag=0; 
    int ans=0, tmp=0;
    string s; 
    cin >> s; 
    
    tokenize(s);
    
    ans+=stoi(num.front());
    num.pop();
    
    while(!num.empty()){
        if(pun.front()=="+"){
            if(mflag){
                tmp+=stoi(num.front());
                num.pop();
                if(num.empty()){
                    ans-=tmp;
                    break;
                }
            }
            else{
                ans+=stoi(num.front());
                num.pop();
            }
        }
        else if(pun.front()=="-"){
            if(mflag){
                ans-=tmp;
                tmp=stoi(num.front());
                num.pop();
                if(num.empty()){
                    ans-=tmp;
                    break;
                }
            }
            else{
                mflag=1;
                tmp=stoi(num.front());
                num.pop();
                if(num.empty()){
                    ans-=tmp;
                    break;
                }
            }
        }
        pun.pop();
    }
    
    cout << ans;

    return 0;
}