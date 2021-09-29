class Trie{
private:
    static const int ALPHABET_SIZE = 26 + 3;
    static const char FIRST_ELEM = 'a';
    
    static int getEdgeID(char c){
        if(isalpha(c)){
            return c - FIRST_ELEM;
        }else if(c == '.'){
            return ALPHABET_SIZE - 3;
        }else if(c == '+'){
            return ALPHABET_SIZE - 2;
        }else if(c == '@'){
            return ALPHABET_SIZE - 1;
        }
        return -1;
    }
    
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    bool insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = getEdgeID(c);
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        bool isNewWord = !node->isTerminalNode;
        node->isTerminalNode = true;
        return isNewWord;
    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        Trie trie;
        int uniqueEmailsCount = 0;
        for(const string& ORIGINAL_EMAIL: emails){
            string email;
            bool isDomainName = false;
            bool visitedPlus = false;
            for(char c: ORIGINAL_EMAIL){
                isDomainName |= (c == '@');
                visitedPlus |= (c == '+');
                if(isDomainName || (!visitedPlus && c != '.')){
                    email += c;
                }
            }
            uniqueEmailsCount += trie.insert(email);
        }
        return uniqueEmailsCount;
    }
};