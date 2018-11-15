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

int licznik=0;


//********************************************************************************8
void wstawia_elem(Node ** head, int klucz)//gotowe
{
    //srand(time(0));
    double los=rand()%1000;
//alokacja pamieci na nowy wezel listy
        Node *nowy= new Node;
        cout<<"nowy "<<nowy<<endl;
        if(!nowy)
        {
            std::cout<<"Nie udalo sie utworzyc nowego wezla listy!\n Brak pamieci!"<<std::endl;
            //tutaj trzeba dac przerwanie
        }
//inicjalizacja liczbowych zmiennych wezla:
        nowy->klucz=klucz;
        nowy->los=los;
        nowy->ch='T';
cout<<"nowy klucz "<<nowy->klucz<<endl;
//wstawianie wezla do listy:
//***********************************************************************************************
//Gdy lista jest pusta:
//*************************************************************************************************

    //Node *temp=*head;   //tymczasowy head
//**************************************************************************************************8
//cout<<"ptr :"<<ptr<<endl;
        if(*head==nullptr)
        {
            *head=nowy;
            nowy->next=nowy;
            nowy->prev=nowy;
            licznik++;
cout<<"head prev"<<(*head)->prev<<endl;
cout<<"licznik :"<<licznik<<endl;
        }//OK
//***************************************************************************************************
//Wstawianie z szukaniem miejsca do niepustej listy:

        //Gdy wstawiamy przed HEADa:
        else if((nowy->klucz)<((*head)->klucz))
        {
            nowy->next=*head;
            nowy->prev=(*head)->prev;
            (*head)->prev=nowy;
            *head=nowy;
            (*head)->prev->next=*head;  //wazne odnowienie polaczenia z koncem listy
            licznik++;
            cout<<"wezel przed headem: "<<nowy<<"   next "<<nowy->next<<"  prev"<<nowy->prev<<endl;
            cout<<"wezel przed headem: "<<nowy<<"   head next "<<(*head)->next<<" head prev"<<(*head)->prev<<endl;
            cout<<"nowy head "<<*head<<endl;
            //cout<<"ptr "<<ptr<<endl;

        }
//****************************************************************************************************


            else
            {//gdy wstawiamy gdzies w srodku, lub na koncu:
                Node * ptr=*head;   //pomocniczt wskaznik wedrujacy
        do
        {   //sprawdzamy, czy to nie duplikat:
            if(nowy->klucz==ptr->klucz)
            {
                std::cout<<"Powtorzona kluczowa wartosc! "<<nowy->klucz<<" = "<<ptr->klucz<<std::endl;
                break;
            }
            if(nowy->klucz<ptr->klucz)//wstawienie przed
            {
                nowy->next=ptr;
                nowy->prev=ptr->prev;
                ptr->prev->next=nowy;
                ptr->prev=nowy;
                licznik++;
                break;
            }
            else if(ptr->next==*head)//wstawienie za ostatnim elementem listy
            {
                nowy->next=*head;
                nowy->prev=ptr;
                (*head)->prev=nowy;
                ptr->next=nowy;
                licznik++;
                break;
            }
                ptr=ptr->next;  //przesuwamy sie o 1 wezel do przodu
        }
        while(ptr!=*head);
 //   koniec tworzenia wezla listy
            }
}
//*************************************************************************************************************

//hurtowe wstawianie wezlow do listy
void wstawia_X_elem(Node ** head, int X)//gotowe
{
    Node * ptr=*head;

    int los;
    //gdy powtorki...
    //gdy brak pamieci...S
bool tabl_losowych[99901]{};            //tablica do spkrawdzania powtarzalnosci
//*********************************************************************************************
//odznaczenie w tablicy juz istniejacych w liscie kluczy
if(*head)
{
    //Node *ptr=*head;

    //przejscie przez liste aby zaktualizowac tablice wystepujacych juz w liscie kluczzy
    do
    {
        if(ptr->klucz>=99&&ptr->klucz<=99999)
            tabl_losowych[ptr->klucz]=true;
        ptr=ptr->next;
    }while(ptr!=*head);
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
    //wywolanie funkcji wstawiajacej dla wylosowanego klucza
        wstawia_elem(head, los);
}
}


