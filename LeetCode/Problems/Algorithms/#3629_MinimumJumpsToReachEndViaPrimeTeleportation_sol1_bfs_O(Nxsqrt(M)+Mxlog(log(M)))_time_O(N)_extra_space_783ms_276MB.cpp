class Solution {
private:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

public:
    int minJumps(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

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

            if(isPrime(nums[i]) && numToIndices.contains(nums[i])){
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