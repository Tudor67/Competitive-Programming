#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using MinHeap = priority_queue<PII, vector<PII>, greater<PII>>;

const long long INF = 2e9 + 5;

vector<vector<int>> children;
unordered_map<int, int> nodeToMedBit;
unordered_map<int, int> medBitToNode;
vector<int> t;
vector<int> s;
vector<long long> g;

int defeatEnemiesAndFindMedicines(int startNode, MinHeap& minHeap, long long& score){
    int medCandidatesMask = 0;

    minHeap.push({s[startNode], startNode});

    while(!minHeap.empty() && minHeap.top().first <= score){
        int node = minHeap.top().second;
        minHeap.pop();

        if(t[node] == 1){
            score += g[node];
            score = min(score, INF);
        }

        for(int child: children[node]){
            if(t[child] == 1){
                minHeap.push({s[child], child});
            }else{
                medCandidatesMask |= (1 << nodeToMedBit[child]);
            }
        }
    }

    return medCandidatesMask;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    children.resize(N);
    t.resize(N);
    s.resize(N);
    g.resize(N);

    for(int node = 1; node < N; ++node){
        int p;
        cin >> p >> t[node] >> s[node] >> g[node];

        p -= 1;
        children[p].push_back(node);

        if(t[node] == 2){
            int bit = nodeToMedBit.size();
            nodeToMedBit[node] = bit;
            medBitToNode[bit] = node;
        }
    }

    const int M = nodeToMedBit.size();
    const int FULL_MASK = (1 << M) - 1;
    const int ENEMY_MAX_STRENGTH = *max_element(s.begin(), s.end());
    
    vector<long long> maxScore(FULL_MASK + 1);
    vector<int> candMasks(FULL_MASK + 1);
    vector<MinHeap> minHeaps(FULL_MASK + 1);

    maxScore[0] = 1;
    candMasks[0] = defeatEnemiesAndFindMedicines(0, minHeaps[0], maxScore[0]);
    for(int visMask = 0; visMask < FULL_MASK; ++visMask){
        for(int bit = 0; bit < M; ++bit){
            int isVisited = (visMask >> bit) & 1;
            int isCandidate = (candMasks[visMask] >> bit) & 1;
            if(!isVisited && isCandidate){
                int nextVisMask = visMask | (1 << bit);
                int nextStartNode = medBitToNode[bit];
                long long nextScore = min(maxScore[visMask] * g[nextStartNode], INF);
                MinHeap nextMinHeap = minHeaps[visMask];
                int nextCandMask = candMasks[visMask] |
                                   defeatEnemiesAndFindMedicines(nextStartNode, nextMinHeap, nextScore);
                if(maxScore[nextVisMask] < nextScore){
                    maxScore[nextVisMask] = nextScore;
                    minHeaps[nextVisMask] = nextMinHeap;
                    candMasks[nextVisMask] = nextCandMask;
                }
            }
        }
    }

    if(maxScore[FULL_MASK] >= ENEMY_MAX_STRENGTH){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}