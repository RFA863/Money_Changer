#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

struct matauang
 {
   string nama_matauang,kode,negara;
   int kurs_jual,kurs_beli,hasil_jual,hasil_beli;

   matauang *prev;
   matauang *next;
 };
 matauang *Head, *Tail, *Cur, *newnode, *del;

 struct Node{
  string label;
  Node *left, *right, *parent;
};

Node *root, *newNode;

void createNewTree( string label )
{
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

}

Node *insertLeft( string label, Node *node )
{
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;

      return newNode;
}

Node *insertRight( string label, Node *node )
{
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;

      return newNode;
}

void find( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }
  else{
    if( !node )
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else{


      cout << "\n\tNama Negara  : " << node->label << endl;

      if( !node->parent )
        cout << "\tMata Uang    : (tidak punya orang tua)" << endl;
      else
        cout << "\tMata Uang    : " << node->parent->label << endl;


      if( node->parent != NULL && node->parent->right != node &&
      node->parent->left == node )

        cout << "\tKode         : " << node->parent->right->label << endl;

      else

        cout << "\tKode         : (tidak punya saudara)" << endl;


      if( !node->left )
        cout << "\tKurs Jual    : (tidak punya anak kiri)" << endl;
      else
        cout << "\tKurs Jual    : " << node->left->label << endl;

      if( !node->right )
        cout << "\tKurs Beli    : (tidak punya anak kanan)" << endl;
      else
        cout << "\tKurs Beli    : " << node->right->label <<"\n"<< endl;

    }
  }
}

int maksimal = 100;//definisi nilai variabel

int counthasil()
{
 if (Head == NULL){return 0;}

 else
 {
     int banyak = 0;
     Cur = Head;
     while(Cur != NULL)
     {
         Cur = Cur->next;
         banyak++;
     }

     return banyak;
 }
}

void push(string nama_matauang,string kode,int kurs,int hasil)
{
    if (counthasil()==maksimal)
    {
        cout<<"History Penuh "<<endl;
    }
    else
    {
        if(counthasil()==0)
        {
            Head = new matauang();
            Head->nama_matauang = nama_matauang;
            Head->kode = kode;
            Head->kurs_beli = kurs;
            Head->kurs_jual = kurs;
            Head->hasil_jual = hasil;
            Head->hasil_beli = hasil;
            Head->prev = NULL;
            Head->next = NULL;
            Tail = Head;
        }
        else
        {
            newnode= new matauang();
            newnode->nama_matauang = nama_matauang;
            newnode->kode = kode;
            newnode->kurs_beli = kurs;
            newnode->kurs_jual = kurs;
            newnode->hasil_beli= hasil;
            newnode->hasil_jual = hasil;
            newnode->prev = Tail;
            newnode->next = NULL;
            Tail = newnode;
        }
    }
}



 struct data_nasabah
 {
     string nama_nasabah, nohp, alamat;

     data_nasabah *next;
 };
 data_nasabah *head, *tail, *cur;

 void buat_data_nasabah(string nama_nasabah, string nohp, string alamat)
 {
    head = new data_nasabah();
    head -> nama_nasabah = nama_nasabah;
    head -> nohp = nohp;
    head -> alamat = alamat;
    head -> next = NULL;
 }

 void cetak_data_nasabah()
 {
     cur = head;
    while(cur != NULL)
    {
        cout<<"\nNama         : "<<cur->nama_nasabah<<endl;
        cout<<"No.Hp        : "<<cur->nohp<<endl;
        cout<<"Alamat       : "<<cur->alamat<<endl;

        cur = cur->next;
    }
 }
string nama_nasabah,nohp,alamat;

 void registr()
{
    system("cls");
    string regUser, regPass, validasi;

    cout << "\n\t========= Register =========" << endl;
    cout << "\tNama          : ";getline(cin,nama_nasabah);
    cout << "\tNo.Hp         : ";getline(cin,nohp);
    cout << "\tAlamat        : ";getline(cin,alamat);
    cout << "\n\tBuat username : ";getline(cin,regUser);
    cout << "\tBuat password : ";getline(cin,regPass);

    buat_data_nasabah(nama_nasabah,nohp,alamat);
    ofstream reg;

    reg.open ("dataDaftarMC.txt", ios::app);
    reg << regUser << " " << regPass << endl;
    cout << "\n\tRegister berhasil!" << endl;
    cout << "\tSilahkan login untuk melanjutkan" << endl << endl;

    reg.close();
}

