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
        queue<pair<int, int>> q;
        vector<bool> vis(wordList.size(), false);
        
        for(int i = 0; i < wordList.size(); ++i){
            if(hamming_distance(beginWord, wordList[i]) == 1){
                q.push({i, 1});
                vis[i] = true;
            }
        }
        
        int answer = 0;
        while(!q.empty()){
            int idx = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(wordList[idx] == endWord){
                answer = dist + 1;
                break;
            }
            
            for(int i = 0; i < wordList.size(); ++i){
                if(!vis[i] && hamming_distance(wordList[idx], wordList[i]) == 1){
                    q.push({i, dist + 1});
                    vis[i] = true;
                }
            }
        }
        
        return answer;
    }
};