#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Ini Struct
struct Produk
{
    string merk;
    int stok;
    float harga;
};

//MAX_PRODUK untuk maksimum produk yang bisa dibikin dalam katalog
//MAX_HISTORY untuk maksimum riwayat yang bisa disimpan dan ditampilkan, kalo dah penuh bakal kehapus sendiri 
const int MAX_PRODUK = 20;
const int MAX_HISTORY = 10;

//BUAT NAMBAH PRODUK
void tambahProduk(Produk katalogProduk[], int &jumlahProduk, stack<Produk> &riwayatProduk)
{
    if (jumlahProduk >= MAX_PRODUK)
    {
        cout << "Katalog penuh !!" << endl;
        return;
    }

    cout << "Masukkan merk produk: ";
    ci1n >> katalogProduk[jumlahProduk].merk;
    cout << "Masukkan stok produk: ";
    cin >> katalogProduk[jumlahProduk].stok;
    cout << "Masukkan harga produk: ";
    cin >> katalogProduk[jumlahProduk].harga;

    jumlahProduk++;

    riwayatProduk.push(katalogProduk[jumlahProduk - 1]);
    if (riwayatProduk.size() > MAX_HISTORY)
    {
        riwayatProduk.pop();
    }

    cout << "Produk berhasil ditambahkan!" << endl;
}

//BUAT NAMPILIN PRODUK 
//Ngelooping dari indeks katalogProduk 
void tampilkanProduk(const Produk katalogProduk[], int jumlahProduk)
{
    if (jumlahProduk == 0)
    {
        cout << "Katalog produk kosong." << endl;
        return;
    }

    //Ini loopingannya 
    cout << "\nDaftar Produk:\n";
    for (int i = 0; i < jumlahProduk; ++i)
    {
        cout << i + 1 << ". " << katalogProduk[i].merk << " - "
             << "Stok: " << katalogProduk[i].stok << ", "
             << "Harga: Rp" << katalogProduk[i].harga << endl;
    }
}

