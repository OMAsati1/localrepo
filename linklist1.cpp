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
    void append(int x)
    {
        node *t;
        t = new node;
        t->v = x;
        t->next = NULL;
        if (start == NULL)
        {
            start = t;
            return;
        }
        node *temp;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t;
    }
    int getLength()
    {
        if (start == NULL)
        {
            return 0;
        }
        node *temp = start;
        int l = 0;
        while (temp != NULL)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }
    int removeFirst()
    {
        if (start == NULL)
        {
            cout << "Empty\n";
            return -1;
        }
        node *t;
        t = start;
        int c = start->v;
        start = start->next;
        delete t;
        return c;
    }
    int removeLast()
    {
        if (start == NULL)
        {
            cout << "Empty\n";
            return -1;
        }
        if (start->next == NULL)
        {
            return removeFirst();
        }
        else
        {
            node *temp = start;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            node *t = temp->next;
            int c = t->v;
            temp->next = NULL;
            delete t;
            return c;
        }
    }
    int removeNTH(int pos)
    {

        if (pos == 1)
        {
            return removeFirst();
        }
        int n = getLength();
        if (pos == n)
        {
            return removeLast();
        }
        node *temp = start;
        for (int i = 2; i <= pos - 1; i++)
        {
            temp = temp->next;
        }

        int c = temp->next->v;
        node *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        return c;
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
    l.addAtBeg(23);
    l.addAtBeg(15);
    l.addAtBeg(9);
    l.addAtBeg(93);
    l.addAtBeg(49);
    l.display();
    cout << '\n';
    // l.append(6);
    // l.append(25);
    // l.append(6);
    // l.display();
    // cout << "\n"
    //      << l.getLength() << '\n'<<endl;
    // cout<<l.removeFirst()<<endl;
    // l.display();
    // cout<<endl;
    // cout<<l.removeLast()<<endl;
    // l.display();
    // cout<<endl;
    // cout<<"\nafter nth removable"<<'\n';
    cout << "Lenght of list: " << l.getLength() << endl;

    cout << "removed elemet is: " << l.removeNTH(4) << endl;

    l.display();

    return 0;
}
