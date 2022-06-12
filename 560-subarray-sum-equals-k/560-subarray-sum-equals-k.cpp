class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        
        int n = (int)arr.size();
        
        int ans = 0;
        
        unordered_map<int, int> hash;
        int sum = 0;
        
        for(int i=0; i<n; ++i){
            sum += arr[i];              // increasing sum
            
            if(sum == k)          // if sum == target
                ans++;
            // if (sum - target) is present, add its freq
            if(hash.find(sum - k) != hash.end())    
                ans += hash[sum - k];
            
            hash[sum]++;
        }
        
        return ans;
    }
};