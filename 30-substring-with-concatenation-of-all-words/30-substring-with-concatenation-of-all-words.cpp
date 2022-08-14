class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = words.size();
        int k = words[0].length();
        vector<int> ans;
        
        // limiting case
        if(s.size() < n*k)
            return ans;
        
        // predefined map for use
        unordered_map<string, int> freq;
        for(int i=0; i<n; i++)
            freq[words[i]]++;
        
        for(int i=0; i <= s.size() - (n*k); i++){
            
            // 1: create map for every index
            unordered_map<string, int> mp = freq;   
            
            // 2: check for words
            int j = i;
            while(mp.size() > 0){
                string str = s.substr(j, k);
                
                if(mp.find(str) != mp.end()){
                    if(--mp[str] == 0) 
                        mp.erase(str);
                }
                else{
                    break;
                } 
                j += k;
            }
            
            if(mp.size() == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};