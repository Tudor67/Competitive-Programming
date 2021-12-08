#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int matchCount;
    Trie* suffixLink;
    Trie* children[ALPHABET_SIZE];

public:
    Trie(){
        matchCount = 0;
        suffixLink = NULL;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    Trie* insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        return node;
    }

    void createSuffixLinks(stack<Trie*>& suffixLinksStack){
        Trie* root = this;
        queue<Trie*> q;
        q.push(root);

        while(!q.empty()){
            Trie* node = q.front();
            q.pop();

            suffixLinksStack.push(node);

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
                    q.push(node->children[edgeID]);
                }
            }
        }
    }

    void matchAllWords(const string& TEXT){
        Trie* root = this;
        Trie* node = root;
        for(char c: TEXT){
            int edgeID = c - FIRST_ELEM;
            while(node != NULL && node->children[edgeID] == NULL){
                node = node->suffixLink;
            }
            if(node == NULL){
                node = root;
            }else{
                node = node->children[edgeID];
            }
            node->matchCount += 1;
        }
    }

    void collectMatchCounts(stack<Trie*> suffixLinksStack){
        while(!suffixLinksStack.empty()){
            Trie* node = suffixLinksStack.top();
            suffixLinksStack.pop();
 
            if(node->suffixLink != NULL){
                node->suffixLink->matchCount += node->matchCount;
            }
        }
    }

    int getMatchCount(){
        return matchCount;
    }
};

int main(){
    ifstream cin("ahocorasick.in");
    ofstream cout("ahocorasick.out");

    string s;
    cin >> s;

    int n;
    cin >> n;

    Trie trie;
    string word;
    vector<Trie*> wordsTerminalNodes(n);
    for(int i = 0; i < n; ++i){
        cin >> word;
        wordsTerminalNodes[i] = trie.insert(word);
    }

    stack<Trie*> suffixLinksStack;
    trie.createSuffixLinks(suffixLinksStack);
    trie.matchAllWords(s);
    trie.collectMatchCounts(suffixLinksStack);

    for(int i = 0; i < n; ++i){
        cout << wordsTerminalNodes[i]->getMatchCount() << "\n";
    }

    cin.close();
    cout.close();
    return 0;
}