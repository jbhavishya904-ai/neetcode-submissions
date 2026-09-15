class LRUCache {
public:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // Add node immediately after head
    void add(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }

    // Remove a node from the list
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        add(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            remove(node);
            node->val = value;
            add(node);
        } else {
            Node* node = new Node(key, value);

            mp[key] = node;
            add(node);

            if (mp.size() > cap) {
                Node* lru = tail->prev;

                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
        }
    }
};