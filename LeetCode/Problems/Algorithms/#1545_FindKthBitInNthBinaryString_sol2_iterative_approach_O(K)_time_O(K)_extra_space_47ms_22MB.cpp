class Solution {
public:
    char findKthBit(int n, int k) {
        string s;
        s.reserve(k);
        s.push_back('0');

        while((int)s.length() < k){
            s.push_back('1');
            for(int i = (int)s.length() - 2; i >= 0; --i){
                s.push_back(s[i] ^ 1);
            }
        }

        return s[k - 1];
    }
};