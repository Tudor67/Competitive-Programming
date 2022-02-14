class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const int N = wordList.size();
        const int L = beginWord.length();
        const int INF = 1e9;
        
        unordered_map<string, int> dist;
        for(const string& WORD: wordList){
            dist[WORD] = INF;
        }
        
        if(!dist.count(endWord)){
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            
            string nextWord = word;
            for(int j = 0; j < L; ++j){
                for(char c = 'a'; c <= 'z'; ++c){
                    nextWord[j] = c;
                    if(dist.count(nextWord) && dist[word] + 1 < dist[nextWord]){
                        dist[nextWord] = dist[word] + 1;
                        q.push(nextWord);
                    }
                }
                nextWord[j] = word[j];
            }
        }
        
        int answer = dist[endWord] + 1;
        if(answer >= INF){
            answer = 0;
        }
        
        return answer;
    }
};