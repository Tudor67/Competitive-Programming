class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;

        int bit = 0;
        for(string s = bitset<30>(n - 1).to_string(); !s.empty(); s.pop_back()){
            while(x & 1){
                x >>= 1;
                bit += 1;
            }
            if(s.back() == '1'){
                res |= (1LL << bit);
            }
            x >>= 1;
            bit += 1;
        }

        return res;
    }
};