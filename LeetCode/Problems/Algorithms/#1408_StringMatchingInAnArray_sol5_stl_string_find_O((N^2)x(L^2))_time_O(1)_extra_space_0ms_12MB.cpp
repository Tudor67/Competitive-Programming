class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();

        vector<string> res;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && words[j].find(words[i]) != string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};