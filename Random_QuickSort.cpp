#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void shuffle(int *a,int s,int e){
      srand(time(NULL));

      int i,j,temp;
      for(int i=e;i>=0;i--){
            ///Generate a random index
            j=rand()%(i+1);
            swap(a[i],a[j]);
      }
}

int partition(int *a,int s,int e){
      int i=s-1;
      int j=s;
      int pivot=a[e];
      for(;j<e;j++){
            if(a[j]<=pivot){
                  i++;
                  swap(a[i],a[j]);
            }
      }
      ///Bring the pivot element to its sorted position
      swap(a[i+1],a[e]);
      return i+1;
}

void QuickSort(int *a,int s,int e){
      if(s>=e){
            return;
      }
      int p=partition(a,s,e);
      QuickSort(a,s,p-1);
      QuickSort(a,p+1,e);


}

int main(){

      int arr[]={2,1,5,6,7,5,8};
      int n=sizeof(arr)/sizeof(int);
      shuffle(arr,0,n-1);
      QuickSort(arr,0,n-1);
      for(int i=0;i<n;i++){
            cout<<arr[i]<<"  ";
      }
      return 0;
}
