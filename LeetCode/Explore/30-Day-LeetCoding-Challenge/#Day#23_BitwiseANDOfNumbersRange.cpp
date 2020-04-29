class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int answer = 0;
        for(int j = 0; j < 32; ++j){
            int p = 1 << j;
            int block1 = m / p;
            int block2 = n / p;
            if(block1 == block2){
                answer += (p & n);
            }
        }
        return answer;
    }
};