class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();
        vector<string> answer;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(words[j].length() > words[i].length() && words[j].find(words[i]) != string::npos){
                    answer.push_back(words[i]);
                    break;
                }
            }
        }
        return answer;
    }
};