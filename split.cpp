#include  <iostream>
#include <string>
using namespace std;

int main(){
    string line = "Ivanov Ivan Ivanovich";
    string name, surname, patronymic;
    int pos = 0;
    pos = line.find(" ");
    surname = line.substr(0, pos);
    line.erase(0, pos + 1); 
    pos = line.find(" ");
    name = line.substr(0, pos);
    line.erase(0, pos + 1);
    patronymic = line;
    cout << "Surname: " << surname << endl;
    cout << "Name: " << name << endl;
    cout << "Patronymic: " << patronymic << endl;
    return 0;
}
