class Solution {
private:
    bool isEqual(const vector<int>& ARR, const int& START_POS1, const int& START_POS2, const int& FIXED_SIZE){
        for(int i = 0; i < FIXED_SIZE; ++i){
            if(ARR[i + START_POS1] != ARR[i + START_POS2]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        const int N = arr.size();
        const int TOTAL_ONES = count(arr.begin(), arr.end(), 1);
        
        vector<int> answer = {-1, -1};
        
        if(TOTAL_ONES == 0){
            answer = {0, N - 1};
        }else if(TOTAL_ONES % 3 == 0){
            /*
               1.) Fix arr[k .. N - 1]: minSuffix with TOTAL_ONES / 3 of ones (i.e., value of common subarray without leading zeros)
               2.) Check if arr is of form: [leadingZeros] minSuffix [leadingZeros] minSuffix [leadingZeros] minSuffix
                   and return indices of the corresponding parts
            */
            int k = N;
            int ones = 0;
            while(ones < TOTAL_ONES / 3){
                k -= 1;
                ones += arr[k];
            }
            
            const int MIN_SUFFIX_SIZE = N - k;
            int startPos1 = find(arr.begin(), arr.end(), 1) - arr.begin();
            int endPos1 = startPos1 + MIN_SUFFIX_SIZE;
            int startPos2 = find(arr.begin() + endPos1, arr.end(), 1) - arr.begin();
            int endPos2 = startPos2 + MIN_SUFFIX_SIZE;
            int startPos3 = k;
            
            if(endPos1 <= startPos2 && endPos2 <= startPos3){
                if(isEqual(arr, startPos1, startPos2, MIN_SUFFIX_SIZE) && isEqual(arr, startPos2, startPos3, MIN_SUFFIX_SIZE)){
                    answer = {endPos1 - 1, endPos2};
                }
            }
        }
        
        return answer;
    }
};