//Adjacency list representation of directed or undirected of generic data types;

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
    public:
    T vertex;
    int cost;
    Node(){
        cost = 0;
    }
    Node(T vertex,int cost){
        this->vertex = vertex;
        this->cost = cost;
    }
    
};

template<typename T>
class Graph{
    public:
    map<T,list<Node<T>>> adjList;
    
    void addEdge(T u,int c,T v,bool bidir=true){
        Node<T> n1(u,c);
        Node<T> n2(v,c);
        adjList[n1.vertex].push_back(n2);
        if(bidir){
            adjList[n2.vertex].push_back(n1);
        }
    }
    
    void print()
    {
        for(auto obj:adjList){
            for(auto j:obj.second){
                Node<T> k = j;
                cout<<"Cost from node "<<obj.first <<" to node "<<k.vertex<<" is "<<k.cost<<endl;
            }
        }
        cout<<endl<<endl;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0,2,1);
    g.addEdge(0,3,2);
    g.addEdge(1,9,3);
    g.addEdge(2,7,4);
    g.print();
    Graph<char> g2;
    g2.addEdge('A',2,'B');
    g2.addEdge('A',3,'C');
    g2.addEdge('B',9,'D');
    g2.addEdge('C',7,'E');
    g2.print();
	return 0;
}