class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        const int N = arr.size();
        const int MEDIAN_IDX = (N - 1) / 2;
        
        nth_element(arr.begin(), arr.begin() + MEDIAN_IDX, arr.end());
        
        const int MEDIAN = arr[MEDIAN_IDX];
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        for(int elem: arr){
            minHeap.emplace(abs(elem - MEDIAN), elem);
            if((int)minHeap.size() == k + 1){
                minHeap.pop();
            }
        }
        
        vector<int> answer;
        while(!minHeap.empty()){
            int elem = minHeap.top().second;
            minHeap.pop();
            answer.push_back(elem);
        }
        
        return answer;
    }
};