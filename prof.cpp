#include <cstdlib>
//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
//#include <conio.h>

using namespace std;
char nomeFileSalvataggio[200], nomeFileLettura[200];
char buffer[2000];
bool inUso=false;
ifstream fleggi;
ofstream fscrivi;
extern string oldFile="";

// N.B. Assegno il comando "extern" alla funzione se voglio che sia visibile anche ai programmi esterni

//restituisce il puntatore ad un vettore di caratteri
//in cui sono copiati i caratteri della stringa c++ s
extern char *allocaStringa(string s)
{
  char *stringa = (char *) malloc(s.length() * sizeof(char) + 1);
  return strcpy(stringa, s.c_str());
}

/*extern void attendi(string messaggio)
{
  cout << messaggio << endl;
  cout << "Premi un tasto per continuare ..." << endl;
  //while (!kbhit());
  //getch();
  getchar();
}*/

extern void attendi(string messaggio)
{
    //bisogna pulire lo stream
    cout << messaggio << endl;
    cout << "Press [Enter] to continue..."<< endl;
    cin.ignore();
    cin.get();
}

extern bool cercaStringa(string cercata, string cercaQui)
{
//   cout << "Cerco " << cercata << endl;
//   cout <<"Nella stringa: " << endl;
//   cout <<cercaQui<<endl;
//   cout <<"-------------------------------------------------------------------------------"<<endl;
//   string s; cin>>s;

       return cercaQui.find(cercata) != string::npos; }

extern string intToString(int n)
{
  string s = "";
  while (n>0)
  {
     s =  (char) (48 + n%10) + s;
     n /=10;
   }
  return  s=="" ? "0" : s;
}

extern void creaFile(string path)
{
  ofstream scrivi(path.c_str());
  scrivi.close();
  strcpy(nomeFileSalvataggio, path.c_str());
  inUso=true;
}

extern void apriFile(const char * path)
{
  strcpy(nomeFileLettura, path);
}

extern char * leggiString(const char * descrizioneValore)
{
  ifstream leggi(nomeFileLettura);
  char descrizioneLetta[100];

    //pulisco buffer
   for(int i=0; i<2000; i++)
     buffer[i]='\0';

  while ( !leggi.eof() )
  {
     leggi.getline(descrizioneLetta, 99);
     if (!strcmp(descrizioneLetta, descrizioneValore) )
     {
        leggi.getline(buffer, 199);
        return buffer;
     }
  }

  leggi.close();

}


extern double leggiDouble(const char * descrizioneValore)
{
  ifstream leggi(nomeFileLettura);
  char descrizioneLetta[100], valore[200];

  while ( !leggi.eof() )
  {
     leggi.getline(descrizioneLetta, 99);
     if (!strcmp(descrizioneLetta, descrizioneValore) )
     {
        leggi.getline(valore, 199);
        return strtod(valore, NULL);
     }
  }

  leggi.close();

}


extern int leggiInt(const char * descrizioneValore)
{
  ifstream leggi(nomeFileLettura);
  char descrizioneLetta[100], valore[200];

  while ( !leggi.eof() )
  {
     leggi.getline(descrizioneLetta, 99);
     if (!strcmp(descrizioneLetta, descrizioneValore) )
     {
        leggi.getline(valore, 199);
        return strtol(valore, NULL, 0);
     }
  }

  leggi.close();

}


static void registra(char * descrizioneValore, string valoreAssociato)
{
    ofstream scrivi(nomeFileSalvataggio, ios::app);
    scrivi << descrizioneValore << endl << valoreAssociato << endl;
    scrivi.close();
}

extern void registraInt(char *  descrizioneValore, int valoreAssociato)
{
    char buffer[50];
    sprintf(buffer, "%d", valoreAssociato);
    registra(descrizioneValore, buffer);
}

extern void registraDouble(char *   descrizioneValore, double valoreAssociato)
{
    char buffer[50];
    sprintf(buffer, "%f", valoreAssociato);
    registra(descrizioneValore, buffer);
}

extern void registraString(char *  descrizioneValore, char *  valoreAssociato)
{
    registra(descrizioneValore, valoreAssociato);
}
           //
