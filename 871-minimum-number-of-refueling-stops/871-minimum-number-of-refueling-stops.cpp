class Solution {
public:
    // Intuition: Using an old station with more fuel means you have more fuel 
    // to go with because we have to travel same dist but now we have more fuel.
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
              
        int n = stations.size();
        int count = 0;
        int idx = 0;    // station index
        priority_queue<int> pq;
        
        while(startFuel < target){
            
            // saving all the options
            while(idx < n && startFuel >= stations[idx][0]){
                pq.push(stations[idx][1]);   
                idx++;
            }
            
            // Edge case -> no stations left to reach target
            if(pq.size() == 0)
                return -1;
            
            // choosing the max fuel
            startFuel += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};