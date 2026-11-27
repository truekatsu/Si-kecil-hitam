#include <iostream>
#include "AlatLaboratorium.hpp"
using namespace std;


AlatLaboratorium::AlatLaboratorium(string nama, string kategori, int jumlah) {
    this->nama = nama;
    this->kategori = kategori;
    this->jumlah = (jumlah < 0) ? 0 : jumlah;
}

void AlatLaboratorium::tampilkanInfo() {
    cout << "Nama     : " << nama << endl;
    cout << "Kategori : " << kategori << endl;
    cout << "Jumlah   : " << jumlah << endl;
    cout << "---------------------------" << endl;
}

void AlatLaboratorium::tambahJumlah(int n) {
    if (n <= 0) {
        cout << "[ERROR] Jumlah tambahan harus lebih dari 0." << endl;
        return;
    }
    jumlah += n;
}

void AlatLaboratorium::kurangiJumlah(int n) {
    if (n <= 0) {
        cout << "[ERROR] Jumlah pengurangan harus lebih dari 0." << endl;
        return;
    }
    if (n > jumlah) {
        cout << "[ERROR] Stok " << nama << " hanya " << jumlah
             << ", tidak bisa dikurangi " << n << "." << endl;
        return;
    }
    jumlah -= n;
}

string AlatLaboratorium::getNama() {
    return nama;
}

string AlatLaboratorium::getKategori() {
    return kategori;
}

int AlatLaboratorium::getJumlah() {
    return jumlah;
}
