class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> cnt;
        for(int i = 0; i + 9 < s.length(); ++i){
            cnt[s.substr(i, 10)] += 1;
        }
        
        vector<string> answer;
        for(const pair<string, int>& P: cnt){
            if(P.second > 1){
                answer.push_back(P.first);
            }
        }
        
        return answer;
    }
};