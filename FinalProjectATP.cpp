#include <iostream>
using namespace std;

struct Mysong {
    string Judul_Lagu [100];
    string Penyanyi [100];
    string Genre [100];
    string Favorit [100];
    Node *next;
};

Node *head = NULL;

void insertAwal (Node** head, string Judul_LaguBaru, string PenyanyiBaru, string GenreBaru, string FavoritBaru){

    //Membuat node baru di heap memori
    Node* nodeBaru = new Node ();
    nodeBaru->Judul_Lagu = judulBaru;
    nodeBaru->Penyanyi = NamaBaru;
    nodeBaru->Genre = GenreBaru;
    nodeBaru->Favorit = FavoritBaru;
    
    //Membuat pointer next mengarah ke head dimana head merupakan NULL
    nodeBaru->next = *head;
    //Pindahkan head ke node yang baru
    *head = nodeBaru;
    
}

void deleteAwal (Node** head) {
    //Mengecek apakah head = NULL
    // Jika pointer ke head itu sendiri NULL, atau list kosong (*head == NULL)
    if (head == NULL || *head == NULL) {
        cout << "List Kosong" << endl;
        return;
    }

    // Menyimpan alamat node pertama sementara
    Node* t = *head;
    // Memindahkan head ke node berikutnya
    *head = (*head)->next;
    // Menghapus node yang lama
    delete t;
}

void printList(Node* n) {
    int i = 1;
    cout << "== Data Mahasiswa Saat Ini ==" << endl;
    while (n != NULL)
    {   cout << i << "." << endl;
        cout << "Judul Lagu: " << n->Judul_Lagu << endl;
        cout << "Penyanyi: " << n->Penyanyi << endl;
        cout << "Genre: " << n->Genre << endl;
        cout << "Favorit: " << n->Favorit << endl;
        //Jadi kita menginisialisasi agar n dapat mengakses ke alamat dari node berikutnya
        n = n->next;
        i++;
    };
    

};

int main (){
struct Mysong s; 
    cout << "Masukkan judul lagu: "; endl;
    cin >> s.Judul_Lagu;
    cout << "Masukkan Genre: "; endl;
    cin >> s.Genre;
    cout << "Masukkan Penyanyi: "; endl
    cin >> s.Penyanyi;
    cout << "Apakah termasuk lagu favorti (y/n)? "; endl;
    cin >> s.Favorit;
    
    return 0;
}

