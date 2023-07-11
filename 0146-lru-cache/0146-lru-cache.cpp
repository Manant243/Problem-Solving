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
        newNode->prev = head;
        head->next = newNode;
        newNode->next->prev = newNode;
    }
    
    void deleteNode(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    unordered_map <int, Node*> m; 
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* cur = m[key];
            int res = cur->val;
            m.erase(key);
            deleteNode(cur);
            addNode(cur);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* existing = m[key];
            m.erase(key);
            deleteNode(existing);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */