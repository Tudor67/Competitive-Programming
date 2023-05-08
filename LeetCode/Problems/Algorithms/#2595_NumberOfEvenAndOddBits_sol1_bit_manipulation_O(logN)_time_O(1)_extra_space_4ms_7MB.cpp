class Solution {
public:
    vector<int> evenOddBit(int n) {
        const int MAX_BIT = floor(log2(n));

        vector<int> count(2);
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if((n >> bit) & 1){
                count[bit % 2] += 1;
            }
        }

        return count;
    }
};