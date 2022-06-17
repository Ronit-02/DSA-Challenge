class Solution {
public:
    static bool sortByLength(string &s1, string &s2){
        
        return s1.length() < s2.length();  
        // eg s1 = "ab", s2 = "abc" -> return true -> no swap
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        
        // Sort all the words in ascending order of their length
        sort(words.begin(), words.end(), sortByLength);
        
        unordered_map<string, int> dp(n);
        int len = 0;
        
        for(int i=0; i < n; i++){
            
            dp[words[i]] = 1;   // can form by itself
            
             // deleting char by char and checking if predecessor exists
            for(int j=0; j < words[i].size(); j++){  
                
                string predecessor = words[i].substr(0, j) + words[i].substr(j+1);
                dp[words[i]] = max(dp[words[i]] , 1 + dp[predecessor]);
            }
            
            len = max(len, dp[words[i]]);
        }
        
        return len;
    }
};