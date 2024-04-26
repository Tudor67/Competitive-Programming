class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        const int N = words.size();

        vector<int> indices;
        for(int i = 0; i < N; ++i){
            if(find(words[i].begin(), words[i].end(), x) != words[i].end()){
                indices.push_back(i);
            }
        }

        return indices;
    }
};