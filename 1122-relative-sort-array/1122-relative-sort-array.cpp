class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int, int> mp;
        
        // mapping values of arr2 to their respective position
        for(int i=0; i<arr2.size(); i++)
            mp[arr2[i]] = i;
        
        int n = arr1.size();
        for(int i=0; i < n-1; i++){
            
            for(int j=i+1; j < n; j++){
                
                // if you can find both -> swap according to value
                if(mp.find(arr1[i]) != mp.end() && mp.find(arr1[j]) != mp.end() 
                   && mp[arr1[i]] > mp[arr1[j]])
                    swap(arr1[i], arr1[j]);    
                
                // if you can find one that is present right side -> swap 
                else if(mp.find(arr1[i]) == mp.end() && mp.find(arr1[j]) != mp.end())
                    swap(arr1[i], arr1[j]);
                
                else if(mp.find(arr1[i]) == mp.end() && mp.find(arr1[j]) == mp.end() 
                        && arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);  
            }
        }
        
        return arr1;
        
        // sort(arr1.begin(), arr1.end(), comparator);
        
    }
    
//     static bool comparator(int x, int y){
//         if(mp.find(x) != mp.end() && mp.find(y) != mp.end()){   // if x and y exists in arr2
            
//             if(mp[x] < mp[y])     // index of x is less than y
//                 return x < y;
//             else
//                 return x > y;
//         }
//         else{
            
//         }
//     }
};