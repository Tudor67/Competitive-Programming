class Solution {
public:
    char findKthBit(int n, int k) {
        string s(1 << n, '0');

        for(int step = 2; step <= n; ++step){
            int startIndex = (1 << (step - 1)) - 1;
            s[startIndex] = '1';
            for(int i = startIndex - 1, j = startIndex + 1; i >= 0; --i, ++j){
                s[j] = s[i] ^ 1;
            }
        }

        return s[k - 1];
    }
};