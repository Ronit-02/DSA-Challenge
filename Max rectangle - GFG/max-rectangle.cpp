// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void nextSmaller(int arr[], vector<int> &next, int n){
    
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--){
            
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            
            next[i] = s.top();
            s.push(i);   // pushing index
        }
    }
    void prevSmaller(int arr[], vector<int> &prev, int n){
        
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++){
            
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            
            prev[i] = s.top();  
            s.push(i);   // pushing index 
        }
    }
    int calculateMaxArea(int row[], int n){
        
        int ans = 0;
        
        vector<int> next(n);    // to store next smaller element index
        nextSmaller(row, next, n);
            
        vector<int> prev(n);   // to store prev smaller element index
        prevSmaller(row, prev, n);
        
        for(int i=0; i<n; i++){
            
            int l = row[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            
            ans = max(ans, l*b);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int ans = calculateMaxArea(M[0], m);
        
        // 1. making row after adding above rows data
        for(int i=1; i<n; i++){
            
            for(int j=0; j<m; j++){
        
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
    
            // 2. calculate max area of that row
            int newArea = calculateMaxArea(M[i], m);

            ans = max(ans, newArea);
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends