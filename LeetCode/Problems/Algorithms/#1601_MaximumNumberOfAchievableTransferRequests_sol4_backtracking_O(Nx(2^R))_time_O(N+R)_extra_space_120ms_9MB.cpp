class Solution {
private:
    void back(int index, vector<vector<int>>& requests, int solvedRequests,
              vector<int>& inDegree, vector<int>& outDegree, int& res){
        if(index == (int)requests.size()){
            if(inDegree == outDegree){
                res = max(res, solvedRequests);
            }
        }else{
            // Option 1: ignore requests[index]
            back(index + 1, requests, solvedRequests, inDegree, outDegree, res);

            // Option 2: solve requests[index]
            int a = requests[index][0];
            int b = requests[index][1];
            
            outDegree[a] += 1;
            inDegree[b] += 1;

            back(index + 1, requests, solvedRequests + 1, inDegree, outDegree, res);

            outDegree[a] -= 1;
            inDegree[b] -= 1;
        }
    }

public:
    int maximumRequests(int N, vector<vector<int>>& requests) {
        const int R = requests.size();

        vector<int> inDegree(N);
        vector<int> outDegree(N);
        int res = 0;

        back(0, requests, 0, inDegree, outDegree, res);

        return res;
    }
};