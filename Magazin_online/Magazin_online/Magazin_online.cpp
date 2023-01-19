// Magazin_online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;

class Admin
{
    friend class Electrocasnice;
    friend class IT;
private: char nume[20], email[20];
       long id,nr=0;
public: Admin();
      Admin(const char*,const char*, long, long);
      //~Admin();
      friend istream& operator>>(istream&, Admin&);
      //friend ostream& operator<<(ostream&, Admin&);
      void get_nr();
      void afis_nr();
};

void Admin::get_nr()
{
    nr++;
}

void Admin::afis_nr()
{
    cout << nr;
}

Admin::Admin()
{
    strcpy(nume, " ");
    strcpy(email, " ");
    id = 0;
    //nr_prod = 0;
}

Admin::Admin(const char *N,const char *EM, long ID, long NP)
{
    //nume = new char[strlen(N) + 1];
    strcpy(nume, N);
    //email = new char[strlen(EM) + 1];
    strcpy(email, EM);
    id = ID;
    //nr_prod = NP;
}
/*
Admin::~Admin()
{
    delete nume;
    delete email;
}*/

istream& operator>>(istream& in, Admin& a)
{
    cout << "Nume admin: ";
    in >> a.nume;
    cout << "Email: ";
    in >> a.email;
    cout << "Id: ";
    in >> a.id;
    //cout << "Nr produse in stoc: ";
    //in >> a.nr_prod;
    return in;
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
         double pret;
         //Admin nr;
public: Magazin_online(const char*, const char*, double);
      ~Magazin_online();
      void afisare();
};

Magazin_online::Magazin_online(const char* TM,const char* Prod, double Pret)
{
    tip_mag = new char[strlen(TM) + 1];
    strcpy(tip_mag, TM);
    produse = new char[strlen(Prod) + 1];
    strcpy(produse, Prod);
    pret = Pret;
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
}

class Electrocasnice:public Magazin_online
{
private: char *tip_prod,*firma,*culoare;
       double volum;
       Admin nr;
public:
    Electrocasnice(const char*, const char*, double, const char*, const char*, double, const char*);
      ~Electrocasnice();
      void afisare();
      void set_pret();
      inline void get_pret();
};

Electrocasnice::Electrocasnice(const char* TM, const char* Prod, double Pret, const char* TP, const char* F, double V, const char* CL) : Magazin_online(TM, Prod, Pret)
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

void Electrocasnice::set_pret()
{
    double p;
    cout << "\nIntroduceti noul pret: ";
    cin >> p;
    pret = p;
    nr.get_nr(); 
    nr.afis_nr();
}

inline void Electrocasnice::get_pret()
{
    cout << "\nNoul pret este: " << pret;
}

class IT:public Magazin_online
{
private: char* tip_prod, * firma, * culoare;
       Admin nr;
public: IT(const char*, const char*, double, const char*, const char*, const char*);
      ~IT();
      void afisare();
      void set_pret();
      inline void get_pret();
};

IT::IT(const char* TM, const char* Prod, double Pret, const char* TP, const char* F, const char* CL) :Magazin_online(TM, Prod, Pret)
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

void IT::set_pret()
{
    double p;
    cout << "\nIntroduceti noul pret: ";
    cin >> p;
    pret = p;
    nr.get_nr();
    nr.afis_nr();
}

inline void IT::get_pret()
{
    cout << "\nNoul pret este: " << pret;
}

class Fashion :public Magazin_online
{
private: char* tip_prod, * firma, * culoare;
       double marime;
public: Fashion(const char*, const char*, double, const char*, const char*, const char*, double);
      ~Fashion();
      friend void set_pret(Fashion&);
      inline void get_pret();
      friend ostream& operator<<(ostream&, Fashion&);
};

Fashion::Fashion(const char* TM, const char* Prod, double Pret, const char* TP, const char* F, const char* CL, double M) : Magazin_online(TM, Prod, Pret)
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

ostream& operator<<(ostream& out, Fashion& p)
{
    out << "Tip magazin: " << p.tip_mag;
    out<< "\nTip produse: " << p.produse;
    out << "\nPret: " << p.pret;
    out << "\nProdus: " << p.tip_prod;
    out << "\nFirma: " << p.firma;
    out << "\nCuloare: " << p.culoare;
    out << "\nMarime: " << p.marime;
    return out;
}

void set_pret(Fashion& x)
{
    double p;
    cout << "\nIntroduceti noul pret: ";
    cin >> p;
    x.pret = p;
}

inline void Fashion::get_pret()
{
    cout << "\nNoul pret este: " << pret;
}

class IngrijPers_Cosmetica :public Magazin_online
{
private: char* tip_prod, * firma, * culoare;
public: IngrijPers_Cosmetica(const char*, const char*, double, const char*, const char*, const char*);
      ~IngrijPers_Cosmetica();
      void afisare();
      friend void set_pret(IngrijPers_Cosmetica&);
      inline void get_pret();
};

IngrijPers_Cosmetica::IngrijPers_Cosmetica(const char* TM, const char* Prod, double Pret, const char* TP, const char* F, const char* CL) :Magazin_online(TM, Prod, Pret)
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

void set_pret(IngrijPers_Cosmetica& x)
{
    double p;
    cout << "\nIntroduceti noul pret: ";
    cin >> p;
    x.pret = p;
}

inline void IngrijPers_Cosmetica::get_pret()
{
    cout << "\nNoul pret este: " << pret;
}

class Bacanie :public Magazin_online
{
private: char* tip_prod, * firma;
       double greutate;
public: Bacanie(const char*, const char*, double, const char*, const char*, double);
      ~Bacanie();
      void afisare();
      friend void set_pret(Bacanie&);
      inline void get_pret();
};

Bacanie::Bacanie(const char* TM, const char* Prod, double Pret, const char* TP, const char* F, double G) :Magazin_online(TM, Prod, Pret)
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
    cout << "\nGreutate: " << greutate;
}

void set_pret(Bacanie& x)
{
    double p;
    cout << "\nIntroduceti noul pret: ";
    cin >> p;
    x.pret = p;
}

inline void Bacanie::get_pret()
{
    cout << "\nNoul pret este: " << pret;
}

int main()
{
    Admin a;
    cin >> a;
    Magazin* ptr;
    Electrocasnice ob1("Online", "Electrocasnice", 450.99, "Frigider", "Phillips", 300,"Gri" );
    IT ob2("Online", "IT", 2199.99, "Laptop", "ASUS", "Negru");
    Fashion ob3("Online", "Imbracaminte", 45.99, "Rochie", "H&M", "Negru", 36);
    ptr = &ob1;
    ptr->afisare();
    ob1.set_pret();
    ob1.get_pret();
    cout << endl;
    ptr = &ob2;
    ptr->afisare();
    ob2.set_pret();
    ob2.get_pret();
    cout << endl;
    cout << ob3;
    set_pret(ob3);
    ob3.get_pret();
    a.afis_nr();
}
