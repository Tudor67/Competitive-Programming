class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    bool isTerminalNode;
    int wordIdx;
    vector<Trie*> children;
    
    static bool isPalindrome(const string& WORD, const int& START_IDX){
        for(int i = START_IDX, j = (int)WORD.length() - 1; i < j; ++i, --j){
            if(WORD[i] != WORD[j]){
                return false;
            }
        }
        return true;
    }
    
    static void addPalindromePairs(Trie* node, string& trieWord, const int& WORD_IDX, vector<vector<int>>& answer){
        for(char c = FIRST_ELEM; c < FIRST_ELEM + ALPHABET_SIZE; ++c){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] != NULL){
                trieWord.push_back(c);
                if(node->children[edgeID]->isTerminalNode){
                    if(isPalindrome(trieWord, 0) && WORD_IDX != node->children[edgeID]->wordIdx){
                        answer.push_back({WORD_IDX, node->children[edgeID]->wordIdx});
                    }
                }
                addPalindromePairs(node->children[edgeID], trieWord, WORD_IDX, answer);
                trieWord.pop_back();
            }
        }
    }
    
public:
    Trie(){
        isTerminalNode = false;
        wordIdx = -1;
        children.resize(ALPHABET_SIZE, NULL);
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
        node->isTerminalNode = true;
        node->wordIdx = WORD_IDX;
    }
    
    void addPalindromePairs(const string& WORD, const int& WORD_IDX, vector<vector<int>>& answer){
        Trie* node = this;
        
        // Case 1
        // particular case (WORD + "")
        // we need only to check if WORD is palindrome
        if(node->isTerminalNode){
            if(isPalindrome(WORD, 0) && WORD_IDX != node->wordIdx){
                answer.push_back({WORD_IDX, node->wordIdx});
            }
        }
        
        // Case 2
        // consume prefix of WORD
        // if the prefix matches a reversed word from trie and the remaining part of WORD is a palindrome
        // then this is a valid pair
        for(int i = 0; i < (int)WORD.length(); ++i){
            char c = WORD[i];
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return;
            }
            node = node->children[edgeID];
            if(node->isTerminalNode){
                if(isPalindrome(WORD, i + 1) && WORD_IDX != node->wordIdx){
                    answer.push_back({WORD_IDX, node->wordIdx});
                }
            }
        }
        
        // Case 3
        // WORD is consumed
        // we need to check if the remaining parts of the reversed words (from trie) are palindromes
        // (i.e., all reversed words starting from the current node)
        string trieWord;
        addPalindromePairs(node, trieWord, WORD_IDX, answer);
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int N = words.size();
        
        Trie trie;
        for(int i = 0; i < N; ++i){
            string revWord(words[i].rbegin(), words[i].rend());
            trie.insert(revWord, i);
        }
        
        vector<vector<int>> answer;
        for(int i = 0; i < N; ++i){
            trie.addPalindromePairs(words[i], i, answer);
        }
        
        return answer;
    }
};