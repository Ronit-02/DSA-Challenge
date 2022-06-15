class Solution {
public:
    void rotate(vector<vector<int>>& a) {
     
        int n = a.size();
        
        // swapping non diagonal elements
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
    
                    swap(a[i][j], a[j][i]);
            }
        }
        
        // swapping whole columns
        for(int j = 0; j < n/2; j++){
            for(int i = 0; i < n; i++){
            
                swap(a[i][j], a[i][n-j-1]);      
            }
        }

    }
};