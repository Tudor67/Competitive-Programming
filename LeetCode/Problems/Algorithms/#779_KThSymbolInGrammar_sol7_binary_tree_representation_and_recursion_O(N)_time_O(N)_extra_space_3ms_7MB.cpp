class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            return 0;
        }
        if(k % 2 == 1){
            return kthGrammar(n - 1, (k + 1) / 2);
        }
        return 1 - kthGrammar(n - 1, k / 2);
    }
};