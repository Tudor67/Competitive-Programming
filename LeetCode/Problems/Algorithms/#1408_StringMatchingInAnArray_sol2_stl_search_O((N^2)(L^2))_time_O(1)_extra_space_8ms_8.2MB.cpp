class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();
        vector<string> answer;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(words[j].length() > words[i].length()){
                    if(search(words[j].begin(), words[j].end(), words[i].begin(), words[i].end()) != words[j].end()){
                        answer.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return answer;
    }
};