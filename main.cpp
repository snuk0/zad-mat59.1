#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector <int> liczby;

void r(int x){
    liczby.clear();
    for (int i = 2; i * i <= x; i++){
        while (x % i == 0){
            liczby.push_back(i);
            x /= i;
        }
    }
    if (x != 0)
        liczby.push_back(x);
}

int p(){
    int ile = 0;
    for (int i = 0; i < liczby.size(); i++){
        if (i == 0 || liczby[i] != liczby[i - 1]){
            if (liczby[i] % 2 == 1)
                ile++;
        }
    }
    return ile;
}

int main(){
    ifstream f1("liczby.txt");
    if (f1.good()){
        int x, licznik = 0;
        while (f1 >> x){
            r(x);
            if (p() == 3)
                licznik++;
        }
        cout << "Zadanie 59.1: " << licznik;
    }

    return 0;
}
