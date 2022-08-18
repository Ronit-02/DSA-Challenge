 class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        
        // 1: making of freq map
        unordered_map<int, int> um;
        for(int i=0; i<n; i++){
            um[arr[i]]++;
        }
    
        // 2: sorting of freq
        vector<int> v;
        for (auto x : um){
           v.push_back(x.second);
        }
        if(v.size()==1) return 1;
        sort(v.begin(), v.end());
        
        int ans = 0;
        int freq = 0;
        for(int i = v.size()-1; i >= 0; i--){
            if(freq >= n/2){
              return ans;
            } 
            ans++;
            freq += v[i];
        }
        
        return 0;
    }
};