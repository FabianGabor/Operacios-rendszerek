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
};


int main()
{
    linked_list list;


    return 0;
}
