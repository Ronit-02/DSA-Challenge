class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
  
        // Sliding Window Approach
        // Untill duplicate elements we keep on adding and increase our window size
        // hash set -> to keep check for unique elements
        // ans -> storing the maximum sum till now
        // currSum -> storing current sum of the window
        
        unordered_set<int> hashset;
        
        int ans = 0;
        int currSum = 0;
        
        int i = 0;
        int j = 0;
        while(j < nums.size()){
            
            while(hashset.find(nums[j]) != hashset.end()){
                hashset.erase(nums[i]);
                currSum -= nums[i];
                i++;
            }
            
            // if element not present -> add it
            hashset.insert(nums[j]);
            currSum += nums[j];
            j++;
            
            ans = max(ans, currSum);       
        }
        
        return ans;
    }
};