class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void reverseInsert(const string& WORD){
        Trie* node = this;
        for(int i = (int)WORD.length() - 1; i >= 0; --i){
            int edgeID = WORD[i] - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    bool reverseContains(const string& WORD){
        Trie* node = this;
        for(int i = (int)WORD.length() - 1; i >= 0; --i){
            int edgeID = WORD[i] - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return false;
            }
            node = node->children[edgeID];
            if(node->isTerminalNode){
                return true;
            }
        }
        return false;
    }
};

class StreamChecker {
private:
    Trie trie;
    string stream;
    
public:
    StreamChecker(vector<string>& words) {
        for(const string& WORD: words){
            trie.reverseInsert(WORD);
        }
    }
    
    bool query(char letter) {
        stream += letter;
        return trie.reverseContains(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

/*
✔️ **Solution 1 (Trie on reversed words + reversed stream)**

**Main ideas**
 - Problem 1: Checking if any suffix of a string is a word in a given dictionary is slow;
 - Problem 2: Checking if any prefix of a string is a word in a given dictionary is fast (we can use `Trie/Prefix tree` data structure);
 - Problem 1 is reduced to Problem 2 by using the following observation:
    - a suffix of string S matches a word from dictionary <=> a prefix of reversed string S matches a reversed word from dictionary;

**Algorithm**
1) Insert `reversed words` in `trie`;
2) Keep previous letters of `query(char letter)` in a string `stream`;
3) For each `query(char letter)`:
    - append letter to `stream`;
    - if any prefix of the `reversed stream` is a reversed word in the trie then return true;
      otherwise return false; 

**Complexity analysis**
* **Time complexity:** `O(N * AVG_LEN + Q * MAX_LEN)`
    - `O(N * AVG_LEN)` for `StreamChecker(..)` constructor;
    -  `O(Q * MAX_LEN)` for `Q` calls of `query(..)`;
        - `O(MAX_LEN)` for one call of `query(..)`;
* **Space complexity:** `O(N * AVG_LEN + Q)`
    - `O(N * AVG_LEN)` for `trie`;
    - `O(Q)` for `stream` buffer/string;
        - `stream` size can be reduced from Q to MAX_LEN (keep only the last MAX_LEN chars of the stream);
* Notation:
    - N = number of words;
    - AVG_LEN = average length of a word;
    - MAX_LEN = max length of a word;
    - N * AVG_LEN = total size (number of chars) of the words;
    - Q = number of queries.
*/