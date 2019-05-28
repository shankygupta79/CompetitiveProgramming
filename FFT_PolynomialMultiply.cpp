#include <bits/stdc++.h>

using namespace std;
 #define PI 3.14159265358979323846

 vector<complex<double>> fft(vector<complex<double>> a){
      int n=(int)a.size();
      if(n<=1){
            return a;
      }
      vector<complex<double>> a0(n/2),a1(n/2);
      for(int i=0;i<n/2;i++){
            a0[i]=a[2*i];
            a1[i]=a[2*i +1];

      }
      a0=fft(a0);
      a1=fft(a1);
      double ang=2*PI/n;
      complex<double> w(1),wn(cos(ang),sin(ang));
      for(int i=0;i<n/2;i++){
            a[i]=a0[i]+w*a1[i];
            a[i+n/2]=a0[i]-w*a1[i];
            w*=wn;
      }
      return a;
 }
 vector<complex<double>> inv_fft(vector<complex<double>>y){
      int n=y.size();
      if(n<=1){
            return y;
      }
      vector<complex<double>> y0(n/2),y1(n/2);
      for(int i=0;i<n/2;i++){
            y0[i]=y[2*i];
            y1[i]=y[2*i+1];
      }
      y0=inv_fft(y0);
      y1=inv_fft(y1);
      double ang=2*PI/n*-1;
      complex<double> w(1),wn(cos(ang),sin(ang));
      for(int i=0;i<n/2;i++){
            y[i]=y0[i]+w*y1[i];
            y[i+n/2]=y0[i]-w*y1[i];
            y[i]/=2;
            y[i+n/2]/=2;
            w*=wn;
      }
      return y;
 }
void multiply(vector<int> a,vector<int> b){
      vector<complex<double>> fa (a.begin(), a.end()), fb (b.begin(), b.end());
      int n=1;
      while(n<max(a.size(),b.size())){
            n<<=1;
      }
      fa.resize(n);
      fb.resize(n);
      fa=fft(fa);
      fb=fft(fb);
      for(int i=0;i<n;i++){
            fa[i]=fa[i]*fb[i];
      }
      fa=inv_fft(fa);
      vector<int> res(n);
      for(int i=0;i<n;i++){
                  if(fa[i].real()<0){
                        res[i]=int(fa[i].real()-0.5);
                  }else{
                         res[i]=int(fa[i].real()+0.5);
                  }

            cout<<res[i]<<" ";
      }

      return;
}
 int main(){



            vector<int> a{1,1,1,0}; // 1+x +x^2
            vector<int> b{1,3,0,0}; // 1+3x
            multiply(a,b); //1+4x+4x^2+3x^3
            cout<<endl;
            vector<int> c{9, -10, 7, 6,0,0}; // 9+-10x +7x^2+6x^3
            vector<int> d{-5, 4, 0, -2,0,0}; // -5+4x-2x^3
            multiply(c,d); // -45 + 86x - 75x^2 - 20x^3 + 44x^4 - 14x^5 - 12x^6

 }


