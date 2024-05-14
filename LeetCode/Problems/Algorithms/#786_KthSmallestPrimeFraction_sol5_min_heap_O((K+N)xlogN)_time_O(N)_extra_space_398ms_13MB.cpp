class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int N = arr.size();

        using T3 = tuple<long double, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        for(int i = 0; i + 1 < N; ++i){
            minHeap.push({(long double)arr[i] / (long double)arr[N - 1], i, N - 1});
        }

        for(int step = 1; step <= k - 1; ++step){
            int i = get<1>(minHeap.top());
            int j = get<2>(minHeap.top());
            minHeap.pop();

            if(i < j - 1){
                minHeap.push({(long double)arr[i] / (long double)arr[j - 1], i, j - 1});
            }
        }

        return {arr[get<1>(minHeap.top())], arr[get<2>(minHeap.top())]};
    }
};