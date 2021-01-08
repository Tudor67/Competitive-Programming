class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int answer = 0;
        arr.push_back(2001);
        for(int i = 0; i < arr.size(); ++i){
            int missing = arr[i] - i - 1;
            if(missing >= k){
                answer = i + k;
                break;
            }
        }
        return answer;
    }
};