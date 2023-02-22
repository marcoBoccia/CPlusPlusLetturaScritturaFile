// Scrivere un programma in c++ che rimane aperto finchè l'utente non digita EXIT. Il programma chiede all'utente una parola da cercare in un file. Restituiisce a schermo la strofa con i numeri di riga in cui appare la parola cercata, chiede la successiva parola a meno che non si inserisce EXIT

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string parola;
    while (true) {
        // Chiedo all'utente una parola da cercare
        cout << "Inserisci una parola da cercare (digita EXIT per uscire): "<<endl;
        cin >> parola;
        if (parola == "EXIT") {
            break; // Esco dal ciclo while se l'utente digita EXIT
        }
        // Apro il file da cercare
        ifstream file("../maggio.txt");
        if (!file.is_open()) {
            cout << "Impossibile aprire il file." << endl;
            continue; // Torna all'inizio del ciclo while
        }
        // Cerco la parola nel file e stampo le righe in cui appare
        string riga;
        int numeroRiga = 1;
        bool trovata = false;
        while (getline(file, riga)) {
            if (riga.find(parola) != string::npos) {
                cout << "Parola trovata alla riga " << numeroRiga << ": " << riga << endl;
                trovata = true;
                // Stampo le righe precedenti finché non si trova una riga vuota
                int righePrecedenti = numeroRiga - 1;
                while (righePrecedenti > 0) {
                    string rigaPrima;

                    for (int i = 1; i < righePrecedenti; i++) {
                        getline(file, rigaPrima);
                    }
                    getline(file, rigaPrima);
                    if (rigaPrima.empty()) {
                        break;
                    }
                    cout << "Riga " << righePrecedenti << ": " << rigaPrima << endl;
                    righePrecedenti--;
                }
                // Stampo le righe successive finché non si trova una riga vuota
                int righeSuccessive = numeroRiga + 1;
                while (getline(file, riga)) {
                    if (riga.empty()) {
                        break;
                    }
                    cout << "Riga " << righeSuccessive << ": " << riga << endl;
                    righeSuccessive++;
                }
            }
            numeroRiga++;
        }
        if (!trovata) {
            cout << "La parola non è stata trovata nel file." << endl;
        }
    }
    return 0;
}


