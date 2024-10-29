class Solution {
public:
    string minimizeStringValue(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            if(c != '?'){
                freq[c - 'a'] += 1;
            }
        }

        vector<int> specialFreq(A);
        for(char c: s){
            if(c == '?'){
                int i = min_element(freq.begin(), freq.end()) - freq.begin();
                c = char('a' + i);
                freq[c - 'a'] += 1;
                specialFreq[c - 'a'] += 1;
            }
        }

        int i = 0;
        for(char& c: s){
            if(c == '?'){
                while(specialFreq[i] == 0){
                    i += 1;
                }
                c = char('a' + i);
                specialFreq[i] -= 1;
            }
        }

        return s;
    }
};