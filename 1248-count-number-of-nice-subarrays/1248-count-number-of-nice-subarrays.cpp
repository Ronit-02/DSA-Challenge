class Solution {
public:
    // Brute force solution:
    // traverse all the subarrays and keep a count of odd no occuring
    // and with that return your subarrays with k odd's

    // Optimised approach:
    // convert odd no's to 1 and even to 0 and then apply no of subarray with sum k
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]%2 != 0) nums[i] = 1;
            else nums[i] = 0;
        }
        
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int psum = 0;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            psum += nums[i];
            
            if(mp.find(psum - k) != mp.end())
                cnt += mp[psum - k];
                      
            mp[psum]++;
        }
        
        return cnt;
    }
};