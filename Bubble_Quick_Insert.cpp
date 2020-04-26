#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <fstream>


using namespace std;
//sortowanie babelkowe
struct student //struktura zawierajaca trzy pola
{
    string imie;
    string nazwisko;
    int punkty;
};
void sortowanieBabelkowe(int* tab, int n, int tryb)
{
    int tymczasowa, z, x;
    if(tryb==1) // rosnąco
    {
        for(z = 0; z<=n; z++)
        {
            for(x = z+1; x<=n; x++)
            {
                if(tab[x] < tab[z])
                {
                    tymczasowa = tab[z];
                    tab[z] = tab[x];
                    tab[x] = tymczasowa;
                }
            }
        }
    }
    else // malejąco
    {
    for(z = 0; z<=n; z++)
        {
        for(x = 0; x<=z; x++)
        {
            if(tab[z] > tab[x])
            {
                tymczasowa = tab[z];
                tab[z] = tab[x];
                tab[x] = tymczasowa;
            }
        }
        }
    }

}
void wypelnijTablice(int* tab, int n, int a, int b)
{
    for(int i=0; i <= n; i++)
    {
      tab[i] = rand()%(b-a+1)+a;
    }
}
void wyswietlTablice(int* tab, int n)
{
    for(int i = 0; i <= n; i++)
        cout << tab[i] << " ";
}
void wyczyscPamiec(int* tab)
{
    delete tab;
}
void bubbleSort()// glowna funkcja sortowania babelkowego
{
    int  n, a, b, tryb;
    cout << "\nPodaj rozmiar tablicy:";
    cin >> n;
    int tab[n];
    cout << "\nPodaj poczatek przedzialu:";
    cin >> a;
    cout << "\nPodaj koniec przedzialu:";
    cin >> b;
    cout << "\nTablica ma byc posortowana rosnaco(1), czy malejaco(0)?: ";
    cin >> tryb;
    wypelnijTablice(tab, n, a, b);
    cout << "\nTablica przed sortowaniem:";
    wyswietlTablice(tab, n);
    sortowanieBabelkowe(tab, n, tryb);
    cout << "\nTablica po sortowaniu:";
    wyswietlTablice(tab, n);
    cout << "\n";
    wyczyscPamiec(tab);
}
//koniec babelkowe
//Insert Sort
void sortowaniePrzezWstawianie(int* tab, int n, int tryb)
{
   int i = n-2;
   int j;
   int temp;
   if(tryb==1)
   {
   while(i >= 0)
    {
       j=i;
       temp = tab[j];
       while(temp > tab[j+1] && j <= n - 1)
       {
           tab[j] = tab[j+1];
           j += 1;
       }
       tab[j] = temp;
       i -= 1;
    }
   }
   else
   {
    while(i >= 0)
    {
       j=i;
       temp = tab[j];
       while(temp < tab[j+1] && j <= n - 1)
       {
           tab[j] = tab[j+1];
           j += 1;
       }
       tab[j] = temp;
       i -= 1;
    }
   }

}
void insertSort() // glowna funkcja sortowania przez wstawienie
{
    int  n, a, b, tryb;
    cout << "\nPodaj rozmiar tablicy:";
    cin >> n;
    int tab[n];
    cout << "\nPodaj poczatek przedzialu:";
    cin >> a;
    cout << "\nPodaj koniec przedzialu:";
    cin >> b;
    cout << "\nTablica ma byc posortowana rosnaco(1), czy malejaco(0)?: ";
    cin >> tryb;
    wypelnijTablice(tab, n, a, b);
    cout << "\nTablica przed sortowaniem:";
    wyswietlTablice(tab, n);
    sortowaniePrzezWstawianie(tab, n, tryb);
    cout << "\nTablica po sortowaniu:";
    wyswietlTablice(tab, n);
    cout << "\n";
    wyczyscPamiec(tab);
}
//koniec sortowanie przez wstawienie
//szybkie sortowanie
void wczytywanie(student*& tab, int &liczbaStudentow)
{
    string sciezka,linia;
    ifstream plik; //uchwyt do wczytania danych z pliku
    char sredniki;
    string temp_punkty;
    //sciezka="studenci.csv"; //nazwa pliku, plik ma sie znajdowac w katalogu projektu
    plik.open("studenci.csv"); //otwarcie pliku
    plik >> liczbaStudentow; //wczytanie z pliku pierwszej linijki - liczby studentow
    tab=new student[liczbaStudentow];
    for(int i = 0; i < 2; i++) //kazda dana oddzielona jest srednikiem, w pierwszej linijce jest tylko jedna liczba stad trzeba
        plik >> sredniki; //przeczytac puste sredniki

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik>>linia; //wczytanie calej linijki, w ktorej sa przechowywane informacje o studencie

        istringstream ss(linia);
        getline(ss, tab[i].imie, ';'); //miedzy srednikami znajduja sie kolejne dane, wyluskanie imienia
        getline(ss, tab[i].nazwisko, ';'); //wyluskanie nazwiska

        getline(ss, temp_punkty, ';'); //wyluskanie punktow
        tab[i].punkty = atoi(temp_punkty.c_str()); //punkty sa typu int, a zmienna temp_punkty jest typu String w zwiazku
    }                                              //z tym nalezy dokonac konwertacji zmiennej temp_punkty na typ int
    plik.close(); //po przeczytaniu wszystkich linijek, plik nalezy zamknac
}

