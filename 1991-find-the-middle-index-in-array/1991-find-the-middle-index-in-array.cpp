class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
  
        int n = arr.size();
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        
        int pre = 0;
        for(int i=0; i<n; i++){
            
            if( sum-pre-arr[i] == pre ){
                return i;
            }
            pre += arr[i];
        }
        
        return -1;
    }
};