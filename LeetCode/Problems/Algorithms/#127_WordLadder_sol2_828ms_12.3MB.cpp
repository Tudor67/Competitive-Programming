class Solution {
private:
    int hamming_distance(const string& s1, const string& s2){
        int dist = 0;
        for(int i = 0; i < s1.length(); ++i){
            dist += (s1[i] != s2[i]);
        }
        return dist;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> wordListCopy = wordList;
        queue<pair<string, int>> q;
        
        int answer = 0;
        q.push({beginWord, 0});
        while(!q.empty()){
            string cur_word = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(cur_word == endWord){
                answer = dist + 1;
                break;
            }
            
            for(int i = 0; i < wordListCopy.size(); ++i){
                if(hamming_distance(cur_word, wordListCopy[i]) == 1){
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