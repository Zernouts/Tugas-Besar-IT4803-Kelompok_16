#ifndef RELASI_H
#define RELASI_H

#include "ojol.h"
#include "penumpang.h"
#include <string>

struct RelasiInfo {
    std::string idRelasi;
    double harga;  // Contoh info relasi
    // Tambah field lain jika perlu, misalnya tanggal
};

struct NodeRelasi {
    NodeOjol* parent;  // Pointer ke Ojol
    NodePenumpang* child;  // Pointer ke Penumpang
    RelasiInfo info;
    NodeRelasi* next;
};

struct ListRelasi {
    NodeRelasi* first;
};

// Deklarasi fungsi
void createListRelasi(ListRelasi& list);
NodeRelasi* createNodeRelasi(NodeOjol* parent, NodePenumpang* child, const RelasiInfo& info);
void insertRelasi(ListRelasi& list, NodeOjol* parent, NodePenumpang* child, const RelasiInfo& info);
void deleteRelasi(ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang, const std::string& idRelasi);
void deleteAllRelasiByOjol(ListRelasi& list, NodeOjol* ojol);
void deleteAllRelasiByPenumpang(ListRelasi& list, NodePenumpang* penumpang);
bool existsRelasi(const ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang);
void showChildrenOfOjol(const ListRelasi& list, const std::string& idOjol);
void showParentsOfChild(const ListRelasi& list, const std::string& idPenumpang);
void showParentWithChildrenAndRelasi(const ListRelasi& list, const ListOjol& listOjol);
void showChildWithParentsAndRelasi(const ListRelasi& list, const ListPenumpang& listPenumpang);
int countChildrenOfOjol(const ListRelasi& list, const std::string& idOjol);
int countParentsOfChild(const ListRelasi& list, const std::string& idPenumpang);
int countChildrenWithoutParent(const ListRelasi& list, const ListPenumpang& listPenumpang);
int countParentsWithoutChild(const ListRelasi& list, const ListOjol& listOjol);
void editRelasiChangeChild(ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang, const std::string& idRelasi, NodePenumpang* newChild);
void editRelasiChangeParent(ListRelasi& list, const std::string& idOjol, const std::string& idPenumpang, const std::string& idRelasi, NodeOjol* newParent);

#endif
