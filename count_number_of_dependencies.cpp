#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>> adjList;
    int count=0;
    public:
    void addEdge(int u,int v){
        adjList[u].push_back(v);
    }
    void count_dependencies(){
        for(auto obj:adjList){
            for(auto edge:obj.second){
                count++;
                
            }
        }
        cout<<count/2<<endl;
    }
    
};
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    int l=2*e;
	    int arr[l];
	    for(int i=0;i<(l);i++){
	        cin>>arr[i];
	    }
	    Graph g;
	    for(int i=0;i<l;i++){
	        g.addEdge(arr[i],arr[i+1]);
	        
	    }
	    g.count_dependencies();//number of dependencies
	    
	}
	return 0;
}