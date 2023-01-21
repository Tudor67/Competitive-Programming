class Solution {
private:
    void back(int startPos, int prevNumIndex, vector<pair<int, int>>& sortedNumsIndices, vector<int>& subseq, vector<vector<int>>& res){
        const int N = sortedNumsIndices.size();

        if((int)subseq.size() >= 2){
            res.push_back(subseq);
        }

        int prevNum = INT_MIN;
        for(int pos = startPos; pos < N; ++pos){
            if(prevNum == sortedNumsIndices[pos].first){
                // avoid duplicates
                continue;
            }
            if(prevNumIndex < sortedNumsIndices[pos].second){
                prevNum = sortedNumsIndices[pos].first;
                subseq.push_back(sortedNumsIndices[pos].first);
                back(pos + 1, sortedNumsIndices[pos].second, sortedNumsIndices, subseq, res);
                subseq.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int N = nums.size();

        vector<pair<int, int>> sortedNumsIndices(N);
        for(int i = 0; i < N; ++i){
            sortedNumsIndices[i] = {nums[i], i};
        }

        sort(sortedNumsIndices.begin(), sortedNumsIndices.end());

        vector<int> subseq;
        vector<vector<int>> res;
        back(0, -1, sortedNumsIndices, subseq, res);

        return res;
    }
};