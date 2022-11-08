class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_map<string, int> dist;
        queue<string> q;
        
        q.push(start);
        dist[start] = 0;
        
        while(!q.empty() && !dist.count(end)){
            string gene = q.front();
            q.pop();
            
            string nextGene = gene;
            for(int pos = 0; pos < (int)gene.length(); ++pos){
                for(char c: "ACGT"){
                    nextGene[pos] = c;
                    if(!dist.count(nextGene) && bankSet.count(nextGene)){
                        dist[nextGene] = dist[gene] + 1;
                        q.push(nextGene);
                    }
                }
                nextGene[pos] = gene[pos];
            }
        }
        
        if(dist.count(end)){
            return dist[end];
        }
        
        return -1;
    }
};