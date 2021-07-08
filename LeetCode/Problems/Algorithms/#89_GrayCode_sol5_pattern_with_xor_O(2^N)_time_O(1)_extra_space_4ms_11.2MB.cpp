class Solution {
public:
    vector<int> grayCode(int n) {
        const int SIZE = (1 << n);
        vector<int> grayCodes(SIZE);
        for(int i = 0; i < SIZE; ++i){
            grayCodes[i] = i ^ (i >> 1);
        }
        return grayCodes;
    }
};