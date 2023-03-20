//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int func(int ind, vector<int> &A, vector<int> &height){
        if(ind == 0) return 0;
        if(A[ind] != -1) return A[ind];
        int left = func(ind-1,A,height) + abs(height[ind] - height[ind-1]);
        int right = INT_MAX;
        if(ind > 1) right = func(ind-2,A,height) + abs(height[ind] - height[ind-2]);
        return A[ind] = min(left,right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        return func(n-1, dp, height);
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends