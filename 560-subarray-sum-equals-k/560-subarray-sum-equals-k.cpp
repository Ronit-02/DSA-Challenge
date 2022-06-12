class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        
        int n = arr.size();
        
        int ans = 0;
        
        unordered_map<int, int> hash;
        int sum = 0;
        
        for(int i=0; i<n; ++i){
            sum += arr[i];              // increasing sum
            
            if(sum == target)          // if sum == target
                ans++;
            // if (sum - target) is present, add its freq
            if(hash.count(sum - target) == 1)    
                ans += hash[sum - target];
            
            hash[sum]++;
        }
        
        return ans;
    }
};