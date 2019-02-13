#include <iostream>
using namespace std;

int a[10000];
int BIT[10000]={0};


void update(int i,int inc,int N){
      while(i<=N){

            BIT[i]=BIT[i]+inc;
            i=i+(i&(-i));
      }
}

int query(int i){
      int ans=0;
      while(i>0){

            ans=ans+BIT[i];
            i=i-(i&(-i));
      }
      return ans;
}
int main(){
      int n,q;
      cin>>n;
      for(int i=1;i<=n;i++){
            cin>>a[i];
            update(i,a[i],n);
      }

      cin>>q;
      while(q--){
            int l,r;
            cin>>l>>r;
            cout<<query(r)-query(l-1)<<endl;
      }
}
