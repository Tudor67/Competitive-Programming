class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k <= 2){
            return k - 1;
        }

        int row = 1;
        int rowSize = 1;
        while(rowSize < k){
            row += 1;
            rowSize *= 2;
        }

        if(row % 2 == 0){
            return 1 - kthGrammar(n, rowSize / 2 - (k - rowSize / 2) + 1);
        }
        return kthGrammar(n, rowSize / 2 - (k - rowSize / 2) + 1);
    }
};