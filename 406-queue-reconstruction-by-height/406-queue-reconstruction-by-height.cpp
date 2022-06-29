class Solution {
public:
    static bool sortcol(vector<int> &v1, vector<int> &v2){
        
        if(v1[0] == v2[0])
            return v1[1] < v2[1];    // ascending order wrt 'k' or 1st column  
        else
            return v1[0] > v2[0];    // descending order wrt 'h' or 0th column
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        // custom sorting
        sort(people.begin(), people.end(), sortcol);
        
        vector<vector<int>> ans;
        
        // inserting element at desired position
        for(auto man : people){
            ans.insert(ans.begin()+man[1], man);   
        }
        
        return ans;
    }
};