class Solution {
private:
    void back(int startPos, vector<pair<int, int>>& st, vector<pair<int, int>>& numsIndices, vector<vector<int>>& incSubsequences){
        if((int)st.size() >= 2){
            incSubsequences.push_back(vector<int>(st.size()));
            for(int i = 0; i < (int)st.size(); ++i){
                incSubsequences.back()[i] = st[i].first;
            }
        }
        
        int prevValidNum = INT_MIN;
        for(int pos = startPos; pos < (int)numsIndices.size(); ++pos){
            if(prevValidNum == numsIndices[pos].first){
                // avoid possible duplicates
                continue;
            }
            if(st.empty() || st.back().second < numsIndices[pos].second){
                st.push_back(numsIndices[pos]);
                back(pos + 1, st, numsIndices, incSubsequences);
                st.pop_back();
                prevValidNum = numsIndices[pos].first;
            }
        }
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int N = nums.size();
        
        vector<pair<int, int>> numsIndices(N);
        for(int i = 0; i < N; ++i){
            numsIndices[i] = {nums[i], i};
        }
        
        sort(numsIndices.begin(), numsIndices.end());
        
        vector<pair<int, int>> st;
        vector<vector<int>> incSubsequences;
        back(0, st, numsIndices, incSubsequences);
        
        return incSubsequences;
    }
};