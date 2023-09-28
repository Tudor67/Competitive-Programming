class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int N = s.length();

        unordered_map<char, int> count;
        for(char c: s){
            count[c] += 1;
        }

        string res;
        for(char c: s){
            count[c] -= 1;
            if(res.find(c) != string::npos){
                continue;
            }
            while(!res.empty() && res.back() > c && count[res.back()] >= 1){
                res.pop_back();
            }
            res.push_back(c);
        }

        return res;
    }
};