#include <iostream>
#include <string>

using namespace std;

// Struct untuk menyimpan data info mahasiswa
struct info {
    string nim;
    string nama;
    string kehadiran;
};

// Struct untuk elemen list
struct ElmList {
    info mhs;
    ElmList* next;
};

// Struct untuk List
struct List {
    ElmList* first;
};

//  Make list
void createList(List &L) {
    L.first = nullptr;
}

// Alokasi elemen baru
ElmList* createNewElement(string nim, string nama, string kehadiran) {
    ElmList* P = new ElmList;
    P->mhs.nim = nim;
    P->mhs.nama = nama;
    P->mhs.kehadiran = kehadiran;
    P->next = nullptr;
    return P;
}

// Menambahkan elemen ke posisi terakhir
void insertLast(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        ElmList* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// Menampilkan isi list
void printList(List L) {
    ElmList* P = L.first;
    while (P != nullptr) {
        cout << "NIM       : " << P->mhs.nim << endl;
        cout << "Nama      : " << P->mhs.nama << endl;
        cout << "Kehadiran : " << P->mhs.kehadiran << endl;
        cout << "-------------------------" << endl;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);

    string nim, nama, kehadiran;

    // Input 40 data (Format: NIM NAMA KEHADIRAN)
    for (int i = 0; i < 40; i++) {
        cin >> nim >> nama >> kehadiran;
        ElmList* P = createNewElement(nim, nama, kehadiran);
        insertLast(L, P);
    }

    // Tampilkan isi list
    printList(L);

    return 0;
}