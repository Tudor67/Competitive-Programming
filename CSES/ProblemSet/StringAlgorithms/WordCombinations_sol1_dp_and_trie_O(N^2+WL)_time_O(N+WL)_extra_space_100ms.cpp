#include <bits/stdc++.h>
using namespace std;

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

    bool isTerminalNodeCheck(){
        return isTerminalNode;
    }

    Trie* getNextNode(char c){
        int edgeID = c - FIRST_ELEM;
        return children[edgeID];
    }
};

class Solution{
public:
    int countWordCombinations(string s, const vector<string>& WORDS){
        const int N = s.length();
        const int MODULO = 1e9 + 7;

        Trie* trieRoot = new Trie();
        for(const string& WORD: WORDS){
            trieRoot->reverseInsert(WORD);
        }

        s = "#" + s;

        vector<long long> dp(N + 1);
        dp[0] = 1;
        for(int i = 1; i <= N; ++i){
            Trie* node = trieRoot;
            for(int j = i; node != NULL && j >= 1; --j){
                node = node->getNextNode(s[j]);
                if(node != NULL && node->isTerminalNodeCheck()){
                    dp[i] += dp[j - 1];
                    dp[i] %= MODULO;
                }
            }
        }

        return dp[N];
    }
};

int main(){
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> words(k);
    for(int i = 0; i < k; ++i){
        cin >> words[i];
    }

    cout << Solution().countWordCombinations(s, words);

    return 0;
}