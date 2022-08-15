class Solution {
public:
    
    int helper(char curr, char prev){
        
        switch (curr) {
            case 'I':
                return 1;
            case 'V':
                return prev == 'I' ? 3 : 5;
            case 'X':
                return prev == 'I' ? 8 : 10;
            case 'L':
                return prev == 'X' ? 30 : 50;
            case 'C':
                return prev == 'X' ? 80 : 100;
            case 'D':
                return prev == 'C' ? 300 : 500;
            case 'M':
                return prev == 'C' ? 800 : 1000;
            default:
                return 0;
        }
    }
    
    int romanToInt(string s) {
    
        int ans = 0;
        char prev = '0';
        char curr = '0';
        
        for(int i=0; i<s.size(); i++){
            
            curr = s[i];
            ans += helper(curr, prev);
            prev = curr;
        }
        return ans;
    }
};