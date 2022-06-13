class Solution {
public:
    string removeChar(string s){
        
        string temp = "";
        for(int i=0; s[i]!='\0'; i++){
            
            int ch = s[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
                temp.push_back(ch);
        }
        
        return temp;
    }
    
    string intoLowerCase(string s){
        
        for(int i=0; s[i] != '\0'; i++){
            
            if(s[i] >= 'A' && s[i] <= 'Z'){    
                s[i] = (s[i] - 'A') + 'a';
            }
        }
        
        return s;
    }
    
    bool checkPalindrome(string s){
        int st = 0;
        int e = s.length() - 1;
        
        while(st < e){
            if(s[st] != s[e])   // at some point if value not equal -> not a palindrome
                return false;
            st++;
            e--;
        }
        
        return true;
    }
    
    bool isPalindrome(string s) {
        
        // removing unnecessary characters
        string str = removeChar(s);
        
        // converting into lower case
        str = intoLowerCase(str);
        
        //checking if string is palindrome
        return checkPalindrome(str);
    }
};