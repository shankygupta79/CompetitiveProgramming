#include <iostream>
#include <set>
#include <math.h>
using namespace std;
set<int> printDivisors(int n){
    set<int> Set;
    Set.insert(1);
    for (int i=2; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i){
                Set.insert(i);
            }
            else{
                Set.insert(n/i);
                Set.insert(i);
            }
        }
    }
    return Set;
}

int calculateMex(set<int> Set){

      int Mex=0;
      while(Set.find(Mex)!=Set.end()){
            Mex++;
      }
      //Set is always sorted
      return Mex;

}
int calculateGrundy(int n){
      if(n==1){

            return(0);
      }
      set<int> Set=printDivisors(n);
      set<int> Set2;
      for (auto it=Set.begin(); it != Set.end(); ++it){
            Set2.insert(calculateGrundy(*it));
      }
      return (calculateMex(Set2));
}
main(){
      cout<<calculateGrundy(100002);
      int t;
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            int m;
            cin>>m;
            int x=calculateGrundy(m);
            if(n&1){
                  if(x){
                        cout<<1<<endl;

                  }else{
                        cout<<2<<endl;
                  }
            }else{
                  cout<<2<<endl;
            }
      }
      return 0;
}
