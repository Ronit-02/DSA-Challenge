class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.length();
        
        vector<float> trav(n, 0);
        float force = 1;
        
        // left traversal
        for(int i=n-1; i>0; i--){
            
            if(dominoes[i] == '.' && trav[i] < 0){ 
                trav[i-1] -= force/2;
            }
            if(dominoes[i] == 'L'){
                force = 1;
                trav[i] -= force;
                trav[i-1] -= force/2;
            }
            force /= 2;   // intensity reduces
        }
        
        force = 1;
        
        // right traversal
        for(int i=0; i<n-1; i++){
            
            if(dominoes[i] == '.' && trav[i] > 0){
                trav[i+1] += force/2;
            }
            if(dominoes[i] == 'R'){
                force = 1;
                trav[i] += force;
                trav[i+1] += force/2;
            }
            force /= 2;   // intensity reduces
        }
        
        // edge cases
        if(dominoes[0] == 'L') trav[0] = -1;
        if(dominoes[n-1] == 'R') trav[n-1] = 1;
            
        
        for(int i=0; i<n; i++){
            if(trav[i] < 0) dominoes[i] = 'L';
            else if(trav[i] == 0) dominoes[i] = '.';
            else dominoes[i] = 'R';
        }
        
        return dominoes;
    }
};