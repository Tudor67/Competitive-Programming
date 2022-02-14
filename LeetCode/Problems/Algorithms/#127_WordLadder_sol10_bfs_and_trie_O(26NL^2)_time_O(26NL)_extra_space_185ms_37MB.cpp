class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int wordIdx;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        wordIdx = -1;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD, const int& WORD_IDX){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->wordIdx = WORD_IDX;
    }
    
    int getWordIdx(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return -1;
            }
            node = node->children[edgeID];
        }
        return node->wordIdx;
    }
};

class Solution {
private:
    void addEdges(const string& WORD, Trie& trie, vector<vector<int>>& g){
        const int L = WORD.length();
        const int WORD_IDX = trie.getWordIdx(WORD);
        string nextWord = WORD;
        for(int j = 0; j < L; ++j){
            for(char c = 'a'; c <= 'z'; ++c){
                nextWord[j] = c;
                int nextWordIdx = trie.getWordIdx(nextWord);
                if(nextWordIdx >= 0){
                    g[WORD_IDX].push_back(nextWordIdx);
                    g[nextWordIdx].push_back(WORD_IDX);
                }
            }
            nextWord[j] = WORD[j];
        }
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        const int N = wordList.size();
        const int L = beginWord.length();
        const int INF = 1e9;
        
        Trie trie;
        for(int i = 0; i < N; ++i){
            trie.insert(wordList[i], i);
        }
        
        vector<vector<int>> g(N + 1);
        if(trie.getWordIdx(beginWord) < 0){
            trie.insert(beginWord, N);
            addEdges(beginWord, trie, g);
        }
        
        for(const string& WORD: wordList){
            addEdges(WORD, trie, g);
        }
        
        vector<int> dist(N + 1, INF);
        queue<int> q;
        q.push(trie.getWordIdx(beginWord));
        dist[trie.getWordIdx(beginWord)] = 0;
        
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
        
        int answer = dist[trie.getWordIdx(endWord)] + 1;
        if(answer >= INF){
            answer = 0;
        }
        
        return answer;
    }
};