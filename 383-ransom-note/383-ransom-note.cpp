class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26, 0);
        
        for(auto alpha: magazine){
            freq[alpha-'a']++;
        }
        
        for(auto note: ransomNote){
            int val = note-'a';
            
            if(freq[val] == 0) return false;
            else freq[val]--;
        }
        
        return true;
    }
};