#include<bits/stdc++.h>
using namespace std;
int main(){
  long int t;
  cin  >> t;
  for(int o=0;o<t;o++){
    long int n;
    cin >> n;
    string s,ans="";
    cin >> s;
    for(int i=0;i<s.length();i++){
      if(s[i]=='E'){
        ans += "S";
      }
      else
        ans += "E";
    }
    cout << "Case #"<< o+1 << ": "<<ans<<endl;
  }
}
