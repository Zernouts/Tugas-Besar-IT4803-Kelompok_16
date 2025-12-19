#include "penumpang.h"
#include <iostream>

void createListPenumpang(ListPenumpang& list) {
    list.first = nullptr;
}

NodePenumpang* createNodePenumpang(const Penumpang& data) {
    NodePenumpang* node = new NodePenumpang;
    node->data = data;
    node->next = nullptr;
    return node;
}

void insertLastPenumpang(ListPenumpang& list, const Penumpang& data) {
    NodePenumpang* node = createNodePenumpang(data);
    if (list.first == nullptr) {
        list.first = node;
    } else {
        NodePenumpang* temp = list.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

NodePenumpang* findPenumpangById(const ListPenumpang& list, const std::string& id) {
    NodePenumpang* temp = list.first;
    while (temp != nullptr) {
        if (temp->data.id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void deletePenumpangById(ListPenumpang& list, const std::string& id) {
    if (list.first == nullptr) return;
    if (list.first->data.id == id) {
        NodePenumpang* temp = list.first;
        list.first = list.first->next;
        delete temp;
        return;
    }
    NodePenumpang* prev = list.first;
    NodePenumpang* curr = list.first->next;
    while (curr != nullptr) {
        if (curr->data.id == id) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void showAllPenumpang(const ListPenumpang& list) {
    NodePenumpang* temp = list.first;
    while (temp != nullptr) {
        printPenumpang(temp->data);
        temp = temp->next;
    }
}

void printPenumpang(const Penumpang& data) {
    std::cout << "ID: " << data.id << ", Nama: " << data.nama << std::endl;
}
