class Solution {
public:
    
    // Using Sliding Window Technique!!
    
    bool isEqual(int a[26], int b[26]){
        
        for(int i=0; i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
     
        // creating freq array for s1
        int freq1[26] = {0};
        
        for(int i=0; i<s1.length(); i++){
            char ch = s1[i];
            int idx = ch - 'a';
            freq1[idx]++;
        }
        
        // processing first window
        int i = 0;
        int windowSize = s1.length();   // window size is pattern length
        int freq2[26] = {0}; 
        
        while(i < windowSize && i < s2.length()){
            char ch = s2[i];
            int idx = ch - 'a';
            freq2[idx]++;
            i++;
        }
        
        // checking if freq array of pattern and window are equal
        if(isEqual(freq1, freq2))
            return true;
        
        // checking for next window
        while(i < s2.length()){
            char newChar = s2[i];
            int idx = newChar - 'a';
            freq2[idx]++;
            
            char oldChar = s2[i - windowSize];
            idx = oldChar - 'a';
            freq2[idx]--;
            
            if(isEqual(freq1, freq2))
                return true;
            
            i++;
        }
        
        return false;
    }
};