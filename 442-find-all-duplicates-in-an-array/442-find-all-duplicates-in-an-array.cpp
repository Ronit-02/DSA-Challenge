class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res(n+1,0);
        vector <int> ans;
        for(int i: nums)
        {
                res[i]++;
        }
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==2)
            {
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};