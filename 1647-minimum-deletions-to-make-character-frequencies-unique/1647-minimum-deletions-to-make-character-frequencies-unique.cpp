class Solution {
public:
    int minDeletions(string s) {
        
        int ans = 0;
        int n = s.length();
        
        // freq array for characters
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++)
            freq[s[i] - 'a']++;
        
        // sorted, all freq are present at last
        sort(freq.begin(), freq.end());
        
        // starting from second last
        for(int i=24; i>=0; i--){
            
            if(freq[i] == 0) break;    // till we encounter 0
            
            // reduce till becomes smaller than prev, but not smaller than 0
            while(freq[i] >= freq[i+1] && freq[i] > 0){   
                freq[i]--;
                ans++;
            }
        }
        
        return ans;
    }
};