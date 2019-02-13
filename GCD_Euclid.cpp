#include <iostream>
using namespace std;

int gcd(int a,int b){
      if(b==0){
            return a;
      }else{
            gcd(b,a%b);
      }
}
int lcm(int a,int b){
      return (a*b)/gcd(a,b);
}
int main(){


      cout<<gcd(10,15)<<endl;
      cout<<gcd(102,3)<<endl;
      cout<<gcd(7,14)<<endl;
      cout<<lcm(10,15)<<endl;
      cout<<lcm(3,5)<<endl;


      return 0;
}
