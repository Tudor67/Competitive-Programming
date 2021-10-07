class Solution {
public:
    int kthGrammar(int n, int k) {
        int res = 0;
        while(k > 1){
            if(k % 2 == 1){
                k = (k + 1) / 2;
            }else{
                k = k / 2;
                res ^= 1;
            }
        }
        return res;
    }
};