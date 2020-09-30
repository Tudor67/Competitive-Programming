class Solution {
private:
    vector<int> indicesToValues(const vector<int>& INDICES, const vector<int>& NUMS){
        vector<int> values(INDICES.size());
        for(int i = 0; i < INDICES.size(); ++i){
            values[i] = NUMS[INDICES[i]];
        }
        return values;
    }
    
    void twoSum(const vector<int>& NUMS, const int& K, int currentSum, const int& TARGET, vector<int>& currentTuple, vector<vector<int>>& answer){
        int startPos = (currentTuple.empty() ? 0 : currentTuple.back() + 1);
        int low = startPos;
        int high = (int)NUMS.size() - 1;
        while(low < high){
            if(currentSum + NUMS[low] + NUMS[high] < TARGET){
                low += 1;
            }else if(currentSum + NUMS[low] + NUMS[high] > TARGET){
                high -= 1;
            }else{
                vector<int> values = indicesToValues(currentTuple, NUMS);
                values.resize(K);
                values[K - 2] = NUMS[low];
                values[K - 1] = NUMS[high];
                // avoid duplicates
                if(answer.empty() || answer.back() != values){
                    answer.push_back(values);
                }
                low += 1;
                high -= 1;
            }
        }
    }
    
    void kSum(const vector<int>& NUMS, const int& K, int currentSum, const int& TARGET, vector<int>& currentTuple, vector<vector<int>>& answer){
        if(currentTuple.size() == K - 2){
            twoSum(NUMS, K, currentSum, TARGET, currentTuple, answer);
        }else if(currentTuple.size() < K - 2){
            int startPos = (currentTuple.empty() ? 0 : currentTuple.back() + 1);
            for(int i = startPos; i < NUMS.size(); ++i){
                // avoid duplicates
                if(i == startPos || NUMS[i - 1] != NUMS[i]){
                    currentTuple.push_back(i);
                    kSum(NUMS, K, currentSum + NUMS[i], TARGET, currentTuple, answer);
                    currentTuple.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> currentTuple;
        kSum(nums, 4, 0, target, currentTuple, answer);
        return answer;
    }
};