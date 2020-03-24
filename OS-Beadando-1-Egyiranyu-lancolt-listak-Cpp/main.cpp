#include <iostream>

using namespace std;

struct node {
    int data;
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

    void insertFront (int n) {
        node *tmp = new node;
        tmp -> data = n;
        tmp -> next = head;
        head = tmp;
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

    void insertAfter (node *a, int value) {
        node *p = new node;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }

    void deleteNode (node *before_del) {
        node *tmp;
        tmp = before_del->next;
        before_del->next = tmp->next;
        delete tmp;
    }

    void deleteFirstData (int value) {
        node *tmp;
        tmp = head;

        if (head->data == value) {
            head = tmp->next;
            return;
        }

        while (tmp != NULL) {
            if (tmp->next->data == value) {
                tmp->next = tmp->next->next;
                return;
            }
            tmp = tmp->next;
        }
    }

    void deleteAllData (int value) {
        node *tmp, *current;
        tmp = head;
        current = head;

        if (current->data == value) {
            tmp = current;
            head = tmp->next;
        }

        while (current->next != NULL) {
            if (current->next->data == value) {
                tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            }
            else
                current = current->next;
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

    node* gethead () {
        return head;
    }

    static void display (node *head) {
        if (head == NULL) {
            cout << "NULL" << endl;
        }
        else {
            cout << head->data << " ";
            display(head->next);
        }
    }
};


int main()
{
    linked_list list;

    list.append(2);
    list.append(3);
    list.insertFront(0);
    list.insertAfter(list.gethead(), 1);

    list.append(2);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(4);

    list.print();
    //list.display(list.gethead());
    //linked_list::display(list.gethead());

    //list.deleteData(0);
    list.deleteFirstData(2);
    list.deleteAllData(2);
    list.print();

    return 0;
}
