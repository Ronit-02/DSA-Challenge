class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // Simple, intuition -> larger diff to be used by ladder 
        // if no. of jumps increases (counted as diff here) than the ladders present, then
        // we use bricks for smallest diff and rest we keep it for ladders
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = heights.size();
        int i=0;
        
        for(i=0; i < n-1; i++){
            
            if(heights[i] < heights[i+1])
                pq.push(heights[i+1] - heights[i]);   // adding jumps in queue
            
            
            if(pq.size() > ladders){   // smallest diff for ladder    
                int temp = pq.top();
                pq.pop();
                bricks -= temp;
                
                if(bricks < 0)
                    break;
            }
        }
        return i;
        
    }
};