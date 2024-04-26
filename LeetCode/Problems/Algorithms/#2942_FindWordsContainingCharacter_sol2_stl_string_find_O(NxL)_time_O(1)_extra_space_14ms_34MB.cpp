class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        const int N = words.size();

        vector<int> indices;
        for(int i = 0; i < N; ++i){
            if(words[i].find(x) != string::npos){
                indices.push_back(i);
            }
        }

        return indices;
    }
};