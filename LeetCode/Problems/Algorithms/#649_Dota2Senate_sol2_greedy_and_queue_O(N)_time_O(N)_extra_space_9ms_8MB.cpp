class Solution {
public:
    string predictPartyVictory(string senate) {
        const int N = senate.length();

        queue<int> rQ;
        queue<int> dQ;
        for(int i = 0; i < N; ++i){
            if(senate[i] == 'R'){
                rQ.push(i);
            }else{
                dQ.push(i);
            }
        }

        while(!rQ.empty() && !dQ.empty()){
            if(rQ.front() < dQ.front()){
                dQ.pop();
                rQ.push(rQ.front() + N);
                rQ.pop();
            }else{
                rQ.pop();
                dQ.push(dQ.front() + N);
                dQ.pop();
            }
        }

        if(rQ.empty()){
            return "Dire";
        }
        return "Radiant";
    }
};