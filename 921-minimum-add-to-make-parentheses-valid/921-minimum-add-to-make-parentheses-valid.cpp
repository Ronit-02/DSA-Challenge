class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            
            char ch = s[i];
            
            if(ch == '(')
                st.push(ch);
            
            if(ch == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    ans++;
            }   
        }
        
        while(!st.empty()){
            ans++;
            st.pop();
        }
        
        return ans;
    }
};