void prezentacja_poczatek(Node *head, int liczba_wezlow)
{//funkcja wypisuje n poczatkowych wezlow od czola listy
    Node * ptr=head;

    //moze ich tyle nie byc...
    //lista moze byc pusta
        cout<<"Wyswietlenie "<<liczba_wezlow<<" poczatkowych wezlow listy:"<<endl;

    if(!head)
    {
        cout<<"Blad!! Lista jest pusta. Nie mozna nic wyswietlic."<<endl;
        return;
    }
    else if(licznik<liczba_wezlow)
    {
        cout<<"Nie ma tylu wezlow w liscie"<<endl;
        cout<<"Wyswietlimy tylko "<<licznik<<" wezlow"<<endl;
    }
    //ptr=ptr->prev;
cout<<"zawartosc head: "<<ptr->klucz<<endl;
    for(int i=0; i<liczba_wezlow; i++)
    {
        cout<<"Klucz: "<<ptr->klucz<<"  "<<ptr->los<<"  "<<ptr->ch<<endl;
        ptr=ptr->next;
        if(ptr==head)
            return;
    }
    delete ptr;

}

//**************************************************************************************************888

void prezentacja_koniec(Node * head, int liczba_wezlow)
{//funkcja wypisuje n koncowych wezlow listy

    //moze byc ich mniej ...
    //lista moze byc pusta
    cout<<"Wyswietlenie "<<liczba_wezlow<<" wezlow listy:"<<endl;
    if(!head)
    {
        cout<<"Blad!! Listaa jest pusta. Nie mozna nic wyswietlic."<<endl;
        return;
    }
    else if(licznik<liczba_wezlow)
    {
        cout<<"Nie ma tylu wezlow w liscie"<<endl;
        cout<<"Wyswietlimy tylko "<<licznik<<" wezlow"<<endl;
        //liczba_wezlow=licznik;
    }
    Node * ptr=head;
    ptr=ptr->prev;

    for(int i=0; i<liczba_wezlow&&licznik>0; i++, licznik--)
    {
        cout<<"Klucz: "<<ptr->klucz<<"  "<<ptr->los<<"  "<<ptr->ch<<endl;
        ptr=ptr->prev;
    }
    delete ptr;
}

//*******************************************************************************************************
void szukaj(Node *head, int klucz)//gotowe
{
    //funkcja wyszukuje wezel o zadanym kluczu i wypisuje go
    Node * ptr=head;
    //moze go nie znalezc...

    if(head)//lizta moze byc pusta...
    {
        //Node * ptr=head;
        //int sukces=0;
        do
        {
            if(ptr->klucz==klucz)
                {
                    //sukces++;
                    cout<<"adres wezla "<<ptr<<"   szukany klucz : "<<ptr->klucz<<
                    "   wartosc losowa double: "<<ptr->los<<endl;
                    return;
                }
            ptr=ptr->next;
        }while(ptr!=head);
            if(ptr==head)//(!sukces)
                cout<<"Niestety nie udalo sie odnalexc szukanej wartosci..."<<endl;
    }
    else
        {
            cout<<"Lista nie zawiera zadnych elementow!"<<endl;
        }
        ptr=nullptr;
}

