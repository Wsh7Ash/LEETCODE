class CombinationIterator {
private:
    string characters;
    int combinationLength;
    vector<int> indices;
    bool has_next;

public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        this->combinationLength = combinationLength;
        this->indices.resize(combinationLength);

        for(int i = 0; i < combinationLength; i++){
            indices[i] = i;
        }
        has_next = true;
    }
    
    string next() {
        string res = "";
        for(int i = 0;  i < combinationLength; i++){
            res += characters[indices[i]];
        }
        geberateNextCombination();

        return res;
    }
    
    bool hasNext() {
       return has_next; 
    }

private:
    void geberateNextCombination(){

        int n = characters.length();

        int i = combinationLength - 1;
        while(i >= 0 && indices[i] == n - combinationLength + i) {i--;}

        if(i < 0){
            has_next = false;
            return;
        }

        indices[i]++;

        for(int j = i + 1; j < combinationLength; j++){
            indices[j] = indices[j - 1] + 1;
        }
    }

};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */