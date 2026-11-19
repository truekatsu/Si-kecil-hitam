#ifndef ALAT_LABORATORIUM_HPP
#define ALAT_LABORATORIUM_HPP

#include <string>
using namespace std;

class AlatLaboratorium {
private:

    string nama;
    string kategori;
    int jumlah;

public:
  
    AlatLaboratorium(string nama, string kategori, int jumlah);

   
    void tampilkanInfo();
    void tambahJumlah(int n);
    void kurangiJumlah(int n);

   
    string getNama();
    string getKategori();
    int getJumlah();
};

#endif
