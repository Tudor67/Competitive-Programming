class Solution {
public:
    int maxUniqueSplit(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;
        
        int answer = 1;
        for(int mask = FULL_MASK; mask >= 1; --mask){
            unordered_set<string> substrings;
            bool isValidSplit = true;
            if(__builtin_popcount(mask) + 1 <= answer){
                continue;
            }
            for(int prevBit = -1, bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    string substring = s.substr(prevBit + 1, bit - prevBit);
                    if(substrings.count(substring)){
                        isValidSplit = false;
                        break;
                    }else{
                        substrings.insert(substring);
                        prevBit = bit;
                    }
                }
            }
            if(isValidSplit){
                answer = max((int)substrings.size(), answer);
            }
        }
        
        return answer;
    }
};