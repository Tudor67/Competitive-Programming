#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
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
        while(!bfsNodes.empty()){
            bfsNodes.pop();
        }

        Trie* root = this;
        queue<Trie*> q;
        q.push(root);

        while(!q.empty()){
            Trie* node = q.front();
            q.pop();

            bfsNodes.push(node);

            for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
                if(node->children[edgeID] != NULL){
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
            node->matchCount += 1;
        }
    }

    void collectAllMatchCounts(stack<Trie*>& bfsNodes){
        while(!bfsNodes.empty()){
            Trie* node = bfsNodes.top();
            bfsNodes.pop();

            if(node->suffixLink != NULL){
                node->suffixLink->matchCount += node->matchCount;
            }
        }
    }

    int getMatchCount(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return 0;
            }
            node = node->children[edgeID];
        }
        return node->matchCount;
    }
};

class Solution{
public:
    void countPatterns(const string& S, const vector<string>& P, vector<int>& count){
        const int N = S.length();
        const int K = P.size();

        // Aho-Corasick
        Trie trie;
        trie.insertAllWords(P);
        stack<Trie*> bfsNodes;
        trie.createSuffixLinks(bfsNodes);
        trie.matchAllWords(S);
        trie.collectAllMatchCounts(bfsNodes);
        
        count.resize(K);
        for(int i = 0; i < K; ++i){
            count[i] = trie.getMatchCount(P[i]);
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

    vector<int> count;
    Solution().countPatterns(s, p, count);

    for(int i = 0; i < k; ++i){
        cout << count[i] << "\n";
    }

    return 0;
}