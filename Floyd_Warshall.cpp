#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long v;
	    cin>>v;
	    long long arr[v+1][v+1];
	    for(long long i=1;i<v+1;i++){
	        for(long long j=1;j<v+1;j++){
	            cin>>arr[i][j];
	        }
	    }
	    
	    for(long long k=1;k<v+1;k++){
	        for(long long i=1;i<v+1;i++){
	            for(long long j=1;j<v+1;j++){
	                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
	            }
	        }
	    }
	    
	     for(long long  i=1;i<v+1;i++){
	        for(long long  j=1;j<v+1;j++){
	            if(arr[i][j]==10000000){
	                cout<<"INF"<<" ";
	            }
	            else cout<<arr[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<endl;
	    
	}
	return 0;
}
