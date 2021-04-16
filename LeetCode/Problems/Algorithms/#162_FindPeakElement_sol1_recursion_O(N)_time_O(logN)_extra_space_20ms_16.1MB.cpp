class Solution {
private:
    bool isPeak(const vector<int>& NUMS, int idx){
        if(idx == 0){
            return (NUMS.size() == 1 || NUMS[idx] > NUMS[idx + 1]);
        }
        if(idx + 1 == NUMS.size()){
            return (NUMS[idx - 1] < NUMS[idx]);
        }
        return (NUMS[idx - 1] < NUMS[idx] && NUMS[idx] > NUMS[idx + 1]);
    }
    
    int getAnyPeak(const vector<int>& NUMS, const vector<int>& INDICES){
        for(int idx: INDICES){
            if(isPeak(NUMS, idx)){
                return idx;
            }
        }
        return -1;
    }
    
    void searchPeak(const vector<int>& NUMS, int l, int r, int& answer){
        if(r - l + 1 <= 0 || answer != -1){
            return;
        }
        if(r - l + 1 <= 2){
            answer = getAnyPeak(NUMS, {l, r});
            return;
        }
        int mid = (l + r) / 2;
        answer = getAnyPeak(NUMS, {l, mid, r});
        searchPeak(NUMS, l, mid, answer);
        searchPeak(NUMS, mid, r, answer);
    }
    
public:
    int findPeakElement(vector<int>& nums) {
        int answer = -1;
        searchPeak(nums, 0, (int)nums.size() - 1, answer);
        return answer;
    }
};