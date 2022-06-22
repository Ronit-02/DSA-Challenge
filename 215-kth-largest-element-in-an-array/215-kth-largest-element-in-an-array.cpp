class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // kth largest/smallest -> Quick Select Algorithm
        // 2nd largest -> ascending order -> index = n-2 (or, n-2 th smallest)
        // kth largest -> ascending order -> index = n-k (or, n-k th smallest)
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        
        int ans = quickSelect(nums, lo, hi, n-k);
        
        return ans;
    }
    int quickSelect(vector<int> &nums, int lo, int hi, int k){
     
        int pivot = nums[hi];
        int pi = partition(nums, lo, hi, pivot);   // partition returns correct index of pivot element
        
        if(pi == k)          // if index is equal -> pivot is your ans
            return pivot;
        else if(pi > k)     // otherwise apply binary search
            return quickSelect(nums, lo, pi-1, k);
        else
            return quickSelect(nums, pi+1, hi, k);
    }
    int partition(vector<int> &nums, int lo, int hi, int pivot){
        
        int i = lo;
        int j = lo;
        while(i <= hi){
            
            if(nums[i] <= pivot){       // if smaller swap
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else                       // if larger or equal -> dont swap
                i++;
        }
        return (j-1);
    }
};