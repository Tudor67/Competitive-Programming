class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dist1;
        unordered_map<string, int> dist2;
        for(const string& WORD: wordList){
            dist1[WORD] = 0;
            dist2[WORD] = 0;
        }
        
        if(dist1.count(endWord)){
            unordered_set<string> set1 = {beginWord};
            unordered_set<string> set2 = {endWord};
            dist1[beginWord] = 1;
            dist2[endWord] = 1;
            while(!set1.empty() && !set2.empty()){
                if(set1.size() > set2.size()){
                    swap(set1, set2);
                    swap(dist1, dist2);
                }
                unordered_set<string> nextSet;
                for(string word: set1){
                    string nextWord = word;
                    for(int i = 0; i < nextWord.length(); ++i){
                        for(int c = 'a'; c <= 'z'; ++c){
                            nextWord[i] = c;
                            if(dist2.count(nextWord) && dist2[nextWord] != 0){
                                return dist1[word] + dist2[nextWord];
                            }
                            if(dist1.count(nextWord) && dist1[nextWord] == 0){
                                nextSet.insert(nextWord);
                                dist1[nextWord] = 1 + dist1[word];
                            }
                        }
                        nextWord[i] = word[i];
                    }
                }
                set1 = move(nextSet);
            }
        }
        
        return 0;
    }
};