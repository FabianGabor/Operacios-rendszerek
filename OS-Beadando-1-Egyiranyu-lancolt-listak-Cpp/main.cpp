#include <iostream>

using namespace std;

struct node {
    unsigned int data;
    node *next;
};

class linked_list {
    private:
        node *head,*tail;
    public:
        linked_list () {
            head = NULL;
            tail = NULL;
        }

    void append (int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void print () {
        node *tmp;
        tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};


int main()
{
    linked_list list;

    list.append(2);
    list.append(3);

    list.print();

    return 0;
}
