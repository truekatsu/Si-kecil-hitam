#include <iostream>
#include <vector>
#include <string>
#include "AlatLaboratorium.hpp"
using namespace std;

int cariAlat(vector<AlatLaboratorium> &daftar, string nama) {
    for (int i = 0; i < daftar.size(); i++) {
        if (daftar[i].getNama() == nama) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<AlatLaboratorium> daftarAlat;

    daftarAlat.push_back(AlatLaboratorium("Mikroskop", "Optik", 5));
    daftarAlat.push_back(AlatLaboratorium("Tabung Reaksi", "Gelas Kimia", 40));
    daftarAlat.push_back(AlatLaboratorium("Multimeter", "Elektronika", 8));

    int pilih;
    string nama, kategori;
    int jumlah;

    do {
        cout << endl;
        cout << "=== INVENTARIS ALAT LABORATORIUM ===" << endl;
        cout << "1. Lihat semua alat" << endl;
        cout << "2. Tambah alat baru" << endl;
        cout << "3. Tambah jumlah alat" << endl;
        cout << "4. Kurangi jumlah alat" << endl;
        cout << "5. Cari info alat" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!" << endl;
            pilih = -1;
            continue;
        }
        cin.ignore(); t

        if (pilih == 1) {
            cout << endl << "--- Daftar Alat ---" << endl;
            if (daftarAlat.size() == 0) {
                cout << "Belum ada alat" << endl;
            }
            for (int i = 0; i < daftarAlat.size(); i++) {
                cout << i + 1 << "." << endl;
                daftarAlat[i].tampilkanInfo();
            }
        }
        else if (pilih == 2) {
            cout << "Nama alat : ";
            getline(cin, nama);

            if (cariAlat(daftarAlat, nama) != -1) {
                cout << "Alat " << nama << " sudah ada! pakai menu 3 untuk tambah jumlah" << endl;
            } else {
                cout << "Kategori  : ";
                getline(cin, kategori);
                cout << "Jumlah    : ";
                cin >> jumlah;

                if (jumlah < 0) {
                    cout << "Jumlah tidak boleh minus" << endl;
                } else {
                    daftarAlat.push_back(AlatLaboratorium(nama, kategori, jumlah));
                    cout << "Alat berhasil ditambahkan" << endl;
                }
            }
        }
        else if (pilih == 3 || pilih == 4) {
            cout << "Nama alat : ";
            getline(cin, nama);
            int index = cariAlat(daftarAlat, nama);

            if (index == -1) {
                cout << "Alat tidak ditemukan" << endl;
            } else {
                cout << "Jumlah    : ";
                cin >> jumlah;

                if (pilih == 3) {
                    daftarAlat[index].tambahJumlah(jumlah);
                } else {
                    daftarAlat[index].kurangiJumlah(jumlah);
                }
                cout << "Stok " << nama << " sekarang: " << daftarAlat[index].getJumlah() << endl;
            }
        }
        else if (pilih == 5) {
            cout << "Nama alat : ";
            getline(cin, nama);
            int index = cariAlat(daftarAlat, nama);

            if (index == -1) {
                cout << "Alat tidak ditemukan" << endl;
            } else {
                daftarAlat[index].tampilkanInfo();
            }
        }
        else if (pilih == 0) {
            cout << "Program selesai, terima kasih" << endl;
        }
        else {
            cout << "Menu tidak ada" << endl;
        }

    } while (pilih != 0);

    return 0;
}
