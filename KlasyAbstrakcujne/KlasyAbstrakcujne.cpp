#include <iostream>
using namespace std;
class Data {
private:
    int dzien;
    int miesiac;
    int rok;
public:
    Data(int dzien, int miesiac, int rok)
    : dzien(dzien), miesiac(miesiac), rok(rok) {}
    
    void Drukuj() const {
        cout << dzien << "." << miesiac << "." << rok;
    }
};
class Umowa {
private:
    string numer;
    Data dataWystawienia; 
    Data dataOd;
    Data dataDo;
protected:
    double wartosc;
public:
    Umowa(string numer,
          int dzienW, int miesiacW, int rokW,
          int dzienO, int miesiacO, int rokO,
          int dzienD, int miesiacD, int rokD,
          double wartosc)
    : numer(numer),
      dataWystawienia(dzienW, miesiacW, rokW),
      dataOd(dzienO, miesiacO, rokO),
      dataDo(dzienD, miesiacD, rokD),
      wartosc(wartosc) {}
    
    virtual double ObliczPodatek() const = 0;

    void DrukujUmowe() const {
        cout << endl << "===Umowa===";
        cout << endl << "Numer: " << numer;
        cout << endl << "Data wystawienia: ";
        dataWystawienia.Drukuj();
        cout << endl << "Data waznosci od: ";
        dataOd.Drukuj();
        cout << endl << "Data waznosci do: ";
        dataDo.Drukuj();
        cout << endl << "Wartosc: " << wartosc;
        cout << endl << "Podatek: " << ObliczPodatek();
    }
};
class UmowaZlecenie : public Umowa {
public:
    UmowaZlecenie(string numer,
                  int dzienW, int miesiacW, int rokW,
                  int dzienO, int miesiacO, int rokO,
                  int dzienD, int miesiacD, int rokD,
                  double wartosc)
    : Umowa(numer, dzienW, miesiacW, rokW, dzienO, miesiacO, rokO, dzienD, miesiacD, rokD, wartosc) {}

    double ObliczPodatek() const override {
        return wartosc * 20 / 100;  // Calculate 20% tax
    }
};
class UmowaAutorska : public Umowa {
public:
    UmowaAutorska(string numer,
                  int dzienW, int miesiacW, int rokW,
                  int dzienO, int miesiacO, int rokO,
                  int dzienD, int miesiacD, int rokD,
                  double wartosc)
    : Umowa(numer, dzienW, miesiacW, rokW, dzienO, miesiacO, rokO, dzienD, miesiacD, rokD, wartosc) {}

    double ObliczPodatek() const override {
        return (wartosc / 2) * 20 / 100;  // Calculate tax on half the contract value
    }
};
int main() {
    cout << "Przyklad klasy abstrakcyjnej";

    UmowaZlecenie uz("Umowa zlecenie 2", 2, 2, 2002, 2, 2, 2002, 2, 2, 2022, 2000);
    uz.DrukujUmowe();

    UmowaAutorska ua("Umowa autorska 3", 3, 3, 2003, 3, 3, 2003, 3, 3, 2023, 3000);
    ua.DrukujUmowe();

    return 0;
}
