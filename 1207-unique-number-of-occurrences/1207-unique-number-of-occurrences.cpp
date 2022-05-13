class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> mp;
        for(int x : arr){
            mp[x]++;
        }
        
        set<int> st;    
        for(auto it: mp){
            if(st.count(it.second) > 0)
                return false;
            else
                st.insert(it.second);
        }
        
        return true;
    }
};