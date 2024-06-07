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

    string wordToRoot(const string& WORD){
        string root;
        Trie* node = this;
        for(char c: WORD){
            root += c;
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                return WORD;
            }else if(node->children[edgeID]->isTerminalNode){
                return root;
            }
            node = node->children[edgeID];
        }
        return WORD;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string resSentence;

        Trie trie;
        for(const string& WORD: dictionary){
            trie.insert(WORD);
        }

        istringstream iss(sentence);
        string word;
        while(iss >> word){
            resSentence += trie.wordToRoot(word);
            resSentence += " ";
        }

        resSentence.pop_back();

        return resSentence;
    }
};