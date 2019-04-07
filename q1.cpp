#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    cin >> n;
    for(int o=0;o<n;o++){
        long int s;
        cin >> s;
        cout << "Case #"<<o+1<<": ";
        vector<int> num, a, b;
        int fours=0;
        while(s>0){
          int r = s%10;
          if(r == 4){
            fours ++;
          }
          num.push_back(r);
          a.push_back(r);
          b.push_back(0);
          s=s/10;
        }
        if(fours > 0){
        for(int i=0;i<num.size();i++){
          if(a[i]==4){
            a[i]=3;
            b[i]=1;
          }
          else
          b[i]=0;
        }
      }
      else{
        int k = a.size();
        if(k == 1){
        if(a[0]==5){
          a[0]=3;
          b[0]=2;
        }
        else{
          a[0]--;
          b[0]=1;
        }
      }
        else{
          for(int i=0;i<k;i++){
            if(a[i]>0){
              if(a[i]==5){
                a[i]=3;
                b[i]=2;
              }
              else{
                a[i]--;
                b[i]=1;
              }
              break;
            }
          }
        }
      }
      long int num1=0,num2=0;
      for(int i=a.size()-1;i>=0;i--){
        num1*=10;
        num2*=10;
        num1+=a[i];
        num2+=b[i];
      }
      if(num1 == 0){
        num1 = (num2+1)/2;
        num2/=2;
      }
      if(num2 == 0){
        num2 = (num1+1)/2;
        num1/=2;
      }
      cout<< num1 << " "<<num2<<endl;
    }
}
