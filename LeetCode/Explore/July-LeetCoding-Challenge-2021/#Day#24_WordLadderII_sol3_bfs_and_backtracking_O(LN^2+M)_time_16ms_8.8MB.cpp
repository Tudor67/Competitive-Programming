class Solution {
private:
    int hammingDistance(const string& S1, const string& S2){
        assert(S1.length() == S2.length());
        const int L = S1.length();
        int dist = 0;
        for(int i = 0; i < L; ++i){
            dist += (S1[i] != S2[i]);
        }
        return dist;
    }
    
    void back(int node, vector<vector<int>>& prevNodes, vector<string>& wordList,
              vector<vector<int>>& g, vector<int>& st, vector<vector<string>>& seq){
        if(prevNodes[node].empty()){
            if((int)st.size() >= 2){
                seq.push_back({});
                for(int i = (int)st.size() - 1; i >= 0; --i){
                    seq.back().push_back(wordList[st[i]]);
                }
            }
        }else{
            for(int nextNode: prevNodes[node]){
                st.push_back(nextNode);
                back(nextNode, prevNodes, wordList, g, st, seq);
                st.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return {};
        }
        
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()){
            wordList.push_back(beginWord);
        }
        
        // wordToNode
        const int N = wordList.size();
        unordered_map<string, int> wordToNode;
        for(int i = 0; i < N; ++i){
            wordToNode[wordList[i]] = i;
        }
        
        // graph
        vector<vector<int>> g(N);
        for(int node = 0; node < N; ++node){
            for(int nextNode = 0; nextNode < N; ++nextNode){
                if(hammingDistance(wordList[node], wordList[nextNode]) == 1){
                    g[node].push_back(nextNode);
                }
            }
        }
        
        // bfs
        const int INF = 1e8;
        vector<int> dist(N, INF);
        vector<vector<int>> prevNodes(N);
        queue<int> q;
        q.push(wordToNode[beginWord]);
        dist[wordToNode[beginWord]] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: g[node]){
                if(dist[nextNode] == INF){
                    q.push(nextNode);
                }
                if(dist[node] + 1 <= dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    prevNodes[nextNode].push_back(node);
                }
            }
        }
        
        // seq
        vector<vector<string>> seq;
        vector<int> st = {wordToNode[endWord]};
        back(wordToNode[endWord], prevNodes, wordList, g, st, seq);
        
        return seq;
    }
};