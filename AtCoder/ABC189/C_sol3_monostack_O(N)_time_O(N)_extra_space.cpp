#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 2);
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    stack<int> st;
    st.push(0);
    A[0] = INT_MIN;

    vector<int> l(N + 1);
    for(int i = 1; i <= N; ++i){
        while(A[st.top()] >= A[i]){
            st.pop();
        }
        l[i] = st.top() + 1;
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    st.push(N + 1);
    A[N + 1] = INT_MIN;

    vector<int> r(N + 1);
    for(int i = N; i >= 1; --i){
        while(A[i] <= A[st.top()]){
            st.pop();
        }
        r[i] = st.top() - 1;
        st.push(i);
    }

    int answer = 0;
    for(int i = 1; i <= N; ++i){
        answer = max(A[i] * (r[i] - l[i] + 1), answer);
    }

    cout << answer;

    return 0;
}