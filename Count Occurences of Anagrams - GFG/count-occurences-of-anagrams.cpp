//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

    bool allzero(unordered_map<char,int> &m){
        for(auto i: m){
            if(i.second != 0) return false;
        }
        return true;
    }
    
	int search(string pat, string txt) {
	    unordered_map<char, int> m;
	    int k = pat.size();
	    int c = 0;
	    for(auto  x: pat){
	        m[x]++;
	    }
	    int i=0,j=0;
	    while(j<txt.size()){
	        m[txt[j]]--;
	        if(j-i+1 == k){
	           if(allzero(m)) c++;
	           m[txt[i]]++;
	           i++;
	        }
	        j++;
	    }
	    return c;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends