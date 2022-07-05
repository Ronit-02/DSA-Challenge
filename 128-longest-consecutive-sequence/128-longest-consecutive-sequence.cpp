class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(),nums.end()); 
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(s.find(nums[i]-1) != s.end())  // if it is not starting of sequence
                continue;
            
            else{
                
                int count = 0;
                while(s.find(nums[i]) != s.end()){  // if next sequence is there, add
                    count++;
                    nums[i]++;
                }
                
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};