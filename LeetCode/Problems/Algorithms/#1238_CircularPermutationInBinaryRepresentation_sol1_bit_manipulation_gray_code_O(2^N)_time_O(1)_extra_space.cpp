class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> p(1 << n);
        for(int i = 1; i <= n; ++i){
            int size = (1 << (i - 1));
            copy(p.begin(), p.begin() + size, p.begin() + size);
            reverse(p.begin() + size, p.begin() + 2 * size);
            for(int j = size; j < 2 * size; ++j){
                p[j] = p[j] | (1 << (i - 1));
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