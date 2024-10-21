#include<iostream>
using namespace std;

class node { // user defined "DATA TYPE"
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList { // user defined "DATA STRUCTURE"
public:
    node* head;
    node* tail;
    int size;
public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd(int val) {
        node* temp = new node(val);
        if (size == 0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtHead(int val) {
        node* temp = new node(val);
        if (size == 0) head = tail = temp;
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtidx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid index\n";
            return;
        } 
        if (idx == 0) insertAtHead(val);
        else if (idx == size) insertAtEnd(val);
        else {
            node* t = new node(val);
            node* temp = head;
            for (int i = 1; i < idx; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void deleteAtidx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index\n";
            return;
        }
        node* temp = head;
        if (idx == 0) {
            head = head->next;
            delete temp;
        } else {
            node* prev = NULL;
            for (int i = 0; i < idx; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            if (temp == tail) tail = prev;
            delete temp;
        }
        size--;
    }

    int getSize() {
        return size;
    }

    bool is_empty() {
        return head == NULL;
    }

    void rotateRight(int k) {
        if (size == 0 || k <= 0) return;
        k = k % size;
        if (k == 0) return;
        node* fast = head;
        node* slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        tail = slow;
    }

    void reverse() {
        node* prev = NULL;
        node* current = head;
        node* next = NULL;
        tail = head;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void append(int val) {
        insertAtEnd(val);
    }

    void prepend(int val) {
        insertAtHead(val);
    }

    void merge(LinkedList& LinkedList2) {
        if (LinkedList2.head == NULL) return;
        if (head == NULL) {
            head = LinkedList2.head;
            tail = LinkedList2.tail;
        } else {
            tail->next = LinkedList2.head;
            tail = LinkedList2.tail;
        }
        size += LinkedList2.size;
        LinkedList2.head = LinkedList2.tail = NULL;
        LinkedList2.size = 0;
    }

    void interleave(LinkedList& LinkedList2) {
        node* tempA = head;
        node* tempB = LinkedList2.head;
        node* next1 = NULL;
        node* next2 = NULL;

        while (tempA != NULL && tempB != NULL) {
            next1 = tempA->next;
            next2 = tempB->next;

            tempA->next = tempB;
            tempB->next = next1;

            tempA = next1;
            tempB = next2;
        }

        LinkedList2.head = NULL;
        LinkedList2.size = 0;
    }

    node* getMiddle() {
        if (head == NULL) return NULL;
        node* slow = head;
        node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    int indexOf(int val) {
        node* temp = head;
        int index = 0;
        while (temp != NULL) {
            if (temp->val == val) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    LinkedList* splitAtidx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index\n";
            return NULL;
        }
        LinkedList* temp = new LinkedList();
        if (idx == 0) {
            temp->head = head;
            temp->tail = tail;
            temp->size = size;
            head = tail = NULL;
            size = 0;
            return temp;
        }
        node* current = head;
        for (int i = 1; i < idx; i++) {
            current = current->next;
        }
        temp->head = current->next;
        temp->tail = tail;
        temp->size = size - idx;
        current->next = NULL;
        tail = current;
        size = idx;
        return temp;
    }
};

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);
    
    ll.display();

    ll.insertAtidx(2, 6);
    ll.display();

    ll.deleteAtidx(3);
    ll.display();


    ll.rotateRight(2);
    ll.display();

    ll.reverse();
    ll.display();


    int index = ll.indexOf(6);

    LinkedList* splitList = ll.splitAtidx(2);
    ll.display();
    splitList->display();

    LinkedList ll2;
    ll2.append(10);
    ll2.append(20);
    ll2.append(30);

    ll.merge(ll2);
    ll.display();

    LinkedList ll3;
    ll3.append(100);
    ll3.append(200);

    ll.interleave(ll3);
    ll.display();

    return 0;
}
