class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        // sort the letter arrangement
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        int x = 1;
        // check if you can match it up with any power of 2
        for(int i=0; i<31; i++){
            string k = to_string(x);
            sort(k.begin(), k.end());
            
            if(k == s)  return true;
            x = x << 1;
        }
        
        return false;
    }
};