void display()
{
    system("cls");
    string data;

    cout << "\n\tUsername |" << "Password" << endl;
    cout << "\t-------------------------" << endl;

    ifstream myfile("dataDaftarMC.txt");
    if (myfile.is_open()){
    while ( getline (myfile,data) ){
      cout << "\t" << data <<endl;
    }
    myfile.close();
  }
  else
    cout <<endl;
    cout << " ";
    cout <<endl;
}

void loading()
{
    //system -> untuk memberi warna
    system("color 2f");
    system("color 0f");

    char a= 177, b = 219;
    cout << "\n\n\t\tLoading...";
    cout << "\n\n";
    cout << "\t";
    for(int i=0; i <= 25; i++)
    {
        cout << b;
        Sleep(80);
    }
    cout << "\n\n";
}

void TukarUang()
{
        matauang matauang[18];

        string matauang_tukar,transaksi,pilih, validasi, input;
        int i,a,uang,hasil_jual,hasil_beli;

              for(i=0;i<18;i++)
              {
                  matauang[0].nama_matauang = "Dollar ";
                  matauang[0].kode = "USD";
                  matauang[0].negara = "Amerika";
                  matauang[0].kurs_beli = 14300;
                  matauang[0].kurs_jual = 14400;
                  matauang[1].nama_matauang = "Euro ";
                  matauang[1].kode ="EUR";
                  matauang[1].negara = "Eropa";
                  matauang[1].kurs_beli = 15700;
                  matauang[1].kurs_jual = 15800;
                  matauang[2].nama_matauang ="Yen ";
                  matauang[2].kode = "JPY";
                  matauang[2].negara = "Jepang";
                  matauang[2].kurs_beli = 117;
                  matauang[2].kurs_jual = 118;
                  matauang[3].nama_matauang = "Dollar Australia ";
                  matauang[3].kode = "AUD";
                  matauang[3].negara = "Australia";
                  matauang[3].kurs_beli = 10410;
                  matauang[3].kurs_jual = 10515;
                  matauang[4].nama_matauang = "Dollar Brunei ";
                  matauang[4].kode ="BND";
                  matauang[4].negara = "Brunei";
                  matauang[4].kurs_beli = 10530;
                  matauang[4].kurs_jual = 10640;
                  matauang[5].nama_matauang ="Dollar Kanada ";
                  matauang[5].kode = "CAD";
                  matauang[5].negara = "Kanada";
                  matauang[5].kurs_beli = 11525;
                  matauang[5].kurs_jual = 11650;
                  matauang[6].nama_matauang = "Franc Swiss ";
                  matauang[6].kode = "CHF";
                  matauang[6].negara = "Swiss";
                  matauang[6].kurs_beli = 14790;
                  matauang[6].kurs_jual = 14950;
                  matauang[7].nama_matauang = "Yuan ";
                  matauang[7].kode ="CNY";
                  matauang[7].negara = "China";
                  matauang[7].kurs_beli = 2170;
                  matauang[7].kurs_jual = 2180;
                  matauang[8].nama_matauang ="Krone ";
                  matauang[8].kode = "DKK";
                  matauang[8].negara = "Denmark";
                  matauang[8].kurs_beli = 2085;
                  matauang[8].kurs_jual = 2107;
                  matauang[9].nama_matauang = "Poundsterling ";
                  matauang[9].kode = "GBP";
                  matauang[9].negara = "Inggris";
                  matauang[9].kurs_beli = 18135;
                  matauang[9].kurs_jual = 18320;
                  matauang[10].nama_matauang = "Dollar Hongkong ";
                  matauang[10].kode ="HKD";
                  matauang[10].negara = "Hongkong";
                  matauang[10].kurs_beli = 1845;
                  matauang[10].kurs_jual = 1860;
                  matauang[11].nama_matauang ="Won ";
                  matauang[11].kode = "KRW";
                  matauang[11].negara = "Korea";
                  matauang[11].kurs_beli = 11;
                  matauang[11].kurs_jual = 11;
                  matauang[12].nama_matauang = "Dinar Kuwait ";
                  matauang[12].kode = "KWD";
                  matauang[12].negara = "Kuwait";
                  matauang[12].kurs_beli = 47270;
                  matauang[12].kurs_jual = 47760;
                  matauang[13].nama_matauang = "Ringgit ";
                  matauang[13].kode ="MYR";
                  matauang[13].negara = "Malaysia";
                  matauang[13].kurs_beli = 3300;
                  matauang[13].kurs_jual = 3330;
                  matauang[14].nama_matauang ="Dollar Singapura ";
                  matauang[14].kode = "SGD";
                  matauang[14].negara = "Singapura";
                  matauang[14].kurs_beli = 10530;
                  matauang[14].kurs_jual = 10640;
                  matauang[15].nama_matauang ="Baht ";
                  matauang[15].kode = "THB";
                  matauang[15].negara = "Thailand";
                  matauang[15].kurs_beli = 417;
                  matauang[15].kurs_jual = 421;
                  matauang[16].nama_matauang ="Riyal ";
                  matauang[16].kode = "SAR";
                  matauang[16].negara = "Arab Saudi";
                  matauang[16].kurs_beli = 3864;
                  matauang[16].kurs_jual = 3903;
                  matauang[17].nama_matauang ="Peso ";
                  matauang[17].kode = "PHP";
                  matauang[17].negara = "Filipina";
                  matauang[17].kurs_beli = 273;
                  matauang[17].kurs_jual = 276;
              }

        menu:

        system("cls");

        cout<<"\n\t\t\tDaftar Mata Uang\n";
        cout<<"\t-----------------------------------------------------------------\n";
        cout<<"\t1. Dollar (US)       7. Franc Swiss        13. Dinar Kuwait"<<endl;
        cout<<"\t2. Euro              8. Yuan               14. Ringgit"<<endl;
        cout<<"\t3. Yen               9. Krone              15. Dollar Singapura"<<endl;
        cout<<"\t4. Dollar Australia  10. Poundsterling     16. Baht"<<endl;
        cout<<"\t5. Dollar Brunei     11. Dollar Hongkong   17. Riyal"<<endl;
        cout<<"\t6. Dollar Kanada     12. Won               18. Peso"<<endl;

        cout<<"\n\t19. Kembali ke menu"<<endl;
        cout<<"\n\tPilih Mata Uang Asal (1-18): ";
        getline(cin,matauang_tukar);

        if (matauang_tukar=="1")
        {a = 0;}
        else if(matauang_tukar=="2")
        {a = 1;}
        else if(matauang_tukar=="3")
        {a = 2;}
        else if(matauang_tukar=="4")
        {a = 3;}
        else if(matauang_tukar=="5")
        {a = 4;}
        else if(matauang_tukar=="6")
        {a = 5;}
        else if(matauang_tukar=="7")
        {a = 6;}
        else if(matauang_tukar=="8")
        {a = 7;}
        else if(matauang_tukar=="9")
        {a = 8;}
        else if(matauang_tukar=="10")
        {a = 9;}
        else if(matauang_tukar=="11")
        {a = 10;}
        else if(matauang_tukar=="12")
        {a = 11;}
        else if(matauang_tukar=="13")
        {a = 12;}
        else if(matauang_tukar=="14")
        {a = 13;}
        else if(matauang_tukar=="15")
        {a = 14;}
        else if(matauang_tukar=="16")
        {a = 15;}
        else if(matauang_tukar=="17")
        {a = 16;}
        else if(matauang_tukar=="18")
        {a = 17;}
        else if(matauang_tukar=="19")
        {
            return;
            getch();
        }
        else{
            cout<<"\n\tInputan yang anda masukan salah. Mohon masukan inputan dengan benar\n"<<endl;
            system("pause");
            goto menu;
            }

        Transaksi:

        system("cls");

        cout<<"\n\t\t"<<matauang[a].nama_matauang<<"("<<matauang[a].kode<<")";
        cout<<endl;
        cout<<endl;
        cout<<"\tKurs Beli        : Rp"<<matauang[a].kurs_beli<<endl;
        cout<<"\tKurs Jual        : Rp"<<matauang[a].kurs_jual<<endl;

        cout<<endl;
        cout<<"\tTransaksi yang dilakukan (jual / beli) : ";
        getline(cin,transaksi);

        if(transaksi=="jual"||transaksi=="Jual"||transaksi=="JUAL")
            {
                cout<<endl;
                cout<<"\tMasukan jumlah uang yang ingin dijual = ";
                getline(cin,input);
                err_transaksi :
                {
                    try{uang = stoi(input);}
                    catch(const std::exception& err){
                printf("\tMasukan jumlah uang yang ingin dijual = "); getline(cin,input);
                goto err_transaksi;
            }

                }

                hasil_jual = uang * matauang[a].kurs_jual;

                cout <<"\n\tAnda yakin ingin menjual sebesar "<<uang<<" "<<matauang[a].kode<<"? (y/n) ";
                getline(cin,pilih);

                    if(pilih == "y" || pilih == "Y")
                    {
                        system("cls");
                        loading();
                        system("pause");
                        system("cls");
                        cout <<endl;
                        cout <<endl;
                        cout <<"\t============================="<<endl;
                        cout <<"\t PENJUALAN VALAS BERHASIL!!!"<<endl;
                        cout <<"\t============================="<<endl;
                        cout <<endl;
                        cout <<"\t"<<uang<<" "<<matauang[a].kode<<" = Rp"<<hasil_jual<<endl;
                        cout <<"\tFaktur penjualan dapat dilihat di menu Faktur Cetak"<<endl;
                        cout <<endl;
                        cout <<endl;

                        push(matauang[a].nama_matauang,matauang[a].kode,matauang[a].kurs_jual,hasil_jual);

                    } else if (pilih == "n" || pilih =="N"){
                        cout <<endl;
                        cout <<endl;
                        cout <<"\tTekan enter untuk kembali ke transaksi"<<endl;
                        system("pause>NUL");
                        goto Transaksi;
                    } else {
                        cout <<"harap input (y/n)";
                        system("pause");
                        system("cls");
                        goto Transaksi;
                    }

                ofstream myFile;

                myFile.open("FakturPenjualan.txt");

                myFile<<"\n\tFAKTUR JUAL"<<endl;
                myFile<<"--------------------------------------------------------------------------------------"<<endl;
                myFile<<"KODE\tNAMA VALAS\t\tJML VALAS\t\tKURS\t\tJUMLAH (Rp.)"<<endl;
                myFile<<"--------------------------------------------------------------------------------------"<<endl;
                myFile<<matauang[a].kode<<"\t"<<matauang[a].nama_matauang<<"\t\t\t"<<uang<<"\t\t\t"<<matauang[a].kurs_jual<<"\t\tRp."<<hasil_jual<<endl;
                myFile<<"\n\n-------------------------------------------------------------------------------------"<<endl;

                myFile.close();

                    } else if(transaksi=="beli"||transaksi=="Beli"||transaksi=="BELI"){
                        cout<<endl;
                        cout<<"\tMasukan jumlah uang yang ingin dibeli = ";
                        getline(cin,input);
                        err_transaksi2 :
                        {
                            try{uang = stoi(input);}
                            catch(const std::exception& err){
                            printf("\tMasukan jumlah uang yang ingin dibeli = "); getline(cin,input);
                            goto err_transaksi2;}

                        }

                        hasil_beli = uang * matauang[a].kurs_beli;

                        cout <<"\tAnda yakin ingin membeli sebesar "<<uang<<" "<<matauang[a].kode<<"? (y/n) ";
                        getline(cin,pilih);

                            if(pilih == "y" || pilih == "Y"){
                                system("cls");
                                loading();
                                system("pause");
                                system("cls");
                                cout <<endl;
                                cout <<endl;
                                cout <<"\t============================="<<endl;
                                cout <<"\t PEMBELIAN VALAS BERHASIL!!! "<<endl;
                                cout <<"\t============================="<<endl;
                                cout <<endl;
                                cout <<"\t"<<uang<<" "<<matauang[a].kode<<" = Rp"<<hasil_beli<<endl;
                                cout <<"\tFaktur pembelian dapat dilihat di menu Faktur Cetak"<<endl;
                                cout <<endl;
                                cout <<endl;

                                push(matauang[a].nama_matauang,matauang[a].kode,matauang[a].kurs_beli,hasil_beli);

                            } else if (pilih == "n" || pilih == "N"){
                                cout <<endl;
                                cout <<endl;
                                cout <<"\tTekan enter untuk kembali ke transaksi"<<endl;
                                system("pause>NUL");
                                goto Transaksi;
                            } else {
                                cout <<"harap input (y/n)";
                                system("pause");
                                system("cls");
                                goto Transaksi;
                            }

                    ofstream myFile;

                    myFile.open("FakturPembelian.txt");

                    myFile << endl;
                    myFile<<"\n\tFAKTUR BELI"<<endl;
                    myFile<<"--------------------------------------------------------------------------------------"<<endl;
                    myFile<<"KODE\tNAMA VALAS\t\tJML VALAS\t\tKURS\t\tJUMLAH (Rp.)"<<endl;
                    myFile<<"--------------------------------------------------------------------------------------"<<endl;
                    myFile<<matauang[a].kode<<"\t"<<matauang[a].nama_matauang<<"\t\t\t"<<uang<<"\t\t\t"<<matauang[a].kurs_beli<<"\t\tRp."<<hasil_beli<<endl;
                    myFile<<"\n\n-------------------------------------------------------------------------------------"<<endl;

                    myFile.close();
                    }

                    else {
                        cout<<"\n\tInputan yang anda masukkan salah. Mohon masukkan inputan yang benar\n"<<endl;
                        system("pause");
                        goto Transaksi;
                        }
                        system("pause");
                        goto menu;
}

