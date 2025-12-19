#include <iostream>
#include <string>
#include "ojol.h"
#include "penumpang.h"
#include "relasi.h"

using namespace std;

// Deklarasi list global
ListOjol listOjol;
ListPenumpang listPenumpang;
ListRelasi listRelasi;

// Fungsi seedDummy untuk data awal
void seedDummy(ListOjol& listOjol, ListPenumpang& listPenumpang, ListRelasi& listRelasi) {
    createListOjol(listOjol);
    createListPenumpang(listPenumpang);
    createListRelasi(listRelasi);

    // Tambah Ojol dummy
    Ojol ojol1 = {"O001", "Driver A"};
    Ojol ojol2 = {"O002", "Driver B"};
    Ojol ojol3 = {"O003", "Driver C"};
    insertLastOjol(listOjol, ojol1);
    insertLastOjol(listOjol, ojol2);
    insertLastOjol(listOjol, ojol3);

    // Tambah Penumpang dummy
    Penumpang pen1 = {"P001", "Passenger A"};
    Penumpang pen2 = {"P002", "Passenger B"};
    Penumpang pen3 = {"P003", "Passenger C"};
    insertLastPenumpang(listPenumpang, pen1);
    insertLastPenumpang(listPenumpang, pen2);
    insertLastPenumpang(listPenumpang, pen3);

    // Tambah Relasi dummy
    NodeOjol* o1 = findOjolById(listOjol, "O001");
    NodeOjol* o2 = findOjolById(listOjol, "O002");
    NodePenumpang* p1 = findPenumpangById(listPenumpang, "P001");
    NodePenumpang* p2 = findPenumpangById(listPenumpang, "P002");
    NodePenumpang* p3 = findPenumpangById(listPenumpang, "P003");

    RelasiInfo info1 = {"R001", 50000};
    RelasiInfo info2 = {"R002", 60000};
    RelasiInfo info3 = {"R003", 70000};
    insertRelasi(listRelasi, o1, p1, info1);
    insertRelasi(listRelasi, o2, p2, info2);
    insertRelasi(listRelasi, o1, p3, info3);

    cout << "Data dummy berhasil dimuat!" << endl;
}

// Menu Insert Ojol
void menuInsertOjol(ListOjol& list) {
    string id, nama;
    cout << "Masukkan ID Ojol: ";
    cin >> id;
    cout << "Masukkan Nama Ojol: ";
    cin >> nama;
    Ojol data = {id, nama};
    insertLastOjol(list, data);
    cout << "Ojol berhasil ditambahkan!" << endl;
}

// Menu Insert Penumpang
void menuInsertPenumpang(ListPenumpang& list) {
    string id, nama;
    cout << "Masukkan ID Penumpang: ";
    cin >> id;
    cout << "Masukkan Nama Penumpang: ";
    cin >> nama;
    Penumpang data = {id, nama};
    insertLastPenumpang(list, data);
    cout << "Penumpang berhasil ditambahkan!" << endl;
}

// Menu Insert Relasi
void menuInsertRelasi(ListRelasi& listRelasi, ListOjol& listOjol, ListPenumpang& listPenumpang) {
    string idOjol, idPenumpang, idRelasi;
    double harga;
    cout << "Masukkan ID Ojol: ";
    cin >> idOjol;
    cout << "Masukkan ID Penumpang: ";
    cin >> idPenumpang;
    NodeOjol* ojol = findOjolById(listOjol, idOjol);
    NodePenumpang* penumpang = findPenumpangById(listPenumpang, idPenumpang);
    if (ojol && penumpang) {
        cout << "Masukkan ID Relasi: ";
        cin >> idRelasi;
        cout << "Masukkan Harga: ";
        cin >> harga;
        RelasiInfo info = {idRelasi, harga};
        insertRelasi(listRelasi, ojol, penumpang, info);
        cout << "Relasi berhasil ditambahkan!" << endl;
    } else {
        cout << "Ojol atau Penumpang tidak ditemukan!" << endl;
    }
}

// Menu Delete Ojol
void menuDeleteOjol(ListRelasi& listRelasi, ListOjol& listOjol) {
    string id;
    cout << "Masukkan ID Ojol yang akan dihapus: ";
    cin >> id;
    NodeOjol* ojol = findOjolById(listOjol, id);
    if (ojol) {
        deleteAllRelasiByOjol(listRelasi, ojol);
        deleteOjolById(listOjol, id);
        cout << "Ojol dan relasinya berhasil dihapus!" << endl;
    } else {
        cout << "Ojol tidak ditemukan!" << endl;
    }
}

