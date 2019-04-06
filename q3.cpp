#include<bits/stdc++.h>
#include<cstdio>
#include<iterator>
using namespace std;
long int gcd(long int a, long int b){
  long int r;
  while(b>0){
    r= a %b;
    a=b;
    b=r;
  }
  return a;
}
int main(){
  long int t;
  cin >> t;
  for(int o = 0; o < t; o++){
    long int n, l;
    cin >> n >> l;
    vector<long int> key(l,0);
    vector<long int> text;
    for(long int k = 0;k<l;k++){
      cin >> key[k];
    }
    long int last = gcd(key[0],key[1]);
    set<long int> s;
    s.insert(key[0]/last);
    text.push_back(key[0]/last);
    for(int i=1;i<l;i++){
      s.insert(last);
      text.push_back(last);
      last = key[i]/last;
    }
    s.insert(last);
    text.push_back(last);
    vector<long int> primes;
    set<long int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
{
    primes.push_back(*it); // Note the "*" here
}
    sort(primes.begin(),primes.end());
   // cout << primes.size()<<endl;
    if(primes.size()<26){
        /// Do something here;
    }
    char x = 'A';
    cout << "Case #"<<o+1 << ": ";
    for(long int i=0;i<text.size();i++){
      long int p = text[i];
      int index = 0;
      for(;index<primes.size();index++){
        if(primes[index] == p)
          break;
      }
      printf("%c",x+index);
    }
    cout << endl;

  }
}
