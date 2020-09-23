class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string lastWord;
        while(ss >> lastWord);
        return lastWord.length();
    }
};