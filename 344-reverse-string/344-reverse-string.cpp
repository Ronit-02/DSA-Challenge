class Solution {
public:
    void reverseString(vector<char>& s) {
     
        stringReverse(s, 0, s.size()-1);
    }
    void stringReverse(vector<char> &str, int i, int j){

        // Base Case
        if(i > j)
            return;

        // Process
        swap(str[i], str[j]);

        //Recursive Call
        stringReverse(str, i+1, j-1);
    }
};