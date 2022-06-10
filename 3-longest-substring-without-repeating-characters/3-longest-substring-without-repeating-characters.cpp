class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        int n = str.length();
        
        vector <int> hash(256, -1);
        
        int i = 0;
        int j = 0;
        int len = 0;
        
        while(j < n){
            if(hash[ str[j] ] != -1)
                i = max(hash[str[j]]+1, i);
            hash[str[j]] = j;
            len = max(len, j-i+1);
            j++;
        }
     
    return len;
    }
};