class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.length();
        
        int *left = new int[n];
        int nearestleftidx = -1;
        
        // left forces
        for(int i=n-1; i>=0; i--){
            
            if(dominoes[i] == 'L'){
                nearestleftidx = i;
            }
            else if(dominoes[i] == 'R'){ 
                nearestleftidx = -1;
            }
            left[i] = nearestleftidx;
        }
        
        int *right = new int[n];
        int nearestrightidx = -1;
        
        // left forces
        for(int i=0; i<n; i++){
            
            if(dominoes[i] == 'R'){
                nearestrightidx = i;
            }
            else if(dominoes[i] == 'L'){ 
                nearestrightidx = -1;
            }
            right[i] = nearestrightidx;
        }
            
        
        for(int i=0; i<n; i++){
            
            if(dominoes[i] == '.'){
                    
                if(right[i] == -1 && left[i] != -1)
                    dominoes[i] = 'L';
                else if(left[i] == -1 && right[i] != -1)
                    dominoes[i] = 'R';
                else if(right[i] == -1 && left[i] == -1)
                    dominoes[i] = '.';
                else{
                    int leftdiff = abs(i - left[i]);
                    int rightdiff = abs(i - right[i]);
                    
                    if(leftdiff == rightdiff)
                        dominoes[i] = '.';
                    else if(leftdiff < rightdiff)
                        dominoes[i] = 'L';
                    else
                        dominoes[i] = 'R';
                }
            }
        }
        
        return dominoes;
    }
};