void cari()
{
    string negara,Input;

    matauang matauang[15];

   Node *kd_1,*kd_2,*kd_3,*kd_4,*kd_5,*kd_6,*kd_7,*kd_8,*kd_9,
        *kd_10,*kd_11,*kd_12,*kd_13,*kd_14,*kd_15,*kd_16,*kd_17,*kd_18,
        *ngr_1,*ngr_2,*ngr_3,*ngr_4,*ngr_5,*ngr_6,*ngr_7,*ngr_8,*ngr_9,
        *ngr_10,*ngr_11,*ngr_12,*ngr_13,*ngr_14,*ngr_15,*ngr_16,*ngr_17,*ngr_18,
        *jl_1,*jl_2,*jl_3,*jl_4,*jl_5,*jl_6,*jl_7,*jl_8,*jl_9,
        *jl_10,*jl_11,*jl_12,*jl_13,*jl_14,*jl_15,*jl_16,*jl_17,*jl_18,
        *bl_1,*bl_2,*bl_3,*bl_4,*bl_5,*bl_6,*bl_7,*bl_8,*bl_9,
        *bl_10,*bl_11,*bl_12,*bl_13,*bl_14,*bl_15,*bl_16,*bl_17,*bl_18;

              createNewTree("Dollar Amarika");
              ngr_1 = insertLeft("Amerika",root);
              kd_1 = insertRight("USD",root);
              jl_1 = insertLeft("14.400,00",ngr_1);
              bl_1 = insertRight("14.300,00",ngr_1);

              createNewTree("Euro");
              ngr_2 = insertLeft("Eropa",root);
              kd_2 = insertRight("EUR",root);
              jl_2 = insertLeft("15.800,00",ngr_2);
              bl_2 = insertRight("15.700,00",ngr_2);

              createNewTree("Yen");
              ngr_3 = insertLeft("Jepang",root);
              kd_3 = insertRight("JPY",root);
              jl_3 = insertLeft("118,00",ngr_3);
              bl_3 = insertRight("117,00",ngr_3);

              createNewTree("Dollar Australia");
              ngr_4 = insertLeft("Australia",root);
              kd_4 = insertRight("AUD",root);
              jl_4 = insertLeft("10.515,00",ngr_4);
              bl_4 = insertRight("10.410,00",ngr_4);

              createNewTree("Dollar Brunei");
              ngr_5 = insertLeft("Brunei",root);
              kd_5 = insertRight("BND",root);
              jl_5 = insertLeft("10.640,00",ngr_5);
              bl_5 = insertRight("10.530,00",ngr_5);

              createNewTree("Dollar Kanada");
              ngr_6 = insertLeft("Kanada",root);
              kd_6 = insertRight("CAD",root);
              jl_6 = insertLeft("11.650,00",ngr_6);
              bl_6 = insertRight("11.525,00",ngr_6);

              createNewTree("Franc Swiss");
              ngr_7 = insertLeft("Swiss",root);
              kd_7 = insertRight("CHF",root);
              jl_7 = insertLeft("14.950,00",ngr_7);
              bl_7 = insertRight("14.790,00",ngr_7);

              createNewTree("Yuan");
              ngr_8 = insertLeft("China",root);
              kd_8 = insertRight("CNY",root);
              jl_8 = insertLeft("2.180,00",ngr_8);
              bl_8 = insertRight("2.170,00",ngr_8);

              createNewTree("Krone");
              ngr_9 = insertLeft("Denmark",root);
              kd_9 = insertRight("DKK",root);
              jl_9 = insertLeft("2.107,00",ngr_9);
              bl_9 = insertRight("2.085,00",ngr_9);

              createNewTree("Poundsterling");
              ngr_10 = insertLeft("Inggris",root);
              kd_10 = insertRight("GBP",root);
              jl_10 = insertLeft("18.320,00",ngr_10);
              bl_10 = insertRight("18.135,00",ngr_10);

              createNewTree("Dollar Hongkong");
              ngr_11 = insertLeft("Hongkong",root);
              kd_11 = insertRight("HKD",root);
              jl_11 = insertLeft("1.860,00",ngr_11);
              bl_11 = insertRight("1.845,00",ngr_11);

              createNewTree("Won");
              ngr_12 = insertLeft("Korea",root);
              kd_12 = insertRight("KRW",root);
              jl_12 = insertLeft("11,00",ngr_12);
              bl_12 = insertRight("11,00",ngr_12);

              createNewTree("Dinar Kuwait");
              ngr_13 = insertLeft("Kuwait",root);
              kd_13 = insertRight("KWD",root);
              jl_13 = insertLeft("47.760,00",ngr_13);
              bl_13 = insertRight("47.270,00",ngr_13);

              createNewTree("Ringgit");
              ngr_14 = insertLeft("Malaysia",root);
              kd_14 = insertRight("MYR",root);
              jl_14 = insertLeft("3.330,00",ngr_14);
              bl_14 = insertRight("3.300,00",ngr_14);

              createNewTree("Dollar Singapura");
              ngr_15 = insertLeft("Singapura",root);
              kd_15 = insertRight("SGD",root);
              jl_15 = insertLeft("10.640,00",ngr_15);
              bl_15 = insertRight("10.530,00",ngr_15);

              createNewTree("Baht");
              ngr_16 = insertLeft("Thailand",root);
              kd_16 = insertRight("THB",root);
              jl_16 = insertLeft("421,71",ngr_16);
              bl_16 = insertRight("417,16",ngr_16);

              createNewTree("Riyal");
              ngr_17 = insertLeft("Arab Saudi",root);
              kd_17 = insertRight("SAR",root);
              jl_17 = insertLeft("3.903,14",ngr_17);
              bl_17 = insertRight("3.864,10",ngr_17);

              createNewTree("Peso");
              ngr_18 = insertLeft("Filipina",root);
              kd_18 = insertRight("PHP",root);
              jl_18 = insertLeft("276,05",ngr_18);
              bl_18 = insertRight("273,20",ngr_18);

              cari_matauang:
                  {
                      system("cls");

                cout<<"\t--------------------------------"<<endl;
                cout<<"          \tCARI MATA UANG        "<<endl;
                cout<<"\t--------------------------------"<<endl;
                cout<<"\n\tInputkan Nama negara : ";
                cin>>negara;

                if (negara == "Amerika"||negara == "amerika"){find(ngr_1);}
                else if(negara == "Eropa"||negara == "eropa"){find(ngr_2);}
                else if(negara == "Jepang"||negara == "jepang"){find(ngr_3);}
                else if(negara == "Australia"||negara == "australia"){find(ngr_4);}
                else if(negara == "Brunei"||negara == "brunei"){find(ngr_5);}
                else if(negara == "Kanada"||negara == "kanada"){find(ngr_6);}
                else if(negara == "Swiss"||negara == "swiss"){find(ngr_7);}
                else if(negara == "China"||negara == "cina"){find(ngr_8);}
                else if(negara == "Denmark"||negara == "denmark"){find(ngr_9);}
                else if(negara == "Inggris"||negara == "inggris"){find(ngr_10);}
                else if(negara == "Hongkong"||negara == "hongkong"){find(ngr_11);}
                else if(negara == "Korea"||negara == "korea"){find(ngr_12);}
                else if(negara == "Kuwait"||negara == "kuwait"){find(ngr_13);}
                else if(negara == "Malaysia"||negara == "malaysia"){find(ngr_14);}
                else if(negara == "Singapura"||negara == "singapura"){find(ngr_15);}
                else if(negara == "Thailand"||negara == "thailand"){find(ngr_16);}
                else if(negara == "Arab Saudi"||negara == "ArabSaudi"||negara == "arabsaudi"|| negara == "arab saudi"){find(ngr_17);}
                else if(negara == "Filipina"||negara == "filipina"){find(ngr_18);}

                else{
                    cout<<"\n\tMohon maaf mata uang negara tersebut belum tersedia \n"<<endl;
                    system("pause");
                    goto cari_matauang;
                }
                  }
}

