class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        const int N = reward1.size();

        int res = accumulate(reward2.begin(), reward2.end(), 0);

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < N; ++i){
            minHeap.push(reward1[i] - reward2[i]);
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            res += minHeap.top();
            minHeap.pop();
        }

        return res;
    }
};