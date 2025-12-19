#include "relasi.h"
#include <iostream>

void createListRelasi(ListRelasi& list) {
    list.first = nullptr;
}

NodeRelasi* createNodeRelasi(NodeOjol* parent, NodePenumpang* child, const RelasiInfo& info) {
    NodeRelasi* node = new NodeRelasi;
    node->parent = parent;
    node->child = child;
    node->info = info;
    node->next = nullptr;
    return node;
}

void insertRelasi(ListRelasi& list, NodeOjol* parent, NodePenumpang* child, const RelasiInfo& info) {
    NodeRelasi* node = createNodeRelasi(parent, child, info);
    if (list.first == nullptr) {
        list.first = node;
    } else {
        NodeRelasi* temp = list.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void deleteRelasi(ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang, const std::string& idRelasi) {
    if (list.first == nullptr) return;
    if (list.first->parent->data.id == idOjol && list.first->child->data.id == idPenumpang && list.first->info.idRelasi == idRelasi) {
        NodeRelasi* temp = list.first;
        list.first = list.first->next;
        delete temp;
        return;
    }
    NodeRelasi* prev = list.first;
    NodeRelasi* curr = list.first->next;
    while (curr != nullptr) {
        if (curr->parent->data.id == idOjol && curr->child->data.id == idPenumpang && curr->info.idRelasi == idRelasi) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void deleteAllRelasiByOjol(ListRelasi& list, NodeOjol* ojol) {
    NodeRelasi* temp = list.first;
    NodeRelasi* prev = nullptr;
    while (temp != nullptr) {
        if (temp->parent == ojol) {
            if (prev == nullptr) {
                list.first = temp->next;
                delete temp;
                temp = list.first;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void deleteAllRelasiByPenumpang(ListRelasi& list, NodePenumpang* penumpang) {
    NodeRelasi* temp = list.first;
    NodeRelasi* prev = nullptr;
    while (temp != nullptr) {
        if (temp->child == penumpang) {
            if (prev == nullptr) {
                list.first = temp->next;
                delete temp;
                temp = list.first;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

bool existsRelasi(const ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang) {
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->parent->data.id == idOjol && temp->child->data.id == idPenumpang) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void showChildrenOfOjol(const ListRelasi& list, const std::string& idOjol) {
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->parent->data.id == idOjol) {
            printPenumpang(temp->child->data);
        }
        temp = temp->next;
    }
}

void showParentsOfChild(const ListRelasi& list, const std::string& idPenumpang) {
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->child->data.id == idPenumpang) {
            printOjol(temp->parent->data);
        }
        temp = temp->next;
    }
}

void showParentWithChildrenAndRelasi(const ListRelasi& list, const ListOjol& listOjol) {
    NodeOjol* tempOjol = listOjol.first;
    while (tempOjol != nullptr) {
        std::cout << "Ojol: " << tempOjol->data.nama << std::endl;
        NodeRelasi* tempRel = list.first;
        while (tempRel != nullptr) {
            if (tempRel->parent == tempOjol) {
                std::cout << "  - Penumpang: " << tempRel->child->data.nama << ", Harga: " << tempRel->info.harga << std::endl;
            }
            tempRel = tempRel->next;
        }
        tempOjol = tempOjol->next;
    }
}

void showChildWithParentsAndRelasi(const ListRelasi& list, const ListPenumpang& listPenumpang) {
    NodePenumpang* tempPen = listPenumpang.first;
    while (tempPen != nullptr) {
        std::cout << "Penumpang: " << tempPen->data.nama << std::endl;
        NodeRelasi* tempRel = list.first;
        while (tempRel != nullptr) {
            if (tempRel->child == tempPen) {
                std::cout << "  - Ojol: " << tempRel->parent->data.nama << ", Harga: " << tempRel->info.harga << std::endl;
            }
            tempRel = tempRel->next;
        }
        tempPen = tempPen->next;
    }
}

int countChildrenOfOjol(const ListRelasi& list, const std::string& idOjol) {
    int count = 0;
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->parent->data.id == idOjol) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int countParentsOfChild(const ListRelasi& list, const std::string& idPenumpang) {
    int count = 0;
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->child->data.id == idPenumpang) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int countChildrenWithoutParent(const ListRelasi& list, const ListPenumpang& listPenumpang) {
    int count = 0;
    NodePenumpang* temp = listPenumpang.first;
    while (temp != nullptr) {
        bool hasParent = false;
        NodeRelasi* tempRel = list.first;
        while (tempRel != nullptr) {
            if (tempRel->child == temp) {
                hasParent = true;
                break;
            }
            tempRel = tempRel->next;
        }
        if (!hasParent) count++;
        temp = temp->next;
    }
    return count;
}

int countParentsWithoutChild(const ListRelasi& list, const ListOjol& listOjol) {
    int count = 0;
    NodeOjol* temp = listOjol.first;
    while (temp != nullptr) {
        bool hasChild = false;
        NodeRelasi* tempRel = list.first;
        while (tempRel != nullptr) {
            if (tempRel->parent == temp) {
                hasChild = true;
                break;
            }
            tempRel = tempRel->next;
        }
        if (!hasChild) count++;
        temp = temp->next;
    }
    return count;
}

void editRelasiChangeChild(ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang, const std::string& idRelasi, NodePenumpang* newChild) {
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->parent->data.id == idOjol && temp->child->data.id == idPenumpang && temp->info.idRelasi == idRelasi) {
            temp->child = newChild;
            return;
        }
        temp = temp->next;
    }
}

void editRelasiChangeParent(ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang, const std::string& idRelasi, NodeOjol* newParent) {
    NodeRelasi* temp = list.first;
    while (temp != nullptr) {
        if (temp->parent->data.id == idOjol && temp->child->data.id == idPenumpang && temp->info.idRelasi == idRelasi) {
            temp->parent = newParent;
            return;
        }
        temp = temp->next;
    }
}
