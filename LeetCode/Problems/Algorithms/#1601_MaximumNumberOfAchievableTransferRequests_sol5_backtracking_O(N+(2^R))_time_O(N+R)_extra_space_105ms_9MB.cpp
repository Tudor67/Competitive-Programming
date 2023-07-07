class Solution {
private:
    void back(int index, vector<vector<int>>& requests, int solvedRequests,
              vector<int>& inDegree, vector<int>& outDegree, int degreeMatches, int& res){
        if(index == (int)requests.size()){
            if(degreeMatches == (int)inDegree.size()){
                res = max(res, solvedRequests);
            }
        }else{
            // Option 1: ignore requests[index]
            back(index + 1, requests, solvedRequests, inDegree, outDegree, degreeMatches, res);

            // Option 2: solve requests[index]
            int a = requests[index][0];
            int b = requests[index][1];

            int nextDegreeMatches = degreeMatches;
            nextDegreeMatches -= (int)(inDegree[a] == outDegree[a]);
            nextDegreeMatches -= (int)(inDegree[b] == outDegree[b]);
            
            outDegree[a] += 1;
            inDegree[b] += 1;

            nextDegreeMatches += (int)(inDegree[a] == outDegree[a]);
            nextDegreeMatches += (int)(inDegree[b] == outDegree[b]);

            back(index + 1, requests, solvedRequests + 1, inDegree, outDegree, nextDegreeMatches, res);

            outDegree[a] -= 1;
            inDegree[b] -= 1;
        }
    }

public:
    int maximumRequests(int N, vector<vector<int>>& requests) {
        const int R = requests.size();

        vector<int> inDegree(N);
        vector<int> outDegree(N);
        int degreeMatches = N;
        int res = 0;

        back(0, requests, 0, inDegree, outDegree, degreeMatches, res);

        return res;
    }
};