void wyswietl1D(student* tab, int r)
{
    for(int i=0; i<r; i++)
    {

        cout<<"Imie: "<<tab[i].imie<<endl; //odwolanie sie do pola imie
        cout<<"Nazwisko: "<<tab[i].nazwisko<<endl;
        cout<<"Punkty: "<<tab[i].punkty<<endl;
    }
}

void quickSort(student* tab,int lewy , int prawy)
{
    int srodek, piwot, granica, i;
    string piwot2, piwot3;
    srodek = (lewy+prawy)/2;
    piwot = tab[srodek].punkty;
    piwot2 = tab[srodek].imie;
    piwot3 = tab[srodek].nazwisko;
    tab[srodek].punkty = tab[prawy].punkty;
    tab[srodek].imie = tab[prawy].imie;
    tab[srodek].nazwisko = tab[prawy].nazwisko;
    granica = lewy;
    i = lewy;
    while(i<prawy)
        {
                if(tab[i].punkty<piwot)
                {
                    swap(tab[granica].punkty, tab[i].punkty);
                    swap(tab[granica].imie, tab[i].imie);
                    swap(tab[granica].nazwisko, tab[i].nazwisko);
                    granica++;
                }
        i++;
        }
        tab[prawy].punkty = tab[granica].punkty;
        tab[granica].punkty = piwot;
        tab[prawy].imie = tab[granica].imie;
        tab[granica].imie = piwot2;
        tab[prawy].nazwisko = tab[granica].nazwisko;
        tab[granica].nazwisko = piwot3;

        if(lewy<granica-1)
        {
            quickSort(tab, lewy, granica-1);
        }
        if(granica+1<prawy)
        {
            quickSort(tab,granica+1,prawy);
        }
   }
void quickSort_Reverse(student* tab,int lewy , int prawy)
{
    int srodek, piwot, granica, i;
    srodek = (lewy+prawy)/2;
    piwot = tab[srodek].punkty;
    tab[srodek].punkty = tab[prawy].punkty;
    granica = lewy;
    i = lewy;
    while(i<prawy)
        {
                if(tab[i].punkty>piwot)
                {
                    swap(tab[granica].punkty, tab[i].punkty);
                    swap(tab[granica].imie, tab[i].imie);
                    swap(tab[granica].nazwisko, tab[i].nazwisko);
                    granica++;
                }
        i++;
        }
        tab[prawy].punkty = tab[granica].punkty;
        tab[granica].punkty = piwot;

        if(lewy<granica-1)
        {
            quickSort_Reverse(tab, lewy, granica-1);
        }
        if(granica+1<prawy)
        {
            quickSort_Reverse(tab,granica+1,prawy);
        }
   }

void sortowanieQuickSort()
{
    student* tab;
    int n;
    int wybor;
    wczytywanie(tab,n);
    cout << "\nJak posortowac dane? Rosnaco(1), malejaco(0):";
    cin >> wybor;
    if(wybor==1)
    {
        cout << "\nDane z pliku przed sortowaniem\n";
        wyswietl1D(tab, n);
        cout << "\nDane z pliku po sortowaniu\n";
        quickSort(tab, 0, n-1);
        wyswietl1D(tab, n);
        delete(tab);
    }
    else
    {
        cout << "\nDane z pliku przed sortowaniem\n";
        wyswietl1D(tab, n);
        cout << "\nDane z pliku po sortowaniu\n";
        quickSort_Reverse(tab, 0, n-1);
        wyswietl1D(tab, n);
        delete(tab);
    }

}
int main()
{
    srand(time(NULL));

    cout << "\nWybierz opcje \n1.Sortowanie Babelkowe\n2.Sortowanie przez wstawienie\n3.Szybkie sortowanie\n4.Wyjscie\nTwoj wybor:";
    int wybor;
    while(wybor!=4)
    {
        cin >> wybor;
        switch(wybor)
        {
            case 1:
                bubbleSort();
                break;
            case 2:
                insertSort();
                break;
            case 3:
                sortowanieQuickSort();
                break;
            case 4:
                break;
            default:
                cout << "Nie ma takiego wyboru";
                break;
        }
        cout << "\nWybierz opcje \n1.Sortowanie Babelkowe\n2.Sort\n3.sort\n4.Wyjscie\nTwoj wybor:";
    }
    return 0;
}
