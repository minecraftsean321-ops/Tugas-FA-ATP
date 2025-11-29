#include <iostream>
#include <string.h>
using namespace std;

//fungsi linked list 
struct Myplaylist {
    string judul;
    string penyanyi;
    string genre;
    string durasi;

    Myplaylist *next;
};

void insertlagu (Myplaylist** head, Myplaylist x){
    //Membuat nodebaru di memori heap
    Myplaylist *nodeBaru = new Myplaylist ();
    //Mengakses nilai dari struct
    nodeBaru->judul = x.judul;
    nodeBaru->penyanyi = x.penyanyi;
    nodeBaru->genre = x.genre;
    nodeBaru->durasi = x.durasi;


    //Mengarahkan alamat node baru ke head
    nodeBaru->next = *head;
    *head = nodeBaru;

};

typedef struct Myplaylist song;

void menampilkanlagu (Myplaylist *n){
    int i = 1;
    while (n != NULL){
        cout << i << "." << endl;
        cout << "Judul: " << n->judul << endl;
        cout << "Penyanyi: " << n->penyanyi << endl;
        cout << "Genre: " << n->genre << endl;
        cout << "Durasi: " << n->durasi << endl;
        cout << "\n";

        n = n->next;
        i++;
    }
    
    
}

void mencarigenre (Myplaylist* temp, string cari){
    bool ditemukan = false;
    
    while(temp != NULL){
        int i = 1;
        if(temp->genre.find(cari) != string::npos){
            cout << i << "." << endl;
            cout << "Judul: " << temp->judul << endl;
            cout << "Penyanyi: " << temp->penyanyi << endl;
            cout << "Genre: " << temp->genre << endl;
            cout << "Durasi: " << temp->durasi << endl;
            cout << "\n";
            i++;
            ditemukan = true;
            
        }
        temp = temp->next;
    }
    if (!ditemukan){
        cout << "There's no song that fall into that genre sir";
    }
}


int main (){
song *head = NULL;
song x;
int pilihan;

cout << "====================================================================================" << endl;
cout << "WELCOME TO YOUR'PLAYLIST WHERE YOU CAN STORE ALL OF THE MUSIC THAT YOU'RE INTERESTED" << endl;
cout << "====================================================================================" << endl;

do {
    cout << "SO IS THERE ANYTHING THAT I COULD HELP YOU SIR" << endl;
    cout << "1. Add the baddest song to your playlist?" << endl;
    cout << "2. Add a song to be your favorite?" << endl;
    cout << "3. Show you're most beutiful playlist?" << endl;
    cout << "4. Show you're favorite song?" << endl;
    cout << "5. Delete song from your playlist?" << endl;
    cout << "6. Delete song from your favorite?" << endl;
    cout << "7. Show you're song by Genre? " << endl;
    cout << "0. Exit" << endl;
    cin >> pilihan;

    switch (pilihan){
        case 1:
        cout << "So what the title of the song: ";
        cin >> x.judul;
        cout << "Wow, that's an interesting choice sir" << endl;
        cout << "Who is the singer? ";
        cin >> x.penyanyi;
        cout << "What genre is the song? ";
        cin >> x.genre;
        cout << "How long is the duration of the song? ";
        cin >> x.durasi;
        cout << "OKAYY SIR, I WILL ADD IT TO YOUR PLAYLIST" << endl;
        cout << "\n";

        insertlagu(&head,x);
        break;

        case 3: 
        menampilkanlagu(head);
        break;

        case 7:
        string cari;
        cout << "What genre are you interesting at? ";
        cin >> cari;
        mencarigenre(head, cari);
        break;
        
    }
        

    
}
while (pilihan != '0');


    return 0;
}

