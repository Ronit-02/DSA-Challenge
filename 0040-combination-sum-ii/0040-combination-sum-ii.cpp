class Solution {
private:
    // TC: O(2^t * k)
    // Intuition: 
    // to avoid picking up the same combnations i.e. we don't pick same element
    // for certain kth position of a combination 
    void recurComb(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> seq, int ind){
        if(target == 0){
            ans.push_back(seq);
            return;
        }   
        
        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1])  // skipping all the duplicates
                continue;
            if(arr[i] > target)
                break;
            
            seq.push_back(arr[i]);
            recurComb(arr, target - arr[i], ans, seq, i+1);
            seq.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> seq;
        
        recurComb(candidates, target, ans, seq, 0);
        
        return ans;
    }
};