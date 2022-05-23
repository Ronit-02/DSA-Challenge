class Solution {
public:
    int binSearch(vector<int>& arr, int target, int s, int e){
        
            int mid = s + (e-s)/2;
            
            while(s <= e){
                if(arr[mid] == target)
                    return mid;
                else if(arr[mid] > target)
                    e = mid - 1;
                else
                    s = mid + 1;
                
                mid = s + (e-s)/2;
            }
        return -1;
    }
    
    int findPivot(vector<int>& arr){
        
        int n = arr.size();   
        
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        
        while(s<e){
            
            if(arr[mid] >= arr[0])  // lying in first line
                s = mid + 1;
            
            else
                e = mid;           // lying in second line
            
            mid = s + (e-s)/2;
        }
        
        return s;
    }
    
    int search(vector<int>& arr, int target) {
  
        int n = arr.size();   
        
        int pivot = findPivot(arr);
        
        //binary search for target wrt pivot
        if(target >= arr[pivot] && target <= arr[n-1]){          //second sorted part
            
            return binSearch(arr, target, pivot, n-1);
        }
        else{                                                  //first sorted part
            
            return binSearch(arr, target, 0, pivot-1);
        }
    }
};