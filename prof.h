#include <string>
using namespace std;

//FILES di testo con record descrizione/valore
extern void creaFile(string pathFile);
extern void registraInt(char * descrizioneValore, int valoreAssociato);
extern void registraDouble(char * descrizioneValore, double valoreAssociato);
extern void registraString(char * descrizioneValore, string valoreAssociato);
extern void apriFile(const char *pathFile );
extern int leggiInt(const char *descrizioneValore );
extern double leggiDouble(const char *descrizioneValore );
extern char * leggiString(const char * descrizioneValore);

//FILES di testo a righe
extern string leggiRiga(string pathFile);
extern void registraRiga(string pathFile, string riga);
extern void elimina(string pathFile);

//CONVERSIONE
extern string intToString(int daConvertire);
extern string maiuscolo(string s);
extern string minuscolo(string s);
extern int esaToInt(string esa);
extern string intToEsa(int dec);

//STRINGHE
extern bool cercaStringa(string cercata, string cercaQui);
extern string rtrim(string s, bool lasciaSpazi=false);
extern string ltrim(string s, bool lasciaSpazi=false);
extern char *allocaStringa(string s);

//VARI
extern void attendi(string messaggio);

