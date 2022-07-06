class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        int n = arr.size();
        
        // 1. creating map with all elements value 1
        
        for(int i=0; i<n; i++){
            mp[arr[i]] = 1;
        }
        
        // 2. Marking elements which are starting of some seq. as 1
        
        for(int i=0; i<n; i++){
            if(mp.find(arr[i]-1) != mp.end())
                mp[arr[i]] = 0;
        }
        
        // 3. Calculating largest sequence
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            if(mp[arr[i]] == 1){  
                
                int len = 1;
                
                while(mp.find(arr[i] + len) != mp.end())
                    len++;
                
                ans = max(ans, len);
            } 
        }
        
        return ans;
    }
};