class Solution {
public:
    int minJumps(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime(MAX_NUM + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= MAX_NUM; ++i){
            if(isPrime[i]){
                for(int j = 2 * i; j <= MAX_NUM; j += i){
                    isPrime[j] = false;
                }
            }
        }

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        vector<int> dist(N, N);
        dist[0] = 0;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int i = q.front();
            q.pop();

            for(int j: {i - 1, i + 1}){
                if(0 <= j && j < N && dist[j] > dist[i] + 1){
                    dist[j] = dist[i] + 1;
                    q.push(j);
                }
            }

            if(isPrime[nums[i]] && numToIndices.contains(nums[i])){
                for(int nextNum = nums[i]; nextNum <= MAX_NUM; nextNum += nums[i]){
                    if(numToIndices.contains(nextNum)){
                        for(int j: numToIndices[nextNum]){
                            if(dist[j] > dist[i] + 1){
                                dist[j] = dist[i] + 1;
                                q.push(j);
                            }
                        }
                        numToIndices.erase(nextNum);
                    }
                }
            }
        }

        return dist[N - 1];
    }
};