class Solution {
public:
    int minPartitions(string n) {
  
        // Highest Digit is the answer
        // as it will take most no to reduce and we can afford only 1's and 0's
        
        int ans = n[0] - '0';
        
        for(int i=0; i<n.length(); i++){
            if((n[i] - '0') > ans)
                ans = n[i] - '0';
        }
        
        return ans;
    }
};