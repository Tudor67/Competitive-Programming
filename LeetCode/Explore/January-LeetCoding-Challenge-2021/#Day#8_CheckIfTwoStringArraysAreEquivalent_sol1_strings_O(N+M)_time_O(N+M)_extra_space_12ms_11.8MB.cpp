class Solution {
private:
    string vec2str(const vector<string>& V){
        string s;
        for(int i = 0; i < V.size(); ++i){
            s += V[i];
        }
        return s;
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return vec2str(word1) == vec2str(word2);
    }
};