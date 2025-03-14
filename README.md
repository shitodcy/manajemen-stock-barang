# 📌 Katalog Produk - Aplikasi Manajemen Produk dengan C++

## 📝 Deskripsi
Aplikasi ini adalah program sederhana untuk mengelola katalog produk menggunakan C++. Dengan aplikasi ini, Anda bisa menambah, melihat, memperbarui, menghapus, mengurutkan, dan mencari produk dengan mudah. Selain itu, riwayat perubahan produk juga disimpan!

## 🔥 Fitur Utama
✅ **Tambah Produk** - Menambahkan produk baru ke katalog.
✅ **Lihat Produk** - Menampilkan daftar produk yang tersedia.
✅ **Update Produk** - Mengubah informasi produk yang ada.
✅ **Hapus Produk** - Menghapus produk dari katalog.
✅ **Urutkan Produk** - Mengurutkan produk berdasarkan merek.
✅ **Cari Produk** - Menemukan produk berdasarkan merek.
✅ **Riwayat Perubahan** - Menampilkan perubahan produk sebelumnya.

## 🚀 Cara Menggunakan
1. **Kompilasi kode**
   ```sh
   g++ katalog_produk.cpp -o katalog_produk
   ```
2. **Jalankan program**
   ```sh
   ./katalog_produk
   ```
3. Pilih menu yang tersedia sesuai kebutuhan.

## 🏗️ Struktur Program
- **`struct Produk`** ➜ Menyimpan informasi produk (merek, stok, harga).
- **`katalogProduk[]`** ➜ Array penyimpan daftar produk (maksimal 20).
- **`stack riwayatProduk`** ➜ Menyimpan riwayat perubahan produk (maksimal 10).
- **CRUD (Create, Read, Update, Delete)** ➜ Mengelola produk dengan mudah.
- **Sorting & Searching** ➜ 
  - **Bubble Sort** untuk mengurutkan produk berdasarkan merek.
  - **Binary Search** untuk mencari produk lebih cepat.

## 📊 Contoh Output
```sh
Menu:
1. Tambah produk
2. Lihat produk
3. Update produk
4. Hapus produk
5. Urutkan produk (berdasarkan merek)
6. Cari produk (berdasarkan merek)
7. Lihat riwayat produk
0. Keluar
Pilihan Anda: 1
Masukkan merek produk: Apple
Masukkan stok produk: 50
Masukkan harga produk: 15000
Produk berhasil ditambahkan!
```

## 📜 Lisensi
Proyek ini dilisensikan di bawah **MIT License**. Lihat file `LICENSE` untuk lebih lanjut.

