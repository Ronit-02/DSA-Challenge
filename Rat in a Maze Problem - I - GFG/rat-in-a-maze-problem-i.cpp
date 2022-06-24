// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(vector<vector<int>> m, vector<vector<int>> a, int x, int y){
        
        int n = m.size();
        
        if((x>=0 && y>=0) && (x<n && y<n) && m[x][y] == 1 && a[x][y] == 0)
            return true;
        else
            return false;
    }
    
    void recurPath(vector<vector<int>> m, vector<vector<int>> a, string path, 
                    vector<string> &ans, int x, int y){
                        
        int n = m.size();
        
        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
            
        a[x][y] = 1;  // marking visited
            
        // Down
        int newx = x+1;
        int newy = y;
        if(isSafe(m, a, newx, newy)){
            
            path.push_back('D');
            recurPath(m, a, path, ans, newx, newy);
            path.pop_back();           // Backtracking
        }
        // Right
        newx = x;
        newy = y+1;
        if(isSafe(m, a, newx, newy)){
            
            path.push_back('R');
            recurPath(m, a, path, ans, newx, newy);
            path.pop_back();           // Backtracking
        }
        // Up
        newx = x-1;
        newy = y;
        if(isSafe(m, a, newx, newy)){
            
            path.push_back('U');
            recurPath(m, a, path, ans, newx, newy);
            path.pop_back();           // Backtracking
        }
        // Left
        newx = x;
        newy = y-1;
        if(isSafe(m, a, newx, newy)){
            
            path.push_back('L');
            recurPath(m, a, path, ans, newx, newy);
            path.pop_back();           // Backtracking
        }
        
        a[x][y] = 0;    // marking unvisited
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        string path;
        
        if(m[0][0] == 0)   // blocked initially
            return ans;
        
        // already visited matrix
        vector<vector<int>> a = m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                a[i][j] = 0;
        }
        
        int x = 0;
        int y = 0;
        recurPath(m, a, path, ans, x, y);
        sort(ans.begin(), ans.end());
           
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends