















// Binary Search Tree
//
// REQUIRES: DefaultConstructable(T) &&
//           Assignable(T) &&
//           Comparable(T) &&
//           Copyconstructable(T) &&
//           Printable(T)
//
template <typename T>
class btree {
public:
    btree() : root(0) {};
    ~btree();
    btree(const btree<T>&);
    void swap(btree<T>&);
    btree<T> & operator=(btree<T> rhs) { swap(rhs); return *this; };
    
    bool isEmpty() const { return root == 0; };
    bool isFull() const;
    bool bfind(const T&) const;
    void binsert(const T&);
    void bremove(const T&);
    void inorder(std::ostream&) const;
    }
};



// binary tree node
//        -----------------
//        |     data      |
//        -----------------
//        | *left  | *right|
//        ------------------
template <typename T>
class bnode {
    public:
    bnode() : left(0), right(0) {};
    bnode(const T& x) : left(0), right(0), data(x) {};
    ~bnode();
    bnode(const bnode<T>&);
    
    bool       bfind(const T&) const;
    void       binsert(const T&);
    bnode<T>*  bremove(const T&);
    T          predecessor() const;
    void       inorder(std::ostream&) const;

    private:
    bnode<T> *left, *right;
    T        data;
};

// ENSURES: if key in Tree
//          then RETVAL == true
//          else RETVAL == false
// Bfinds
template <typename T>
bool btree<T>::bfind(const T& key) const {
    if (!root) return false;
    return root->bfind(key);
}
    
template <typename T>
bool bnode<T>::bfind(const T& key) const {
    if (data == key) return true;
    if (key < data) {
        if (left) return left->bfind(key);
        else      return false;
    } else {
        if (right) return right->bfind(key);
        else       return false;
    }
}

// Inserts
template <typename T>
boid btree<T>::binsert(const T& key) {
    if (root == 0) {
        root = new bnode<T>(key);
    } else {
        root->binsert(key);
    }
}

template <typename T>
boid bnode<T>::binsert(const T& key) {
    if (key < data) {
        if (left) left->binsert(key);
        else left = new bnode<T>(key);
    } else {
        if (right) right->binsert(key);
        else right = new bnode<T>(key);
    }
}

// Destructors
template <typename T>
btree<T>::~btree() {
    if (root) delete root;
}

template <typename T>
bnode<T>::~bnode() {
    if (left) delete left;
    if (right) delete right;
    // Rest of bnode is deallocated by compiler
}

// Copys
template <typename T>
btree<T>::btree(const btree<T>& actual) {
    if (actual.root) root = bnode <T>(*(actual.root));
    else             root = 0;
}

template <typename T>
bnode<T>::bnode(const bnode<T>& actual) {
    data = actual.data;
    if (actual.left) left = bnode<T>(*(actual.left));
    if (actual.right) right = bnode<T>(*(actual.right));
}

// x.left->predecessor()
// REQUIRES: Given x.left
// ENSURE:   RETVAL == predecessor of x.data
template <typename T>
T bnode<T>::predecessor() const {
    if (right) return right->predecessor();
    return data;
}

// REQUIRES: Given key
// ENSURE:   key removed from tree and still BST
// Removes
template <typename T>
void btree<T>::bremove(const T& key) {
    if (find(x)) root = root->bremove(key);
}

// REQUIRES: key in tree
template <typename T>
bnode<T>* bnode<T>::bremove(const T& key) {
    if (key == data) {
        if (!left && !right) { //No children
            delete this;
            return 0;
        }
        if (!left && right) { //Right child only
            dnode<T> *temp = right;
            right = 0;
            delete this;
            return temp;
        }
        if (left && !right) { //Left child only
            dnode<T> *temp = left
            left = 0;
            delete this;
            return temp;
        }
        data = left->predecessor(); //Two children
        left = left->bremove(data);
    } else {
        if (key < data)
            left = left->bremove(key);
        else
            right = right->bremove(key);
    }
    return this;
}
