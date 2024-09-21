class Solution {
private:
    bool isVowel(char c){
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        return (VOWELS.find(c) != VOWELS.end());
    }

public:
    int findTheLongestSubstring(string s) {
        const int N = s.length();

        int maxLen = 0;
        unordered_map<int, int> firstPos;
        firstPos[0] = -1;
        int prefMask = 0;

        for(int i = 0; i < N; ++i){
            if(isVowel(s[i])){
                prefMask ^= (1 << (s[i] - 'a'));
            }

            if(firstPos.count(prefMask)){
                maxLen = max(maxLen, i - firstPos[prefMask]);
            }else{
                firstPos[prefMask] = i;
            }
        }

        return maxLen;
    }
};