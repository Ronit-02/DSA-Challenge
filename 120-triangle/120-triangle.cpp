class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
     
        for(int i=triangle.size()-2 ; i >= 0 ; i--){
            
            for(int j=0 ; j < triangle[i].size() ; j++){
                
                int Min = min(triangle[i+1][j], triangle[i+1][j+1]);
                int sum = triangle[i][j] + Min;
                triangle[i][j] = sum;
            }
        }
        return triangle[0][0];
    }
};


// class Solution {
//     public int minimumTotal(List<List<Integer>> triangle) {
//         // BOTTOM UP APPROACH
//         for(int  i=triangle.size()-2;i>=0;--i)
//             for(int j=0;j<triangle.get(i).size();++j){  
//                 int min = Math.min(triangle.get(i+1).get(j),triangle.get(i+1).get(j+1));
//                 int sum = triangle.get(i).get(j) + min; 
//                 triangle.get(i).set(j,sum);
//               }
//         return triangle.get(0).get(0);
//     }
// }