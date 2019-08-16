#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<string,int> m;
    m.insert(make_pair("Apple",120));
    m["Mango"]=100;
    //Search
    if(m.count("Apple")==1){
        cout<<"Price of the apple is "<<m["Apple"]<<endl;
    }
    m["Guava"]=m["Apple"]+90;
    if(m.count("Guava")==0){
        cout<<"Guave doesn't exists"<<endl;
    }else{
        cout<<"Price of the apple is "<<m["Guava"]<<endl;
    }
    /*So the replace unordered_map with map to get sorted balanced BST and its
    complexity will be logn forn adding , removing.*/
    cout<<endl<<"Display"<<endl;
      for(auto i=m.begin();i!=m.end();++i){
            cout<< i->first  << "  ::  "<<i->second<<endl;
      }
}
