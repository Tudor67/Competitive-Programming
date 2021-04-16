class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        const int N = arr.size();
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        
        vector<int> count(MAX_ELEM + 1, 0);
        for(int elem: arr){
            count[elem] += 1;
        }
        
        vector<int> prefCount(MAX_ELEM + 1, 0);
        for(int elem = 1; elem <= MAX_ELEM; ++elem){
            prefCount[elem] = prefCount[elem - 1] + count[elem];
        }
        
        int answer = 0;
        int answerDiff = abs(0 - target);
        
        int curSum = 0;
        for(int elem = 1; elem <= MAX_ELEM; ++elem){
            int remCount = N - prefCount[elem - 1];
            int value = elem;
            int valueDiff = abs(curSum + remCount * value - target);
            if(valueDiff < answerDiff){
                answer = value;
                answerDiff = valueDiff;
            }
            curSum += elem * count[elem];
        }
        
        return answer;
    }
};