class Solution {
public:
    string oddString(vector<string>& words) {
        const int N = words.size();
        const int L = words[0].length();
        
        map<int, vector<int>> indices;
        for(int j = 0; j + 1 < L; ++j){
            indices.clear();
            for(int i = 0; i < N; ++i){
                int diff = words[i][j + 1] - words[i][j];
                if((int)indices[diff].size() < 2){
                    indices[diff].push_back(i);
                }
            }
            
            if((int)indices.size() == 2){
                if((int)indices.begin()->second.size() == 1){
                    return words[indices.begin()->second.back()];
                }else{
                    return words[indices.rbegin()->second.back()];
                }
            }
        }
        
        return "";
    }
};