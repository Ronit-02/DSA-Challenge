class Solution {
public:
//     int containsDuplicate(string s){    // -1 if it doesnt contains duplicate, otherwise its index
     
//         for(int i=0; i<s.length() - 1; i++)
//             if(s[i] == s[i+1])
//                 return i;
        
//         return -1;
//     }
    string removeDuplicates(string s) {
        
        int i = 0;
        while(i < s.length()){
            
            if(s[i] == s[i+1]){
                s.erase(i,2);
                
                if(i>0)
                    i--;
            }
            else
                i++;
        } 
        return s;
    }
};