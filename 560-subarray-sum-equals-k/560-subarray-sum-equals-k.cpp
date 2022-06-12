class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        
        int n = arr.size();
        
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;             // for 0 sum
        
        for(int i=0; i<n; ++i){
            
            sum += arr[i];
            int rsum = sum - target;    // remaining sum
            
            if(hash.count(rsum) == 1)    // if rem_sum is there, increase ans
                ans += hash[rsum];
            
            if(hash.count(sum) == 1)     // if it present -> increase freq
                hash[sum]++;
            else
                hash[sum] = 1;          // if not -> give it freq = 1
        }
        
        return ans;
    }
};