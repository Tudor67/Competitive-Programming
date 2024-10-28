class Trie{
private:
    static const int ALPHABET_SIZE = 27;
    static const int FIRST_ELEM = 'a';
    static const int SPECIAL_ELEM = '/';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];

    static int getEdgeID(char c){
        if(c == SPECIAL_ELEM){
            return ALPHABET_SIZE - 1;
        }
        return c - FIRST_ELEM;
    }

    static char getChar(int edgeID){
        if(edgeID == ALPHABET_SIZE - 1){
            return SPECIAL_ELEM;
        }
        return char(FIRST_ELEM + edgeID);
    }

    static void collectShortestStrings(Trie* node, string& s, vector<string>& shortestStrings){
        if(node->isTerminalNode){
            shortestStrings.push_back(s.substr(0, (int)s.length() - 1));
            return;
        }
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            if(node->children[edgeID] != nullptr){
                s.push_back(getChar(edgeID));
                collectShortestStrings(node->children[edgeID], s, shortestStrings);
                s.pop_back();
            }
        }
    }

public:
    Trie(){
        isTerminalNode = false;
        fill(begin(children), end(children), nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void lazyInsert(string s){
        s.push_back(SPECIAL_ELEM);
        Trie* node = this;
        for(char c: s){
            int edgeID = getEdgeID(c);
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            if(node->isTerminalNode){
                break;
            }
        }
        node->isTerminalNode = true;
    }

    vector<string> collectShortestStrings(){
        string s;
        vector<string> shortestStrings;
        collectShortestStrings(this, s, shortestStrings);
        return shortestStrings;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        Trie trie;
        for(const string& FOLDER: folders){
            trie.lazyInsert(FOLDER);
        }
        return trie.collectShortestStrings();
    }
};