// Menu Delete Penumpang
void menuDeletePenumpang(ListRelasi& listRelasi, ListPenumpang& listPenumpang) {
    string id;
    cout << "Masukkan ID Penumpang yang akan dihapus: ";
    cin >> id;
    NodePenumpang* penumpang = findPenumpangById(listPenumpang, id);
    if (penumpang) {
        deleteAllRelasiByPenumpang(listRelasi, penumpang);
        deletePenumpangById(listPenumpang, id);
        cout << "Penumpang dan relasinya berhasil dihapus!" << endl;
    } else {
        cout << "Penumpang tidak ditemukan!" << endl;
    }
}

// Menu Delete Relasi
void menuDeleteRelasi(ListRelasi& list) {
    string idOjol, idPenumpang, idRelasi;
    cout << "Masukkan ID Ojol: ";
    cin >> idOjol;
    cout << "Masukkan ID Penumpang: ";
    cin >> idPenumpang;
    cout << "Masukkan ID Relasi: ";
    cin >> idRelasi;
    deleteRelasi(list, idOjol, idPenumpang, idRelasi);
    cout << "Relasi berhasil dihapus!" << endl;
}

// Menu Find Ojol
void menuFindOjol(const ListOjol& list) {
    string id;
    cout << "Masukkan ID Ojol: ";
    cin >> id;
    NodeOjol* node = findOjolById(list, id);
    if (node) {
        printOjol(node->data);
    } else {
        cout << "Ojol tidak ditemukan!" << endl;
    }
}

// Menu Find Penumpang
void menuFindPenumpang(const ListPenumpang& list) {
    string id;
    cout << "Masukkan ID Penumpang: ";
    cin >> id;
    NodePenumpang* node = findPenumpangById(list, id);
    if (node) {
        printPenumpang(node->data);
    } else {
        cout << "Penumpang tidak ditemukan!" << endl;
    }
}

// Menu Find Apakah Relasi Ada
void menuFindApakahRelasiAda(const ListRelasi& list) {
    string idOjol, idPenumpang;
    cout << "Masukkan ID Ojol: ";
    cin >> idOjol;
    cout << "Masukkan ID Penumpang: ";
    cin >> idPenumpang;
    if (existsRelasi(list, idOjol, idPenumpang)) {
        cout << "Relasi ada!" << endl;
    } else {
        cout << "Relasi tidak ada!" << endl;
    }
}

// Menu Show Children of Ojol
void menuShowChildrenOfOjol(const ListRelasi& list) {
    string id;
    cout << "Masukkan ID Ojol: ";
    cin >> id;
    showChildrenOfOjol(list, id);
}

// Menu Show Parents of Child
void menuShowParentsOfChild(const ListRelasi& list) {
    string id;
    cout << "Masukkan ID Penumpang: ";
    cin >> id;
    showParentsOfChild(list, id);
}

// Menu Show All Ojol
void menuShowAllOjol(const ListOjol& list) {
    showAllOjol(list);
}

// Menu Show All Penumpang
void menuShowAllPenumpang(const ListPenumpang& list) {
    showAllPenumpang(list);
}

// Menu Show Parent with Children and Relasi
void menuShowParentWithChildrenAndRelasi(const ListRelasi& list, const ListOjol& listOjol) {
    showParentWithChildrenAndRelasi(list, listOjol);
}

// Menu Show Child with Parents and Relasi
void menuShowChildWithParentsAndRelasi(const ListRelasi& list, const ListPenumpang& listPenumpang) {
    showChildWithParentsAndRelasi(list, listPenumpang);
}

// Menu Count Children of Ojol
void menuCountChildrenOfOjol(const ListRelasi& list) {
    string id;
    cout << "Masukkan ID Ojol: ";
    cin >> id;
    int count = countChildrenOfOjol(list, id);
    cout << "Jumlah penumpang untuk Ojol " << id << ": " << count << endl;
}

// Menu Count Parents of Child
void menuCountParentsOfChild(const ListRelasi& list) {
    string id;
    cout << "Masukkan ID Penumpang: ";
    cin >> id;
    int count = countParentsOfChild(list, id);
    cout << "Jumlah ojol untuk Penumpang " << id << ": " << count << endl;
}

// Menu Count Children Without Parent
void menuCountChildrenWithoutParent(const ListRelasi& list, const ListPenumpang& listPenumpang) {
    int count = countChildrenWithoutParent(list, listPenumpang);
    cout << "Jumlah penumpang tanpa ojol: " << count << endl;
}

// Menu Count Parents Without Child
void menuCountParentsWithoutChild(const ListRelasi& list, const ListOjol& listOjol) {
    int count = countParentsWithoutChild(list, listOjol);
    cout << "Jumlah ojol tanpa penumpang: " << count << endl;
}

