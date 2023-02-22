// Scrivere un programma in c++ che rimane aperto finchè l'utente non digita EXIT. Il programma chiede all'utente una parola da cercare in un file. Restituiisce a schermo la strofa con i numeri di riga in cui appare la parola cercata, chiede la successiva parola a meno che non si inserisce EXIT

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string parola;
    while (true) {
        cout << "Inserisci una parola da cercare (o EXIT per uscire): " <<endl;
        getline(cin, parola);
        if (parola == "EXIT") {
            break;
        }
        ifstream file("../maggio.txt");
        if (!file) {
            cout << "Impossibile aprire il file!" << endl;
            return 1;
        }
        string riga;
        int numeroRiga = 1;
        bool trovata = false;
        while (getline(file, riga)) {
            if (riga.find(parola) != string::npos) {
                trovata = true;
                cout << "La parola '" << parola << "' è presente alla riga " << numeroRiga << ": " << riga << endl;
                int i = 1;
                while (getline(file, riga) && !riga.empty()) {
                    cout << numeroRiga + i<< ": " << riga << endl;
                    i++;
                }
                break;
            }
            numeroRiga++;
        }
        if (!trovata) {
            cout << "La parola '" << parola << "' non è stata trovata." << endl;
        }
    }
    return 0;
}

