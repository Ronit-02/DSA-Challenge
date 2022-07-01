class Solution {
public:
    static bool sortCol(vector<int> v1, vector<int> v2){
        
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    
        sort(boxTypes.begin(), boxTypes.end(), sortCol);
        
        int units = 0;
        
        for(int i = 0; i < boxTypes.size() && truckSize > 0; i++){
            
            if(truckSize - boxTypes[i][0] >= 0){
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                units += truckSize * boxTypes[i][1];
                break;
            }
        }
        
        return units;
    }
};