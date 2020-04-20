class Solution {
private:
    // words
    string begin_word;
    string end_word;
    vector<string> word_list_ext; // word_list_ext = [begin_word] + word_list;
    vector<int> st;
    
    // graph
    int src;
    int dest;
    vector<int> dist;
    vector<vector<int>> prev;
    vector<vector<int>> graph;
    
    // solution
    vector<vector<string>> ans;
    
    void create_graph(){
        int n = word_list_ext.size();
        graph.resize(n, vector<int>());
        
        src = 0;
        dest = -1;
        for(int i = 1; i < word_list_ext.size(); ++i){
            if(word_list_ext[i] == end_word){
                dest = i;
            }
        }
        
        for(int i = 0; i <= n - 1; ++i){
            for(int j = i + 1; j <= n - 1; ++j){
                if(hamming_distance(word_list_ext[i], word_list_ext[j]) == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
    
    void bfs(){
        queue<int> q;
        dist.resize(graph.size());
        prev.resize(graph.size());
        
        fill(dist.begin(), dist.end(), -1);
        for(int i = 0; i < prev.size(); ++i){
            prev[i].resize(0);
        }
        
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int next_node: graph[node]){
                if(dist[next_node] == -1){
                    dist[next_node] = dist[node] + 1;
                    q.push(next_node);
                }
                if(dist[node] + 1 == dist[next_node]){
                    prev[next_node].push_back(node);
                }
            }
        }
    }
    
    int hamming_distance(const string& s1, const string& s2){
        int dist = 0;
        for(int i = 0; i < min(s1.size(), s2.size()); ++i){
            dist += (s1[i] != s2[i]);
        }
        return dist;
    }
    
    void back(int node){
        if(node == src){
            ans.push_back({});
            for(int i = 0; i <= dist[dest]; ++i){
                ans.back().push_back(word_list_ext[st[i]]);
            }
        }else{
            for(int prev_node: prev[node]){
                st[dist[prev_node]] = prev_node;
                back(prev_node);
            }
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->begin_word = beginWord;
        this->end_word = endWord;
        this->word_list_ext = wordList;
        this->word_list_ext.push_back(wordList.front());
        this->word_list_ext[0] = beginWord;
        this->st.resize(word_list_ext.size());
        this->ans.clear();
        
        create_graph();
        if(dest != -1){
            bfs();
        }
        
        if(dest != -1 && dist[dest] != -1){
            st[dist[dest]] = dest;
            back(dest);
        }else{
            ans = {};
        }
        
        return ans;
    }
};