/*
//*********************************************************************************************************
void usuwanie_elementu(int k)//gotowe
{//funkcja usuwa z listy wezel o zadanym kluczu
    if(!head)//gdy lista jest pusta
        {
            cout<<"Lista jest pusta i nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }
    Node * ptr=head;

    //lista moze byc pusta ,,, po usunieciu
    if(head)
    {
        do
        {
            if(ptr->klucz==k)   //znalezienie wezla z szukanym kluczem
            {
                cout<<"wezel o kluczu "<<k<<" znaleziony..."<<endl;

                    if(ptr==head)//gdy X jest headem...
                    {
                        cout<<"byl headem ";

                        if(ptr->next==ptr)//czy X to jedyny element listy?
                        {
                            cout<<"i w dodatku jedynym wezlem "<<endl;

                            head=nullptr;//wiec trzeba wyzerowac heaada...
                            delete ptr;
                            licznik--;
                            cout<<"...juz go nie ma wsrod nas."<<endl;
                            return;
                        }
                        else
                        {
                            cout<<", ale nie byl jedyny"<<endl;
                            //trzeba bedzie przestawic heada...
                            head->prev->next=head->next;
                            head->next->prev=head->prev;
                            head=ptr->next;
                            delete ptr;
                            licznik--;
                            cout<<"Juz po nim... "<<endl;
                            return;
                        }
                    }
                //gdy to nastepny po X jest headem...
                else //if(ptr!=head)//else if(ptr->next==head)
                {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    licznik--;
                    delete ptr;
                    cout<<"Byl gdzies w srodku listy. "<<endl;
                    return;
                }
            }
            ptr=ptr->next;
        }while(ptr!=head);  //dotarcie do konca listy

        if(ptr==head) //lub ptr==head  wtedy komunikat
                cout<<"Niestety nie udalo sie odnalexc i usunac wezla o kluczu: "<<k<<endl;
    }
        ptr=nullptr;
}
/*
//************************************************************************************************************88
void usuwanie_calej_listy()//gotowe
{


    if(!licznik)//gdy lista jest pusta
        {
            cout<<"Lista jest pusta i nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }
    while(head)
    {
                Node * ptr=head;

                        cout<<"byl headem ";

                        if(ptr->next==ptr)//czy X to jedyny element listy?
                        {
                            cout<<"i w dodatku jedynym wezlem "<<endl;

                            head=nullptr;//wiec trzeba wyzerowac heaada...
                            delete ptr;
                            licznik--;
                            cout<<"...juz go nie ma wsrod nas."<<endl;
                            //return;
                        }
                        else
                        {
                            cout<<", ale nie byl jedyny"<<endl;
                            //trzeba bedzie przestawic heada...
                            head->prev->next=head->next;
                            head->next->prev=head->prev;
                            head=ptr->next;
                            //delete ptr;
                            licznik--;
                            cout<<"Juz po nim... "<<endl;

                        }
                        cout<<"Licznik w funkcji: "<<licznik<<endl;


    }

            if((!head)||(!licznik))
            {
                cout<<"Lista usunieta..."<<endl;
                return;
            }
}



*/


//*************************************************************************************************************8
int main()
{
    srand(time(0));

    struct Node *head=nullptr;
struct Node *wsk_head=head;


wstawia_elem(&head, 10000);


//cout<<"head w main"<<wsk_head<<"    "<<endl;

wstawia_elem(&head, 8700);

wstawia_elem(&head, 12100);

//wstawia_elem(2);
//wstawia_elem(321);
//wstawia_elem(121);
wstawia_elem(&head, 1);
wstawia_X_elem(&head, 5);
//wstawia_elem(1937);
//usuwanie_elementu(100);
//usuwanie_elementu(87);
//usuwanie_elementu(121);
//usuwanie_calej_listy();
szukaj(head, 121);
//szukaj(1000000);
//usuwanie_elementu(100);

//szukaj(1937);
//usuwanie_elementu(100);
//prezentacja_koniec(30);
//prezentacja_koniec(head, 39);
//prezentacja_poczatek(100);
//prezentacja_poczatek(head, 5);
//prezentacja_poczatek(head, 20);
//prezentacja_poczatek(head, 49);
//prezentacja_poczatek(5);
//usuwanie_calej_listy();
cout<<"licznik po usunieciu listy: "<<licznik<<endl;
//usuwanie_calej_listy();
//usuwanie_calej_listy();

/*
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
*/

    return 0;
}
