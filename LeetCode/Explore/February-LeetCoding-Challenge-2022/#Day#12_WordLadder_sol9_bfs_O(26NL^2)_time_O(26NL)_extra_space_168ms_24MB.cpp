class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const int N = wordList.size();
        const int L = beginWord.length();
        const int INF = 1e9;
        
        unordered_map<string, int> idxOf;
        for(int i = 0; i < N; ++i){
            idxOf[wordList[i]] = i;
        }
        
        if(!idxOf.count(beginWord)){
            idxOf[beginWord] = N;
        }
        
        if(!idxOf.count(endWord)){
            return 0;
        }
        
        vector<vector<int>> g(N + 1);
        for(const pair<string, int>& P: idxOf){
            const string& WORD = P.first;
            const int& WORD_IDX = P.second;
            
            string nextWord = WORD;
            for(int j = 0; j < L; ++j){
                for(char c = 'a'; c <= 'z'; ++c){
                    nextWord[j] = c;
                    if(idxOf.count(nextWord)){
                        int nextWordIdx = idxOf[nextWord];
                        g[WORD_IDX].push_back(nextWordIdx);
                        g[nextWordIdx].push_back(WORD_IDX);
                    }
                }
                nextWord[j] = WORD[j];
            }
        }
        
        vector<int> dist(N + 1, INF);
        queue<int> q;
        q.push(idxOf[beginWord]);
        dist[idxOf[beginWord]] = 0;
        
        while(!q.empty()){
            int wordIdx = q.front();
            q.pop();
            
            for(int nextWordIdx: g[wordIdx]){
                if(dist[wordIdx] + 1 < dist[nextWordIdx]){
                    dist[nextWordIdx] = dist[wordIdx] + 1;
                    q.push(nextWordIdx);
                }
            }
        }
        
        int answer = dist[idxOf[endWord]] + 1;
        if(answer >= INF){
            answer = 0;
        }
        
        return answer;
    }
};