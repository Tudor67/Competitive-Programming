class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dist;
        for(const string& WORD: wordList){
            dist[WORD] = 0;
        }
        
        if(dist.count(endWord)){
            queue<string> q;
            q.push(beginWord);
            dist[beginWord] = 1;
            while(!q.empty() && dist[endWord] == 0){
                string word = q.front();
                q.pop();
                string nextWord = word;
                for(int i = 0; i < nextWord.length(); ++i){
                    for(int c = 'a'; c <= 'z'; ++c){
                        nextWord[i] = c;
                        if(dist.count(nextWord) && dist[nextWord] == 0){
                            q.push(nextWord);
                            dist[nextWord] = 1 + dist[word];
                        }
                    }
                    nextWord[i] = word[i];
                }
            }
        }
        
        return dist[endWord];
    }
};