void pop()
{
    del = Tail;
    Tail = Tail->prev;
    delete del;
    cout<<"\n\tHistory transaksi berhasil dihapus \n"<<endl;
}

void destroy()
{
    Cur = Tail;
    while(Cur!=NULL)
    {
        del = Cur;
        Tail = Tail->prev;
        delete del;
        Cur=Cur->prev;
    }

    cout<<"\n\tHistori berhasil dihapus !!!\n"<<endl;
}

void display_counthasil()
{
    display_hasil:
    {
    system("cls");
    string hapus;
 if (Tail == NULL){cout<<"\n\tHistori Kosong !! \n"<<endl;}

 else
 {
     cout<<"\t======================================="<<endl;
     cout<<"\t          HISTORY TRANSAKSI "<<endl;
     cout<<"\t======================================="<<endl;

     Cur = Tail;

        while(Cur != NULL)
        {

         cout<<"\n\tMata uang       : "<<Cur->nama_matauang<<endl;
         cout<<"\tKode            : "<<Cur->kode<<endl;
         cout<<"\tKurs            : "<<Cur->kurs_jual<<endl;
         cout<<"\tHasil Transaksi : "<<Cur->hasil_jual<<endl;
         Cur = Cur->prev;
        }

        cout<<"\n\tHapus history transaksi terakhir tekan '1'"<<endl;
        cout<<"\tHapus history seluruhnya tekan '2'"<<endl;
        cout<<"\tKeluar tekan '0'"<<endl;
        cout<<"\t-> ";
        getline(cin,hapus);

        if(hapus=="1")
        {
          pop();
          system("pause");
          goto display_hasil;
        }


        else if(hapus=="2")
        {
            destroy();
            system("pause");
            goto display_hasil;
        }

        else if(hapus=="0")
        {
            return;
            getch();

        }

        else
        {
            cout<<"\n\tMaaf inputan yang anda masukan salah"<<endl;
            system("pause");
            goto display_hasil;
        }
 }
    }
}

