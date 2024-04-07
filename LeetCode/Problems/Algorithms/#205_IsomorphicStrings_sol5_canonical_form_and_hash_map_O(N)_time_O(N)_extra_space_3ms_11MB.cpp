class Solution {
private:
    string getCanonicalForm(string s){
        string canonicalForm;

        unordered_map<char, char> oldCharToNewChar;
        char newChar = 'a';
        for(char c: s){
            if(!oldCharToNewChar.count(c)){
                oldCharToNewChar[c] = newChar;
                newChar += 1;
            }
            canonicalForm += oldCharToNewChar[c];
        }

        return canonicalForm;
    }

public:
    bool isIsomorphic(string s, string t) {
        return (getCanonicalForm(s) == getCanonicalForm(t));
    }
};