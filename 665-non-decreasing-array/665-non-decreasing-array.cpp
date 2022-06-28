class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        // when arr[i-1] > arr[i] -> modification req
        // case 1: arr[i-2] <= arr[i]
        //         arr[i-1] = arr[i]
        // case 2: arr[i-2] > arr[i] 
        //         arr[i] = arr[i-1]
        
        int cnt = 0; 
        
        for(int i = 1; i < nums.size(); i++){        
            if(nums[i] < nums[i-1]){
                if(cnt >= 1) 
                    return false;
                
                if(i == 1 || nums[i-2] <= nums[i])    // case 1
                    nums[i-1] = nums[i];    
                else                                  // case 2
                    nums[i] = nums[i-1];
                
                cnt++;
            }
        }
        return true;
    } 
};