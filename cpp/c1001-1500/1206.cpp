struct Node {
    int val;
    Node* right;
    Node* down;
    Node(int v, Node* r, Node* d) : val(v), right(r), down(d) {}
};
class Skiplist {
private:
    Node* head;
    mt19937 gen;
    uniform_real_distribution<double> dis;
    const double p = 0.5;
    int maxLevel = 16;

public:
    Skiplist() : gen(random_device{}()), dis(0.0, 1.0) {
        head = new Node(-1, nullptr, nullptr);
        Node* cur = head;

        for(int i = 0; i < maxLevel - 1; i++){
            cur->down = new Node(-1, nullptr, nullptr);
            cur = cur->down;
        }
    }
    
    bool search(int target) {
        Node* cur = head;
        while(cur){
            while(cur->right && cur->right->val < target){
                cur = cur->right;
            }

            if(cur->right && cur->right->val  == target) return true;

            cur = cur->down;
        }
        return false;
    }
    
    void add(int num) {
        vector<Node*> path;
        Node* cur = head;

        while(cur){
            while(cur->right && cur->right->val < num){
                cur = cur->right;
            }
            path.push_back(cur);
            cur = cur->down;
        }

        bool insertAbove = true;
        Node* downNode = nullptr;
        int level = 0;

        while(insertAbove && level < maxLevel){
            Node* prev = path.back();
            path.pop_back();

            prev->right = new Node(num, prev->right, downNode);
            downNode = prev->right;

            insertAbove = (dis(gen) < p);
            level++;
        }

        while(level < maxLevel && insertAbove){
            Node* newHead = new Node(-1, nullptr, head);
            newHead->right = new Node(num, nullptr, downNode);
            downNode = newHead->right;
            head = newHead;
            insertAbove = (dis(gen) < p);
            level++;
        }
    }
    
    bool erase(int num) {
        Node* cur = head;
        bool found = false;

        while(cur){
            while(cur->right && cur->right->val < num) cur = cur->right;
            
            if(cur->right && cur->right->val == num) {
                found = true;
                Node* toDelete = cur->right;
                cur->right = toDelete->right;
                delete toDelete;
            }
            cur = cur->down;
        }     
        return found;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */