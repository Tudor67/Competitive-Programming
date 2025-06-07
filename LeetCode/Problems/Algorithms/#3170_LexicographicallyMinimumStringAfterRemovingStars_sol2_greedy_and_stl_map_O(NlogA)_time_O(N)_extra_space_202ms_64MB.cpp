class Solution {
public:
    string clearStars(string s) {
        const int N = s.length();

        map<char, int> freq;
        unordered_map<char, vector<int>> indices;
        vector<bool> isRemoved(N, false);

        for(int i = 0; i < N; ++i){
            if(s[i] == '*'){
                char c = freq.begin()->first;
                freq[c] -= 1;
                isRemoved[i] = true;
                isRemoved[indices[c].back()] = true;
                indices[c].pop_back();
                if(freq[c] == 0){
                    freq.erase(c);
                }
            }else{
                freq[s[i]] += 1;
                indices[s[i]].push_back(i);
            }
        }

        string res;
        for(int i = 0; i < N; ++i){
            if(!isRemoved[i]){
                res += s[i];
            }
        }
        
        return res;
    }
};