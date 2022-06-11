class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        
        int n = arr.size();
        
        int i = 0;
        for(int j=0; j<n; ++j){
            
            if(arr[j] != val){
                swap(arr[i], arr[j]);
                i++;
            }   
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
            if(arr[i] != val)
                ans++;
        
        return ans;
    }
};