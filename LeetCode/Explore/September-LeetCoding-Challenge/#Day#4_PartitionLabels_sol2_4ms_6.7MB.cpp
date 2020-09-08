class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_pos(128);
        for(int i = 0; i < S.length(); ++i){
            last_pos[S[i]] = i;
        }
        
        vector<int> partition_sizes;
        int partition_start = 0;
        int partition_end = last_pos[S[0]];
        for(int i = 0; i < S.length(); ++i){
            partition_end = max(last_pos[S[i]], partition_end);
            if(i == partition_end){
                partition_sizes.push_back(i - partition_start + 1);
                partition_start = i + 1;
            }
        }
        
        return partition_sizes;
    }
};