#include "ojol.h"
#include <iostream>

void createListOjol(ListOjol& list) {
    list.first = nullptr;
}

NodeOjol* createNodeOjol(const Ojol& data) {
    NodeOjol* node = new NodeOjol;
    node->data = data;
    node->next = nullptr;
    return node;
}

void insertLastOjol(ListOjol& list, const Ojol& data) {
    NodeOjol* node = createNodeOjol(data);
    if (list.first == nullptr) {
        list.first = node;
    } else {
        NodeOjol* temp = list.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

NodeOjol* findOjolById(const ListOjol& list, const std::string& id) {
    NodeOjol* temp = list.first;
    while (temp != nullptr) {
        if (temp->data.id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void deleteOjolById(ListOjol& list, const std::string& id) {
    if (list.first == nullptr) return;
    if (list.first->data.id == id) {
        NodeOjol* temp = list.first;
        list.first = list.first->next;
        delete temp;
        return;
    }
    NodeOjol* prev = list.first;
    NodeOjol* curr = list.first->next;
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

void showAllOjol(const ListOjol& list) {
    NodeOjol* temp = list.first;
    while (temp != nullptr) {
        printOjol(temp->data);
        temp = temp->next;
    }
}

void printOjol(const Ojol& data) {
    std::cout << "ID: " << data.id << ", Nama: " << data.nama << std::endl;
}
