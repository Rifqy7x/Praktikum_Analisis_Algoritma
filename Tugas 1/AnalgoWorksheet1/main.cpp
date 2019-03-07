#include <iostream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

struct orang{
    string nama;
    bool menikah = false;
    int preferensi[5];
    string pasangan;
    int indexPasangan;
};

string findPerson(int i){
    switch(i){
        case 0 : return "Amy";
            break;
        case 1 : return "Bertha";
            break;
        case 2 : return "Clare";
            break;
        case 3 : return "Diane";
            break;
        case 4 : return "Erika";
            break;
        case 5 : return "Victor";
            break;
        case 6 : return "Wyatt";
            break;
        case 7 : return "Xavier";
            break;
        case 8 : return "Yancey";
            break;
        case 9 : return "Zeus";
            break;
    }
}

void deklarasi (orang (&lakiLaki)[5], orang (&perempuan)[5]){
    lakiLaki[0].nama = "Victor";
    lakiLaki[0].preferensi[0] = 1;
    lakiLaki[0].preferensi[1] = 0;
    lakiLaki[0].preferensi[2] = 3;
    lakiLaki[0].preferensi[3] = 4;
    lakiLaki[0].preferensi[4] = 2;

    lakiLaki[1].nama = "Wyatt";
    lakiLaki[1].preferensi[0] = 3;
    lakiLaki[1].preferensi[1] = 1;
    lakiLaki[1].preferensi[2] = 0;
    lakiLaki[1].preferensi[3] = 2;
    lakiLaki[1].preferensi[4] = 4;

    lakiLaki[2].nama = "Xavier";
    lakiLaki[2].preferensi[0] = 1;
    lakiLaki[2].preferensi[1] = 4;
    lakiLaki[2].preferensi[2] = 2;
    lakiLaki[2].preferensi[3] = 3;
    lakiLaki[2].preferensi[4] = 0;

    lakiLaki[3].nama = "Yancey";
    lakiLaki[3].preferensi[0] = 0;
    lakiLaki[3].preferensi[1] = 3;
    lakiLaki[3].preferensi[2] = 2;
    lakiLaki[3].preferensi[3] = 1;
    lakiLaki[3].preferensi[4] = 4;

    lakiLaki[4].nama = "Zeus";
    lakiLaki[4].preferensi[0] = 1;
    lakiLaki[4].preferensi[1] = 3;
    lakiLaki[4].preferensi[2] = 0;
    lakiLaki[4].preferensi[3] = 4;
    lakiLaki[4].preferensi[4] = 2;

    perempuan[0].nama = "Amy";
    perempuan[0].preferensi[0] = 9;
    perempuan[0].preferensi[1] = 5;
    perempuan[0].preferensi[2] = 6;
    perempuan[0].preferensi[3] = 8;
    perempuan[0].preferensi[4] = 7;

    perempuan[1].nama = "Bertha";
    perempuan[1].preferensi[0] = 7;
    perempuan[1].preferensi[1] = 6;
    perempuan[1].preferensi[2] = 8;
    perempuan[1].preferensi[3] = 5;
    perempuan[1].preferensi[4] = 9;

    perempuan[2].nama = "Clare";
    perempuan[2].preferensi[0] = 6;
    perempuan[2].preferensi[1] = 7;
    perempuan[2].preferensi[2] = 8;
    perempuan[2].preferensi[3] = 9;
    perempuan[2].preferensi[4] = 5;

    perempuan[3].nama = "Diane";
    perempuan[3].preferensi[0] = 5;
    perempuan[3].preferensi[1] = 9;
    perempuan[3].preferensi[2] = 8;
    perempuan[3].preferensi[3] = 7;
    perempuan[3].preferensi[4] = 6;

    perempuan[4].nama = "Erika";
    perempuan[4].preferensi[0] = 8;
    perempuan[4].preferensi[1] = 6;
    perempuan[4].preferensi[2] = 9;
    perempuan[4].preferensi[3] = 7;
    perempuan[4].preferensi[4] = 5;
};

int findArray(orang person[], string nama, int indexOrang){
    int index;
    string indexNama;
    int dia;

    for(int i = 0; i<5; i++){
        index = person[indexOrang].preferensi[i];
        indexNama = findPerson(index);
        if(indexNama.compare(nama)==0){
            dia = i;
        }
    }

    return dia;
};


void hasil(orang lakiLaki[5]){
    cout<<"Hasil SMP :"<<endl;

    for(int i = 0; i<5; i++){
        cout<<lakiLaki[i].nama<<" menikah dengan "<<lakiLaki[i].pasangan<<endl;
    }

    cout<<endl;
};


void matching(orang (&lakiLaki)[5], orang (&perempuan)[5]){
    int temp;
    int indexLaki;
    string nama1, nama2;

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(!lakiLaki[j].menikah){
                temp = lakiLaki[j].preferensi[i];
                if(!perempuan[lakiLaki[j].preferensi[i]].menikah){
                    lakiLaki[j].pasangan = perempuan[lakiLaki[j].preferensi[i]].nama;
                    lakiLaki[j].menikah = true;
                    lakiLaki[j].indexPasangan = i;
                    perempuan[temp].pasangan = lakiLaki[j].nama;
                    perempuan[temp].menikah= true;
                    perempuan[temp].indexPasangan = findArray(perempuan, lakiLaki[j].nama, temp);
                }
                else{
                    if(findArray(perempuan, lakiLaki[j].nama, temp)<perempuan[temp].indexPasangan){
                        for(int k = 0; k<5; k++){
                            nama1 = lakiLaki[k].nama;
                            nama2 = perempuan[temp].pasangan;
                            if(nama1.compare(nama2)==0)
                                indexLaki = k;
                        }
                        lakiLaki[indexLaki].menikah = false;
                        lakiLaki[indexLaki].pasangan = "";
                        lakiLaki[j].pasangan = perempuan[lakiLaki[j].preferensi[i]].nama;
                        lakiLaki[j].menikah = true;
                        lakiLaki[j].indexPasangan = i;
                        perempuan[temp].pasangan = lakiLaki[j].nama;
                        perempuan[temp].indexPasangan = findArray(perempuan, lakiLaki[j].nama, temp);
                    }
                }
            }
        }
    }
}

int main()
{
    orang cowo[5];
    orang cewe[5];

    deklarasi(cowo, cewe);
    matching(cowo, cewe);
    hasil(cowo);

    return 0;
}
