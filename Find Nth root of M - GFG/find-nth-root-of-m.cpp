//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    if(n == 1) return m;
	    long long int s = 1, e=sqrt(m), mid;
	    while(s<=e){
	        mid = (s+e)/2;
	        long long temp = 1;
	        for(long long int i=0; i<n; ++i){
	            temp*=mid;
	            if(temp > m){
	                break;
	            }
	        }
	        
	        if(temp == m) return mid;
	        else if(temp > m) e=mid-1;
	        else s=mid+1;
	        
	    }
	    return -1;
	}   
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends