class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int answer = -1;
        if(k == 1){
            answer = accumulate(jobs.begin(), jobs.end(), 0);
        }else if(k == jobs.size()){
            answer = *max_element(jobs.begin(), jobs.end());
        }else{
            const int N = jobs.size();
            sort(jobs.begin(), jobs.end());
            priority_queue<int, vector<int>, greater<int>> minHeap;
            answer = INT_MAX;
            do{
                for(int i = N - 1; i >= N - k; --i){
                    minHeap.push(jobs[i]);
                }
                for(int i = N - k - 1; i >= 0; --i){
                    int t = minHeap.top();
                    minHeap.pop();
                    minHeap.push(t + jobs[i]);
                    if(t + jobs[i] >= answer){
                        break;
                    }
                }
                int maxTime = minHeap.top();
                while(!minHeap.empty()){
                    maxTime = max(minHeap.top(), maxTime);
                    minHeap.pop();
                }
                answer = min(maxTime, answer);
            }while(next_permutation(jobs.begin(), jobs.end()));
        }
        return answer;
    }
};