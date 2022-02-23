class Solution {
public:
    string reverseWords(string s) {
        string res;
        string word;
        istringstream ss(s);
        while(ss >> word){
            res.append(word.rbegin(), word.rend());
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};