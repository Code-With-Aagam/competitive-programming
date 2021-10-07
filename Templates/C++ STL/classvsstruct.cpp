#include <bits/stdc++.h>
using namespace std;

struct PersonStruct {
    string name;    // public
};

class PersonClass {
    string name;    // private
};

int main() {
    // compiles
    PersonStruct personStruct;
    personStruct.name = "John";
    cout << personStruct.name << "\n";

    // does not compile
    PersonClass personClass;
    personClass.name = "John";
    cout << personClass.name << "\n";

    // another way to init a struct
    PersonStruct* person = new PersonStruct();
    person->name = "John Doe";
    cout << person->name << "\n";
    return 0;
}