//trim a destra
//elimina anche caratteri strani dovuti a codifica unicode
extern string rtrim(string s, bool lasciaSpazi=false)
{
    while (true && s.length()>0)
      if ( (!isalnum(s[s.length()-1]) && !isalnum(s[s.length()-1]) && !ispunct(s[s.length()-1]))
           || ( isspace(s[s.length()-1]) && !lasciaSpazi)  )
        s.erase(s.length()-1,1);
      else
        break;

  return s;
}

//trim a sinistra
//elimina anche caratteri strani dovuti a codifica unicode
extern string ltrim(string s, bool lasciaSpazi=false)
{

    while (true && s.length()>0)
      if (  (!isspace(s[0]) && !isalnum(s[0])  && !ispunct(s[0])) || ( isspace(s[0])  && !lasciaSpazi)  )
        s.erase(0,1);
      else
        break;

  return s;
}

extern string leggiRiga(string pathFile)
{
   //meglio locale per 'pulizia' buffer automatica!
   //cout << "inizio leggi riga" << endl;

   //pulisco buffer
   for(int i=0; i<2000; i++)
     buffer[i]='\0';

   if (oldFile != pathFile && inUso) //chiesto un altro file
   {
       fleggi.close();
       inUso = false;
   }

   if (!inUso)
   {
     fleggi.clear();

     fleggi.open(pathFile.c_str());

     if (fleggi.fail())
     {
        cout << "ERRORE APERTURA FILE" << endl;
        return "";
     }

     inUso=true;
     oldFile = pathFile;
   }

   string riga="";

   if (!fleggi.eof() )
   {
     fleggi.getline(buffer, 1999);
     riga = string(buffer, 1999);
     riga = ltrim(rtrim(riga, true), true);

     if (riga!="" || !fleggi.eof())
        return riga;
     else
     {
       fleggi.close();
       inUso=false;
       return "#FINITO#"; //problema endline finale
     }
   }
   else
   {
     fleggi.close();
     inUso=false;
     return("#FINITO#");
   }
}

extern void registraRiga(string pathFile, string riga)
{
  ifstream fleggi;
  fleggi.open(pathFile.c_str());

  if (fleggi.fail() || fleggi.peek() == EOF )
  {

    fleggi.close();
    fscrivi.open(pathFile.c_str(), ios::out);
    fscrivi << riga;
  }
  else
  {
    fleggi.close();
    fscrivi.open(pathFile.c_str(), ios::app);
    fscrivi << endl << riga;

  }

  fscrivi.close();
}

extern void elimina(string pathFile)
{
  ifstream fleggi;
  fleggi.open(pathFile.c_str());

  if (!fleggi.fail())
  {
    fleggi.close();
    fscrivi.open(pathFile.c_str(), ios::trunc);
    fscrivi.close();
  }
  else
   fleggi.close();
}

extern string maiuscolo(string s)
{
  string result="";
  for (int i=0; i<s.length(); i++)
    result += toupper(s[i]);

  return result;
}

extern string minuscolo(string s)
{
  string result="";
  for (int i=0; i<s.length(); i++)
    result += tolower(s[i]);

  return result;
}

extern int esaToInt(string esa)
{
  int result=0; int cifra=0;

  for(int i=0; i<esa.length(); i++)
  {
     //funziona sia con cifra esadecimale in minuscolo che maiuscolo
     cifra = isdigit(esa[i]) ? esa[i] - '0' : 10 + esa[i] - (islower(esa[i]) ? 'a' : 'A');
     result += (int) pow(16.0, (int) (esa.length() - i - 1) ) * cifra;
  }
  return result;
}

extern string intToEsa(int dec)
{
   string result=""; int quoziente=0;
   int resto=0; string restoString="";

   //cout << "fx(" << dec <<")" <<endl;

   if (dec<16)
     if (dec<10)
       return intToString(dec);
     else
     {
       result += (char) ('A' + dec - 10);
       return result;
     }
   else //dec>=16
   {
      resto = dec % 16;
 //     cout << "resto: " << resto <<endl;

      if (resto<10)
        restoString = intToString(resto);
      else
        restoString +=  (char) ('A' + resto - 10);

     //cout << restoString << endl;

     //quoziente = dec / 16;
//     cout << "quoziente: " << quoziente << endl;

     return intToEsa(dec / 16) + restoString;
    }
}

