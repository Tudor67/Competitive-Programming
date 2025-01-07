class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int N = boxes.size();
        
        int leftSum = 0;
        int leftCount = 0;
        int rightSum = 0;
        int rightCount = 0;
        for(int i = 0; i < N; ++i){
            if(boxes[i] == '1'){
                rightSum += i;
                rightCount += 1;
            }
        }

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            int leftContrib = i * leftCount - leftSum;
            int rightContrib = rightSum - i * rightCount;

            res[i] = leftContrib + rightContrib;

            if(boxes[i] == '1'){
                leftSum += i;
                leftCount += 1;
                rightSum -= i;
                rightCount -= 1;
            }
        }

        return res;
    }
};