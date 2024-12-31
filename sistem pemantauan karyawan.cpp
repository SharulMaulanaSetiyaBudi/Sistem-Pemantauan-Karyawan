#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Karyawan {
    int id;
    string nama;
    string posisi;
    int jamKerja;
};

class SistemPemantauan {
private:
    vector<Karyawan> daftarKaryawan;

public:
    void tambahKaryawan(int id, const string& nama, const string& posisi, int jamKerja) {
        Karyawan karyawan = {id, nama, posisi, jamKerja};
        daftarKaryawan.push_back(karyawan);
        cout << "Karyawan berhasil ditambahkan!" << endl;
    }

    void tampilkanKaryawan() {
        if (daftarKaryawan.empty()) {
            cout << "Tidak ada karyawan yang terdaftar." << endl;
            return;
        }

        cout << "\nDaftar Karyawan:\n";
        for (const auto& karyawan : daftarKaryawan) {
            cout << "ID: " << karyawan.id
                 << ", Nama: " << karyawan.nama
                 << ", Posisi: " << karyawan.posisi
                 << ", Jam Kerja: " << karyawan.jamKerja << " jam" << endl;
        }
    }

    void updateJamKerja(int id, int jamBaru) {
        for (auto& karyawan : daftarKaryawan) {
            if (karyawan.id == id) {
                karyawan.jamKerja = jamBaru;
                cout << "Jam kerja karyawan berhasil diperbarui!" << endl;
                return;
            }
        }
        cout << "Karyawan dengan ID " << id << " tidak ditemukan." << endl;
    }

    void hapusKaryawan(int id) {
        for (auto it = daftarKaryawan.begin(); it != daftarKaryawan.end(); ++it) {
            if (it->id == id) {
                daftarKaryawan.erase(it);
                cout << "Karyawan berhasil dihapus!" << endl;
                return;
            }
        }
        cout << "Karyawan dengan ID " << id << " tidak ditemukan." << endl;
    }
};

int main() {
    SistemPemantauan sistem;
    int pilihan;

    do {
        cout << "\nSistem Pemantauan Tenaga Kerja Pabrik" << endl;
        cout << "1. Tambah Karyawan" << endl;
        cout << "2. Tampilkan Karyawan" << endl;
        cout << "3. Update Jam Kerja" << endl;
        cout << "4. Hapus Karyawan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            int id, jamKerja;
            string nama, posisi;
            cout << "Masukkan ID: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan Posisi: ";
            getline(cin, posisi);
            cout << "Masukkan Jam Kerja: ";
            cin >> jamKerja;
            sistem.tambahKaryawan(id, nama, posisi, jamKerja);
            break;
        }
        case 2:
            sistem.tampilkanKaryawan();
            break;
        case 3: {
            int id, jamBaru;
            cout << "Masukkan ID karyawan: ";
            cin >> id;
            cout << "Masukkan jam kerja baru: ";
            cin >> jamBaru;
            sistem.updateJamKerja(id, jamBaru);
            break;
        }
        case 4: {
            int id;
            cout << "Masukkan ID karyawan: ";
            cin >> id;
            sistem.hapusKaryawan(id);
            break;
        }
        case 5:
            cout << "Keluar dari sistem." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
