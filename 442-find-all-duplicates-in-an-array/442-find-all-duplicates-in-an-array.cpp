class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
  
        map<int, int> mp;
        
        //frequencies stored in map
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
    
        //checking for value 2 in map (which represent freq)
        vector<int> ans;
        for(auto itr = mp.begin(); itr!=mp.end(); itr++){
            if(itr->second == 2)
                ans.push_back(itr->first);
        }

        return ans;
    }
};