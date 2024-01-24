#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct person
{
    string imie, nazwisko, data_ur, miejsce_ur;
    vector<person*> synowie;
};

    void show_next (person* current)
    {
        for(int i = 1; i <= current -> synowie.size(); ++i)
        {

            cout<<i<<": "<<current -> synowie[i-1] -> imie<<endl;
        }

    }

    void print_inf (person* current)
    {
        cout<<endl<<"imie: "<<current -> imie<<endl<<"nazwisko: "<<current -> nazwisko<<endl<<"data urodzenia: "<<current -> data_ur<<"miejsce urodzenia: "<<endl<<current -> miejsce_ur<<endl;
    }


    person* przejscie (person* current)
    {

        cout<<"czy chcesz wyswietlic informacje o tym czlonku rodziny (wpisz tak lub nie)"<<endl;
        string b;
        cin>>b;

        if(b == "tak")
        {
            print_inf(current);
        }

        cout<<endl<<"Potomkowie: "<<endl;
        show_next(current);

        int a;



        if(current -> synowie.size() == 0)
        {
           cout<<"koniec";
           return 0;
        }

        cin>>a;

        if(current -> synowie.size() >= a)
        {

            przejscie (current -> synowie[a-1]);
            a = 0;
        }
        else
        {
            cout<<"podano niewlasciwa liczbe"<<endl;
            a = 0;
            przejscie(current);
        }

    }

int main()
{

    vector<person*> GGF = {new person, new person};
    vector<person*> GF1 = {new person, new person, new person};
    vector<person*> GF2 = {new person};
    vector<person*> F1 = {new person, new person};
    vector<person*> F3 = {new person};
    vector<person*> F4 = {new person, new person};
    vector<person*> S2 = {new person};
    vector<person*> S5 = {new person, new person};


    person* ggfather = new person;
    ggfather -> imie = "Mieczyslaw";
    ggfather -> nazwisko = "Sobczak";
    ggfather -> data_ur = "1.01.1900";
    ggfather -> miejsce_ur = "Warszawa";
    ggfather -> synowie = GGF;

    person* gfather1 = ggfather -> synowie[0];
    gfather1 -> imie = "Kazimierz";
    gfather1 -> nazwisko = "Sobczak";
    gfather1 -> data_ur = "1.01.1925";
    gfather1 -> miejsce_ur = "Warszawa";
    gfather1 -> synowie = GF1;

    person* gfather2 = ggfather -> synowie[1];
    gfather2 -> imie = "Boleslaw";
    gfather2 -> nazwisko = "Sobczak";
    gfather2 -> data_ur = "1.01.1926";
    gfather2 -> miejsce_ur = "Warszawa";
    gfather2 -> synowie = GF2;

    person* father1 = gfather1 -> synowie[0];
    father1 -> imie = "Anrzej";
    father1 -> nazwisko = "Sobczak";
    father1 -> data_ur = "1.01.1951";
    father1 -> miejsce_ur = "Warszawa";
    father1 -> synowie = F1;

    person* father2 = gfather1 -> synowie[1];
    father2 -> imie = "Mariusz";
    father2 -> nazwisko = "Sobczak";
    father2 -> data_ur = "1.01.1953";
    father2 -> miejsce_ur = "Warszawa";


    person* father3 = gfather1 -> synowie[2];
    father3 -> imie = "Marcin";
    father3 -> nazwisko = "Sobczak";
    father3 -> data_ur = "1.01.1949";
    father3 -> miejsce_ur = "Warszawa";
    father3 -> synowie = F3;


    person* father4  = gfather2 -> synowie[0];
    father4 -> imie = "Artur";
    father4 -> nazwisko = "Sobczak";
    father4 -> data_ur = "1.01.1952";
    father4 -> miejsce_ur = "Warszawa";
    father4 -> synowie = F4;


    person* son1 = father1 -> synowie[0];
    son1 -> imie = "Wojciech";
    son1 -> nazwisko = "Sobczak";
    son1 -> data_ur = "1.01.1975";
    son1 -> miejsce_ur = "Warszawa";

    person* son2 = father1 -> synowie[1];
    son2 -> imie = "Antoni";
    son2 -> nazwisko = "Sobczak";
    son2 -> data_ur = "1.01.1973";
    son2 -> miejsce_ur = "Warszawa";
    son2 -> synowie = S2;


    person* son3 = father3 -> synowie[0];
    son3 -> imie = "Grzegorz";
    son3 -> nazwisko = "Sobczak";
    son3 -> data_ur = "1.01.1977";
    son3 -> miejsce_ur = "Warszawa";

    person* son4 = father4 -> synowie[0];
    son4 -> imie = "Karol";
    son4 -> nazwisko = "Sobczak";
    son4 -> data_ur = "1.01.1975";
    son4 -> miejsce_ur = "Warszawa";


    person* son5 = father4 -> synowie[1];
    son5 -> imie = "Tomasz";
    son5 -> nazwisko = "Sobczak";
    son5 -> data_ur = "1.01.1974";
    son5 -> miejsce_ur = "Warszawa";
    son5 -> synowie = S5;

    person* gson1 = son2 -> synowie[0];
    gson1 -> imie = "Stanislaw";
    gson1 -> nazwisko = "Sobczak";
    gson1 -> data_ur = "1.01.2000";
    gson1 -> miejsce_ur = "Warszawa";


    person* gson2 = son5 -> synowie[0];
    gson2 -> imie = "Dariusz";
    gson2 -> nazwisko = "Sobczak";
    gson2 -> data_ur = "1.01.2001";
    gson2 -> miejsce_ur = "Warszawa";


    person* gson3 = son5 -> synowie[1];
    gson3 -> imie = "Szymon";
    gson3 -> nazwisko = "Sobczak";
    gson3 -> data_ur = "1.01.1999";
    gson3 -> miejsce_ur = "Warszawa";

    przejscie(ggfather);



}
