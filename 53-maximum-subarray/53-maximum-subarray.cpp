class Solution {
public:
    int maxSubArray(vector<int>& arr) {
  
        int n = arr.size();
        
        int sum = 0;
        int maxVal = INT_MIN;
        
        for(int i=0; i<arr.size(); ++i){
                
            sum += arr[i];
            maxVal = max(maxVal, sum);    
            
            if(sum < 0)
                sum = 0;
        }
        
        return maxVal;
    }
};