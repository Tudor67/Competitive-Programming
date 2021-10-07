class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        const int SIZE = (1 << n);
        vector<int> p(SIZE);
        for(int i = 0; i < SIZE; ++i){
            p[i] = start ^ i ^ (i >> 1);
        }
        return p;
    }
};