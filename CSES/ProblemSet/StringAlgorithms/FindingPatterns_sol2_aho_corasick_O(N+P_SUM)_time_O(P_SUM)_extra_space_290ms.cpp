#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
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
    }

    void insertAllWords(const vector<string>& WORDS){
        for(const string& WORD: WORDS){
            insert(WORD);
        }
    }

    void createSuffixLinks(stack<Trie*>& bfsNodes){
        Trie* root = this;
        queue<Trie*> q;
        q.push(root);

        while(!q.empty()){
            Trie* node = q.front();
            q.pop();

            bfsNodes.push(node);

            for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
                if(node->children[edgeID]){
                    Trie* x = node->suffixLink;
                    while(x != NULL && x->children[edgeID] == NULL){
                        x = x->suffixLink;
                    }
                    if(x == NULL){
                        node->children[edgeID]->suffixLink = root;
                    }else{
                        node->children[edgeID]->suffixLink = x->children[edgeID];
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
            node->isMatchNode = true;
        }
    }

    void updateAllMatches(stack<Trie*>& bfsNodes){
        while(!bfsNodes.empty()){
            Trie* node = bfsNodes.top();
            bfsNodes.pop();

            if(node->isMatchNode && node->suffixLink != NULL){
                node->suffixLink->isMatchNode = true;
            }
        }
    }

    bool getMatchStatus(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return false;
            }
            node = node->children[edgeID];
        }
        return node->isMatchNode;
    }
};

class Solution{
public:
    void findPatterns(const string& S, const vector<string>& P, vector<bool>& found){
        const int N = S.length();
        const int K = P.size();

        // Aho-Corasick
        Trie trie;
        trie.insertAllWords(P);
        stack<Trie*> bfsNodes;
        trie.createSuffixLinks(bfsNodes);
        trie.matchAllWords(S);
        trie.updateAllMatches(bfsNodes);
        
        found.resize(K);
        for(int i = 0; i < K; ++i){
            found[i] = trie.getMatchStatus(P[i]);
        }
    }
};

int main(){
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> p(k);
    for(int i = 0; i < k; ++i){
        cin >> p[i];
    }

    vector<bool> found;
    Solution().findPatterns(s, p, found);

    for(int i = 0; i < k; ++i){
        if(found[i]){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}