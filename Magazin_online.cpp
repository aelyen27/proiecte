// Magazin_online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;

class Admin
{
    friend class Magazin_online;
private: char nume[100], email[100], ok[100];
       long id;
public: Admin();
      Admin(const char*,const char*, long, const char*);
      friend istream& operator>>(istream&, Admin&);
      friend ostream& operator<<(ostream&, Admin&);
};

Admin::Admin()
{
    strcpy(nume, "");
    strcpy(email, "");
    strcpy(ok, "");
    id = 0;
}

Admin::Admin(const char* N, const char* EM, long ID, const char* OK)
{
    strcpy(nume, N);
    strcpy(email, EM);
    id = ID;
    strcpy(ok, OK);
}

istream& operator>>(istream& in, Admin& a)
{
    cout << "Nume admin: ";
    in >> a.nume;
    cout << "Email: ";
    in >> a.email;
    cout << "Id: ";
    in >> a.id;
    return in;
}

ostream& operator<<(ostream& out, Admin& a)
{
    out << "\nAdministrator curent:" << "\tNume: " << a.nume << "\tEmail: " << a.email << "\tId: " << a.id<<"\tStatus admin: activ";
    return out;
}

class Magazin
{
public: virtual void afisare();
};

void Magazin::afisare()
{
    cout << "\nTip magazin: ";
}

class Magazin_online:public Magazin
{
protected: char* tip_mag, *produse;
         double pret, stoc;
         Admin stat;
public: 
    Magazin_online(const char*, const char*, double, double);
      ~Magazin_online();
      void afisare();
      void set_pret();
      inline void get_pret();
      void verif_stoc();
};

void Magazin_online::verif_stoc()
{
    if (stoc > 0)
        cout << "\nStoc suficient";
    else
    {
        cout << "\nStoc insuficient";
        int s;
        cout << "\nIntrod noul nr de prod in stoc: ";
        cin >> s;
    }
}

Magazin_online::Magazin_online(const char* TM,const char* Prod, double Pret, double Stoc)
{
    tip_mag = new char[strlen(TM) + 1];
    strcpy(tip_mag, TM);
    produse = new char[strlen(Prod) + 1];
    strcpy(produse, Prod);
    pret = Pret;
    stoc = Stoc;
}

Magazin_online::~Magazin_online()
{
    delete tip_mag;
    delete produse;
}

void Magazin_online::afisare()
{
    Magazin::afisare();
    cout << tip_mag;
    cout << "\nTip produse: " << produse;
    cout << "\nPret: " << pret;
    cout << "\nNr prod in stoc: " << stoc;
}


void Magazin_online::set_pret()
{
    double p;
    cout << "\nIntroduceti noul pret: ";
    cin >> p;
    if (p == pret)
    {
        strcpy(stat.ok, "pretul nu s-a schimbat");
        cout << "Admin status: " << stat.ok;
    }
    else
    {
        strcpy(stat.ok, "pretul s-a schimbat");
        cout << "Admin status: " << stat.ok;
        pret = p;
    }
}

inline void Magazin_online::get_pret()
{
    cout << "\nPretul este: " << pret;
}
/*
void Magazin_online::operator-(Magazin_online& x)
{
    double m;
    m = p - x.pret;
    //return m;
}*/

class Electrocasnice:public Magazin_online
{
private: char *tip_prod,*firma,*culoare;
       double volum;
public:
    Electrocasnice(const char*, const char*, double, double, const char*, const char*, double, const char*);
      ~Electrocasnice();
      void afisare();
};

Electrocasnice::Electrocasnice(const char* TM, const char* Prod, double Pret, double Stoc, const char* TP, const char* F, double V, const char* CL) : Magazin_online(TM, Prod, Pret, Stoc)
{
    tip_prod = new char[strlen(TP) + 1];
    strcpy(tip_prod, TP);
    firma = new char[strlen(F) + 1];
    strcpy(firma, F);
    culoare = new char[strlen(CL) + 1];
    strcpy(culoare, CL);
    volum = V;
}

Electrocasnice::~Electrocasnice()
{
    delete tip_prod;
    delete firma;
    delete culoare;
}

void Electrocasnice::afisare()
{
    Magazin_online::afisare();
    cout << "\nProdus: " << tip_prod;
    cout << "\nFirma: " << firma;
    cout << "\nVolum: " << volum<<" kg";
    cout << "\nCuloare: " << culoare;
}

class IT:public Magazin_online
{
private: char* tip_prod, * firma, * culoare;
public: 
    IT(const char*, const char*, double, double, const char*, const char*, const char*);
    ~IT();
    void afisare();
    int operator-(IT&);
};

IT::IT(const char* TM, const char* Prod, double Pret, double Stoc, const char* TP, const char* F, const char* CL) :Magazin_online(TM, Prod, Pret, Stoc)
{
    tip_prod = new char[strlen(TP) + 1];
    strcpy(tip_prod, TP);
    firma = new char[strlen(F) + 1];
    strcpy(firma, F);
    culoare = new char[strlen(CL) + 1];
    strcpy(culoare, CL);
}

IT::~IT()
{
    delete tip_prod;
    delete firma;
    delete culoare;
}

