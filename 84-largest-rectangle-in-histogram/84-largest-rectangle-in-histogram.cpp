class Solution {
public:
    void nextSmaller(vector<int> arr, vector<int> &next, int n){
        
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
    void prevSmaller(vector<int> arr, vector<int> &prev, int n){
        
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
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;
        
        vector<int> next(n);    // to store next smaller element index
        nextSmaller(heights, next, n);
         
        vector<int> prev(n);   // to store prev smaller element index
        prevSmaller(heights, prev, n);
        
        for(int i=0; i<n; i++){
            
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            
            ans = max(ans, l*b);
        }
     
        return ans;
    }
};