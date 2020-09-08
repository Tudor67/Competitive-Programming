class Solution {
public:
    vector<int> partitionLabels(string S) {
        const int FIRST_CHAR = 'a';
        const int LAST_CHAR = 'z';
        const int ALPHABET_SIZE = 128;
        
        vector<int> S_cnt(ALPHABET_SIZE, 0);
        for(char c: S){
            S_cnt[c] += 1;
        }
        
        vector<int> P_sizes;
        vector<int> P_cnt(ALPHABET_SIZE, 0);
        int partition_start = 0;
        
        // check if the current position is the end of the current partition
        for(int i = 0; i < S.length(); ++i){
            P_cnt[S[i]] += 1;
            
            if(P_cnt[S[i]] == S_cnt[S[i]]){
                bool is_partition_end = true;
                for(char c = FIRST_CHAR; c <= LAST_CHAR; ++c){
                    if(P_cnt[c] != 0 && P_cnt[c] < S_cnt[c]){
                        is_partition_end = false;
                        break;
                    }
                }
                if(is_partition_end){
                    P_sizes.push_back(i - partition_start + 1);
                    partition_start = i + 1;
                }
            }
        }
        
        return P_sizes;
    }
};