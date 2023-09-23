class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            
            Node* next;
            Node* prev;
            
            Node(int key_, int val_){
                key = key_;
                val = val_;
            }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next->prev = newNode;
    }
    
    void deleteNode(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    unordered_map <int, Node*> m; 
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* current = m[key];
        deleteNode(current);
        addNode(current);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        Node* current = new Node(key, value);
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            deleteNode(curr);
            m.erase(key);
        }
        if(m.size() < cap){
            addNode(current);
        }
        else{
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNode(current);
        }
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */