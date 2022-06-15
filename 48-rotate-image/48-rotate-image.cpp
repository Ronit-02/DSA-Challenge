class Solution {
public:
    void rotate(vector<vector<int>>& a) {
     
        int n = a.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
    
                    swap(a[i][j], a[j][i]);
            }
        }
        
        int j = 0;
        for(int j = 0; j < n/2; j++){
            for(int i = 0; i < n; i++){
            
                swap(a[i][j], a[i][n-j-1]);      
            }
        }

    }
};