class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        
        vector <int> ans;
        
        int left = 0;
        int right = a[0].size() - 1;    // left, right -> in a row
        int top = 0;
        int bottom = a.size() - 1;      // top, bottom -> in a columm
        
        while(left <= right && top <= bottom){
            
            if(left <= right && top <= bottom){
                for(int i=left; i<=right; i++)
                    ans.push_back(a[top][i]);
                
                top++;
            }
            if(left <= right && top <= bottom){
                for(int i=top; i<=bottom; i++)
                    ans.push_back(a[i][right]);
                
                right--;
            }
            if(left <= right && top <= bottom){
                for(int i=right; i>=left; i--)
                    ans.push_back(a[bottom][i]);
                
                bottom--;
            }
            if(left <= right && top <= bottom){
                for(int i=bottom; i>=top; i--)
                    ans.push_back(a[i][left]);
                
                left++;
            }
            
        }
        return ans;
    }
};