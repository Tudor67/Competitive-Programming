class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> firstPos(A, -1);
        vector<int> lastPos(A, -1);
        for(int i = 0; i < N; ++i){
            if(firstPos[s[i] - 'a'] == -1){
                firstPos[s[i] - 'a'] = i;
            }
            lastPos[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> segments;
        for(char c = 'a'; c <= 'z'; ++c){
            if(firstPos[c - 'a'] == -1){
                continue;
            }

            int l = firstPos[c - 'a'];
            int r = lastPos[c - 'a'];
            bool isValid = true;
            for(int i = l; i <= r; ++i){
                if(firstPos[s[i] - 'a'] < l){
                    isValid = false;
                    break;
                }
                r = max(r, lastPos[s[i] - 'a']);
            }
            
            if(isValid){
                segments.push_back({l, r});
            }
        }

        sort(segments.begin(), segments.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                return (LHS.second - LHS.first < RHS.second - RHS.first);
             });

        vector<string> res;
        vector<bool> used(A, false);
        for(auto [l, r]: segments){
            bool isValid = true;
            for(int i = l; i <= r; ++i){
                if(used[s[i] - 'a']){
                    isValid = false;
                    break;
                }
            }

            if(isValid){
                res.push_back(s.substr(l, r - l + 1));
                for(int i = l; i <= r; ++i){
                    used[s[i] - 'a'] = true;
                }
            }
        }

        return res;
    }
};