#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;
bool inUso = false;
extern string oldFile = "";
// N.B. Assegno il comando "extern" alla funzione se voglio che sia visibile anche ai programmi esterni

extern void attendi()
{
    cout << "Premi [Invio] per continuare..."<< endl;
    cin.ignore();
    cin.get();
}

// Restituisce il puntatore ad un vettore di caratteri in cui sono copiati i caratteri della stringa c++ s
extern char *allocaStringa(string s)
{
    char *stringa = (char *) malloc(s.length() * sizeof(char) + 1);   // alloca uno spazio grande quanto un char * lunghezza dell'array s + 1 (per \0)

    return strcpy(stringa, s.c_str());
}

extern int contaRighe(string nomeFile)
{
    string s = "";
    ifstream leggi;
    string path = "Documents/Lavoro/Repository/testingCpp/";
    int conta = 0;

    //nome del file da aprire, si può mettere anche il percorso (es C:\\file.txt)
    leggi.open(path + nomeFile, ios::in);

    if(!leggi)
        cout << "ERRORE: impossibile aprire il file" << endl;

    while(leggi)    //fino a quando c'è qualcosa da leggere ..
    {
        getline(leggi, s);  //legge tutta la riga dal file e la mette nella variabile s
        conta++;
    }

    leggi.close();  //chiude il file

    return conta-1;
}

extern string leggiRiga(string nomeFile)
{
    ifstream leggi;
    string path = "Documents/Lavoro/Repository/testingCpp/";
    string s = "";

    if(oldFile != nomeFile && inUso) //chiesto un altro file
    {
        leggi.close();
        inUso = false;
    }

    if(!inUso)
    {
        leggi.clear();

        leggi.open(path + nomeFile, ios::in);

        if(!leggi)
        {
            cout << "ERRORE: impossibile aprire il file" << endl;
            return "";
        }

        cout << "Sto inserendo inUso = true: " << inUso << endl;
        inUso = true;
        cout << "Ho inserito inUso: " << inUso << endl;
        cout << "Sto inserendo oldFile = nomeFile: " << oldFile << endl;
        oldFile = nomeFile;
        cout << "Ho inserito oldFile: " << oldFile << endl;
    }

    if(leggi.good())
    {
        getline(leggi, s, '\n');
        cout << "inUso: "<< inUso << endl;
        cout << "La riga letta è: " << s << endl;

        if(s != "" || leggi.good())
            return s;
        else
        {
            leggi.close();
            inUso = false;
            return "#PIRLA#"; //problema endline finale
        }
    }
    else
    {
        leggi.close();
        inUso = false;
        return("#FINITO#");
    }
}
/*
extern string leggiRiga(string nomeFile)
{
    string s = "";
    ifstream leggi;
    string path = "Documents/Lavoro/Repository/testingCpp/";

    if(!inUso)
    {
        //nome del file da aprire, si può mettere anche il percorso (es C:\\file.txt)
        leggi.open(path + nomeFile, ios::in);

        if(!leggi)
            cout << "ERRORE: impossibile aprire il file" << endl;

        inUso = true;
    }

    if(!leggi.eof() && inUso)
    {
        getline(leggi, s);
        cout << "Stringa letta: " << s << endl;

        if(s != "" || !leggi.eof())
            return s;
        else
        {
            leggi.close();
            inUso = false;
            return "#FINITO#"; //problema endline finale
        }
    }
    else
    {
        leggi.close();
        inUso = false;
        return("#FINITO#");
    }
}
*/
