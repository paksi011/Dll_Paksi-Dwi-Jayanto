#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;

struct node
{
      int data;
      node* next;
      node* prev;
};
node* head;
node* tail;
node* ctk;
node* del;
node* entry;

void inisialisasi()
{
      head = NULL;
      tail = NULL;
}

void input(int *dt)
{
      entry = new node;
      entry->data = *dt;
      entry->next = NULL;
      entry->prev = NULL;
      if(head!=NULL)
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
            cout<<"\n"<<simpan<<" data yang dihapus adalah"<<endl;
            head = head->next;
            head->prev = NULL;
            delete del;
            }
            else
            {
                  simpan = head->data;
                  cout<<"\n"<<simpan<<" data yang dihapus adalah"<<endl;
                  head = NULL;
            }

      }
      else
            cout<<"\nLinked List kosong penghapusan tidak dapat dilakukan"<<endl;
}

void cetak()
{
      ctk = head;
      if(head!=NULL)
      {
            while(ctk!=NULL)
            {
                  cout<<"\n\t"<<ctk->data;
                  ctk = ctk->next;
            }
      }
      else
            cout<<"\nTidak ada data dalam linked list"<<endl;

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
      cout<<"-------------------------------"<<endl;
      cout<<"Menu: ";
      cout<<"\n1. Input Data";
      cout<<"\n2. Hapus Data";
      cout<<"\n3. Cetak Data";
      cout<<"\n4. Exit";
      cout<<"\nMasukkan pilihan Anda : ";
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
            cout<<"\nTerima kasih"<<endl;
            exit;
            break;
      default :
            cout<<"\nPilih ulang"<<endl;
            goto menu;
      }
      cout<<"\nKembali ke menu? (y/n)";
      cin>>ulang;
      }while(ulang=='y' || ulang =='Y');
}

int main()
{
      inisialisasi();
      menu();
      return 0 ;
}
