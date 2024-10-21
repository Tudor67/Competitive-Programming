class Solution {
public:
    int maxUniqueSplit(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;

        int res = 1;
        unordered_set<string> substrSet;

        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(((mask >> (N - 1)) & 1) == 0){
                continue;
            }

            bool isPossible = true;
            substrSet.clear();

            int prevPos = 0;
            for(int bit = 0; bit < N && isPossible; ++bit){
                if((mask >> bit) & 1){
                    string substr = s.substr(prevPos, bit - prevPos + 1);
                    if(substrSet.count(substr)){
                        isPossible = false;
                    }else{
                        substrSet.insert(substr);
                        prevPos = bit + 1;
                    }
                }
            }

            if(isPossible){
                res = max(res, __builtin_popcount(mask));
            }
        }

        return res;
    }
};