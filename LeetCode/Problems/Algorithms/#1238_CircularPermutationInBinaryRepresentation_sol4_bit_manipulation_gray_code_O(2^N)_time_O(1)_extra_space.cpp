class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        const int SIZE = (1 << n);
        vector<int> p(SIZE);
        
        int startIdx = 0;
        while((startIdx ^ (startIdx >> 1)) != start){
            startIdx += 1;
        }
        
        for(int i = 0, j = startIdx; i < SIZE; ++i, ++j){
            p[i] = (j % SIZE) ^ ((j % SIZE) >> 1);
        }
        
        return p;
    }
};