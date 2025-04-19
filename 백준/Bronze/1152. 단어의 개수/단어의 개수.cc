#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

typedef pair<int, string> p; 

string trim(const string& s){
    auto start = find_if_not(s.begin(), s.end(), ::isspace);
    auto end = find_if_not(s.rbegin(), s.rend(), ::isspace).base();
    
    if(start >= end) return "";
    return string(start, end);
}


int main()
{
    string str; 
    size_t pos;
    int cnt=0;
    getline(cin, str);
    str = trim(str);
    pos = str.find(" ");
    while(pos != string::npos){
        cnt++;
        pos = str.find(" ", pos+1);
    }
    cnt += (str.size()==0) ? 0 : 1;
    cout << cnt;
    return 0;
}