class Solution {
public:
    static bool sortCol(vector<int>& v1, vector<int>& v2){
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    
        sort(boxTypes.begin(), boxTypes.end(), sortCol);
        int units = 0;
        
        for(auto box : boxTypes){
            if(truckSize >= box[0]){
                units += box[0]*box[1];
                truckSize -= box[0];
            }
            else{
                units += box[1]*truckSize;
                break;
            }
        }
        return units;
    }
};