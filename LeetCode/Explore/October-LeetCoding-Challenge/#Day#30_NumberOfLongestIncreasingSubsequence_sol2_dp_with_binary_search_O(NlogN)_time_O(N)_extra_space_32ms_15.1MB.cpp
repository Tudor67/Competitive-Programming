class Solution {
private:
    static bool lessBackComp(const vector<int>& SEQ, const int& VAL){
        return (SEQ.back() < VAL);
    }
    
public:
    int findNumberOfLIS(vector<int>& nums) {
        // ------------------------------------------------------------------------
        // decSequences[i].back() - the minimum num which is the end of an increasing subsequence of length i;
        //                        - these values are updated at each step (when iterating through nums from left to right);
        // decSequences.size() is the length of longest increasing subsequence;
        // ------------------------------------------------------------------------
        // cumFreq[i].back() - the number of increasing subsequences of length i;
        //                   - these values are updated at each step (when iterating through nums from left to right);
        // cumFreq.back().back() is the number of longest increasing subsequences;
        // ------------------------------------------------------------------------
        vector<vector<int>> decSequences;
        vector<vector<int>> cumFreq;
        for(int num: nums){
            int seqIdx = lower_bound(decSequences.begin(), decSequences.end(), num, lessBackComp) - decSequences.begin();
            if(seqIdx >= decSequences.size()){
                decSequences.resize(seqIdx + 1);
                cumFreq.resize(seqIdx + 1);
                cumFreq[seqIdx].push_back(0);
            }
            
            decSequences[seqIdx].push_back(num);
            
            if(seqIdx - 1 >= 0){
                const vector<int>& v = decSequences[seqIdx - 1];
                int pos = upper_bound(v.begin(), v.end(), num, greater<int>()) - v.begin();
                int freq = cumFreq[seqIdx - 1].back() - cumFreq[seqIdx - 1][pos];
                cumFreq[seqIdx].push_back(cumFreq[seqIdx].back() + freq);
            }else{
                cumFreq[seqIdx].push_back(cumFreq[seqIdx].back() + 1);
            }
        }
        
        return cumFreq.back().back();
    }
};