// Menu Edit Relasi Change Child
void menuEditRelasiChangeChild(ListRelasi& list, ListPenumpang& listPenumpang) {
    string idOjol, idPenumpang, idRelasi, newIdPenumpang;
    cout << "Masukkan ID Ojol: ";
    cin >> idOjol;
    cout << "Masukkan ID Penumpang Lama: ";
    cin >> idPenumpang;
    cout << "Masukkan ID Relasi: ";
    cin >> idRelasi;
    cout << "Masukkan ID Penumpang Baru: ";
    cin >> newIdPenumpang;
    NodePenumpang* newChild = findPenumpangById(listPenumpang, newIdPenumpang);
    if (newChild) {
        editRelasiChangeChild(list, idOjol, idPenumpang, idRelasi, newChild);
        cout << "Relasi berhasil diubah!" << endl;
    } else {
        cout << "Penumpang baru tidak ditemukan!" << endl;
    }
}

// Menu Edit Relasi Change Parent
void menuEditRelasiChangeParent(ListRelasi& list, ListOjol& listOjol) {
    string idOjol, idPenumpang, idRelasi, newIdOjol;
    cout << "Masukkan ID Ojol Lama: ";
    cin >> idOjol;
    cout << "Masukkan ID Penumpang: ";
    cin >> idPenumpang;
    cout << "Masukkan ID Relasi: ";
    cin >> idRelasi;
    cout << "Masukkan ID Ojol Baru: ";
    cin >> newIdOjol;
    NodeOjol* newParent = findOjolById(listOjol, newIdOjol);
    if (newParent) {
        editRelasiChangeParent(list, idOjol, idPenumpang, idRelasi, newParent);
        cout << "Relasi berhasil diubah!" << endl;
    } else {
        cout << "Ojol baru tidak ditemukan!" << endl;
    }
}

// Fungsi utama
int main() {
    seedDummy(listOjol, listPenumpang, listRelasi);
    int choice;
    do {
        cout << "\n=== Menu Sistem Ojol ===" << endl;
        cout << "1. Insert Ojol" << endl;
        cout << "2. Insert Penumpang" << endl;
        cout << "3. Insert Relasi" << endl;
        cout << "4. Delete Ojol" << endl;
        cout << "5. Delete Penumpang" << endl;
        cout << "6. Delete Relasi" << endl;
        cout << "7. Find Ojol" << endl;
        cout << "8. Find Penumpang" << endl;
        cout << "9. Find Apakah Relasi Ada" << endl;
        cout << "10. Show Children of Ojol" << endl;
        cout << "11. Show Parents of Child" << endl;
        cout << "12. Show All Ojol" << endl;
        cout << "13. Show All Penumpang" << endl;
        cout << "14. Show Parent with Children and Relasi" << endl;
        cout << "15. Show Child with Parents and Relasi" << endl;
        cout << "16. Count Children of Ojol" << endl;
        cout << "17. Count Parents of Child" << endl;
        cout << "18. Count Children Without Parent" << endl;
        cout << "19. Count Parents Without Child" << endl;
        cout << "20. Edit Relasi Change Child" << endl;
        cout << "21. Edit Relasi Change Parent" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: menuInsertOjol(listOjol); break;
            case 2: menuInsertPenumpang(listPenumpang); break;
            case 3: menuInsertRelasi(listRelasi, listOjol, listPenumpang); break;
            case 4: menuDeleteOjol(listRelasi, listOjol); break;
            case 5: menuDeletePenumpang(listRelasi, listPenumpang); break;
            case 6: menuDeleteRelasi(listRelasi); break;
            case 7: menuFindOjol(listOjol); break;
            case 8: menuFindPenumpang(listPenumpang); break;
            case 9: menuFindApakahRelasiAda(listRelasi); break;
            case 10: menuShowChildrenOfOjol(listRelasi); break;
            case 11: menuShowParentsOfChild(listRelasi); break;
            case 12: menuShowAllOjol(listOjol); break;
            case 13: menuShowAllPenumpang(listPenumpang); break;
            case 14: menuShowParentWithChildrenAndRelasi(listRelasi, listOjol); break;
            case 15: menuShowChildWithParentsAndRelasi(listRelasi, listPenumpang); break;
            case 16: menuCountChildrenOfOjol(listRelasi); break;
            case 17: menuCountParentsOfChild(listRelasi); break;
            case 18: menuCountChildrenWithoutParent(listRelasi, listPenumpang); break;
            case 19: menuCountParentsWithoutChild(listRelasi, listOjol); break;
            case 20: menuEditRelasiChangeChild(listRelasi, listPenumpang); break;
            case 21: menuEditRelasiChangeParent(listRelasi, listOjol); break;
            case 0: cout << "Keluar..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}
