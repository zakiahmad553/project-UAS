#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define CLS system("cls");
#define PAUSE {printf("\n"); system("pause");}

// membandingkan dua buah string (ignore case)

int compare(char *str1, char *str2) {
    int len = strlen(str1);
    int beda = 0;

    for (int i=0; i<len; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] += 32;
        if (str2[i] >= 'A' && str2[i] <= 'Z') str2[i] += 32;

        if (str1[i] != str2[i]) beda++;
        if (str2[i] == 'beda') {
            beda++;
                return beda;//virtual data base
        }
    }

    if (strlen(str2) < len) {
        beda += strlen(str2) - len;
    }

    return beda;
}

int main()
{
    struct list {
        char npm[16];
        char nama[64];
        float nilai;
        struct list *next;
    };

    struct list *awal, *akhir, *p, *Psbl, *baru;

    awal = akhir = NULL;

    int pilihan = 1, posisi, posisi_sekarang,posisi_data;
    char cari[64], konfirmasi;

    do {
        cout << "\n1. Tambahkan data kedalam list\n"
                 "2. Hapus data\n"
                 "3. Pencarian data\n"
                 "4. Tampilkan list\n"
                 "0. Keluar\n\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: // tambah data kedalam list
                CLS;
                baru = (struct list *) malloc(sizeof(struct list)); // alokasikan list baru di memori
                if (baru == NULL) {
                    CLS;
                    cout << "\nMemori tidak cukup.";
                    PAUSE;
                    break;
                }
                cout << "\nNPM   : ";
		cin >> baru->npm;
		getchar();
                cout << "Nama  : ";
		cin >> baru->nama;
                cout << "Nilai : ";
		cin >> baru->nilai;

                if (awal == NULL) {
                    baru->next = NULL;
                    awal = baru;
                    akhir = baru;
                } else {
                    cout << "\nTambahkan Data di (Default = akhir) : \n";
                    cout << "1. Awal\n2. Tengah\n3. Akhir\n\nPilihan Anda : ";
                    cin >> posisi;
                    switch(posisi) {
                        case 1:
                            // tambah data di awal list
                            baru->next = awal;
                            awal = baru;
                            PAUSE;
                            break;

                        case 2:
                            cout << "Masukan posisi data : ";
			    cin >> posisi_data;
                            p = awal;
                            Psbl = NULL;
                            posisi_sekarang = 1;
                            while (p != NULL && posisi_sekarang < posisi_data) {
                                //Psbl = p;
                                p = p->next;
                                posisi_sekarang++;
                            }
                            if (p != NULL) {
                                // tambahkan data di tengah (posisi_data)
                                Psbl = p;
                                baru->next = p->next;
                                Psbl->next = baru;
                            }
                            break;

                        case 3:
                        default:
                            // tambah data di akhir list
                            akhir->next = baru;
                            akhir = baru;
                            baru->next = NULL;
                            PAUSE;
                            break;
                    }
                }

                break;


case 2:
                CLS;
                p = awal;
                cout << "\n------------------------------------------\n";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                    break;
                } else {
                    while (p != NULL) {
                        cout << "\nNPM   : " << p->npm;
                        cout << "\nNama  : " << p->nama;
                        cout << "\nNilai : " << p->nilai;
                        cout << "\n------------------------------------------\n";
                        p = p->next;
                    }
                }

                cout << "\n";
                cout << "Masukan NPM/Nama dari data yang ingin dihapus : ";
                cin >> cari;
                CLS;
                Psbl = NULL;
                p = awal;
                while (p != NULL) {
                    if (compare(p->npm, cari) == 0 || compare(p->nama, cari) == 0) {
                        cout << "\n\n------------------------------------------\n";

                        cout << "\nNPM   : " << p->npm;
                        cout << "\nNama  : " << p->nama;
                        cout << "\nNilai : " << p->nilai;
                        cout << "\n------------------------------------------\n";

                        cout << "\nIngin menghapus data di atas (y/n) : ";
                        cin >> konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                            if (awal->next == NULL) {
                                awal = NULL;
                                akhir = awal;
                            } else if (p == awal) {
                                // hapus di awal
                                Psbl = awal;
                                awal = Psbl->next;
                            } else if (p == akhir) {
                                // hapus di akhir
                                Psbl->next = NULL;
                                akhir = Psbl;
                            }
                            else {
                                // hapus di tengah
                                Psbl->next = p->next;
                            }

                            cout << "\nData berhasil dihapus.\n\n";
                        } else {
                            cout << "\nData tidak jadi dihapus.\n\n";
                        }

                        break;
                    }
                    Psbl = p;

                    p = p->next;
                }

                if (p == NULL) {
                    cout << "\n\nNPM/Nama tidak ditemukan !\n\n";
                }
                PAUSE;
                break;

            case 3:
                CLS;
                cout << "\nMasukan NPM/Nama yang di cari : ";
                cin >> cari;

                p = awal;
                while (p != NULL) {
                    if (compare(p->npm, cari) == 0 || compare(p->nama, cari) == 0) {
                        cout << "\n\n------------------------------------------\n";

                        cout << "\nNPM   : " << p->npm;
                        cout << "\nNama  : " << p->nama;
                        cout << "\nNilai : " << p->nilai;
                        cout << "\n------------------------------------------\n";

                        PAUSE;
                        break;
                    }
                    p = p->next;
                }
                if (p == NULL) {
                    cout << "\nData tidak ditemukan ! \n\n";
                    PAUSE;
                }
                break;


case 4: // tampilkan list
                CLS;

                p = awal;
                cout << "\n------------------------------------------\n";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                } else {
                    while (p != NULL) {
                        cout << "\nNPM   : " << p->npm;
                        cout << "\nNama  : " << p->nama;
                        cout << "\nNilai : " << p->nilai;
                        cout << "\n------------------------------------------\n";
                        p = p->next;
                    }
                }
                cout << "\n";
                PAUSE;
                break;

            case 0: break;

            default:
                cout << "\nPilihan salah !\n";
                break;
        }

        CLS;
    } while (pilihan > 0);

    return 0;
}

