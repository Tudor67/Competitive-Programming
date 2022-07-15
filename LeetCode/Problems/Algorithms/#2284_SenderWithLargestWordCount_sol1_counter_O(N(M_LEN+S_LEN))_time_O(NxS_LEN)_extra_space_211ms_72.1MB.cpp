class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        const int N = messages.size();
        
        unordered_map<string, int> wordCount;
        for(int i = 0; i < N; ++i){
            wordCount[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
        }
        
        string maxSender = senders[0];
        for(const pair<string, int>& P: wordCount){
            const string& SENDER = P.first;
            if((wordCount[SENDER] > wordCount[maxSender]) ||
               (wordCount[SENDER] == wordCount[maxSender] && SENDER > maxSender)){
                maxSender = SENDER;
            }
        }
        
        return maxSender;
    }
};