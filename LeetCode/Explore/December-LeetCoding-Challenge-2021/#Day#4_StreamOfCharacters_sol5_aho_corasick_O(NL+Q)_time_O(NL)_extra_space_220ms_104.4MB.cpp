class Trie{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    bool isMatchNode;
    Trie* suffixLink;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isMatchNode = false;
        suffixLink = NULL;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isMatchNode = true;
    }
    
    void insertAllWords(const vector<string>& WORDS){
        for(const string& WORD: WORDS){
            insert(WORD);
        }
    }
    
    void createSuffixLinks(){
        Trie* root = this;
        queue<Trie*> q;
        q.push(root);
        
        while(!q.empty()){
            Trie* node = q.front();
            q.pop();
            
            for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
                if(node->children[edgeID] != NULL){
                    Trie* tempNode = node->suffixLink;
                    while(tempNode != NULL && tempNode->children[edgeID] == NULL){
                        tempNode = tempNode->suffixLink;
                    }
                    if(tempNode == NULL){
                        node->children[edgeID]->suffixLink = root;
                    }else{
                        node->children[edgeID]->suffixLink = tempNode->children[edgeID];
                    }
                    node->children[edgeID]->isMatchNode |= node->children[edgeID]->suffixLink->isMatchNode;
                    q.push(node->children[edgeID]);
                }
            }
        }
    }
    
    static Trie* getNextState(Trie* node, char letter, Trie* root){
        int edgeID = letter - FIRST_ELEM;
        while(node != NULL && node->children[edgeID] == NULL){
            node = node->suffixLink;
        }
        if(node == NULL){
            node = root;
        }else{
            node = node->children[edgeID];
        }
        return node;
    }
};

class StreamChecker {
private:
    Trie trieRoot;
    Trie* currentNode;
    
public:
    StreamChecker(vector<string>& words) {
        trieRoot.insertAllWords(words);
        trieRoot.createSuffixLinks();
        currentNode = &trieRoot;
    }
    
    bool query(char letter) {
        currentNode = Trie::getNextState(currentNode, letter, &trieRoot);
        return currentNode->isMatchNode;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

/*
✔️ **Solution 2 (Aho-Corasick)**
If you are familiar with the `Aho-Corasick` algorithm then this problem should be easy (easy to solve, difficult to implement).

**Algorithm**
1) Insert all words in `trie`;
2) For each trie node (starting from the root, nodes are traversed level by level in a BFS fashion):
    - compute the `suffix link` of the current node using the main idea from the `KMP` algorithm;
        - the `suffix link` of the current node X should point to a different node Y
        which represents the longest prefix in the trie which is also a suffix of the current node X; 
        - a prefix of a node is represented by the string formed by the chars of the path `root` -> ... -> `node`;
    - if the `suffix link` points to a match node then the current node is updated to a match node;
        - `suffix link` points to a substring of a shorter length which is also a suffix of the current string;
        - if that node is a match then the current node is also a match (because shorter suffix is included in the current string);
3) `trie` + `additional suffix links` is a finite state machine `FSM` such that:
    - each node of the trie is a state;
    - each match node/state represents a match with a word from trie/dictionary;
4) Set the current state of the `FSM` to the trie root;
5) For each letter of `query(char letter)`:
    - update the current state of `FSM`;
        - if there is an edge with label `letter` to a child node, then the current state is updated to that child;
        otherwise traverse `suffix links` to find the first node with an edge (labeled `letter` ) to a child and update the current state to that child;
    - if the current state represents a match then return true;
      otherwise return false;

**Complexity analysis**
* **Time complexity:** `O(N * AVG_LEN + Q)`
    - `O(N * AVG_LEN)` for `StreamChecker(..)` constructor;
    -  `O(Q)` for `Q` calls of `query(..)`;
        - Amortized `O(1)` for one call of `query(..)`;
* **Space complexity:** `O(N * AVG_LEN)`
    - `O(N * AVG_LEN)` for `trie`;
* Notation:
    - N = number of words;
    - AVG_LEN = average length of a word;
    - N * AVG_LEN = total size (number of chars) of the words;
    - Q = number of queries.
*/