#include <iostream>
using namespace std;

class Human {
private:
    int* fullName;
    int length;

    void copyArray(int*& dest, const int* src, int len) {
        dest = new int[len];
        for (int i = 0; i < len; ++i) {
            dest[i] = src[i];
        }
    }

public:
    Human() : fullName(nullptr), length(0) {}

    Human(const int* name, int len) : length(len) {
        fullName = new int[length];
        for (int i = 0; i < length; ++i) {
            fullName[i] = name[i];
        }
    }

    Human(const Human& other) : length(other.length) {
        copyArray(fullName, other.fullName, other.length);
    }

    Human& operator=(const Human& other) {
        if (this == &other) return *this;
        delete[] fullName;
        length = other.length;
        copyArray(fullName, other.fullName, other.length);
        return *this;
    }

    ~Human() {
        delete[] fullName;
    }

    void print() const {
        cout << "Human: ";
        for (int i = 0; i < length; ++i) {
            cout << static_cast<char>(fullName[i]);
        }
        cout << endl;
    }
};

class Apartment {
private:
    Human* residents;
    int residentCount;

public:
    Apartment() : residents(nullptr), residentCount(0) {}

    Apartment(Human* people, int count) : residentCount(count) {
        residents = new Human[residentCount];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = people[i];
        }
    }

    Apartment(const Apartment& other) : residentCount(other.residentCount) {
        residents = new Human[residentCount];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = other.residents[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this == &other) return *this;
        delete[] residents;
        residentCount = other.residentCount;
        residents = new Human[residentCount];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = other.residents[i];
        }
        return *this;
    }

    ~Apartment() {
        delete[] residents;
    }

    void print() const {
        cout << "Apartment with " << residentCount << " residents:" << endl;
        for (int i = 0; i < residentCount; ++i) {
            residents[i].print();
        }
    }
};

class House {
private:
    Apartment* apartments;
    int apartmentCount;

public:
    House() : apartments(nullptr), apartmentCount(0) {}

    House(Apartment* apts, int count) : apartmentCount(count) {
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = apts[i];
        }
    }

    House(const House& other) : apartmentCount(other.apartmentCount) {
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this == &other) return *this;
        delete[] apartments;
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = other.apartments[i];
        }
        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void print() const {
        cout << "House with " << apartmentCount << " apartments:" << endl;
        for (int i = 0; i < apartmentCount; ++i) {
            cout << " Apartment " << i + 1 << ":" << endl;
            apartments[i].print();
        }
    }
};

int main() {
    int name1[] = { 'I', 'v', 'a', 'n', ' ', 'I', 'v', 'a', 'n', 'o', 'v' };
    int name2[] = { 'P', 'e', 't', 'r', 'o', ' ', 'P', 'e', 't', 'r', 'o', 'v' };
    int name3[] = { 'A', 'n', 'n', 'a', ' ', 'A', 'n', 'i', 's', 'i', 'm', 'o', 'v', 'a' };
    int name4[] = { 'O', 'k', 's', 'a', 'n', 'a', ' ', 'O', 'k', 's', 'a', 'n', 'i', 'n', 'a' };

    Human h1(name1, 11);
    Human h2(name2, 12);
    Human h3(name3, 14);
    Human h4(name4, 15);

    Human apt1Residents[] = { h1, h2 };
    Human apt2Residents[] = { h3, h4 };

    Apartment apt1(apt1Residents, 2);
    Apartment apt2(apt2Residents, 2);

    Apartment houseApartments[] = { apt1, apt2 };
    House house(houseApartments, 2);

    house.print();

    return 0;
}
