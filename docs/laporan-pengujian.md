# Hasil Testing

Compile pakai:

```
g++ src/main.cpp src/AlatLaboratorium.cpp -o inventaris
```

Compile berhasil, tidak ada error.

## Skenario yang dicoba

| No | Yang dicoba | Input | Hasil | Keterangan |
|----|-------------|-------|-------|------------|
| 1 | Lihat semua alat | 1 | Muncul 3 alat (Mikroskop, Tabung Reaksi, Multimeter) | Berhasil |
| 2 | Tambah alat baru | 2, Gelas Ukur, Gelas Kimia, 15 | Alat berhasil ditambahkan | Berhasil |
| 3 | Tambah alat yang sudah ada | 2, Mikroskop | Muncul pesan alat sudah ada | Berhasil |
| 4 | Tambah jumlah | 3, Multimeter, 4 | Stok jadi 12 | Berhasil |
| 5 | Kurangi lebih dari stok | 4, Mikroskop, 10 | Muncul error, stok tetap 5 | Berhasil |
| 6 | Kurangi jumlah | 4, Mikroskop, 2 | Stok jadi 3 | Berhasil |
| 7 | Tambah jumlah minus | 3, Tabung Reaksi, -5 | Muncul error, stok tetap 40 | Berhasil |
| 8 | Cari info alat | 5, Gelas Ukur | Info Gelas Ukur muncul | Berhasil |
| 9 | Cari alat yang tidak ada | 5, Bunsen | Alat tidak ditemukan | Berhasil |
| 10 | Input huruf di menu | abc | Input harus angka! | Berhasil |
| 11 | Menu yang tidak ada | 9 | Menu tidak ada | Berhasil |
| 12 | Lihat semua alat lagi | 1 | Muncul 4 alat dengan stok yang sudah berubah | Berhasil |
| 13 | Keluar | 0 | Program selesai | Berhasil |

Input yang dipakai ada di file `tests/skenario-input.txt`, bisa dijalankan pakai:

```
inventaris < tests/skenario-input.txt
```

Output lengkapnya ada di `docs/contoh-output.txt`.

## Catatan

- File cpp awalnya namanya `Method-laboratorium.cpp` dan ada di luar folder src,
  jadi dipindah ke `src/AlatLaboratorium.cpp` biar sesuai struktur folder.
- Kalau masukin huruf di menu, `cin` bisa error dan looping terus, makanya
  ditambah `cin.clear()` dan `cin.ignore()`.
- Nama alat ada yang pakai spasi (contoh "Tabung Reaksi"), jadi inputnya pakai
  `getline` bukan `cin >>`.
- Pengecekan nama alat masih peka huruf besar/kecil, jadi "mikroskop" dan
  "Mikroskop" dianggap beda.
