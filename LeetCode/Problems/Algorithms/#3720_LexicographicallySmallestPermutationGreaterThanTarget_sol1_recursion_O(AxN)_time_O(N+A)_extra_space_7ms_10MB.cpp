class Solution {
private:
    void dfs(int i, vector<int>& freq, const string& target, string& res){
        if(!res.empty() || i == (int)target.length()){
            return;
        }

        if(freq[target[i] - 'a'] > 0){
            freq[target[i] - 'a'] -= 1;
            dfs(i + 1, freq, target, res);
            freq[target[i] - 'a'] += 1;
        }

        for(char c = target[i] + 1; c <= 'z' && res.empty(); ++c){
            if(freq[c - 'a'] > 0){
                freq[c - 'a'] -= 1;

                res.append(target, 0, i);
                res.append(1, c);
                for(char remChar = 'a'; remChar <= 'z'; ++remChar){
                    res.append(freq[remChar - 'a'], remChar);
                }

                freq[c - 'a'] += 1;
            }
        }
    }

public:
    string lexGreaterPermutation(string s, string target) {
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            freq[c - 'a'] += 1;
        }

        string res;
        dfs(0, freq, target, res);

        return res;
    }
};