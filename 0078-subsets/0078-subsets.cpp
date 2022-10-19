class Solution {
public:
    // Intuition: 
    // Iterative approach adding elements one by one
    // to existing starting from an empty set
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subsets;
        subsets.push_back({});
        
        for(int i=0; i<nums.size(); i++){
            
            int n = subsets.size();
            for(int j=0; j<n; j++){
                // extract
                vector<int> temp = subsets[j];
                // modify
                temp.push_back(nums[i]);
                // add
                subsets.push_back(temp);
            }
        }
        
        return subsets;
    }
};