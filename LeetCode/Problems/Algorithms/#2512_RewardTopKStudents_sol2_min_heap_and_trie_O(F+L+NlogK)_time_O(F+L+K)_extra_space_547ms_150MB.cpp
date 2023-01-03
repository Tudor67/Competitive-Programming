class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }

    void insertAll(const vector<string>& WORDS){
        for(const string& WORD: WORDS){
            insert(WORD);
        }
    }

    bool contains(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                return false;
            }
            node = node->children[edgeID];
        }
        return node->isTerminalNode;
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        const int N = report.size();

        Trie posTrie;
        posTrie.insertAll(positive_feedback);
        
        Trie negTrie;
        negTrie.insertAll(negative_feedback);
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        for(int i = 0; i < N; ++i){
            int score = 0;
            string currentWord;
            istringstream iss(report[i]);
            while(iss >> currentWord){
                if(posTrie.contains(currentWord)){
                    score += 3;
                }else if(negTrie.contains(currentWord)){
                    score -= 1;
                }
            }

            minHeap.push({score, -student_id[i]});
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> res(k);
        for(int i = k - 1; i >= 0; --i){
            res[i] = -minHeap.top().second;
            minHeap.pop();
        }
        
        return res;
    }
};