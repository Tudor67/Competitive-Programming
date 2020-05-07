class Solution {
private:
    bool is_valid_edge(const string& s1, const string& s2){
        int dist = 0;
        for(int i = 0; i < s1.length(); ++i){
            dist += (s1[i] != s2[i]);
            if(dist > 1){
                return false;
            }
        }
        return true;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> wordListCopy = wordList;
        queue<pair<string, int>> q;
        
        int answer = 0;
        q.push({beginWord, 0});
        while(!q.empty() && answer == 0){
            string cur_word = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(int i = 0; i < wordListCopy.size(); ++i){
                if(is_valid_edge(cur_word, wordListCopy[i])){
                    if(wordListCopy[i] == endWord){
                        answer = dist + 2;
                        break;
                    }
                    q.push({wordListCopy[i], dist + 1});
                    wordListCopy[i] = wordListCopy.back();
                    wordListCopy.pop_back();
                    --i;
                }
            }
        }
        
        return answer;
    }
};