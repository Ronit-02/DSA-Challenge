class Solution {
public:   
    int firstOcc(vector <int>& arr, int key){
        
        int n = arr.size();
        
        int start = 0;
        int end = n-1;
        int mid = (start + mid)/2;
        int ans = -1;
        
        while(start <= end){
            
            if(arr[mid] == key){
                ans = mid;
                end = mid - 1;
            }
            else if(arr[mid] < key)
                start = mid + 1;
            else
                end = mid - 1;
            
            mid = end + (start-end)/2;
        }
            return ans;
        
    }
    int lastOcc(vector <int>& arr, int key){
        
        int n = arr.size();
        
        int start = 0;
        int end = n-1;
        int mid = (start+ mid)/2;
        int ans = -1;
        
        while(start <= end){
            
            if(arr[mid] == key){
                ans = mid;
                start = mid + 1;
            }
            else if(arr[mid] < key)
                start = mid + 1;
            else
                end = mid - 1;
            
            mid = end + (start-end)/2;
        }
            return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        int output = firstOcc(nums, target);
        ans.push_back(output);
        
        output = lastOcc(nums, target);
        ans.push_back(output);
        
        return ans;
    }
};