#ifndef IntVector_H
#define IntVector_H

class IntVector {
private:
    unsigned sz;
    unsigned cap;
    int *data;
public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    int & at(unsigned index);
    void insert(unsigned index, int value);
    void erase(unsigned index);
    const int & front() const;
    int & front();
    const int & back() const;
    int & back();
    void assign(unsigned n, int value = 0);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned n, int value = 0);
    void reserve(unsigned n);

private:
    void expand();
    void expand(unsigned amount);
};

#endif
