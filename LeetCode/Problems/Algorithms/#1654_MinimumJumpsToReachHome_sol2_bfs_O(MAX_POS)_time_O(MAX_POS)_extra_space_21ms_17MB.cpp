class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        const int MAX_POS = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;
        const int INF = 1e9;

        vector<bool> isValid(MAX_POS + 1, true);
        for(int forbiddenPos: forbidden){
            isValid[forbiddenPos] = false;
        }

        enum JumpType { BACKWARD = 0, FORWARD = 1 };
        vector<vector<int>> minJumps(2, vector<int>(MAX_POS + 1, INF));
        queue<tuple<int, int, int>> q;
        minJumps[JumpType::FORWARD][0] = 0;
        q.push({minJumps[JumpType::FORWARD][0], JumpType::FORWARD, 0});

        while(!q.empty()){
            int prevJumpType = get<1>(q.front());
            int pos = get<2>(q.front());
            q.pop();

            if(pos == x){
                return minJumps[prevJumpType][x];
            }

            int nextPos = pos + a;
            if(nextPos <= MAX_POS && isValid[nextPos]){
                if(minJumps[prevJumpType][pos] + 1 < minJumps[JumpType::FORWARD][nextPos]){
                    minJumps[JumpType::FORWARD][nextPos] = minJumps[prevJumpType][pos] + 1;
                    q.push({minJumps[JumpType::FORWARD][nextPos], JumpType::FORWARD, nextPos});
                }
            }

            nextPos = pos - b;
            if(prevJumpType == JumpType::FORWARD && 0 <= nextPos && nextPos <= MAX_POS && isValid[nextPos]){
                if(minJumps[prevJumpType][pos] + 1 < minJumps[JumpType::BACKWARD][nextPos]){
                    minJumps[JumpType::BACKWARD][nextPos] = minJumps[prevJumpType][pos] + 1;
                    q.push({minJumps[JumpType::BACKWARD][nextPos], JumpType::BACKWARD, nextPos});
                }
            }
        }

        return -1;
    }
};