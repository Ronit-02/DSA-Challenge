class Solution {
public:
    string reverseWords(string str) {
        
        int i = 0;
        int n = str.size();
        string ans = "";
        
        while(i < n){
			
            while(i < n && str[i] == ' ') 
                i++;                    //iterate till space is present
            if(i>=n) 
                break;
            
            int j = i+1;
            while(j < n && str[j] != ' ') 
                j++;                    //iterate for word
            
            string sub = str.substr(i,j-i);
            
            if(ans == "") 
                ans = sub;
            else 
                ans = sub + " " + ans;
            
            i = j+1;
        }
        return ans;
    }
};