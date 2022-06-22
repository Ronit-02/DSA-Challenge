class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = heights.size();
        int i=0;
        
        for(i=0; i < n-1; i++){
            
            if(heights[i] < heights[i+1])
                pq.push(heights[i+1] - heights[i]);   // if diff > 0 -> add in queue
            
            // Simple, intuition -> larger diff to be used by ladder 
            // if no of diff increases than the ladder
            // we use bricks for smallest diff and rest we keep it for ladders
            if(pq.size() > ladders){    
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