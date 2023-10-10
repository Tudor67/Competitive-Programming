class Solution {
public:
    string reverseWords(string s) {
        string revWords;

        istringstream iss(s);
        string word;
        while(iss >> word){
            if(!revWords.empty()){
                revWords += ' ';
            }
            revWords.append(word.rbegin(), word.rend());
        }

        return revWords;
    }
};