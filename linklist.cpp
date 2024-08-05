#include <iostream>
using namespace std;
struct node
{
    int v;
    node *next;
};
class linklist
{
private:
    node *start;

public:
    linklist()
    {
        start = NULL;
    }
    void addAtBeg(int x)
    {
        node *t;
        t = new node;
        t->v = x;
        t->next = NULL;
        if (start == NULL)
        {
            start = t;
        }
        else
        {
            t->next = start;
            start = t;
        }
    }
    void display()
    {
        node *temp;
        temp = start;
        while (temp != NULL)
        {
            cout << temp->v << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    linklist l;
    l.addAtBeg(10);
    l.addAtBeg(13);
    l.addAtBeg(17);
    l.addAtBeg(19);
    l.display();
    return 0;
}