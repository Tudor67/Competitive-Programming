class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        for(int i = n - 1; i >= 0 && k > 0; --i){
            int delta = min(25, k);
            s[i] += delta;
            k -= delta;
        }
        return s;
    }
};