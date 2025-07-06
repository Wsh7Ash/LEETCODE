class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            vector<int> forces(n, 0);
            queue<int> q;
    
            for(int i = 0; i <  n; i++){
                if(dominoes[i] == 'L'){
                    q.push(i);
                    forces[i] = -1;
                }else if(dominoes[i] == 'R'){
                    q.push(i);
                    forces[i] = 1;
                }
            }
    
            while(!q.empty()){
                int size = q.size();
                vector<pair<int, int>> nextForces;
    
                for(int i = 0; i < size; i++){
                    int pos = q.front();
                    q.pop();
                    int force =  forces[pos];
    
                    if(force == 1 && pos + 1 < n && dominoes[pos + 1] == '.'){
                        nextForces.emplace_back(pos+ 1, 1);
                    }else if(force == -1 && pos - 1 >= 0 && dominoes[pos - 1] == '.'){
                        nextForces.emplace_back(pos-1, -1);
                    }
                }
    
                for(auto& p : nextForces){
                    int pos = p.first;
                    int force = p.second;
    
                    if(dominoes[pos] == '.'){
                        dominoes[pos] = (force == 1) ? 'R' : 'L';
                        forces[pos] = force;
                        q.push(pos);
                    }else if(dominoes[pos] == 'R' && force == -1){
                        dominoes[pos] = '.';
                    }else if(dominoes[pos] == 'L' && force == 1){
                        dominoes[pos] = '.';
                    }
                }
            }
            return dominoes;
        }
    };