class Solution {
public:
    string lastNonEmptyString(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        vector<int> lastPos(A);
        for(int i = 0; i < N; ++i){
            freq[s[i] - 'a'] += 1;
            lastPos[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> v;
        for(char c = 'a'; c <= 'z'; ++c){
            v.push_back({freq[c - 'a'], -lastPos[c - 'a']});
        }

        sort(v.rbegin(), v.rend());

        string res;
        int maxFreq = v[0].first;
        for(int i = 0; i < (int)v.size() && v[i].first == maxFreq; ++i){
            res += s[-v[i].second];
        }

        return res;
    }
};