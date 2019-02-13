#include <iostream>
using namespace std;

long long gcd(long long a,long long b){
    //Base case
    if(b==0){
        return a;
    }
    //Recursive Case
    return gcd(b,a%b);
}

long long x,y,GCD;
void extendedEuclidMethod(long long a,long long b){
    //Base Case
    if(b==0){
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    //Recursive Case
    extendedEuclidMethod(b,a%b);
    long long cX = y;
    long long cY = x -(a/b)*y;

    x =  cX;
    y = cY;
}

long long inverseModulu(long long a,long long m){

      extendedEuclidMethod(a,m);
      return (x%m+m)%m;
}



int main() {

    long long int k;
    cin>>k;
    long long int num[k];
    long long int rem[k];
    long long int product=1;
      for(long long i=0;i<k;i++){
            cin>>num[i];
            product=product*num[i];
      }
      for(long long int i=0;i<k;i++){
            cin>>rem[i];
      }
      long long int x=0;
      for(long long int i=0;i<k;i++){
            long long int pp=product/num[i];
            x=(x+((rem[i]*(pp)*inverseModulu((pp),num[i]))));
      }
      cout<<x%product<<endl;



    return 0;
}


