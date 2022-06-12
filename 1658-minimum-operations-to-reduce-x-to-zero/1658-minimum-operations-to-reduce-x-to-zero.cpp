class Solution {
public:
    int lenOfLongSubarr(vector<int> &arr,  int n, int k) 
    { 
        int maxlen = 0;
        int sum = 0;
        
        unordered_map<int, int> hash;
        
        for(int i=0; i<n; i++){
            
            sum += arr[i];
            
            if(sum == k){
                maxlen = i+1;
            }
            
            if (hash.find(sum) == hash.end())
                hash[sum] = i;
            
            if(hash.find(sum - k) != hash.end()){
                maxlen = max(maxlen, (i - hash[sum-k]));
            }
        }
        
        return maxlen;
    }
    
    int minOperations(vector<int>& arr, int x) {
        
        int n = arr.size();
        
        int arrsum = 0;               // calculating sum of array
        for(int i=0; i<n; ++i){
            arrsum += arr[i];
        }
        
        if(arrsum == x)       // all elements used
            return n;
        
        // maxlen will store max len of subarray having sum (arrsum - x)
        // so that we can get min len of subarray havin sum (x)
        
        int maxlen = lenOfLongSubarr(arr, n, arrsum - x);   
        
        // len 0 indicates no such subarray exist having sum (arrsum - x) or (x)
        if(maxlen == 0)        
            return -1;
        else
            return (n - maxlen);
    }
};