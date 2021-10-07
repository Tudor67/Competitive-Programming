class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> p(1 << n);
        for(int j = 0; j < (int)p.size(); ++j){
            p[j] = j ^ (j >> 1);
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