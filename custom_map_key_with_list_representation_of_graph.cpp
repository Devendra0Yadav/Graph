#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int vertex;
    int cost;
    int costFrom;
    Node(){
        cost=0;
        costFrom=0;
    }
    Node(int u,int v,int c){
        vertex=u;
        cost =c;
        costFrom=v;
    }
};
bool operator<(const Node &n1,const Node &n2 ){
            return n1.vertex < n2.vertex;
        }
class Graph{
    public:
    int totalCost=0;
    map<Node,list<Node> > m;
    void addEdge(int u,int v,int c,bool bidir=true){
        Node n1(u,v,c);
        Node n2(v,u,c);
        m[n1].push_back(n2);
        if(bidir){
            m[n2].push_back(n1);
        }
        totalCost+=c;
    }
    void print(){
        for(auto obj:m){
            cout<<"cost from "<<obj.first.vertex<<"->";
            for(auto it:obj.second){
                cout<<" , "<<it.vertex<<" is "<<it.cost;
            }
            cout<<endl;
        }
        cout<<"\nTotal cost of this graph : "<<totalCost<<endl;
    }
};

int main() {
	Graph g;
	g.addEdge(1,2,2,false);
	g.addEdge(1,3,4,false);
	g.addEdge(2,4,7,false);
	g.addEdge(2,3,1,false);
	g.addEdge(5,4,2,false);
	g.addEdge(5,6,5,false);
	g.addEdge(4,6,1,false);
	g.addEdge(3,5,3,false);
	g.print();
	return 0;
}
