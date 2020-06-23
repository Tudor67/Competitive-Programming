class Solution {
private:
    pair<bool, int> valid_position(const string& S, const int& L){
        // Case 1: empty substring
        if(L == 0){
            return {true, 0};
        }
        
        // Case 2: search duplicates of length L
        const int MOD = 666013;
        int hash = 0;
        int p = 1;
        for(int i = 0; i < L; ++i){
            hash = (26 * hash + (S[i] - 'a')) % MOD;
            if(i > 0){
                p = (26 * p) % MOD;
            }
        }
        
        unordered_map<int, vector<int>> pos;
        pos[hash] = {0};
        for(int i = L; i < S.size(); ++i){
            hash = ((hash - p * (S[i - L] - 'a')) % MOD + MOD) % MOD;
            hash = (26 * hash + (S[i] - 'a')) % MOD;
            if(pos.count(hash)){
                for(int start_position: pos[hash]){
                    bool match = true;
                    for(int j = 0; match && j < L; ++j){
                        if(S[start_position + j] != S[i - L + 1 + j]){
                            match = false;
                        }
                    }
                    if(match){
                        return {true, start_position};
                    }
                }
            }
            pos[hash].push_back(i - L + 1);
        }
        
        // Case 3: duplicates of length L not found
        return {false, -1};
    }
    
public:
    string longestDupSubstring(string S) {
        const int N = S.length();
        
        // binary search the length of duplicates
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(valid_position(S, mid).first){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        // extract the answer
        int answer_length = r;
        int answer_start_pos = valid_position(S, answer_length).second;
        string answer = S.substr(answer_start_pos, answer_length);
        
        return answer;
    }
};