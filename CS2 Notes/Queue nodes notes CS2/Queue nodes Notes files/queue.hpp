

















class node {
public:
    node() : next(0) {};
    node(const T& x) : data(x), next(0) {};
    T data;
    node<T> *next;
};


//
// CLASS INV: beginning -> x1 -> x2 -> .... xN <- ending
//
template<typename T>
class queue {
public:
    queue() : beginning(0), ending(0) {};
    ~queue();
    queue(const queue<T>&);
    void swap(queue<T>&);
    queue<T>& operator=(queue<T> rhs) { swap(rhs); return *this; };
    
    bool isEmpty() const { return beginning == 0; };
    bool isFull() const;
    T dequeue();
    void enqueue(const T&);
    
private:
    node<T> *beginning;
            *ending;
};


// REQUIRES: beginning-> x1 -> ... -> xn <- ending && !isFull()
// ENSURES:  beginning-> x1 -> ... -> xn -> item <- ending
template<typename T>
void queue<T>::enqueue(const T& item) {
    assert(!isFull());
    if (ending == 0) {
        ending = new node<T>(item);
        beginning = ending;
    } else {
        ending->next = new node<T>(item);
        ending = ending->next;
    }
}

//REQUIRES: !isEmpty()
template<typename T>
T queue<T>::dequeue() {
    assert(!isEmpty());
    T result = beginning->data;
    if (beginning == ending) {
        delete beginning;
        ending = 0;
        beginning = 0;
    }else {
        node<T> *temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
    return result;
}


template<typename T>
queue<T>::~queue() {
    node<T> *temp;
    while (beginning != 0) {
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

// Copy Constructor
template <typename T>
queue<T>::queue(const queue<T>& actual) : queue() {
    node<T> *temp = actual.beginning;
    while (temp != 0) {
        if (beginning == 0) { //First node to be inserted
            beginning = new node<T>(temp->data);
            ending = beginning;
        } else {
            ending->next = new node<T>(temp->data);
            ending = ending->next;
        }
        temp = temp->next;
    }
}

template <typename T>
void queue<T>::swap(queue<T> &rhs) {
    node<T> *temp = beginning;
    beginning     = rhs.beginning;
    rhs.beginning = temp;
    temp          = ending;
    ending        = rhs.ending;
    rhs.ending    = temp;
}


template<typename T>
bool queue<T>::isFull() const {
    node<T>* temp = new(std::nothrow) node<T>();
    if (temp == 0) return true;
    delete temp;
    return false;
}
