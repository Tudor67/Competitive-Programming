class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();
        
        unordered_map<char, vector<int>> posOf;
        for(int i = 0; i < N; ++i){
            posOf[s[i]].push_back(i);
        }
        
        int count = 0;
        for(int i = 0; i < N; ++i){
            int j = i;
            for(char c: {'a', 'b', 'c'}){
                auto it = lower_bound(posOf[c].begin(), posOf[c].end(), i);
                if(it == posOf[c].end()){
                    j = N;
                    break;
                }else{
                    j = max(j, *it);
                }
            }
            count += (N - j);
        }
        
        return count;
    }
};