#include <iostream>
#include <string>
#include <math.h>
#include <exception>
#include <stdlib.h>
#include <time.h>

class quadrangle_t
{
public:
    virtual double area() = 0;
    virtual void toString() = 0;
    virtual ~quadrangle_t() {}
};

class diamond : public quadrangle_t
{
private:
    size_t shortEdge;
    size_t longEdge;

public:
    diamond(size_t sEdge, size_t lEdge)
    {
        shortEdge = sEdge;
        longEdge = lEdge;
    }

    ~diamond() {}

    double area()
    {
        return shortEdge * longEdge / 2;
    }

    void toString()
    {
        std::cout << "diamond: diagnal1=" << shortEdge << ", diagnal2=" << longEdge << ", area=";
    }
};

class trapezoid : public quadrangle_t
{
private:
    int bottomLength;
    int topLength;
    int height;

public:
    trapezoid(int bottom, int top, int hei)
    {
        height = hei;
        topLength = top;
        bottomLength = bottom;
    }

    ~trapezoid() {}

    double area()
    {
        return (bottomLength + topLength) * height / 2;
    }

    void toString()
    {
        std::cout << "trapezoid: width1=" << topLength << ", width2=" << bottomLength << ", height=" << height << ", area=";
    }
};

class parallelogram : public quadrangle_t
{
private:
    int height;
    int width;

public:
    parallelogram(int hei, int wid)
    {
        height = hei;
        width = wid;
    }

    ~parallelogram() {}

    double area()
    {
        return height * width;
    }

    void toString()
    {
        std::cout << "parallelogram: width=" << width << ", height=" << height << ", area=";
    }
};

class rectangle : public quadrangle_t
{
private:
    int height;
    int width;

public:
    rectangle(int hei, int wid)
    {
        height = hei;
        width = wid;
    }

    ~rectangle() {}

    double area()
    {
        return height * width;
    }

    void toString()
    {
        std::cout << "rectangle: width=" << width << ", height=" << height << ", area=";
    }
};

class square : public quadrangle_t
{
private:
    int edge;

public:
    square(int edg)
    {
        edge = edg;
    }

    ~square() {}

    double area()
    {
        return edge * edge;
    }

    void toString()
    {
        std::cout << "square: width=" << edge << ", area=";
    }
};

struct node
{
    using data = struct
    {
        quadrangle_t *shape;
        double answer;
    };
    data dat;
    node *next;
};

template <typename value_t = quadrangle_t *>
class linkedList
{
private:
    node *head;

public:
    linkedList()
    {
        head = new node();
        head->next = nullptr;
    }

    void addNode(typename node::data &data)
    {
        node *ptr = new node();
        ptr->dat.answer = data.answer;
        ptr->dat.shape = data.shape;
        ptr->next = head->next;
        head->next = ptr;
    }

    ~linkedList()
    {
        while (head->next != nullptr)
        {
            node *ptr = head->next;
            delete head->dat.shape;
            delete head;
            head = ptr;
        }
        delete head->dat.shape;
        delete head;
        head = nullptr;
    }

    class iterator
    {
    private:
        node *p;

    public:
        iterator()
        {
            p = nullptr;
        }

        iterator(const linkedList &list)
        {
            p = list.head;
        }

        ~iterator()
        {
            p = nullptr;
        }

        iterator &operator=(const iterator &itr)
        {
            p = itr.p;
            return this;
        }

        iterator &operator++(int)
        {
            p = p->next;
            return *this;
        }

        iterator &operator++()
        {
            p = p->next;
            return *this;
        }

        bool operator!=(const iterator &itr)
        {
            return p != itr.p;
        }

        typename node::data &operator*()
        {
            return p->dat;
        }
    };

    iterator begin()
    {
        return iterator(*this);
    }

    iterator end()
    {
        return iterator();
    }
};

int main()
{
    linkedList list;
    std::cout << "Practicing. Input negative value to halt." << std::endl;
    srand((unsigned)time(NULL));
    quadrangle_t *shape;
    while (true)
    {
        int i = rand() % 5;
        double answer;
        switch (i)
        {
        case 0:
            shape = new diamond(rand() % 20 + 1, rand() % 20 + 1);
            break;
        case 1:
            shape = new trapezoid(rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1);
            break;
        case 2:
            shape = new parallelogram(rand() % 20 + 1, rand() % 20 + 1);
            break;
        case 3:
            shape = new square(rand() % 20 + 1);
            break;
        case 4:
            shape = new rectangle(rand() % 20 + 1, rand() % 20 + 1);
            break;
        }

        shape->toString();
        std::cout << "?";
        std::cin >> answer;
        if (answer < 0.0)
        {
            delete shape;
            break;
        }
        typename node::data data = {shape, answer};
        list.addNode(data);

        if (answer == shape->area())
        {
            std::cout << "Your answer is correct" << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "Your answer is incorrect" << std::endl
                      << std::endl;
        }
    }

    std::cout << "\n\n\nReviewing..." << std::endl;

    size_t total = 0, correct = 0;
    for (linkedList<quadrangle_t *>::iterator itr = ++list.begin(); itr != list.end(); itr++)
    {
        typename node::data data = *itr;
        char rightOrWrong;
        if (data.answer == data.shape->area())
        {
            rightOrWrong = 'V';
            correct++;
        }
        else
        {
            rightOrWrong = 'X';
        }
        total++;
        data.shape->toString();
        std::cout << data.shape->area() << ", answer=" << data.answer << " " << rightOrWrong << std::endl;
    }
    std::cout << std::endl << "Total: " << total << ", Correct: " << correct << std::endl;
}