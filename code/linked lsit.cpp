#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* berikutnya;
};

// Kelas LinkedList
class LinkedList {
private:
    Node* kepala;
public:
    LinkedList() : kepala(NULL) {}

    // Menambahkan node di awal
    void tambahDiAwal(int data) {
        Node* simpulBaru = new Node();
        simpulBaru->data = data;
        simpulBaru->berikutnya = kepala;
        kepala = simpulBaru;
    }

    // Menambahkan node di akhir
    void tambahDiAkhir(int data) {
        Node* simpulBaru = new Node();
        simpulBaru->data = data;
        simpulBaru->berikutnya = NULL;
        if (kepala == NULL) {
            kepala = simpulBaru;
        } else {
            Node* sementara = kepala;
            while (sementara->berikutnya != NULL) {
                sementara = sementara->berikutnya;
            }
            sementara->berikutnya = simpulBaru;
        }
    }

    // Menghapus node dari awal
    void hapusDariAwal() {
        if (kepala == NULL) {
            cout << "List kosong." << endl;
            return;
        }
        Node* sementara = kepala;
        kepala = kepala->berikutnya;
        delete sementara;
    }

    // Menghapus node dari akhir
    void hapusDariAkhir() {
        if (kepala == NULL) {
            cout << "List kosong." << endl;
            return;
        }
        if (kepala->berikutnya == NULL) {
            delete kepala;
            kepala = NULL;
        } else {
            Node* sementara = kepala;
            while (sementara->berikutnya->berikutnya != NULL) {
                sementara = sementara->berikutnya;
            }
            delete sementara->berikutnya;
            sementara->berikutnya = NULL;
        }
    }

    // Menampilkan Linked List
    void tampilkan() {
        Node* sementara = kepala;
        while (sementara != NULL) {
            cout << sementara->data << " -> ";
            sementara = sementara->berikutnya;
        }
        cout << "null" << endl;
    }

    // Mencari elemen dalam Linked List
    bool cari(int kunci) {
        Node* sementara = kepala;
        while (sementara != NULL) {
            if (sementara->data == kunci) {
                return true;
            }
            sementara = sementara->berikutnya;
        }
        return false;
    }
};

int main() {
    LinkedList list;
    list.tambahDiAwal(10);
    list.tambahDiAwal(20);
    list.tambahDiAkhir(30);
    list.tambahDiAkhir(40);
    cout << "Linked List: ";
    list.tampilkan();

    cout << "Menghapus dari awal..." << endl;
    list.hapusDariAwal();
    cout << "Linked List: ";
    list.tampilkan();

    cout << "Menghapus dari akhir..." << endl;
    list.hapusDariAkhir();
    cout << "Linked List: ";
    list.tampilkan();

    int kunciPencarian = 30;
    if (list.cari(kunciPencarian)) {
        cout << "Elemen " << kunciPencarian << " ditemukan dalam list." << endl;
    } else {
        cout << "Elemen " << kunciPencarian << " tidak ditemukan dalam list." << endl;
    }

    return 0;
}