void login()
{
    int count; //untuk perantara, karena ifstream hanya membaca file
    string user, pass, u, p, validasi;
    char ch;

    login:

    system("cls");
    cout << "\n\t============ Login ===========" << endl;
    cout << "\tUsername : "; getline(cin,user);
    cout << "\tPassword : "; ch =_getch();
        while(ch != 13){
                pass.push_back(ch);
                cout<<'*';
                ch = _getch();}

    ifstream input;
    input.open("dataDaftarMC.txt",ios::app);
    while(input >> u >> p){
        if(u == user && p == pass){
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count == 1){

        homepage:

        string choice;

        system("cls");
        cout << endl;
        cout << "\t" << "============ PROGRAM MONEY CHANGER ============= " << endl;
        cout << endl;
        cout << endl;
        cout << "\t" << "================================================ " << endl;
        cout << "\t" << " PROGRAM INI BERTUJUAN UNTUK MEMENUHI  TUGAS UAS " << endl;
        cout << "\t" << "     MATA KULIAH STRUKTUR DATA DAN ALGORITMA     " << endl;
        cout << "\t" << "             SEMOGA BERMANFAAT :)                " << endl;
        cout << "\t" << "================================================ " << endl;
        cout << endl;
        cout << "\t" << "Dibuat oleh: " << endl;
        cout << endl;
        cout << "\t" << "No.        Nama           NIM             Kelas" << endl;
        cout << "\t" << "------------------------------------------------" << endl;
        cout << "\t" << "1.	Afwa Afini      2101968		2A - RPL" << endl;
        cout << "\t" << "2.	Akbar Hidayat	2102392		2A - RPL" << endl;
        cout << "\t" << "3.	Rafi Fajrul     2101569		2A - RPL" << endl;
        cout << "\t" << "------------------------------------------------" << endl;
        cout << endl;
        cout << "\t" << "Selamat datang, " << user << "." << endl << endl;
        cout << "\t" << "Layanan Yang Akan Dipilih: " << endl;
        cout << "\t" << "1. Tukar uang" << endl;
        cout << "\t" << "2. Cari Mata Uang" << endl;
        cout << "\t" << "3. Faktur Penjualan" << endl;
        cout << "\t" << "4. Faktur Pembelian" << endl;
        cout << "\t" << "5. History Transaksi" << endl;
        cout << "\t" << "6. Keluar dari program" << endl;
        cout << "\t" << "Menu yang dipilih (1-5): ";
        getline(cin,choice);

            if(choice == "1")
            {
              system("cls");
              TukarUang();
              cout << endl;
              cout << endl;
              cout << "\t" << "(tekan Enter untuk kembali ke menu Money Changer)" << endl;
              getch();
              system("cls");
              goto homepage;
            }

            else if(choice=="2"){
                system("cls");

                cari();
                system("pause");
                system("cls");
                goto homepage;
            }

            else if(choice == "3"){
               ifstream myFile("FakturPenjualan.txt");
               string str;

                    if (!myFile.fail())
                    {

                    system ("cls");

                        cout<<"\n\n";
                        cetak_data_nasabah();

                        while (getline(myFile,str)){

                        cout << str << endl;
                        }

                        cout << endl;
                        cout << endl;
                        cout << "\t" << "(tekan Enter untuk kembali ke menu Money Changer)" << endl;
                        getch();
                        system("cls");
                        goto homepage;
                    }
                    else
                    {
                    cout << endl;
                    cout << "\t" << "Anda belum pernah menjual." << endl;
                    cout << "\t" << "(tekan Enter untuk kembali)" << endl;
                    getch();
                    system("cls");
                    goto homepage;
                    }
            }

            else if(choice == "4"){
                 ifstream myFile("FakturPembelian.txt");
                 string str;

                    if (!myFile.fail())
                    {

                    system ("cls");

                        cout<<"\n\n";
                        cetak_data_nasabah();

                        while (getline(myFile,str)){

                        cout << str << endl;
                        }

                        cout << endl;
                        cout << endl;
                        cout << "\t" << "(tekan Enter untuk kembali ke menu Money Changer)" << endl;
                        getch();
                        system("cls");
                        goto homepage;
                        }
                    else
                    {
                    cout << endl;
                    cout << "\t" << "Anda belum pernah membeli." << endl;
                    cout << "\t" << "(tekan Enter untuk kembali)" << endl;
                    getch();
                    system("cls");
                    goto homepage;
                    }
            }

             else if (choice == "5")
                {
                    system("cls");
                    display_counthasil();
                    cout << "\t" << system("pause");
                    goto homepage;
                }


            else if(choice == "6"){
                system("cls");
                cout << "\tLogout berhasil! Silahkan datang kembali ya!" << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t" << system("pause");
                cout << "\t" << system("cls");
            }

            else{
                cout << "\n\tHarap input yang benar (1/2/3/4)" << endl;
                cout << "\t" << system("pause");
                goto homepage;
            }
    cout << endl;
    }
    else{
        string jawab;
        erorLogin:
            cout <<endl;
            cout << "\tLogin error! Periksa kembali username dan password Anda" << endl;
            cout << "\tCoba lagi? (Y/N) -> ";
            getline(cin,jawab);
            if(jawab == "Y" || jawab == "y"){
                goto login;
            }
            else if(jawab == "N" || jawab == "n"){
                system("cls");
            }
            else{
                system("cls");
                goto erorLogin;
            }
        }
    }


int main()
{
    string pilih, validasi;

    system("cls");
    landingPage:
        cout <<endl;
        cout << "\t     Money Changer Program   " << endl;
        cout << "\t==============================" << endl;
        cout << "\t1) Login" << endl;
        cout << "\t2) Register" << endl;
        cout << "\t3) Display data " << endl;
        cout << "\t4) Keluar program " << endl;
        cout << "\tPilih (1/2/3/4) : "; getline(cin,pilih);
        cout << endl;

    if(pilih == "1"){
        login();
    } else if(pilih == "2"){
        registr();
            cout << "\n\tKembali ke Menu Utama? [y/n] : ";
            getline(cin,validasi);
                if (validasi == "y" || validasi == "Y")
                {
                    system("cls");
                    goto landingPage;
                }
                else if (validasi == "n" || validasi == "N")
                {
                    cout <<"\tThank you!! :D";
                    return 0;
                }
                 else
                    cout <<"Harap input y/n)";
                    system("pause");
                    system("cls");
                    goto landingPage;
    } else if(pilih == "3"){
        display();
            cout << "\nKembali ke Menu Utama? [y/n] : ";
            getline(cin,validasi);
                if (validasi == "y" || validasi == "Y")
                {
                    system("cls");
                    goto landingPage;
                }
                else if (validasi == "n" || validasi == "N")
                {
                    cout <<"Thank you!! :D";
                    return 0;
                }
                else
                    cout <<"Harap input (y/n)";
                    system("pause");
                    system("cls");
                    goto landingPage;
    } else if(pilih == "4"){
        cout <<"\tThank you!! :D";
        return 0;
    } else{
        cout << "\tHarap input (1/2/3/4)" << endl;
        cout << "\t" << system("pause");
        cout << "\t" << system("cls");
        goto landingPage;
    }
}

