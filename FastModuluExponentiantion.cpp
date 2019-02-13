#include <iostream>
using namespace std;

#define ll long long
ll fastMod(ll a,ll b,ll m){
      ll res=1;

      while(b>0){

            if(b&1){ ///ExtractLastBit
                  res=(res*a)%m;

            }
            a=(a*a)%m; ///1.2.4.8
            b=b>>1;

      }
      return res;
}
int main(){
      ll a=5;ll b=3;ll m=100;
      cout<<fastMod(a,b,m)<<endl;
      return 0;
}
