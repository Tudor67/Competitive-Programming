class Solution {
private:
    bool isPowOf5(int num){
        while(num > 1 && num % 5 == 0){
            num /= 5;
        }
        return (num == 1);
    }

public:
    int minimumBeautifulSubstrings(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;

        int res = -1;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(!((mask >> (N - 1)) & 1)){
                continue;
            }

            bool isValid = true;
            int prevOneBit = -1;
            int oneBits = 0;
            int num = 0;
            for(int bit = 0; bit < N && isValid; ++bit){
                num = 2 * num + (s[bit] - '0');
                if((mask >> bit) & 1){
                    if(s[prevOneBit + 1] == '0' || !isPowOf5(num)){
                        isValid = false;
                    }
                    num = 0;
                    prevOneBit = bit;
                    oneBits += 1;
                }
            }

            if(isValid){
                if(res == -1 || res > oneBits){
                    res = oneBits;
                }
            }
        }

        return res;
    }
};