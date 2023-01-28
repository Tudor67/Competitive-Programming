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
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(!((mask >> (N - 1)) & 1)){
                continue;
            }

            bool isValid = true;
            int prevPos = -1;
            vector<string> partition;

            for(int bit = 0; bit < N && isValid; ++bit){
                if((mask >> bit) & 1){
                    if(isPalindrome(s, prevPos + 1, bit)){
                        partition.push_back(s.substr(prevPos + 1, bit - prevPos));
                    }else{
                        isValid = false;
                    }
                    prevPos = bit;
                }
            }

            if(isValid){
                res.push_back(partition);
            }
        }

        return res;
    }
};