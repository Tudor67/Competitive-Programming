class Solution {
public:
    void rotate(vector<int>& nums, int K) {
        const int N = nums.size();
        K %= N;
        
        int visCnt = 0;
        for(int start = 0; visCnt < N; ++start){
            int curPos = start;
            int prevNum = nums[start];
            do{
                int nextPos = (curPos + K) % N;
                int temp = nums[nextPos];
                nums[nextPos] = prevNum;
                prevNum = temp;
                curPos = nextPos;
                visCnt += 1;
            }while(start != curPos);
        }
    }
};