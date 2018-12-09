#pragma once
#include <iostream>
#include <string>
using namespace std;

class Musician {
private:
    string fName;
    string lName;
    string role;

public:
    Musician();
    Musician(string, string, string);
    Musician(const Musician & muToCopy);
    ~Musician();
    void operator=(const Musician & muToCopy);
    void setFirstName(string);
    void setLastName(string);
    void setRole(string);
    string getFirstName() const;
    string getLastName()const;
    string getRole() const;
    friend ostream & operator << (ostream &out, const Musician &c);
};

inline ostream & operator<<(ostream & out, const Musician & m)
{
    out << m.getFirstName() << " " << m.getLastName() << ": " << m.getRole();
    return out;
}