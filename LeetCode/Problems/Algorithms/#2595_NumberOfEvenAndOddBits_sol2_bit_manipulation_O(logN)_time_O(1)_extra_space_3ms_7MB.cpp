class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> count(2);

        int bit = 0;
        while(n > 0){
            count[bit % 2] += (n % 2);
            bit += 1;
            n >>= 1;
        }

        return count;
    }
};