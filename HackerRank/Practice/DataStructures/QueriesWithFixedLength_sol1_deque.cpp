vector<int> solve(vector<int> arr, vector<int> queries) {
    const int INF = 1e9;
    const int N = arr.size();
    vector<int> answer(queries.size());

    for(int query_idx = 0; query_idx < queries.size(); ++query_idx){
        int d = queries[query_idx];
        int min_val = INF;
        
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            if(!dq.empty() && i - dq.front() + 1 > d){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i >= d - 1){
                min_val = min(arr[dq.front()], min_val);
            }
        }

        answer[query_idx] = min_val;
    }

    return answer;
}