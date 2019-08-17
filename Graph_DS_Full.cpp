#include <iostream>
#include <list>
#include <bits/stdc++.h>
#include <cstring>
#include <map>
using namespace std;
//Adj List Implementation for Integer Nodes
template <typename T>
class Graph{
      map<T,list<T>> adjList;
      int V;
      public :
      Graph(){

      }
      void addEdge(T u,T v,bool bidir=true){
                  adjList[u].push_back(v);
                  if(bidir){
                        adjList[v].push_back(u);
                  }
      }
      void printAdjList(){
                  for(auto node:adjList){
                        T key=node.first;
                        cout<<key<<"-> ";
                        for(T element : node.second){
                              cout<<element<<",";
                        }
                        cout<<endl;
                  }

      }
      void bfs(T src){ //Source Node
            queue<T> q;
            map<T,bool> visited;

            q.push(src);
            visited[src]=true;
            while(!q.empty()){
                  T node=q.front();
                  cout<<node<<" ";
                  q.pop();
                  for(T neighbour : adjList[node]){
                        if(!visited[neighbour]){
                              q.push(neighbour);
                              visited[neighbour]=true;
                        }
                  }
            }

      }
      void bfs2(T src){ //Source Node
            queue<T> q;
            map<T,int> dist;
            for(auto i:adjList){
                  dist[i.first]=INT_MAX;
            }
            q.push(src);
            dist[src]=0;
            while(!q.empty()){
                  T node=q.front();
                  q.pop();
                  for(T neighbour : adjList[node]){
                        if(dist[neighbour]==INT_MAX){
                              q.push(neighbour);
                              dist[neighbour]=dist[node]+1;
                        }
                  }
            }
            for(auto i:adjList){
                  T node=i.first;
                  cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
            }

      }
      void dfs(T src){
            ///USES STACK ALSO
            ///Here we are using recursion
            map<T,bool> visited;
            dfsHelper(src,visited);
      }
      void dfsHelper(T node,map<T,bool> &visited){  ///Taking address only..
            visited[node]=true;
            cout<<node<<" ";
            for(T neighbour : adjList[node]){
                  if(!visited[neighbour]){
                        dfsHelper(neighbour,visited);
                  }
            }
      }
      void dfs2(T src){
            map<T,bool> visited;

            int component=1;
            int nodes=0;
            dfsHelper(src,visited);
            cout<<endl;

            for(auto i:adjList){
                  T city=i.first;
                  if(!visited[city]){
                        dfsHelper(city,visited);
                        component++;

                  }
            }
            cout<<"Graph has total components ==> "<<component<<endl;
      }
      bool iscyclicBFS(T src){
            map<T,bool> visited;
            map<T,int> parent;
            queue<T> q;

            q.push(src);
            visited[src]=true;
            parent[src]=src;

            while(!q.empty()){
                  T node=q.front();
                  q.pop();

                  for(T neighbour : adjList[node]){
                        if(visited[neighbour]==true && parent[node]=neighbour){
                              return true;
                        }else if(!visited[neighbour]){
                              visited[neighbour]=true;
                              parent[neighbour]=node;
                              q.push(neighbour);
                        }
                  }
            }

      }
      bool isBipartite(int s){

            queue<int> q;
            q.push(s);

            int *colors = new int[V];
            for(int i=0;i<V;i++){
                colors[i] = -1; //Not Visited
            }

            colors[s] = 0;
            bool ans = true;

            while(!q.empty() && ans){

                int u = q.front();
                q.pop();

                for(auto v:adjList[u]){

                    if(colors[v]==-1){
                        colors[v] = 1 - colors[u];
                        q.push(v);
                    }
                    else if(colors[v]==colors[u]){
                        return false;
                    }

                }

            }

        return true;
        }

};
int main(){
      Graph<int> g;
      g.addEdge(0,1);
      g.addEdge(1,4);
      g.addEdge(2,4);
      g.addEdge(0,4);
      g.addEdge(2,3);
      g.addEdge(4,3);
      g.addEdge(5,3);
      g.addEdge(6,7);
      g.printAdjList();
      cout<<"\n"<<endl;
      g.bfs(0);
      cout<<"\n"<<endl;
      g.bfs2(0);
      ///In Output keys are sorted due to MAP..
            cout<<endl;
            g.dfs(0);
            cout<<endl;
            cout<<endl;
            g.dfs2(0);
            cout<<endl;
            cout<<"Bipartite 0 or 1 => ";
            cout<<g.isBipartite(0)<<endl;
      return 0;
}
