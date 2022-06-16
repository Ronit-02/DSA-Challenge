class Solution {
public:
    
    // Seive of Eratosthenes
    // Time Complexity: O(nlog(logn))
    
    int countPrimes(int n){
        
        vector<bool> prime(n + 1, true);
        
        for (int i = 2; i * i <= n; i++){      // i*i <= n <- optimization
            if (prime[i]){
                
                for (int p = i * i; p <= n; p += i){     // start from i*i 
                    prime[p] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++){
            count += prime[i];
        }
        return count;
    }
};