//BUAT HAPUS PRODUK, cara kerjanya ngelooping index nya, kalo index dah dipilih itu bakal 
//dihapus dari memory, terus biar ga kosong bakal langsung digeser biar gada slot array kosong
void hapusProduk(Produk katalogProduk[], int &jumlahProduk)
{
    if (jumlahProduk == 0)
    {
        cout << "Katalog produk kosong. Tidak ada yang bisa dihapus." << endl;
        return;
    }

    int indeks;
    cout << "Masukkan indeks produk yang ingin dihapus (1-" << jumlahProduk << "): ";
    cin >> indeks;

    if (indeks < 1 || indeks > jumlahProduk)
    {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    for (int i = indeks - 1; i < jumlahProduk - 1; i++)
    {
        katalogProduk[i] = katalogProduk[i + 1];
    }

    jumlahProduk--;
    cout << "Produk berhasil dihapus!" << endl;
}

//BUAT UPDATE PRODUK 
void updateProduk(Produk katalogProduk[], int jumlahProduk, stack<Produk> &riwayatProduk)
{

    if (jumlahProduk == 0)
    {
        cout << "Katalog produk kosong. Tidak ada yang bisa diupdate." << endl;
        return;
    }

    int indeks;
    cout << "Masukkan indeks produk yang ingin diupdate (1-" << jumlahProduk << "): ";
    cin >> indeks;

    // Input validation
    if (indeks < 1 || indeks > jumlahProduk)
    {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    // Update product details, cara kerjanya looping index nya, terus kalo dah sesuai index ntar bakal akses index array nya
    //abis tuh bakal bisa di update dari katalogProduk
    cout << "\nData produk saat ini:\n";
    cout << "  Merk: " << katalogProduk[indeks - 1].merk << endl;
    cout << "  Stok: " << katalogProduk[indeks - 1].stok << endl;
    cout << "  Harga: " << katalogProduk[indeks - 1].harga << endl;

    cout << "\nMasukkan data baru (kosongkan jika tidak ingin mengubah):\n";
    cout << "Merk: ";
    cin.ignore();
    getline(cin, katalogProduk[indeks - 1].merk);
    cout << "Stok: ";
    cin >> katalogProduk[indeks - 1].stok;
    cout << "Harga: ";
    cin >> katalogProduk[indeks - 1].harga;

    riwayatProduk.push(katalogProduk[indeks - 1]);
    if (riwayatProduk.size() > MAX_HISTORY)
    {
        riwayatProduk.pop();
    }

    cout << "Produk berhasil diupdate!" << endl;
}

//Ini bubble sort kalo ga salah, lupa jujur. Pokoke dari atas ke bawah sorting array nya
void sortProduk(Produk katalogProduk[], int jumlahProduk)
{
    for (int i = 0; i < jumlahProduk - 1; i++)
    {
        for (int j = 0; j < jumlahProduk - i - 1; j++)
        {
            if (katalogProduk[j].merk > katalogProduk[j + 1].merk)
            {
                // Swap katalogProduk[j] and katalogProduk[j + 1]
                Produk temp = katalogProduk[j];
                katalogProduk[j] = katalogProduk[j + 1];
                katalogProduk[j + 1] = temp;
            }
        }
    }
}

//Ini binary search dari awal ampe akhir 
int cariProdukByMerk(const Produk katalogProduk[], int jumlahProduk, const string &merkCari)
{
    int low = 0;
    int high = jumlahProduk - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; 

        if (katalogProduk[mid].merk == merkCari)
        {
            return mid; 
        }

        if (katalogProduk[mid].merk < merkCari)
        {
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main()
{
    Produk katalogProduk[MAX_PRODUK];
    int jumlahProduk = 0;
    int pilihan;
    stack<Produk> riwayatProduk;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah produk\n";
        cout << "2. Tampilkan produk\n";
        cout << "3. Update produk\n";
        cout << "4. Hapus produk\n";
        cout << "5. Urutkan produk (berdasarkan merk)\n";
        cout << "6. Cari produk (berdasarkan merk)\n";
        cout << "7. Tampilkan riwayat produk\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahProduk(katalogProduk, jumlahProduk, riwayatProduk);
            break;
        case 2:
            tampilkanProduk(katalogProduk, jumlahProduk);
            break;
        case 3:
            updateProduk(katalogProduk, jumlahProduk, riwayatProduk);
            break;
        case 4:
            hapusProduk(katalogProduk, jumlahProduk);
            break;
        case 5:
            sortProduk(katalogProduk, jumlahProduk);
            cout << "Produk berhasil diurutkan!" << endl;
            break;
        case 6:
        {
            cout << "Masukkan merk produk yang ingin dicari: ";
            string merkCari;
            cin.ignore();
            getline(cin, merkCari);

            int index = cariProdukByMerk(katalogProduk, jumlahProduk, merkCari);
            if (index != -1)
            {
                cout << "Produk ditemukan:\n";
                cout << "  Merk: " << katalogProduk[index].merk << endl;
                cout << "  Stok: " << katalogProduk[index].stok << endl;
                cout << "  Harga: Rp" << katalogProduk[index].harga << endl;
            }
            else
            {
                cout << "Produk tidak ditemukan." << endl;
            }
            break;
        }
        case 7:
        {
            if (riwayatProduk.empty())
            {
                cout << "Riwayat produk kosong." << endl;
            }
            else
            {
                cout << "\nRiwayat Produk:\n";
                stack<Produk> tempStack = riwayatProduk;
                while (!tempStack.empty())
                {
                    Produk produk = tempStack.top();
                    cout << "  Merk: " << produk.merk << ", Stok: " << produk.stok << ", Harga: Rp" << produk.harga << endl;
                    tempStack.pop();
                }
            }
            break;
        }
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}