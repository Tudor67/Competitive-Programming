long long solve(vector<int> arr) {
    const int N = arr.size();
    vector<int> left_idx(N);
    vector<int> right_idx(N);
    stack<int> st;

    // left_idx
    st.push(0);
    left_idx[0] = 0;
    for(int i = 1; i < N; ++i){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            left_idx[i] = 0;
        }else{
            left_idx[i] = st.top() + 1;
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    // right_idx
    st.push(N - 1);
    right_idx[N - 1] = 0;
    for(int i = N - 2; i >= 0; --i){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            right_idx[i] = 0;
        }else{
            right_idx[i] = st.top() + 1;
        }
        st.push(i);
    }

    long long answer = 0;
    for(int i = 1; i < N - 1; ++i){
        answer = max(1LL * left_idx[i] * right_idx[i], answer);
    }

    return answer;
}