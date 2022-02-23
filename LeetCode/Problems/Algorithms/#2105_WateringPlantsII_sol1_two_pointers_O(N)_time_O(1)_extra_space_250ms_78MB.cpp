class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        const int N = plants.size();
        
        int answer = 0;
        int canA = capacityA;
        int canB = capacityB;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            if(canA < plants[i]){
                canA = capacityA;
                answer += 1;
            }
            if(canB < plants[j]){
                canB = capacityB;
                answer += 1;
            }
            canA -= plants[i];
            canB -= plants[j];
        }
        
        if(N % 2 == 1 && max(canA, canB) < plants[N / 2]){
            answer += 1;
        }
        
        return answer;
    }
};