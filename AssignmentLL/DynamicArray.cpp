#include<iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;
    int fact;

    void resize(int capacity1) {
        int* Data1 = new int[capacity1];
        for (int i = 0; i < size; i++) {
            Data1[i] = data[i];
        }
        delete[] data;
        data = Data1;
        capacity = capacity1;
    }

public:
    DynamicArray(int fact = 2) {
        capacity = 1;
        size = 0;
        this->fact = fact;
        data = new int[capacity];
    }


    void insertAtidx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid index\n";
            return;
        }
        if (size == capacity) {
            resize(capacity * fact);
        }
        for (int i = size; i > idx; i--) {
            data[i] = data[i - 1];
        }
        data[idx] = val;
        size++;
    }

    void deleteAtidx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = idx; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size > 0 && size == capacity / (fact * fact)) {
            resize(capacity / fact);
        }
    }

    int getSize() {
        return size;
    }

    bool is_empty() {
        return size == 0;
    }

    void rotateRight(int k) {
        if (size == 0 || k <= 0) return;
        k = k % size;
        if (k == 0) return;
        int* Data1 = new int[k];
        for (int i = 0; i < k; i++) {
            Data1[i] = data[size - k + i];
        }
        for (int i = size - 1; i >= k; i--) {
            data[i] = data[i - k];
        }
        for (int i = 0; i < k; i++) {
            data[i] = Data1[i];
        }
        delete[] Data1;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = data[i];
            data[i] = data[size - i - 1];
            data[size - i - 1] = temp;
        }
    }

    void append(int val) {
        if (size == capacity) {
            resize(capacity * fact);
        }
        data[size++] = val;
    }

    void prepend(int val) {
        insertAtidx(0, val);
    }

    void merge(DynamicArray& arr) {
        while (size + arr.size > capacity) {
            resize(capacity * fact);
        }
        for (int i = 0; i < arr.size; i++) {
            data[size++] = arr.data[i];
        }
    }

    void interleave(DynamicArray& arr) {
        int newSize = size + arr.size;
        while (capacity < newSize) {
            resize(capacity * fact);
        }
        int* Data1 = new int[newSize];
        int i = 0, j = 0, k = 0;
        while (i < size && j < arr.size) {
            Data1[k++] = data[i++];
            Data1[k++] = arr.data[j++];
        }
        while (i < size) {
            Data1[k++] = data[i++];
        }
        while (j < arr.size) {
            Data1[k++] = arr.data[j++];
        }
        delete[] data;
        data = Data1;
        size = newSize;
    }

    int getMiddle() {
        if (size == 0) return -1; 
        return data[size / 2];
    }

    int indexOf(int val) {
        for (int i = 0; i < size; i++) {
            if (data[i] == val) return i;
        }
        return -1;
    }

    DynamicArray* splitAtidx(int idx) {
        if (idx < 0 || idx > size) {
            cout << "Invalid index\n";
            return NULL;
        }
        DynamicArray* temp = new DynamicArray(fact);
        for (int i = idx; i < size; i++) {
            temp->append(data[i]);
        }
        size = idx;
        return temp;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);

    arr.display();

    arr.insertAtidx(2, 6);
    arr.display();

    arr.deleteAtidx(3);
    arr.display();


    arr.rotateRight(2);
    arr.display();

    arr.reverse();
    arr.display();


    int index = arr.indexOf(6);

    DynamicArray* splitArr = arr.splitAtidx(2);
    arr.display();
    splitArr->display();

    DynamicArray arr2;
    arr2.append(10);
    arr2.append(20);
    arr2.append(30);

    arr.merge(arr2);
    arr.display();

    DynamicArray arr3;
    arr3.append(100);
    arr3.append(200);

    arr.interleave(arr3);
    arr.display();

    return 0;
}
