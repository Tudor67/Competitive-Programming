class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int N = s.length();

        unordered_map<char, int> minPosOf;
        unordered_map<char, int> maxPosOf;
        for(int i = 0; i < N; ++i){
            if(!minPosOf.count(s[i])){
                minPosOf[s[i]] = i;
            }
            maxPosOf[s[i]] = i;
        }

        unordered_set<string> palindromesSet;
        for(int i = 1; i + 1 < N; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(minPosOf[c] < i && i < maxPosOf[c]){
                    palindromesSet.insert(string(1, c) + string(1, s[i]) + string(1, c));
                }
            }
        }

        return palindromesSet.size();
    }
};