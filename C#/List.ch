#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List {
private:

    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr) : data(data), pNext(pNext) {};
    };

    int Size;
    Node<T> *head;

public:
    List();
    ~List();
    void insert(T data, int index);
    void removeAt(int index);
    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void pop_back();
    void clear();
    int GetSize() { return Size; }

    T& operator[] (const int index);
};

template <typename T>
List<T>::List() : head(nullptr), Size(0) {};

template <typename T>
List<T>::~List() 
{
    clear();
}

template <typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

template <typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* newNode = previous->pNext;
        previous->pNext = newNode->pNext;

        delete newNode;
        Size--;
    }
}

template <typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template <typename T>
void List<T>::pop_back()
{
    removeAt(Size-1);
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;

        while ( current-> pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template <typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template <typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template <typename T>
T&  List<T> :: operator[] (const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    List<int> li;
    li.push_back(4);
    li.push_back(6);
    li.push_back(5);
    li.removeAt(1);
    li.pop_back();

    for (int i = 0; i < li.GetSize(); i++) cout << li[i] << endl;
	return 0;
}
