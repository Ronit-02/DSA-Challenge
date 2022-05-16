class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        sort( nums.begin(), nums.end() );
        
        vector< vector<int> > ans;
        int n = nums.size();
        int sum=0;
        
        for(int i=0; i<n-2; i++){
            
            int lo=i+1;
            int hi=n-1;
            sum = 0 - nums[i];
            
            if(i==0 || ( i>0 && (nums[i] != nums[i-1]) )){
                
                while(lo < hi){
                    
                    if(nums[lo] + nums[hi] == sum){
                        
                        vector<int> v1;
                        v1.push_back(nums[i]);
                        v1.push_back(nums[lo]);
                        v1.push_back(nums[hi]);
                        
                        ans.push_back(v1);
                        
                        while(lo < hi && (nums[lo] == nums[lo+1]))
                            lo++;
                        while(lo < hi && (nums[hi] == nums[hi-1]))
                            hi--;
                        
                        lo++;
                        hi--;
                    }
                    else if( nums[lo] + nums[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};