/*
 * Fábián Gábor
 * CXNU8T
 * https://github.com/FabianGabor/Operacios-rendszerek/tree/master/OS-Beadando-1-Egyiranyu-lancolt-listak-Cpp
 */

#include <iostream>
#include <fstream>

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
        print();
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

        display(gethead());
    }

    void insertAfter (node *a, int value) {
        node *p = new node;
        p->data = value;
        p->next = a->next;
        a->next = p;

        display(gethead());
    }

    void deleteNode (node *before_del) {
        node *tmp;
        tmp = before_del->next;
        before_del->next = tmp->next;
        delete tmp;

        display(gethead());
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

                display(gethead());
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
        display(gethead());
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
            cout << endl;
        }
        else {
            cout << head->data << " ";
            display(head->next);
        }
    }


    void readFromFileSpaceSeparated(string filename) {
        std::fstream file(filename, std::ios_base::in);

        int a;
        while (file >> a)
            append(a);
    }

    void readFromFileCommaSeparated (string filename) {
        ifstream file;
        file.open (filename, ifstream::in);

        if (file.is_open()) {
            int i=0;
            char cNum[10];

            while (file.good()) {
                file.getline(cNum, 256, ',');
                append(atoi(cNum));
                i++;
            }
            file.close();
        }
        else
            cout << "Error opening file";
    }

    char separator (string filename) {
        ifstream file;
        file.open (filename, ifstream::in);

        char str[20];
        char sep = '\13';

        if (file.is_open()) {
            while (file.good()) {
                file.getline(str, 256);
                unsigned long i=0;
                while ((str[i] != ' ') && (str[i] != ',')) {
                    i++;
                }
                sep = str[i];
            }
            file.close();
        }
        else
            cout << "Error opening file";

        return sep;
    }

    void readFromFile (string filename) {
        ifstream file;
        file.open (filename, ifstream::in);

        if (file.is_open()) {
            char cNum[10];
            char sep = separator(filename);

            while (file.good()) {
                file.getline(cNum, 256, sep);
                append(atoi(cNum));
            }
            file.close();
        }
        else
            cout << "Error opening file";
    }
};





int main()
{
    linked_list list;   

    // The input file has the numbers separated by comma ','
    list.readFromFile("input_comma_separated");
    linked_list::display(list.gethead());

    // The input file has the numbers separated by space ' '
    list.readFromFile("input_space_separated");
    linked_list::display(list.gethead());

    // TODO: input file's numbers separator character should be identified by a function and threated accordingly like in the plain C version

    // Add to the end of the list
    list.append(2);
    list.append(3);

    // Add to the front of the list
    list.insertFront(0);
    // Add after the specified node
    list.insertAfter(list.gethead(), 1);

    // A few more data just for good measure
    list.append(0);
    list.append(2);
    list.append(3);
    list.append(0);
    list.append(4);

    // Delete first occurence of '2'
    list.deleteFirstData(2);
    // Delete ALL occurences of '0'
    list.deleteAllData(0);

    return 0;
}
