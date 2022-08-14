class Solution {
private:
    using Graph = vector<vector<int>>;
    
    bool isValidEdge(const string& W1, const string& W2){
        const int L = W1.length();
        int distinctLetters = 0;
        for(int i = 0; i < L; ++i){
            if(W1[i] != W2[i]){
                distinctLetters += 1;
            }
            if(distinctLetters >= 2){
                return false;
            }
        }
        return true;
    }
    
    void dfs(int node, vector<string>& st, const Graph& G, vector<string>& wordList, vector<int>& dist,
             vector<vector<string>>& res){
        if(dist[node] == 0){
            res.push_back(vector<string>(st.rbegin(), st.rend()));
        }else{
            for(int prevNode: G[node]){
                if(dist[prevNode] + 1 == dist[node]){
                    st.push_back(wordList[prevNode]);
                    dfs(prevNode, st, G, wordList, dist, res);
                    st.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Special case
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return {};
        }
        
        // Add beginWord if wordList does not contain it
        bool addedBeginWord = false;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()){
            addedBeginWord = true;
            wordList.push_back(beginWord);
        }
        
        // Create graph G where an edge from node i to node j exists
        // if and only if wordList[i] and wordList[j] differs by a single letter
        const int N = wordList.size();
        Graph G(N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(isValidEdge(wordList[i], wordList[j])){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        
        // Compute for each node its distance to beginWord
        // (BFS from beginWord to endWord)
        const int SRC = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        const int DEST = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        const int INF = 1e9;
        vector<int> dist(N, INF);
        queue<int> q;
        q.push(SRC);
        dist[SRC] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
        
        // Use recursion/backtracking to store all shortest sequences from SRC to DEST
        vector<vector<string>> res;
        if(dist[DEST] != INF){
            vector<string> st = {endWord};
            dfs(DEST, st, G, wordList, dist, res);
        }
        
        if(addedBeginWord){
            wordList.pop_back();
        }
        
        return res;
    }
};