
# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi  
**Semester**: Genap / Tahun Ajaran 2024–2025  
**Nama**: `fikianto`  
**NIM**: `240202899`  
**Modul yang Dikerjakan**:  
`Modul 2 – Proses, Fork, dan Sinkronisasi`

---

## 📌 Deskripsi Singkat Tugas

**Modul 2 – Proses, Fork, dan Sinkronisasi**  
Modul ini menguji pemahaman mahasiswa tentang pembuatan proses (`fork`) dan sinkronisasi eksekusi antar proses menggunakan sistem call dasar pada XV6. Program `ptest` membuat dua child process dan mengatur urutan eksekusi agar outputnya tertib dan terstruktur.

---

## 🛠️ Rincian Implementasi

- Membuat program `ptest.c` yang memanggil `fork()` sebanyak dua kali
- Mengatur urutan output dengan menunggu child process selesai menggunakan `wait()`
- Setiap child menampilkan pesan selesai, diakhiri oleh parent
- Tidak ada system call baru yang ditambahkan ke kernel pada modul ini

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

- `ptest`: menguji proses beranak (fork) dan sinkronisasi antar parent dan child
- Output mengindikasikan child selesai terlebih dahulu, lalu parent

---

## 📷 Hasil Uji

### 📍 Output `ptest`

```
Child 2 selesai
Child 1 selesai
Parent selesai
```

📷 Screenshot hasil pengujian:  
### 📸 screenshoots:
(./screnshoot/modul2.png)
---

## ⚠️ Kendala yang Dihadapi

- Pernah tertukar urutan output karena tidak menunggu child dengan benar (`wait()` belum dipanggil di parent)
- Child process saling tumpang tindih output jika tidak diberi penjadwalan eksplisit

---

## 📚 Referensi

- Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)
- Repositori xv6-public: [https://github.com/mit-pdos/xv6-public](https://github.com/mit-pdos/xv6-public)
- Diskusi praktikum dan debugging melalui output kernel

