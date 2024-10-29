class Solution {
public:
    string minimizeStringValue(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> f(A);
        for(char c: s){
            if(c != '?'){
                f[c - 'a'] += 1;
            }
        }

        string newChars;
        for(char c: s){
            if(c == '?'){
                int i = min_element(f.begin(), f.end()) - f.begin();
                c = char('a' + i);
                f[c - 'a'] += 1;
                newChars.push_back(c);
            }
        }

        sort(newChars.rbegin(), newChars.rend());

        for(char& c: s){
            if(c == '?'){
                c = newChars.back();
                newChars.pop_back();
            }
        }

        return s;
    }
};