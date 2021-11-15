class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    int terminalNodeCount;
    Trie* children[ALPHABET_SIZE];
    
    int countWords(Trie* node, int idx, const string& SORTED_PUZZLE, const char& FIRST_LETTER_OF_PUZZLE, bool containsFirstLetterOfPuzzle){
        if(node == NULL){
            return 0;
        }
        int count = (int)(containsFirstLetterOfPuzzle) * node->terminalNodeCount;
        for(int i = idx; i < (int)SORTED_PUZZLE.length(); ++i){
            int edgeID = SORTED_PUZZLE[i] - FIRST_ELEM;
            if(node->children[edgeID] != NULL){
                count += countWords(node->children[edgeID], i + 1, SORTED_PUZZLE, FIRST_LETTER_OF_PUZZLE,
                                    containsFirstLetterOfPuzzle | (SORTED_PUZZLE[i] == FIRST_LETTER_OF_PUZZLE));
            }
        }
        return count;
    }
    
public:
    Trie(){
        terminalNodeCount = 0;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
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
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->terminalNodeCount += 1;
    }
    
    int countWords(const string& SORTED_PUZZLE, const char& FIRST_LETTER_OF_PUZZLE){
        return countWords(this, 0, SORTED_PUZZLE, FIRST_LETTER_OF_PUZZLE, false);
    }
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        const int W = words.size();
        const int P = puzzles.size();
        
        Trie trie;
        for(string word: words){
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            trie.add(word);
        }
        
        vector<int> answer(P);
        for(int i = 0; i < P; ++i){
            string puzzle = puzzles[i];
            char firstLetterOfPuzzle = puzzles[i][0];
            sort(puzzle.begin(), puzzle.end());
            answer[i] = trie.countWords(puzzle, firstLetterOfPuzzle);
        }
        
        return answer;
    }
};