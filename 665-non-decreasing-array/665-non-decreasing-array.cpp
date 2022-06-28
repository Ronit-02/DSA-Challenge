class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
  
        int n = arr.size();
        vector<int> arr2(arr);
        
        int cnt1 = 0;              // from starting to end
        for(int i=1; i<n; i++){     
            if(arr2[i] < arr2[i-1]){
                arr2[i] = arr2[i-1];
                cnt1++;
            }
        }
        
        int cnt2 = 0;              // from ending to start
        for(int i=n-2; i>=0; i--){
            if(arr[i] > arr[i+1]){
                arr[i] = arr[i+1];
                cnt2++;
            }
        }
        
        int cnt = min(cnt1, cnt2);
        if(cnt <= 1)
            return true;
        else
            return false;
    }
};