#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

struct Node
{
    int klucz;
    double los;
    char ch;
    Node *next;
    Node *prev;
};
Node *head=nullptr;
int licznik=0;


//********************************************************************************8
void wstawia_elem(int klucz)//gotowe
{
    srand(time(0));
//alokacja pamieci na nowy wezel listy
        Node *nowy= new Node;
        if(!nowy)
        {
            std::cout<<"Nie udalo sie utworzyc nowego wezla listy!\n Brak pamieci!"<<std::endl;
            //tutaj trzeba dac przerwanie
        }
//inicjalizacja liczbowych zmiennych wezla:
        nowy->klucz=klucz;
        nowy->los=rand()%1000;
        nowy->ch='T';

//wstawianie wezla do listy:
//***********************************************************************************************
//Gdy lista jest pusta:
//*************************************************************************************************
    Node * ptr=head;        //pomocniczt wskaznik wedrujacy
//**************************************************************************************************8
        if(head==nullptr)
        {
            head=nowy;
            nowy->next=nowy;
            nowy->prev=nowy;
            licznik++;

            //test adresow - pozniej do usuniecia
            //cout<<"Test adresow I-go wezla:"<<endl;
            //cout<<"nowy = "<<nowy<<"    "<<"head = "<<head<<"   "<<"nowy->next = "<<nowy->next<<
           // "   "<<"nowy->prev = "<<nowy->prev<<endl;
        }//OK
//***************************************************************************************************
//Wstawianie z szukaniem miejsca do niepustej listy:

        //Gdy wstawiamy przed HEADa:
        else if((nowy->klucz)<(ptr->klucz))
        {
            nowy->next=head;//ok
            nowy->prev=head->prev;
            head->prev=nowy;
            head=nowy;
            head->prev->next=head;  //wazne odnowienie polaczenia z koncem listy
            licznik++;
            //ok
//***************************************************************************************************
            //test adresow - pozniej do usuniecia
            //cout<<"Test adresow II-go wezla klucz<klucz heada:"<<endl;
           // cout<<"nowy = "<<nowy<<"    "<<"head = "<<head<<"   "<<"nowy->next = "<<nowy->next<<
           // "   "<<"nowy->prev = "<<nowy->prev<<endl;

        }
//****************************************************************************************************

            else
            {//gdy wstawiamy gdzies w srodku, lub na koncu:
        do
        {   //sprawdzamy, czy to nie duplikat:
            if(nowy->klucz==ptr->klucz)
            {
                std::cout<<"Powtorzona kluczowa wartosc! "<<nowy->klucz<<" = "<<ptr->klucz<<std::endl;
                break;
            }
        //dotad chyba jest dobrze
            if(nowy->klucz<ptr->klucz)//wstawienie przed
            {
                nowy->next=ptr;
                nowy->prev=ptr->prev;
                ptr->prev->next=nowy;
                ptr->prev=nowy;
                licznik++;
                break;
            }
            else if(ptr->next==head)//wstawienie za ostatnim elementem listy
            {
                nowy->next=head;
                nowy->prev=ptr;
                head->prev=nowy;
                ptr->next=nowy;
                licznik++;
                break;
            }
                ptr=ptr->next;  //przesuwamy sie o 1 wezel do przodu
        }
        while(ptr!=head);
 //   koniec tworzenia wezla listy
            }
}
//*************************************************************************************************************

//hurtowe wstawianie wezlow do listy
void wstawia_X_elem(int X)//gotowe
{
    srand(time(0));
    int los;
    //gdy powtorki...
    //gdy brak pamieci...S
bool tabl_losowych[99901]{};            //tablica do spkrawdzania powtarzalnosci
//*********************************************************************************************
//odznaczenie w tablicy juz istniejacych w liscie kluczy
if(head)
{
    Node * ptr=head;
    do
    {
        if(ptr->klucz>=99&&ptr->klucz<=99999)
            tabl_losowych[ptr->klucz]=true;
        ptr=ptr->next;
    }while(ptr!=head);
    ptr=nullptr; //oslepienie wskaznika
}
//**************************************************************************************************
for(int i=0; i<X; i++)
{
    //losowanie unikalnej liczby i przes³anie jej do wezla listy
    do
        {
            los=(rand()%99901);
        }
        while(tabl_losowych[los]);
        tabl_losowych[los]=true;        //zapamietanie wylosowania danej liczb
        los+=99;
//***********************************************************************************************
wstawia_elem(los);
}
}



