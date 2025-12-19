#ifndef OJOL_H
#define OJOL_H

#include <string>

struct Ojol {
    std::string id;
    std::string nama;
    // Tambah field lain jika perlu, misalnya rating, kendaraan
};

struct NodeOjol {
    Ojol data;
    NodeOjol* next;
};

struct ListOjol {
    NodeOjol* first;
};

// Deklarasi fungsi
void createListOjol(ListOjol& list);
NodeOjol* createNodeOjol(const Ojol& data);
void insertLastOjol(ListOjol& list, const Ojol& data);
NodeOjol* findOjolById(const ListOjol& list, const std::string& id);
void deleteOjolById(ListOjol& list, const std::string& id);
void showAllOjol(const ListOjol& list);
void printOjol(const Ojol& data);

#endif
