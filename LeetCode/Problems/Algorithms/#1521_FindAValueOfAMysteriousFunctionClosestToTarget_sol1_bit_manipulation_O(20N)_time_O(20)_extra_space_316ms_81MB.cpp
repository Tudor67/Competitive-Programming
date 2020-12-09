class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int answer = INT_MAX;
        deque<int> dq;
        for(int i = (int)arr.size() - 1; i >= 0; --i){
            dq.push_back(arr[i]);
            int rangeAND = arr[i];
            answer = min(abs(arr[i] - target), answer);
            for(int prevSize = (int)dq.size() - 1; prevSize >= 1; --prevSize){
                rangeAND &= dq.front();
                dq.pop_front();
                if(rangeAND != dq.back()){
                    dq.push_back(rangeAND);
                }
                answer = min(abs(rangeAND - target), answer);
            }
        }
        return answer;
    }
};