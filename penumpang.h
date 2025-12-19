#ifndef PENUMPANG_H
#define PENUMPANG_H

#include <string>

struct Penumpang {
    std::string id;
    std::string nama;
    // Tambah field lain jika perlu, misalnya lokasi
};

struct NodePenumpang {
    Penumpang data;
    NodePenumpang* next;
};

struct ListPenumpang {
    NodePenumpang* first;
};

// Deklarasi fungsi
void createListPenumpang(ListPenumpang& list);
NodePenumpang* createNodePenumpang(const Penumpang& data);
void insertLastPenumpang(ListPenumpang& list, const Penumpang& data);
NodePenumpang* findPenumpangById(const ListPenumpang& list, const std::string& id);
void deletePenumpangById(ListPenumpang& list, const std::string& id);
void showAllPenumpang(const ListPenumpang& list);
void printPenumpang(const Penumpang& data);

#endif
