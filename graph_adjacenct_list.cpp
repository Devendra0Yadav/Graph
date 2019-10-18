//Adjacency list Implementation of generic Data
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public:
    Graph(){
        
    }
    void addEdge(T u,T v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto obj:adjList){
            cout<<obj.first<<"->";
            for(auto entry:obj.second){
                cout<<entry<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
	Graph<string> g;
	g.addEdge("putin","trump",false);
	g.addEdge("putin","modi",false);
	g.addEdge("putin","pope",false);
	g.addEdge("modi","trump");
	g.addEdge("prabhu","modi",false);
	g.addEdge("yogi","modi");
	g.addEdge("yogi","prabhu",false);
	g.print();
	return 0;
}