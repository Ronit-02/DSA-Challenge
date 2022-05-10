class Solution {
public:
    int findComplement(int num) {
        
        int mask = 0;
        int n = num;
        
        if(n==0)
            return 0;
        
        while(n!=0){
            
            mask = (mask<<1) | 1;
            n = n>>1;
        }
        
        return mask & (~num);
    }
};