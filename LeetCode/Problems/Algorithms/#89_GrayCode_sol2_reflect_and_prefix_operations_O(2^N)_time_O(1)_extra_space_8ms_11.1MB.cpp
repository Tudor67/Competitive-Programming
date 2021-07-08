class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> grayCodes(1 << n);
        for(int step = 1; step <= n; ++step){
            int size = 1 << step;
            for(int i = size / 2 - 1, j = size / 2; j < size; --i, ++j){
                grayCodes[j] = grayCodes[i] | (1 << (step - 1));
            }
        }
        return grayCodes;
    }
};

/*
n = 1     n = 2     n = 3
0           00       000
1           01       001
            11       011
            10       010
                     110
                     111
                     101
                     100
*/