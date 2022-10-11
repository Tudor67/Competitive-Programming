class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int count;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        count = 0;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void add(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->count += 1;
        }
    }
    
    int countAllPrefixes(const string& WORD){
        Trie* node = this;
        int totalCount = 0;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                break;
            }
            node = node->children[edgeID];
            totalCount += node->count;
        }
        return totalCount;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const int N = words.size();
        
        Trie trie;
        for(int i = 0; i < N; ++i){
            trie.add(words[i]);
        }
        
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            answer[i] = trie.countAllPrefixes(words[i]);
        }
        
        return answer;
    }
};