
# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi  
**Semester**: Genap / Tahun Ajaran 2024–2025  
**Nama**: `fikianto`  
**NIM**: `240202899`  
**Modul yang Dikerjakan**:  
`Modul 3 – Copy-on-Write (CoW) dan Shared Memory`

---

## 📌 Deskripsi Singkat Tugas

**Modul 3 – Copy-on-Write dan Shared Memory**  
Modul ini menambahkan dua fitur penting ke dalam kernel XV6:  
- **Copy-on-Write (CoW)**: untuk efisiensi proses `fork()` dengan berbagi halaman memori sampai terjadi penulisan.  
- **Shared Memory**: memungkinkan dua proses mengakses halaman memori yang sama menggunakan `shmget()` dan `shmrelease()`.

---

## 🛠️ Rincian Implementasi

- Menambahkan sistem manajemen `ref_count[]` untuk halaman fisik di `vm.c`
- Mengimplementasikan `cowuvm()` untuk menggantikan `copyuvm()` saat `fork`
- Menambahkan bit permission `PTE_COW` dan handler page fault agar salinan dilakukan saat proses menulis
- Menambahkan syscall `shmget()` dan `shmrelease()` untuk akses shared memory
- Mengelola page mapping shared memory di `vm.c` dan `proc.c`
- Membuat dua program uji: `cowtest.c` dan `shmtest.c`

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

- `cowtest`: untuk menguji apakah proses child dan parent membaca isi yang berbeda setelah CoW dilakukan
- `shmtest`: untuk menguji apakah child dan parent dapat membaca isi shared memory yang berbeda

---

## 📷 Hasil Uji

### 📍 Output `cowtest`

```
Child sees: Y
Parent sees: X
```

### 📍 Output `shmtest`

```
Child reads: A
Parent reads: B
```

📷 Screenshot hasil pengujian:  
![Hasil cowtest dan shmtest](./modul3.png)

---

## ⚠️ Kendala yang Dihadapi

- Salah menangani page fault menyebabkan kernel panic saat fork
- Lupa menambahkan pengecekan `PTE_COW` sebelum menyalin halaman
- Salah mapping alamat shared memory ke `USERTOP - PGSIZE`, menyebabkan konflik

---

## 📚 Referensi

- Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)
- Repositori xv6-public: [https://github.com/mit-pdos/xv6-public](https://github.com/mit-pdos/xv6-public)
- Dokumentasi virtual memory dan diskusi CoW di Stack Overflow

