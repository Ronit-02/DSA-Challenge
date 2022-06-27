// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        
        vector<int> ans;
        
        int x, y = 0;
        x = N;
        
        while(x != 0){
            x = x >> 1;    // right shifting
            y = y << 1 | 1;   // left shifting or 1
        }
        
        ans.push_back(y-N);
        ans.push_back(y);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends