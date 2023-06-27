//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check(int A[], int mid, int N, int M){
        int students=1;
        int pages=0;
        for(int i=0;i<N;i++){
            if(A[i] > mid) return false;
            if(pages+A[i] > mid){
                students++;
                pages=0;
                pages+=A[i];
            }
            else pages+=A[i];
        }
        if(students > M) return false;
        return true;
    }
    
    
    int findPages(int a[], int n, int m) 
    {
        if(n<m) return -1;
        int sum = accumulate(a, a+n, 0);
        int s=*max_element(a, a+n), e=sum, ans=-1;
        while(s <= e){
            int mid=(s+e)>>1;
            if(check(a, mid, n, m)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends