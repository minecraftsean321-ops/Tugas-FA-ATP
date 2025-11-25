#include <iostream>
#include <string>

using namespace std;

// Definisi Node untuk Linked List
struct Node {
    string Judul_Lagu;
    string Penyanyi;
    string Genre;
    string Favorit;
    Node *next;
};

// Pointer head global (bisa juga ditaruh di main, tapi ini mengikuti gaya kode Anda)
Node *head = NULL;

// Fungsi untuk menambah data di awal (Push Front)
void insertAwal(Node** head, string Judul_LaguBaru, string PenyanyiBaru, string GenreBaru, string FavoritBaru) {
    // 1. Membuat node baru di heap memori
    Node* nodeBaru = new Node();

    // 2. Mengisi data ke node baru
    nodeBaru->Judul_Lagu = Judul_LaguBaru;
    nodeBaru->Penyanyi   = PenyanyiBaru;
    nodeBaru->Genre      = GenreBaru;
    nodeBaru->Favorit    = FavoritBaru;

    // 3. Membuat pointer next node baru mengarah ke head saat ini
    nodeBaru->next = *head;

    // 4. Pindahkan head ke node yang baru
    *head = nodeBaru;
    
    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus data di awal (Pop Front)
void deleteAwal(Node** head) {
    // Mengecek apakah list kosong
    if (*head == NULL) {
        cout << "List Kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    // Menyimpan alamat node pertama sementara
    Node* t = *head;

    // Memindahkan head ke node berikutnya
    *head = (*head)->next;

    // Menghapus node yang lama dari memori
    delete t;
    
    cout << "Data awal berhasil dihapus." << endl;
}

// Fungsi untuk menampilkan seluruh data (Traversal)

void printList(Node* n) {
    int i = 1;
    cout << "\n== Data Lagu Saat Ini ==" << endl;
    
    if (n == NULL) {
        cout << "(List Kosong)" << endl;
        return;
    }

    while (n != NULL) {
        cout << i << "." << endl;
        cout << "   Judul Lagu : " << n->Judul_Lagu << endl;
        cout << "   Penyanyi   : " << n->Penyanyi << endl;
        cout << "   Genre      : " << n->Genre << endl;
        cout << "   Favorit    : " << n->Favorit << endl;
        
        // Pindah ke node berikutnya
        n = n->next;
        i++;
    }
    cout << "========================" << endl;
}

int main() {
    // Variabel temporary untuk input user
    string inJudul, inPenyanyi, inGenre, inFavorit;
    char pilihan;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Tambah Lagu (Insert Awal)" << endl;
        cout << "2. Hapus Lagu (Delete Awal)" << endl;
        cout << "3. Tampilkan Playlist" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer enter

        switch(pilihan) {
            case '1':
                cout << "Masukkan Judul Lagu : ";
                getline(cin, inJudul);
                cout << "Masukkan Penyanyi   : ";
                getline(cin, inPenyanyi);
                cout << "Masukkan Genre      : ";
                getline(cin, inGenre);
                cout << "Favorit (y/n)?      : ";
                getline(cin, inFavorit);
                
                // Panggil fungsi insertAwal
                insertAwal(&head, inJudul, inPenyanyi, inGenre, inFavorit);
                break;
            
            case '2':
                deleteAwal(&head);
                break;

            case '3':
                printList(head);
                break;
            
            case '4':
                cout << "Keluar program..." << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != '4');

    return 0;
}
