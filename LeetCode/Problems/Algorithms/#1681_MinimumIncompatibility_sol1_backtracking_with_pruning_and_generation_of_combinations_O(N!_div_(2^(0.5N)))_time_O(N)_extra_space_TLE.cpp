class Solution {
private:
    void back(int level, int startNum, vector<vector<int>>& st, const int& EXPECTED_LEVEL_ELEMS, int incompatibilitySum,
              vector<int>& count, int& answer){
        if(incompatibilitySum >= answer){
            // doesn't make sense to continue => pruning
        }else if(level == 0){
            answer = min(incompatibilitySum, answer);
        }else if(st[level].size() == EXPECTED_LEVEL_ELEMS){
            int levelMaxElem = *max_element(st[level].begin(), st[level].end());
            int levelMinElem = *min_element(st[level].begin(), st[level].end());
            back(level - 1, 1, st, EXPECTED_LEVEL_ELEMS, incompatibilitySum + levelMaxElem - levelMinElem, count, answer);
        }else{
            for(int num = startNum; num < count.size(); ++num){
                if(count[num] > 0){
                    count[num] -= 1;
                    st[level].push_back(num);
                    back(level, num + 1, st, EXPECTED_LEVEL_ELEMS, incompatibilitySum, count, answer);
                    st[level].pop_back();
                    count[num] += 1;
                }
            }
        }
    }
    
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int N = nums.size();
        const int EXPECTED_LEVEL_ELEMS = N / k;
        int answer = INT_MAX;
        if(EXPECTED_LEVEL_ELEMS == 1){
            answer = 0;
        }else{
            vector<vector<int>> st(k + 1);
            vector<int> count(N + 1, 0);
            for(int num: nums){
                count[num] += 1;
            }
            back(k, 1, st, EXPECTED_LEVEL_ELEMS, 0, count, answer);
            answer = (answer == INT_MAX ? -1 : answer);
        }
        return answer;
    }
};