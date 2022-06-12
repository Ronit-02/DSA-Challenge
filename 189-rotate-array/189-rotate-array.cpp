class Solution {
public:
    void reverse(vector<int> &arr, int s, int e){
        
        while(s < e){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
    
    void rotate(vector<int> &arr, int k) {
  
        int n = arr.size();
        
        k = k % n;     // to remove repetition
        reverse(arr, 0, n-k-1);
        reverse(arr, n-k, n-1);
        reverse(arr, 0, n-1);
    }
};