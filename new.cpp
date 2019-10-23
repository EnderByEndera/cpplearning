#include <iostream>
#include <initializer_list>

class list
{
public:
    using value_type = float;
    using reference = value_type&;
    using pointer = value_type*;

    using callback = void (reference);

private:
    struct node
    {
        value_type data;
        node * next;
    };

    using nodeptr = node *;

    nodeptr head, tail;
    size_t len;

public:
    //trivial constructor
    list() : head(nullptr), tail(nullptr), len(0) {}
    //list() : list() {}

    //initializer-list constructor
    list(std::initializer_list<value_type> l) : list()
    {
        for (auto e : l) push_back(e);
    }

    //copy control(1--4)
    //1. copy constructor
    // This kind of constructor definition can also be used and seems to be no difference from orignial one
    list(const list& l) : head(nullptr), tail(nullptr), len(0)
    //list(const list& l) : list() //constructor delegates
    {
        for (auto p = l.head; p != nullptr; p = p->next) 
            push_back(p->data);
    }

    //2. move copy constructor
    list(list&& l) : list()
    {
        std::swap(head, l.head);
        std::swap(tail, l.tail);
        std::swap(len, l.len);
    }

    //3. normal assignment
    //operator function overloading
    list& operator =(list& l)
    {
        clear();

        // for (auto p = l.head; p != nullptr; p = p->next) 
        //     push_back(p->data);

        std::swap(head, l.head);
        std::swap(tail, l.tail);
        std::swap(len, l.len);

        return *this;
    }

    //4. move assignment
    list& operator =(list&& l)
    {
        std::swap(head, l.head);
        std::swap(tail, l.tail);
        std::swap(len, l.len);

        return *this;
    }

    //destructor
    ~list() { clear(); }

    void clear()
    {
        for (auto p = head; head != nullptr; )
        {
            head = head->next;
            delete p;
            p = head;
        }

        head = tail = nullptr;
        len = 0;
    }

    void push_back(value_type v)
    {
        auto p = new node{v, nullptr};
        
        head == nullptr ? head = p : tail->next = p;
        tail = p;

        ++len;
    }

    void traverse(callback f)
    {
        for (auto p = head; p != nullptr; p = p->next)
            f(p->data);
    }

    size_t size() const { return this->len; }
};

int main()
{
    auto print = [](list::reference v) { std::cout << v << std::endl; };

    list &&l = list{1, 2, 3};
    list l2 = {1, 2, 3, 4}, l3;

    l3 = l;

    l.traverse(print);
    l2.traverse(print);
    l3.traverse(print);
    // std::cout << l2.size() << std::endl;

    return 0;
}
