class Solution {
public:
    int compress(vector<char>& chars) {
     
        int i = 0;
        int ansIndex = 0;
        
        while(i < chars.size()){
            
            int j = i+1;
            while(j < chars.size() && chars[i] == chars[j])    // moving j to different alpha
                j++;
            
            // saving character
            chars[ansIndex++] = chars[i];
            
            // saving count
            int count = j-i;
            if(count > 1){            // count greater than 1 will only be stored
                
                string cnt = to_string(count);
                for(char ch: cnt){
                    chars[ansIndex++] = ch;
                }
            }
            
            i = j;   // moving i to j which is on different char
        }
        
        return ansIndex;
    }
};