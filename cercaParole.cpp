// Scrivere un programma in c++ che rimane aperto finchè l'utente non digita EXIT. Il programma chiede all'utente una parola da cercare in un file. Restituiisce a schermo la strofa con i numeri di riga in cui appare la parola cercata, chiede la successiva parola a meno che non si inserisce EXIT

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string parola;
    while (true)
    {
        cout << "Inserisci una parola da cercare (o EXIT per uscire): "<< endl;
        cin >> parola;
        if (parola == "EXIT"){
            break;
        }
        ifstream file("../maggio.txt");
        string riga;
        int numeroRiga = 1;
    }
    
}
