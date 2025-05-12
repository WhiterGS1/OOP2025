#include <cstdio>

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        int index;
        Node(const K& k, const V& v, int idx) : key(k), value(v), next(nullptr), index(idx) {}
    };

    Node* root = nullptr;
    Node* last = nullptr;
    int count = 0;

public:
    ~Map() {
        Clear();
    }

    struct Element {
        const K& key;
        V& value;
        const int& index;
    };

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        Element operator*() const {
            return { current->key, current->value, current->index };
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(root); }
    Iterator end() { return Iterator(nullptr); }

    V& operator[](const K& key) {
        Node* curr = root;
        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }

        Node* newNode = new Node(key, V{}, count++);
        if (!root) {
            last = newNode;
            root = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        return newNode->value;
    }

    void Set(const K& key, const V& value) {
        *this[key] = value;
    }

    bool Get(const K& key, V& value) const {
        Node* curr = root;
        while (curr) {
            if (curr->key == key) {
                value = curr->value;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        Node* curr = root;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        root = nullptr;
        last = nullptr;
        count = 0;
    }

    void Reindex() {
        Node* curr = root;
        int idx = 0;
        while (curr) {
            curr->index = idx++;
            curr = curr->next;
        }
        count = idx;
    }

    bool Delete(const K& key) {
        Node* curr = root;
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) prev->next = curr->next;
                else root = curr->next;
                if (curr == last) last = prev;
                delete curr;
                Reindex();
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        Node* node = other.root;
        while (node) {
            V temp;
            if (!Get(node->key, temp))
                return false;
            node = node->next;
        }
        return true;
    }
};


int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}