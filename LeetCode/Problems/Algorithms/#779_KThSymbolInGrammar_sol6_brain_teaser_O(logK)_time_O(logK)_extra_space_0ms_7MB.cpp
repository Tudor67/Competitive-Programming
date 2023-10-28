class Solution {
public:
    int kthGrammar(int n, int k) {
        const int LOG_K = log2(k);

        vector<int> rowSize(LOG_K + 3);
        rowSize[1] = 1;
        for(int row = 2; row <= LOG_K + 2; ++row){
            rowSize[row] = rowSize[row - 1] * 2;
        }

        int row = LOG_K + 2;
        int flip = 0;
        while(k > 2){
            while(k <= rowSize[row - 1]){
                row -= 1;
            }
            if(row % 2 == 0){
                flip ^= 1;
            }
            k = rowSize[row] / 2 - (k - rowSize[row] / 2) + 1;
        }

        return (k - 1) ^ flip;
    }
};