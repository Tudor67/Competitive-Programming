class Solution {
private:
    vector<int> computeDiff(string& s){
        const int L = s.length();
        vector<int> diff;
        for(int i = 1; i < L; ++i){
            diff.push_back(s[i] - s[i - 1]);
        }
        return diff;
    }
    
public:
    string oddString(vector<string>& words) {
        const int N = words.size();
        const int L = words[0].length();
        
        map<vector<int>, int> count;
        for(int i = 0; i < N; ++i){
            count[computeDiff(words[i])] += 1;
        }
        
        for(int i = 0; i < N; ++i){
            if(count[computeDiff(words[i])] == 1){
                return words[i];
            }
        }
        
        return "";
    }
};