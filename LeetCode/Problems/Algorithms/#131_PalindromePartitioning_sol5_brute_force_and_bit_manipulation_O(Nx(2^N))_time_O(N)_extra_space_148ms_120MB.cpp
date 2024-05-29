class Solution {
private:
    bool isPalindrome(const string& S, int l, int r){
        while(l < r){
            if(S[l] == S[r]){
                l += 1;
                r -= 1;
            }else{
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;

        vector<vector<string>> res;

        for(int mask = 0; mask <= FULL_MASK; ++mask){
            if(((mask >> (N - 1)) & 1) == 0){
                continue;
            }
            
            vector<string> p;
            bool isValid = true;
            int startBit = 0;
            for(int bit = 0; bit < N && isValid; ++bit){
                if((mask >> bit) & 1){
                    if(isPalindrome(s, startBit, bit)){
                        p.push_back(s.substr(startBit, bit - startBit + 1));
                        startBit = bit + 1;
                    }else{
                        isValid = false;
                    }
                }
            }

            if(isValid){
                res.push_back(p);
            }
        }

        return res;
    }
};