void prezentacja_poczatek(int liczba_wezlow)
{
    //funkcja wypisuje n poczatkowych wezlow od czola listy
    //moze ich tyle nie byc...
    //lista moze byc pusta

}

void prezentacja_koniec(int liczba_wezlow)
{
    //funkcja wypisuje n koncowych wezlow listy
    //moze byc ich mniej ...
    //lista moze byc pusta
}

void szukaj(int klucz)//gotowe
{

    Node * ptr=head;
    //funkcja wyszukuje wezel o zadanym kluczu i wypisuje go
    //moze go nie znalezc...
    //lizta moze bbyc pusta...
    if(head)
    {
        Node * ptr=head;
        int sukces=0;
        do
        {
            if(ptr->klucz==klucz)
                {
                    sukces++;
                    cout<<"adres wezla "<<ptr<<"   szukany klucz : "<<ptr->klucz<<
                    "   wartosc losowa double: "<<ptr->los<<endl;
                    break;
                }
            ptr=ptr->next;
        }while(ptr!=head);
            if(!sukces)
                cout<<"Niestety nie udalo sie odnalexc szukanej wartosci..."<<endl;
    }
    else
        {
            cout<<"Lista nie zawiera zadnych elementow!"<<endl;
        }



}



void usuwanie_elementu(int k)//gotowe
{
    if(!head)
        {
            cout<<"Lista nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }

    Node * ptr=head;
    //funkcja usuwa z listy wezel o zadanym kluczu
    //lista moze byc pusta ,,, po usunieciu
    if(head)
    {
        do
        {
            if(ptr->klucz==k)   //znalezienie wezla z szukanym kluczem
            {
                cout<<"klucz "<<k<<" znaleziony"<<endl;
                    //gdy X jest headem...
                    if(ptr==head)
                    {
                        cout<<"byl headem"<<endl;
                        //czy X to jedyny element listy?
                        if(ptr->next==ptr)
                        {
                            cout<<"byl jedynym wezlem:"<<endl;
                            //trzeba wyzerowac heaada...

                            head=nullptr;//chyba ok
                            delete ptr;
                            licznik--;
                            return;
                        }
                        else
                        {
                            cout<<"head, ale nie byl jedyny"<<endl;
                            //trzeba bedzie przestawic heada...
                            head->prev->next=head->next;
                            head->next->prev=head->prev;
                            head=ptr->next;
                            delete ptr;
                            licznik--;
                            return;     //ok

                        }
                    }
                //gdy to nie X, ale nastepny jest headem...
                else if(ptr!=head)//else if(ptr->next==head)
                {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    licznik--;
                    delete ptr;
                    return;
                }
            }
            ptr=ptr->next;
        }while(ptr!=head);  //dotarcie do konca listy
            if(ptr==head) //lub ptr==head  wtedy komunikat
                cout<<"Niestety nie udalo sie odnalexc i usunac wezla o kluczu: "<<k<<endl;
    }
        //ptr=nullptr;
}







int main()
{


wstawia_elem(100);
/*
wstawia_elem(87);
wstawia_elem(121);
wstawia_elem(2);
wstawia_elem(321);
wstawia_elem(121);
wstawia_elem(121);
wstawia_X_elem(12);
wstawia_elem(1937);
*/
szukaj(1937);
szukaj(1000000);
usuwanie_elementu(100);

szukaj(1937);
usuwanie_elementu(100);

cout<<"head = "<<head<<endl;
//usuwanie_elementu(100);
if(head)
{
   Node* wsk_head=head;
cout<<"head = "<<head<<endl;
cout<<"wsk_head = "<<wsk_head<<endl;
std::cout<<"Licznik : "<<licznik<<std::endl;
cout<<"Petla:"<<endl;



do
{
cout<<"adres wezla "<<wsk_head<<"   klucz : "<<wsk_head->klucz<<"   next: "<<wsk_head->next<<endl;
wsk_head=wsk_head->next;

}while(wsk_head!=head);

}


    return 0;
}
