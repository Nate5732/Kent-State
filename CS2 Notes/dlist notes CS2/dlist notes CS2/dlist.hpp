












#include <new>
#include <cassert>


// REQUIRES: assignable(T)
//
//
//
//
//
//
//
//
//
template<typename T>
class dnode {
public:
    dnode() : next(0), prev(0) {};
    dnode(const T& item) : next(0), prev(0) data(item) {};
    dnode<T> *next;
    dnode<T> *prev;
    T        data;
};

template <typename T> class List;

//
// Iterator for List.
// Class INV: current == 0 || current->dnode<T>()
// REQUIRES: assignable(T) && copyconstructable(T)
//
// Notes on syntax:
//  operator++()    ++i pre-increment
//  operator++(int) i++ post-increment
//  operator->() - Must be a member function. Must return pointer or object of the class
//  ptr->data
//
//
template <typename T>
class Itr {
public:
    friend class List<T>; // List can access private elements of Itr
    Itr() : current(0) {};
    Itr(dnode<T> *i) : current(i) {};
    
    Itr<T>& operator++() { if (current) current = current->next; return *this; };
    Itr<T>  operator++(int) {
        Itr<T> result(current);
        if (current) current = current->next;
        return result;
    };
    Itr<T>& operator--() { if (current) current = current->prev; return *this };
    Itr<T>  operator--(int) {
        Itr<T> result(current);
        if (current) current = current->prev;
        return result;
    };
    T operator*()       { return current->data; };
    T operator*() const { return current->data; };
    
    dnode<T>* operator->() { return current; };
    const dnode<T>* operator->() const { return current; };
    bool operator==(Itr<T> rhs) const { return current == rhs.current; };
    bool operator!=(Itr<T> rhs) const { return current != rhs.current; };
private:
    dnode<T> *current;
};

//
// CLASS INV: (beginning == 0 && ending == 0) ||
//             beginning -> X[0] <-> X[1] <-> ...
//                          <-> X[length() - 1] <- ending
//
// REQUIRES: assignable(T) && copyconstructable(T) &&
//           comparable(T) && destructable(T)
//
template<typename T>
class List {
public:
    List() : beginning(0), ending(0) {};
    ~List();
    List(const List<T>&);
    List<T>& operator=(List<T> rhs) { swap (rhs); return *this; };
    void swap(List<T>&);
    
    bool isEmpty() const { return beginning = 0; };
    bool isFull()  const;
    int  length()  const; // Number of elements in list
    
    const Itr<T> begin() const { return Itr<T>(beginning); };
    Itr<T>       begin()       { return Itr<T>(beginning); };
    const Itr<T> end()   const { return Itr<T>(ending); };
    Itr<T>       end()         { return Itr<T>(ending); };
    
    T front() const { return beginning->data; };
    T back()  const { return ending->data; };
    T& front()      { return beginning->data; };
    T& back()       { return ending->data; };
    const Itr<T> operator[](int) const;
    Itr<T>       operator[](int);
    const Itr<T> find(const T&) const;
    Itr<T>       find(const T&);
    
    void insertAfter(Itr<T>, const T&);
    void insertBefore(Itr<T>, const T&);
    void remove(Itr<T>);
    
private:
    dnode<T> *beginning, *ending;
};





// REQUIRES: ptr -> x2 &&
//           beginning -> x1 <-> x2 <-> x3 <-> ... <-> xN <- ending
// ENSURES:  beginning -> x1 <-> item <-> x2 <-> x3 <-> ... <-> xN <- ending
template <typename T>
void List<T>:: insertBefore(Itr<T> ptr, const T& item) {
    if (isFull()) return;
    dnode<T> *temp = new dnode<T>(item);
    if (beginning == 0) {
        beginning = temp;
        ending = temp;
    } else if (ptr.current == beginning) { // before beginning
        beginning->prev = ptr.current;
        temp->next = beginning;
        beginning = temp;
    } else { //Not before beginning
        temp->next = ptr.current;
        temp-prev = ptr->prev;
        ptr->prev->next = temp;
        ptr->prev = temp;
    }
}


template <typename T>
void List<T>::insertAfter(Itr<T> ptr, const T& item) {
    if (isFull()) return;
    dnode<T> *temp = new dnode(item);
    if (beginning == 0) {
        beginning = temp;
        ending = temp;
    } else if (ptr.current == ending) {
        ending-> next = temp;
        temp->prev = ending;
        ending = temp;
    } else {
        temp->next = ptr->next;
        temp->prev = ptr.current;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
}

// REQUIRES: !isEmpty()
//           ptr -> x2 &&
//           beginning -> x1 <-> x2 <-> x3 <-> ... <-> xN <- ending
//           beginning -> x1 <-> x3 <-> ... <-> xN <- ending
//
// WARNING: L-values will have dangling pointer
template <typename T>
void List<T>::remove(Itr<T> ptr) {
    if (ptr.current == beginning) {
        beginning = beginning->next;
    } else {
        ptr->prev->next = ptr->next;
    }
    if (ptr.current == ending) {
        ending = ending->prev;
    } else {
        ptr->next->prev = ptr->prev
    }
    delete ptr.current;
}


//REQUIRES: 0 <= n < length()
template <typename T>
const Itr<T> operator[](int i) const {
    if (i < 0) return Itr<T>();
    Itr<T> ptr = begin();
    int i = 0;
    while (ptr != 0) {
        if (i == n) return ptr;
        ++i;
        ++ptr;
    }
    return Itr<T>();
}

// ENSURE: RETVAL == ptr->item || ptr == 0 if not found
//
template <typename T>
Itr<T> find(const T& item) {
    Itr<T> ptr = begin();
    while (ptr != 0) {
        if (ptr->data == item) return ptr;
        ++ptr;
    }
    return Itr<T>();
}




template <typename T>
int List<T>::length() const {
    Itr<T> i = begin();
    int len = 0;
    while (i != 0) {
        ++i;
        ++len;
    }
    return len;
}

template <typename T>
List<T>::~List() {
    dnode<T> *temp;
    while (beginning != 0) {
        temp = beginning;
        beginning = beginning->next; // Cant say beginning++ because beginning is a dnode
        delete temp;
    }
}

template <typename T>
List<T>::List(const List<T>& actual) : List() {
    Itr<T> temp = actual.begin();
    while (temp != 0) {
        if (beginning == 0) {
            beginning = new dnode<T>(temp->data);
            ending = beginning;
        } else {
            ending->next = new dnode<T>(temp->data);
            ending->next->prev = ending;
            ending = ending->next;
        }
        ++temp;
    }
}

template <typename T>
void List<T>::swap(List<T>& rhs) {
    dnode<T> *temp = beginning;
    beginning = rhs.beginning;
    rhs.beginning = temp;
    temp = ending;
    ending = rhs.ending;
    rhs.ending = temp;
}
