class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dist1;
        unordered_map<string, int> dist2;
        for(const string& WORD: wordList){
            dist1[WORD] = 0;
            dist2[WORD] = 0;
        }
        
        if(dist1.count(endWord)){
            queue<string> q1; q1.push(beginWord);
            queue<string> q2; q2.push(endWord);
            dist1[beginWord] = 1;
            dist2[endWord] = 1;
            while(!q1.empty() && !q2.empty()){
                if(q1.size() > q2.size()){
                    swap(q1, q2);
                    swap(dist1, dist2);
                }
                for(int i = q1.size(); i >= 1; --i){
                    string word = q1.front(); q1.pop();
                    string nextWord = word;
                    for(int i = 0; i < nextWord.length(); ++i){
                        for(int c = 'a'; c <= 'z'; ++c){
                            nextWord[i] = c;
                            if(dist2.count(nextWord) && dist2[nextWord] != 0){
                                return dist1[word] + dist2[nextWord];
                            }
                            if(dist1.count(nextWord) && dist1[nextWord] == 0){
                                q1.push(nextWord);
                                dist1[nextWord] = 1 + dist1[word];
                            }
                        }
                        nextWord[i] = word[i];
                    }
                }
            }
        }
        
        return 0;
    }
};