class Solution {
private:
    bool isPowOf5(int num){
        while(num > 1 && num % 5 == 0){
            num /= 5;
        }
        return (num == 1);
    }

    int myStoi(const string& S, int firstPos, int lastPos, int base){
        int val = 0;
        for(int i = firstPos; i <= lastPos; ++i){
            val = base * val + (S[i] - '0');
        }
        return val;
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
            for(int bit = 0; bit < N && isValid; ++bit){
                if((mask >> bit) & 1){
                    if(s[prevOneBit + 1] == '0' || !isPowOf5(myStoi(s, prevOneBit + 1, bit, 2))){
                        isValid = false;
                    }
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