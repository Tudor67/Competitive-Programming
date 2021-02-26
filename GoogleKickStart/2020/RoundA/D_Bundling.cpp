#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'A';
    vector<Trie*> children;
    int prefCount;

    void dfs(Trie* node, const int& K, int& contrib){
        contrib += (node->prefCount / K);
        for(short int edgeID = 0; edgeID < Trie::ALPHABET_SIZE; ++edgeID){
            if(node->children[edgeID] != NULL){
                dfs(node->children[edgeID], K, contrib);
            }
        }
    }

public:
    Trie(){
        children.resize(Trie::ALPHABET_SIZE, NULL);
        prefCount = 0;
    }

    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            short int edgeID = c - Trie::FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node->children[edgeID]->prefCount += 1;
            node = node->children[edgeID];
        }
    }

    int prefContrib(const int& K){
        int contrib = 0;
        dfs(this, K, contrib);
        return contrib;
    }
};

void solve(const int& TEST_CASE, istream& cin, ostream& cout){
    int N, K;
    cin >> N >> K;

    Trie trie;
    for(int i = 0; i < N; ++i){
        string s;
        cin >> s;
        trie.insert(s);
    }

    cout << "Case #" << TEST_CASE << ": " << trie.prefContrib(K) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        solve(testCase, cin, cout);
    }

    return 0;
}