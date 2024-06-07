class Solution {
public:
    int longestPalindrome(string s) {
        const int N = s.length();

        int maxLen = 0;
        unordered_set<char> unmatchedSet;
        for(char c: s){
            if(unmatchedSet.count(c)){
                unmatchedSet.erase(c);
                maxLen += 2;
            }else{
                unmatchedSet.insert(c);
            }
        }

        return maxLen + (int)!unmatchedSet.empty();
    }
};