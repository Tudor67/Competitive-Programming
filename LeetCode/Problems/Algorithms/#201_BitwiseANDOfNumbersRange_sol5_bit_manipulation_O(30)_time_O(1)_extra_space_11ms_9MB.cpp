class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int k = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            k += 1;
        }
        return (left << k);
    }
};