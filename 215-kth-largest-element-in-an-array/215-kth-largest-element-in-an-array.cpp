class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0; i < nums.size(); i++){
            pq.push(nums[i]);    // adding
            
            if(pq.size() > k)   // removing, when size increases more than k 
                pq.pop();
        }
        return pq.top();    // top element is your answer
    }
};