#include <iostream>
#include <Windows.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasDuplicatePairRecursive(Node* current, int currentValue) {
    if (current == nullptr) // базовий випадок: якщо поточний елемент nullptr, то пара не знайдена
        return false;

    if (current->data == currentValue) // перевірка наявності пари
        return true;

    return hasDuplicatePairRecursive(current->next, currentValue); // рекурсивний виклик для наступного елементу
}

bool hasDuplicatePair(Node* head) {
    if (head == nullptr || head->next == nullptr) // якщо список порожній або має лише один елемент, повертаємо false
        return false;

    int currentValue = head->data; // значення поточного елементу
    return hasDuplicatePairRecursive(head->next, currentValue) || hasDuplicatePair(head->next); // рекурсивний виклик для наступного елементу
}

void createList(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr;
    tail = nullptr;

    if (size <= 0) // базовий випадок: якщо розмір масиву не більше 0
        return;

    head = new Node();//1
    head->data = values[0];//2
    head->next = nullptr;//3
    tail = head;

    createList(head->next, tail, values + 1, size - 1); // рекурсивний виклик для наступного елементу
}

void printList(Node* head) {
    if (head == nullptr) // базовий випадок: якщо список порожній, закінчуємо рекурсію
        return;

    cout << head->data << " ";
    printList(head->next); // рекурсивний виклик для наступного елементу
}

int main() {
    int values[] = { 1, 2, 3, 4, 5, 2 };
    int size = sizeof(values) / sizeof(values[0]);

    Node* head = nullptr;
    Node* tail = nullptr;

    createList(head, tail, values, size);

    cout << "Список елементів:" << endl;
    printList(head);
    cout << endl;

    if (hasDuplicatePair(head)) {
        cout << "Список містить пару елементів з однаковими значеннями." << endl;
    }
    else {
        cout << "Список не містить пару елементів з однаковими значеннями." << endl;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
