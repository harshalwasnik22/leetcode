//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void f(int n, int open, int close, int ind, string s, vector<string> &ans){
        if(close == n and open == n){
            ans.push_back(s);
            return;
        }
        if(ind >= 2*n) return;
        
        if(open < n)
            f(n, open+1, close, ind+1, s+"(", ans);
        if(close < open)
            f(n, open, close+1, ind+1, s+")", ans);
    }
    
    vector<string> AllParenthesis(int n){
        vector<string> ans;
        string s="";
        f(n,0,0,0,s,ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends