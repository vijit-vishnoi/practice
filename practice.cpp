#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int count=0;
    for(int i=0;i<s.size();i++){
        count+=(s[i]-'0')*pow(2,i);
    }
    cout<<count;
    
    cout<<"hello worlf hi ";
}