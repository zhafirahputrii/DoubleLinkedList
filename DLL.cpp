//ZhafirahNurShadrinaPutri
//G1A021028
//DLL
#include <iostream>
using namespace std;

typedef struct node
{
    long data;
    node* next;
    node* prev;
};

node* head;
node* tail;
node* print;
node* del;
node* entry;

void inisialisasi()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

void input(int *dta)
{
    entry = new node;
    entry->data = *dta;
    entry->next = NULL;
    entry->prev = NULL;
    if(isEmpty()==1)
	{
        head = entry;
        head->next = NULL;
        head->prev = NULL;
        tail=head;
    }
    else
	{
        tail->next = entry;
        entry->prev = tail;
        tail = entry;
    }
}

void hapus()
{
    int simpan;
    if(head!=NULL) 
    {
        if(head->next != NULL)
        {
		del=head;
        simpan = head->data;
        cout<<"\n"<<simpan<<"data berhasil dihapus"<<endl;
        head = head->next;
        head->prev = NULL;
        delete del;
        }
        else
        {
            simpan = head->data;
            cout<<"\n"<<simpan<<"data berhasil dihapus"<<endl;
            head = NULL;
        }

    }
    else
        cout<<"\npenghapusan tidak dapat dilakukan karena tidak ada data"<<endl;
}

void cetak()
{
    print = head;
    if(head!=NULL)
    {
        while(print!=NULL)
        {
            cout<<"\n\t"<<print->data;
            print = print->next;
        }
    }
    else
        cout<<"\nData Kosong"<<endl;

}
void menu()
{
char pilih, ulang;
int data;
do
{
    system("CLS");
	menu :
    cout<<"DOUBLE LINKED LIST"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Menu: \n";
    cout<<"1. Masukkan Data\n";
    cout<<"2. Hapus Data\n";
    cout<<"3. Lihat Data\n";
    cout<<"4. Keluar\n";
    cout<<"Masukkan pilihan Anda : \n";
    cin>>pilih;

    switch(pilih)
    {
    case '1' :
        cout<<"\nMasukkan Data  : ";
        cin>>data;
		input(&data);
        cout<<"\n"<<data<<" telah ditambahkan"<<endl;
		break;
    case '2' :
        hapus();
        break;
    case '3'  :
        cetak();
        break;
    case '4' :
        cout<<"\nTerima kasih "<<endl;
        exit;
        break;
    default :
        cout<<"\nPilih Kembali"<<endl;
        goto menu;
    }
    cout<<"\nKembali ke menu? (y/n)";
    cin>>ulang;
    }
	while(ulang =='y' || ulang =='Y');
}

int main()
{
    inisialisasi();
    menu();
    return 0 ;
}