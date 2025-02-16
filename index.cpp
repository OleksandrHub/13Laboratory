#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct University {
    string name;
    string address;
    string category;
};

int main() {
    int n = 0;
    string line;
    const int maxUniversities = 100;
    University universities[maxUniversities];

    fstream file("input.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    while (getline(file, line) && n < maxUniversities) {
        size_t pos = 0;

        pos = line.find(';');
        universities[n].name = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(';');
        universities[n].address = line.substr(0, pos);
        line.erase(0, pos + 1);
        universities[n].category = line;

        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (universities[j].category > universities[j + 1].category) {
                swap(universities[j], universities[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(i==0 or universities[i].category!=universities[i-1].category){
            cout << universities[i].category << endl;
        }
        cout  << "-" << universities[i].address << endl;
    }

    file.close();
    return 0;
}
