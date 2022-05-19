class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        
        int n = arr.size();
        int ans = -1;
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        
        int pre = 0;
        for(int i=0; i<n; i++){
            
            if( sum-pre-arr[i] == pre ){
                ans = i;
                break;
            }
            pre += arr[i];
        }
        
        return ans;
    }
};