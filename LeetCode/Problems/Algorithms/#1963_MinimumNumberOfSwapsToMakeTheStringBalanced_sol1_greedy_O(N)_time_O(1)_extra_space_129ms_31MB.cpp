class Solution {
public:
    int minSwaps(string s) {
        const int N = s.length();
        
        int swaps = 0;
        int bal = 0;
        for(char c: s){
            if(c == '['){
                bal += 1;
            }else{
                bal -= 1;
            }
            if(bal == -1){
                swaps += 1;
                bal = 1;
            }
        }
        
        return swaps;
    }
};