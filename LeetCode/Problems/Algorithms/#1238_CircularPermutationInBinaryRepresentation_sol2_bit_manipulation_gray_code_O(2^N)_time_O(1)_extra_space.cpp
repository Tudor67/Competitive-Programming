class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> p(1 << n);
        for(int step = 1; step <= n; ++step){
            int size = (1 << (step - 1));
            for(int i = size - 1, j = size; j < 2 * size; --i, ++j){
                p[j] = p[i] | (1 << (step - 1));
            }
        }
        for(int j = 0; j < (int)p.size(); ++j){
            if(p[j] == start){
                reverse(p.begin(), p.end());
                reverse(p.begin(), p.end() - j);
                reverse(p.end() - j, p.end());
                break;
            }
        }
        return p;
    }
};