void IT::afisare()
{
    Magazin_online::afisare();
    cout << "\nProdus: " << tip_prod;
    cout << "\nFirma: " << firma;
    cout << "\nCuloare: " << culoare;
}

int IT::operator-(IT& x)
{
    int d;
    d = this->pret - x.pret;
    return d;
}

class Fashion :public Magazin_online
{
private: char* tip_prod, * firma, * culoare;
       double marime;
public: Fashion(const char*, const char*, double, double, const char*, const char*, const char*, double);
      ~Fashion();
      void afisare();
};

Fashion::Fashion(const char* TM, const char* Prod, double Pret, double Stoc, const char* TP, const char* F, const char* CL, double M) : Magazin_online(TM, Prod, Pret, Stoc)
{
    tip_prod = new char[strlen(TP) + 1];
    strcpy(tip_prod, TP);
    firma = new char[strlen(F) + 1];
    strcpy(firma, F);
    culoare = new char[strlen(CL) + 1];
    strcpy(culoare, CL);
    marime = M;
}

Fashion::~Fashion()
{
    delete tip_prod;
    delete firma;
    delete culoare;
}

void Fashion::afisare()
{
    Magazin_online::afisare();
    cout << "\nProdus: " << tip_prod;
    cout << "\nFirma: " << firma;
    cout << "\nCuloare: " << culoare;
    cout << "\nMarime: " << marime;
}

class IngrijPers_Cosmetica :public Magazin_online
{
private: char* tip_prod, * firma, * culoare;
public: IngrijPers_Cosmetica(const char*, const char*, double, double, const char*, const char*, const char*);
      ~IngrijPers_Cosmetica();
      void afisare();
};

IngrijPers_Cosmetica::IngrijPers_Cosmetica(const char* TM, const char* Prod, double Pret, double Stoc, const char* TP, const char* F, const char* CL) :Magazin_online(TM, Prod, Pret, Stoc)
{
    tip_prod = new char[strlen(TP) + 1];
    strcpy(tip_prod, TP);
    firma = new char[strlen(F) + 1];
    strcpy(firma, F);
    culoare = new char[strlen(CL) + 1];
    strcpy(culoare, CL);
}

IngrijPers_Cosmetica::~IngrijPers_Cosmetica()
{
    delete tip_prod;
    delete firma;
    delete culoare;
}

void IngrijPers_Cosmetica::afisare()
{ 
    Magazin_online::afisare();
    cout << "\nProdus: " << tip_prod;
    cout << "\nFirma: " << firma;
    cout << "\nCuloare: " << culoare;
}

class Bacanie :public Magazin_online
{
private: char* tip_prod, * firma;
       double greutate;
public: Bacanie(const char*, const char*, double, double, const char*, const char*, double);
      ~Bacanie();
      void afisare();
};

Bacanie::Bacanie(const char* TM, const char* Prod, double Pret, double Stoc, const char* TP, const char* F, double G) :Magazin_online(TM, Prod, Pret, Stoc)
{
    tip_prod = new char[strlen(TP) + 1];
    strcpy(tip_prod, TP);
    firma = new char[strlen(F) + 1];
    strcpy(firma, F);
    greutate = G;
}

Bacanie::~Bacanie()
{
    delete tip_prod;
    delete firma;
}

void Bacanie::afisare()
{
    Magazin_online::afisare();
    cout << "\nProdus: " << tip_prod;
    cout << "\nFirma: " << firma;
    cout << "\nGreutate: " << greutate<<" kg";
}

int main()
{
    double dif;
    Admin a;
    cin >> a;
    cout << a;
    cout << endl;
    Magazin* ptr;
    Electrocasnice ob1("Online", "Electrocasnice", 450.99, 0, "Frigider", "Phillips", 300,"Gri" );
    IT ob2_1("Online", "IT", 2199.99, 2, "Laptop", "ASUS", "Negru");
    IT ob2_2("Online", "IT", 2000.99, 6, "Laptop", "ASUS", "Negru");
    Fashion ob3("Online", "Imbracaminte", 45.99, 5, "Rochie", "H&M", "Negru", 36);
    IngrijPers_Cosmetica ob4("Online", "Cosmetica", 34.99, 20, "Ruj", "Nyx", "Roz");
    Bacanie ob5("Online", "Bacanie", 12.99, 50, "Faina de grau", "Baneasa", 1);
    
    
    ptr = &ob1;
    ptr->afisare();
    ob1.verif_stoc();
    ob1.set_pret();
    ob1.get_pret();
    cout << endl;
    ptr = &ob2_1;
    ptr->afisare();
    //ob2_1.set_pret();
    //ob2_1.get_pret();
    cout << endl;
    ptr = &ob2_2;
    ptr->afisare();
    //ob2_2.set_pret();
    //ob2_2.get_pret();
    dif = (float)(ob2_1 - ob2_2);
    cout << "\nDiferenta de pret dintre cele 2 prod este: " << dif;
    cout << endl;
    ptr = &ob3;
    ptr->afisare();
    ob3.set_pret();
    ob3.get_pret();
    cout << endl;
    ptr = &ob4;
    ptr->afisare();
    ob4.set_pret();
    ob4.get_pret();
    cout << endl;
    ptr = &ob5;
    ptr->afisare();
    ob5.set_pret();
    ob5.get_pret();
}
