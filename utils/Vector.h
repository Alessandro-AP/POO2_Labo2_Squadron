

#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H
// https://stackoverflow.com/questions/5159061/implementation-of-vector-in-c

template <class T>
class  Vector
{
public:

    typedef T * iterator;

    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T & value);
    void pop_back();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T & operator[](unsigned int index);
    Vector<T> & operator=(const Vector<T> &);
    void clear();
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};


#endif //BASE_VECTOR_H
