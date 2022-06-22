class Solution {
    public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int,int> s;

        for (int i=0; i<arr2.size(); i++)    // Hashmap of arr2
            s[arr2[i]]=i;             

        sort(begin(arr1), end(arr1), [&s](int a, int b) { 
            return (s.count(a) && (s.count(b)==0 || s[a]<s[b])) || (s.count(b)==0 && a<b);
        });        

        return arr1;
    }
};