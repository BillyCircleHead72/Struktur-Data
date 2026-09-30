#include <iostream>
#include <string>

using namespace std;


int main() {
    string nama, nim, kehadiran;
    int i;
    string arrNama[40], arrNIM[40];
    string arrHadir[40];

    for (i = 0; i < 40; i++) {
        cin >> arrNama[i];
        cin >> arrNIM[i];
        cin >> arrHadir[i];
    }
    for (i = 0; i < 40; i++) {
        cout << arrNama[i] << endl;
        cout << arrNIM[i] << endl;
        cout << arrHadir[i] << endl;
    }
}