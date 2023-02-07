#include <iostream>
using namespace std;

template <typename T>
class DLLNode
{
public:
    int key;
    T value;
    DLLNode<T> *next;
    DLLNode<T> *prev;

    DLLNode(int key, T value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    ~DLLNode() {}
};