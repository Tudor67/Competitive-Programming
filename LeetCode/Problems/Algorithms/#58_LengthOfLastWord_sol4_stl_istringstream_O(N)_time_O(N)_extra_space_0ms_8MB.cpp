class Solution {
public:
    int lengthOfLastWord(string s) {
        const int N = s.length();

        int lastWordLen = 0;
        
        istringstream iss(s);
        string currentWord;
        while(iss >> currentWord){
            lastWordLen = currentWord.length();
        }

        return lastWordLen;
    }
};