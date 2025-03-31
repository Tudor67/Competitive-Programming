class Solution {
private:
    int countDistinctPrimes(int num){
        int distinctPrimes = 0;
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                distinctPrimes += 1;
                while(num % i == 0){
                    num /= i;
                }
            }
        }

        if(num > 1){
            distinctPrimes += 1;
        }

        return distinctPrimes;
    }

    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        a %= MODULO;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            n >>= 1;
            a = (a * a) % MODULO;
        }
        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        // Step 1: compute scores
        vector<int> scores(N);
        for(int i = 0; i < N; ++i){
            scores[i] = countDistinctPrimes(nums[i]);
        }

        // Step 2: compute prevGreaterOrEqual and nextGreater for scores using monostacks
        stack<int> st;
        vector<int> nextGreater(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && scores[st.top()] < scores[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> prevGreaterOrEqual(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && scores[i] >= scores[st.top()]){
                prevGreaterOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Step 3: counting
        priority_queue<pair<int, long long>> maxHeap;
        for(int i = 0; i < N; ++i){
            long long lSize = i - prevGreaterOrEqual[i];
            long long rSize = nextGreater[i] - i;
            maxHeap.push({nums[i], lSize * rSize});
        }

        long long res = 1;
        while(!maxHeap.empty() && k > 0){
            long long num = maxHeap.top().first;
            long long numDistinctSubarrays = maxHeap.top().second;
            maxHeap.pop();

            long long take = min((long long)k, numDistinctSubarrays);
            res *= fastPow(num, take, MODULO) % MODULO;
            res %= MODULO;
            k -= take;
        }

        return res;
    }
};