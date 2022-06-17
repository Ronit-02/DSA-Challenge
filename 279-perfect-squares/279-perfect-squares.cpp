class Solution {
public:
    int numSquares(int n) {
     
        // Lagranges 3-Square Theorem
        // Every natural no can be represented as sum of 4 squares
        // So ans lies in range (1-4) -> 4 conditions
        // Time Complexity: O(N^1/2)
        
        // For value 1
        // Check if n is a perfect square
        
        int a = sqrt(n);
        if(a * a == n)
            return 1;
        
        // For value 4
        // Check if n is of form 4^a(8b + 7)
        
        while(n % 4 == 0)     // Removing 4^a terms
            n /= 4;
        if(n % 8 == 7)
            return 4;
        
        // For value 2
        // Break point which divides it into two perfect squares
        
        for(int i=1; i*i <= n; i++){
            
            int base = sqrt(n - i*i);   // other half
            if(base*base == (n - i*i))
                return 2;
        }
        
        // For value 3 (when all 3 are checked)
        
        return 3;
    }
};