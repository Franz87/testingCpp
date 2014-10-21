/* Esempi di Programmazione in C++

  Autore: Franz
  Creato il: 05/09/2014
  Versione 1.1
  Cronologia modifiche:
    - gg/mm/aa Release 1.1
      Elenco modifiche:
        * eliminati bug ...
        * ottimizzato ...
        * aggiunto supporto ...
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// dichiarazioni dei prototipi di funzione
void menu();
void separaNumeri();
void pariDispari();
void minMax();
void plotMatrix();
void mediaVoti();
void breakContinue();
void convBinDec();
void calcPagaOra();
void gameCrap();
unsigned long fattoriale(unsigned long n);
long fibonacci(long n);
void pasValRef();
void esAutosilo();
void minMaxFloat();
void indovinaNum();
int mcd(int x, int y);
void tripleNumValRef();
void arrayIstogramma();
void bubbleSort();
void ricBinaria(int x);
void prenotaAereo();
void giroCavallo();
void esPuntatori();
void mescolaCarte();
void puntRef();
void puntFx();
void manipString();
void pokerHand();
void intToString();

// ####################################  MAIN  #################################### //
int main()
{
    menu();

    return 0;
}
// ################################################################################ //


// ####################################  MENU  #################################### //
void menu()
{
    int scelta = 0;

    do
    {
        cout << "\n\t\t*******************************\n";
        cout << "\t\t****   PROGRAMMI IN C++    ****\n";
        cout << "\t\t*******************************\n";
        cout << "\n#######################################################################\n";
        cout << "##   1) separaNumeri" << "\t"   << " 2) pariDispari"     << "\t\t"   << " 3) minMax           ##" << endl;
        cout << "##   4) plotMatrix"   << "\t"   << " 5) mediaVoti"       << "\t\t"   << " 6) breakContinue    ##" << endl;
        cout << "##   7) convBinDec"   << "\t"   << " 8) calcPagaOra"     << "\t\t"   << " 9) gameCrap         ##" << endl;
        cout << "##  10) fattoriale"   << "\t"   << "11) fibonacci"       << "\t\t"   << "12) pasValRef        ##" << endl;
        cout << "##  13) esAutosilo"   << "\t"   << "14) minMaxFloat"     << "\t\t"   << "15) indovinaNum      ##" << endl;
        cout << "##  16) MCD"          << "\t\t" << "17) tripleNumValRef" << "\t"     << "18) arrayIstogramma  ##" << endl;
        cout << "##  19) bubbleSort"   << "\t"   << "20) ricBinaria"      << "\t\t"   << "21) prenotaAereo     ##" << endl;
        cout << "##  22) giroCavallo"  << "\t"   << "23) esPuntatori"     << "\t\t"   << "24) mescolaCarte     ##" << endl;
        cout << "##  25) puntRef"      << "\t\t" << "26) puntFx"          << "\t\t"   << "27) manipString      ##" << endl;
        cout << "##  28) pokerHand"    << "\t"   << "29) intToString"     << "\t\t"     << " 0) Termina          ##" << endl;
        cout << "#######################################################################\n";
        cout << "Che programma vuoi usare? ";
        cin >> scelta;

        switch(scelta)
        {
            case 1 : separaNumeri(); break;
            case 2 : pariDispari(); break;
            case 3 : minMax(); break;
            case 4 : plotMatrix(); break;
            case 5 : mediaVoti(); break;
            case 6 : breakContinue(); break;
            case 7 : convBinDec(); break;
            case 8 : calcPagaOra(); break;
            case 9 : gameCrap(); break;
            case 10 :
                {
                    unsigned long nFatt = 0;
                    cout << "\nCalcola fattoriale di: ";
                    cin >> nFatt;
                    cout << "Fattoriale di " << nFatt << ": " << fattoriale(nFatt) << endl;
                    break;
                }
            case 11 :
                {
                    long nFib = 0;
                    cout << "\nInserisci un intero: ";
                    cin >> nFib;
                    cout << "Fibonacci di " << nFib << ": " << fibonacci(nFib) << endl;
                    break;
                }
            case 12 : pasValRef(); break;
            case 13 : esAutosilo(); break;
            case 14 : minMaxFloat(); break;
            case 15 : indovinaNum(); break;
            case 16 :
                {
                    int a = 0, b = 0;
                    cout << "\nInserisci due interi: ";
                    cin >> a >> b;
                    cout << "M.C.D. di " << a << " e " << b << " = " << mcd(a, b) << endl;
                    break;
                }
            case 17 : tripleNumValRef(); break;
            case 18 : arrayIstogramma(); break;
            case 19 : bubbleSort(); break;
            case 20 :
                {
                    int n = 0;
                    cout << "\nInserisci un numero (0 - 28): ";
                    cin >> n;
                    ricBinaria(n);
                    break;
                }
            case 21 : prenotaAereo(); break;
            case 22 : giroCavallo(); break;
            case 23 : esPuntatori(); break;
            case 24 : mescolaCarte(); break;
            case 25 : puntRef(); break;
            case 26 : puntFx(); break;
            case 27 : manipString(); break;
            case 28 : pokerHand(); break;
            case 29 : intToString(); break;
        } //end switch
    }
    while(scelta != 0);
}
// ########################################################################################## //


// ####################################  separaNumeri()  #################################### //
// Fx che separa le cifre di un intero di 5 cifre
void separaNumeri()
{
    int n = 0;
    int dm = 0, m = 0, c = 0, d = 0, u = 0;

    cout << "\nInserisci un numero di 5 cifre: ";
    cin >> n;

    u = n % 10 ;
    //cout << "Unitˆ: " << u << endl;
    d = (n / 10) % 10;
    //cout << "Decine: " << d << endl;
    c = (n / 100) % 10;
    //cout << "Centinaia: " << c << endl;
    m = (n / 1000) % 10;
    //cout << "Migliaia: " << m << endl;
    dm = (n / 10000) % 10;
    //cout << "Decine di migliaia: " << dm << endl;

    cout << dm << "   " << m << "   " << c << "   " << d << "   " << u << endl;
}
// ######################################################################################### //


// ####################################  pariDispari()  #################################### //
// Fx che calcola se un intero è pari o dispari
void pariDispari()
{
    int n = 0;

    cout << "\nInserisci un numero: ";
    cin >> n;

    if((n % 2) == 0)
        cout << "Il numero " << n << " è pari" << endl;
    else
        cout << "Il numero " << n << " è dispari" << endl;
}
// ######################################################################################### //


// ####################################  minMax()  #################################### //
// Fx che dati 5 interi calcola min e max
void minMax()
{
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    int minimo, massimo;

    cout << "\nInserisci cinque numeri interi: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    if(n1 <= minimo)
        minimo = n1;
    if(n2 <= minimo)
        minimo = n2;
    if(n3 <= minimo)
        minimo = n3;
    if(n4 <= minimo)
        minimo = n4;
    if(n5 <= minimo)
        minimo = n5;

    if(n1 >= massimo)
        massimo = n1;
    if(n2 >= massimo)
        massimo = n2;
    if(n3 >= massimo)
        massimo = n3;
    if(n4 >= massimo)
        massimo = n4;
    if(n5 >= massimo)
        massimo = n5;

    cout << "Minimo: " << minimo << endl;
    cout << "Massimo: " << massimo << endl;
}
// ######################################################################################## //


// ####################################  plotMatrix()  #################################### //
// Fx che disegna una matrice di simboli
void plotMatrix()
{
    char a[10][10];

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == j || (i+j) == 9)
                a[i][j] = '*';
            else
                a[i][j] = '-';
        }
    }

    cout << endl;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            cout << a[i][j] << " ";

        cout << endl;
    }
}
// ####################################################################################### //


// ####################################  mediaVoti()  #################################### //
// Fx che calcola la media dei voti inseriti
void mediaVoti()
{
    int nVoti = 0, totale = 0, voto = 0, media = 0;

    cout << "\nQuanti voti vuoi inserire? ";
    cin >> nVoti;

    for(int i = 0; i < nVoti; i++)
    {
        cout << "Inserisci voto: ";
        cin >> voto;
        totale += voto;
    }

    media = totale / nVoti;
    cout << "Media voti: " << media << endl;
}
// ########################################################################################### //


// ####################################  breakContinue()  #################################### //
// Fx che visualizza la differenza tra istruzioni break() e continue()
void breakContinue()
{
    for(int i = 0; i < 10; i++)
    {
        if(i == 5)
            break;  // il ciclo termina prima di stampare il valore 5

        cout << i << " ";
    }
    cout << "\nUscita dal ciclo (break)" << endl;

    for(int i = 0; i < 10; i++)
    {
        if(i == 5)
            continue;   // il ciclo continua a stampare ma salta il valore 5

        cout << i << " ";
    }
    cout << "\nSalto del valore 5 (continue)" << endl;
}
// ################################################################################################ //


// ####################################  convertitoreBinDec()  #################################### //
// Fx che converte un numero intero da decimale a binario
void convBinDec()
{
    int n = 0, nOrig = 0, cifraBin = 0, contatore = 0, decimale = 0;

    cout << "\nInserisci un numero binario: ";
    cin >> n;
    nOrig = n;

    if(n == 0)
        cout << "BINARIO: " << n << " --> DECIMALE: 0" << endl;
    else
    {
        while(n > 0)
        {
            cifraBin = (n % 10) * pow(2, contatore);    // pow() utilizza libreria <cmath>
            decimale += cifraBin;
            n = n / 10;
            contatore++;
        }

        cout << "BINARIO: " << nOrig << " --> DECIMALE: " << decimale << endl;
    }
}
// ######################################################################################### //


// ####################################  calcPagaOra()  #################################### //
// Fx che calcola la paga oraria di 4 diversi lavoratori
void calcPagaOra()
{
    const double FISSO_MANAGER = 1000, FISSO_ORARIO = 500, FISSO_COMM = 250, FISSO_COTT = 150;
    int cod = 0, oreStra = 0, nPezzi = 0;
    double pagaOra = 0, vendIngr = 0;

    cout << "\n*** CALCOLA PAGA ORARIA ***" << endl;
    cout << "(1) - Manager" << endl;
    cout << "(2) - Lav. orario" << endl;
    cout << "(3) - Lav. commissione" << endl;
    cout << "(4) - lav. cottimo" << endl;
    cout << "Inserisci il codice impiegato:";
    cin >> cod;

    switch(cod)
    {
        case 1 :
            pagaOra = FISSO_MANAGER / 40;
            cout << "Paga oraria MANAGER: " << pagaOra << endl;
            break;
        case 2 :
            cout << "Ore di straordinario: ";
            cin >> oreStra;
            pagaOra = (FISSO_ORARIO / 40) + ((FISSO_ORARIO / 40)* 2 * oreStra);
            cout << "Paga oraria LAV. ORARIO: " << pagaOra << endl;
            break;
        case 3 :
            cout << "Vendite ingrosso settimanali (€): ";
            cin >> vendIngr;
            pagaOra = (FISSO_COMM + ((5.7 * vendIngr) / 100)) / 40;
            cout << "Paga oraria LAV. COMMISSIONE: " << pagaOra << endl;
            break;
        case 4 :
            cout << "Pezzi lavorati: ";
            cin >> nPezzi;
            pagaOra = (FISSO_COTT * nPezzi) / 40;
            cout << "Paga oraria LAV. COTTIMO: " << pagaOra << endl;
            break;
    }
}
// ###################################################################################### //


// ####################################  gameCrap()  #################################### //
// Fx che rappresenta il gioco del Crap (dadi) utilizzando istruzioni rand() e srand() per
// la generazione di numeri casuali.
int rollDice(); // prototipo della fx rollDice()

void gameCrap()
{
    enum Status {CONTINUA, VITTORIA, SCONFITTA};    // var. enum per tenere conto dello status (CONTINUA = 0, VITTORIA = 1, SCONFITTA = 2)
    int somma = 0, mieiPunti = 0;
    Status gameStatus;

    srand(time(NULL));
    somma = rollDice();

    switch(somma)
    {
        case 7 :
        case 11 :
            gameStatus = VITTORIA;
            break;
        case 2 :
        case 3 :
        case 12 :
            gameStatus = SCONFITTA;
            break;
        default :
            gameStatus = CONTINUA;
            mieiPunti = somma;
            cout << "Il mio punteggio: " << mieiPunti << endl;
            break;
    }

    while(gameStatus == CONTINUA)
    {
        somma = rollDice();

        if(somma == mieiPunti)
            gameStatus = VITTORIA;
        else if (somma == 7)
            gameStatus = SCONFITTA;
    }

    if(gameStatus == VITTORIA)
        cout << "Complimenti, hai vinto!" << endl;
    else
        cout << "Mi dispiace, hai perso" << endl;
}

// Fx che si occupa della gestione del lancio di due dadi
int rollDice()
{
    int d1 = 0, d2 = 0, tot = 0;

    d1 = 1 + rand() % 6;
    d2 = 1 + rand() % 6;
    tot = d1 + d2;

    cout << "Il giocatore ottiene: " << d1 << " + " << d2 << " = " << tot << endl;

    return tot;
}
// ######################################################################################## //


// ####################################  fattoriale()  #################################### //
// Fx ricorsiva che calcola il fattoriale di un intero
unsigned long fattoriale(unsigned long n)
{
    if(n <= 1)
        return 1;
    else
        return n * fattoriale(n - 1);
}
// ####################################################################################### //


// ####################################  fibonacci()  #################################### //
// Fx ricorsiva che calcola l'n-esimo numero della serie di fibonacci
long fibonacci(long n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
// ####################################################################################### //


// ####################################  pasValRef()  #################################### //
// Fx che visualizza la differenza tra passaggio parametro per valore e riferimento
int squareByValue(int nVal);
void squareByReference(int &nRef);

void pasValRef()
{
    int x = 2, z = 4;

    cout << "x = " << x << " prima di squareByValue" << endl
         << "Valore tornato da squareByValue: " << squareByValue(x) << endl
         << "x = " << x << " dopo squareByValue" << endl;

    cout << "z = " << z << " prima di squareByReference" << endl;
    squareByReference(z);
    cout << "z = " << z << " dopo squareByReference" << endl;
}

int squareByValue(int nVal)
{
    return nVal *= nVal;    // l'argomento del chiamante non è modificato
}

void squareByReference(int &nRef)
{
    nRef *= nRef;   // l'argomento del chiamante è modificato
}
// ######################################################################################## //


// ####################################  esAutosilo()  #################################### //
// Fx che si occupa della gestione del conto di un autosilo per 3 clienti
double calcolaConto(double ore);
const double FISSO = 2.00, ORA = 0.50, GIORNO = 10.00;

void esAutosilo()
{
    double ore[3], conto[3], totOre = 0, totConto = 0;

    for(int i = 1; i <= 3; i++)
    {
        cout << "Cliente [" << i << "] inserisci ore: ";
        cin >> ore[i];
        conto[i] = calcolaConto(ore[i]);
        totOre += ore[i];
        totConto += conto[i];
    }

    cout << "\nMacchina\tOre\t\tA pagare" << endl;
    for(int i = 1; i <= 3; i++)
    {
        cout << "[" << i << "]\t\t["
             << setiosflags(ios::fixed | ios::showpoint) << setprecision(1)
             << ore[i] << "]\t\t["
             << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
             << conto[i] << "]"
             << endl;
    }
    cout << "TOTALE\t\t["
         << setiosflags(ios::fixed | ios::showpoint) << setprecision(1)
         << totOre << "]\t\t["
         << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
         << totConto << "]"
         << endl;
}

double calcolaConto(double ore)
{
    if(ore <= 3)
        return FISSO;
    else if(ore > 3 && ore < 24)
        return FISSO + (ore - 3) * ORA;
    else if(ore == 24)
        return GIORNO;
}
// ######################################################################################### //


// ####################################  minMaxFloat()  #################################### //
// Fx che dati 3 valori in virgola mobile ne calcola min e max
float calcMin(float n1, float n2, float n3);
float calcMax(float n1, float n2, float n3);

void minMaxFloat()
{
    float n1 = 0, n2 = 0, n3 = 0;

    cout << "\nInserisci tre numeri a virgola mobile (max 2 cifre decimali): ";
    cin >> n1 >> n2 >> n3;

    cout << "Min: "
         << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
         << calcMin(n1, n2, n3)
         << endl;
    cout << "Max: "
         << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
         << calcMax(n1, n2, n3)
         << endl;
}

// Fx che calcola il min tra 3 numeri in virgola mobile
float calcMin(float n1, float n2, float n3)
{
    float minimo = n1;

    if(n2 <= minimo)
        minimo = n2;
    else if(n3 <= minimo)
        minimo = n3;

    return minimo;
}

// Fx che calcola il max tra 3 numeri in virgola mobile
float calcMax(float n1, float n2, float n3)
{
    float massimo = n1;

    if(n2 >= massimo)
        massimo = n2;
    else if(n3 >= massimo)
        massimo = n3;

    return massimo;
}
// ######################################################################################### //


// ####################################  indovinaNum()  #################################### //
// Fx che rappresenta il gioco "Indovina il numero"
int calcolaNum();
bool checkNum(int n, int num);

void indovinaNum()
{
    int num = 0, t = 0;

    srand(time(NULL));
    num = calcolaNum();

    cout << "Ho pensato un numero tra 1 e 1000." << endl;
    cout << "Prova un po' a indovinarlo!" << endl;
    cout << "Digita il primo tentativo: ";
    cin >> t;

    if(checkNum(t, num) == true)
        cout << "Complimenti, hai indovinato!" << " [" << num << "]" << endl;
    else
        cout << "Mi dispiace, hai perso." << " [" << num << "]" << endl;
}

// Fx che calcola un numero casuale tra 1 e 1000
int calcolaNum()
{
    return (1 + rand() % 1000);
}

// Fx che si occupa del controllo della vincita (in 10 tentativi)
bool checkNum(int n, int num)
{
    bool found = false;
    int t = 0, contatore = 1;

    while(found != true && contatore <=10)
    {
        if(n == num)
            found = true;
        else if(n > num)
        {
            contatore++;
            cout << "Troppo alto. Riprova!" << endl;
            cout << "Nuovo tentativo: ";
            cin >> n;
        }
        else if(n < num)
        {
            contatore++;
            cout << "Troppo basso. Riprova!" << endl;
            cout << "Nuovo tentativo: ";
            cin >> n;
        }
    }

    return found;
}
// ################################################################################# //


// ####################################  mcd()  #################################### //
// Fx ricorsiva che calcola il MCD tra due interi
int mcd(int x, int y)
{
    if(y == 0)
        return x;
    else
        return mcd(y, x % y);
}
// ############################################################################################# //


// ####################################  tripleNumValRef()  #################################### //
// Fx che triplica un intero (passato per valore e per riferimento)
int tripleNumVal(int nVal);
void tripleNumRef(int &nRef);

void tripleNumValRef()
{
    int x = 0, y = 0;

    cout << "\nInserisci due interi: ";
    cin >> x >> y;

    cout << "x = " << x << " prima di tripleNumVal" << endl
         << "Valore tornato da tripleNumVal: " << tripleNumVal(x) << endl
         << "x = " << x << " dopo tripleNumVal" << endl;

    cout << "y = " << y << " prima di tripleNumRef" << endl;
    tripleNumRef(y);
    cout << "y = " << y << " dopo tripleNumRef" << endl;
}

int tripleNumVal(int nVal)
{
    return nVal *= 3;
}

void tripleNumRef(int &nRef)
{
    nRef *= 3;
}
// ########################################################################################### //


// #################################### arrayIstogramma() #################################### //
// Fx che utilizza array per creare dei semplici istogrammi
void arrayIstogramma()
{
    const int arraySize = 10;
    int n[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Elemento" << setw(13) << "Valore" << setw(17) << "Istogramma" << endl;

    for(int i = 0; i < arraySize; i++)
    {
        cout << setw(7) << i << setw(13) << n[i] << setw(9);

        for(int j = 0; j < n[i]; j++)
            cout << "*";

        cout << endl;
    }
}
// ###################################################################################### //


// #################################### bubbleSort() #################################### //
// Fx che esegue il BubbleSort su un array di 10 interi (confronto di coppie di interi)
// N.B. Si devono utilizzare i passaggi per riferimento per la fx scambia, altrimenti
// verrebbero passati per valore e al ritorno dalla funzione "scambia" l'array non verrebbe
// modificato in quanto la fx lavorerebbe su copie degli elementi. Invece passando gli elementi
// per riferimento la fx "scambia" può agire direttamente sull'array originale
void scambia(int &a, int &b);

void bubbleSort()
{
    const int arraySize = 10;
    int a[arraySize] = {2,56,6,45,63,23,35,77,78,1};

    cout << "\nValori originali dell'array" << endl;

    for(int i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];

    for(int i = 0; i < arraySize - 1; i++)
        for(int j = 0; j < arraySize - 1; j++)
            if(a[j] > a[j + 1])
                scambia(a[j], a[j+1]);

    cout << "\nValori dell'array ordinato" << endl;

    for(int i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];
}

void scambia(int &a, int &b)
{
    int temp = 0;
    temp = a ;
    a = b;
    b = temp;
}
// ########################################################################################## //


// #################################### ricercaBinaria() #################################### //
// Fx che esegue la ricerca binaria di un intero, visualizzando l'intero procedimento
// Array di 15 elementi, quindi la potenza di 2 più vicina è 16=(2^4) -> 4 confronti al massimo
// infatti ad ogni passaggio viene presa solo una metà dell'array risultante
int ricerca(int a[], int key, int low, int high, int aSize);
void printHeader(int aSize);
void printRow(int a[], int low, int mid, int high, int aSize);

void ricBinaria(int n)
{
    const int arraySize = 15;
    int a[arraySize], risultato = 0;

    // riempie l'array con alcuni valori
    for(int i = 0; i < arraySize; i++)
        a[i] = 2 * i;

    printHeader(arraySize);
    risultato = ricerca(a, n, 0, arraySize - 1, arraySize);

    if(risultato != -1)
        cout << "\n" << n << " trovato nell'elemento dell'array " << risultato << endl;
    else
        cout << "\n" << n << " non trovato nell'array" << endl;
}

int ricerca(int a[], int key, int low, int high, int aSize)
{
    int middle;

    while(low <= high)
    {
        middle = (low + high) / 2;

        printRow(a, low, middle, high, aSize);

        // confronto con elemento centrale dell'array
        if(key == a[middle])
            return middle;
        else if(key < a[middle])
            high = middle - 1;  // ricerca sulla metà inferiore
        else
            low = middle + 1;   // ricerca sulla metà superiore
    }

    return -1;  // chiave non trovata
}

// Fx che visualizza un'intestazione per l'output
void printHeader(int aSize)
{
    cout << "\nVisualizzazione:" << endl;

    for(int i = 0; i < aSize; i++)
        cout << setw(3) << i << " ";

    cout << endl;

    for(int i = 1; i <= 4 * aSize; i++)
        cout << "-";

    cout << endl;
}

// Fx che visualizza una riga di output che mostra la parte dell'array che è in
// elaborazione in un dato momento
void printRow(int a[], int low, int mid, int high, int aSize)
{
    for(int i = 0; i < aSize; i++)
    {
        if(i < low || i > high)
            cout << "   ";
        else if (i == mid)  // marca il valore centrale
            cout << setw(3) << a[i] << "*";
        else
            cout << setw(3) << a[i] << " ";
    }

    cout << endl;
}
// ########################################################################################## //


// #################################### prenotaAereo() #################################### //
// Fx che gestisce le prenotazioni di un'agenzia aerea.
// 10 posti disponibili divisi in due reparti: fumatori e non fumatori.
// L'utente sceglie il reparto e il sistema prenota. Se un reparto è completamente occupato
// si chiede all'utente il desiderio di prenotare nell'altro, altrimenti si conclude.
void inizializzaArray(int a[], int aSize);
void printArray(int a[], int aSize);

void prenotaAereo()
{
    const int aSize = 10;
    int a[aSize], scelta = 0, sentinella = (aSize / 2), contaFumatori = 0, contaNonFumatori = 0;
    char cambio;

    inizializzaArray(a, aSize);

    for(int i = 0; i < aSize; i++)
    {
        cout << "\nBenvenuto, scegli un reparto:" << endl;
        cout << "Fumatori (1) / Non fumatori (2): ";
        cin >> scelta;

        // reparto fumatori
        if((scelta != -1) && (i < (aSize / 2)) && (contaFumatori < 5))
        {
            if((scelta == 2) && (contaNonFumatori == 5))
            {
                cout << "Reparto non fumatori pieno, vuoi cambiare? (s/n): ";
                cin >> cambio;
                if(cambio == 's')
                {
                    a[i] = 1;
                    cout << "a[" << i << "] = Posto prenotato" << endl;
                    printArray(a, aSize);
                    contaFumatori++;
                }
                else
                {
                    cout << "Prossimo aereo tra 3 ore." << endl;
                    break;
                }
            }

            if((scelta == 1) && contaNonFumatori != 5)
            {
                a[i] = 1;
                cout << "a[" << i << "] = Posto prenotato" << endl;
                printArray(a, aSize);
                contaFumatori++;
            }
        }
        // reparto non fumatori
        if((scelta != -1) && (contaNonFumatori < 5))    // !!! se fumatori è tutto occupato poi si entra direttamente in questo f anche se non si dovrebbe
        {
            if((scelta == 1) && (contaFumatori == 5))
            {
                cout << "Reparto fumatori pieno, vuoi cambiare? (s/n): ";
                cin >> cambio;
                if(cambio == 's')
                {
                    a[sentinella] = 1;  // inizia a inserire da metà array
                    cout << "a[" << sentinella << "] = Posto prenotato" << endl;
                    sentinella++;
                    printArray(a, aSize);
                    i--;    // in questo modo il ciclo non "salta" un elemento della zona fumatori
                    contaNonFumatori++;
                }
                else
                {
                    cout << "Prossimo aereo tra 3 ore." << endl;
                    break;
                }
            }

            if(scelta == 2)
            {
                a[sentinella] = 1;  // inizia a inserire da metà array
                cout << "a[" << sentinella << "] = Posto prenotato" << endl;
                sentinella++;
                printArray(a, aSize);
                i--;    // in questo modo il ciclo non "salta" un elemento della zona fumatori
                contaNonFumatori++;
            }
        }

        if((scelta == -1) || ((contaFumatori == 5) && (contaNonFumatori == 5)))
            break;
    }

    cout << "\nRIEPILOGO PRENOTAZIONI:" << endl;
    printArray(a, aSize);
}

// Fx che inizializza a 0 gli elementi dell'array
void inizializzaArray(int a[], int aSize)
{
    for(int i = 0; i < aSize; i++)
        a[i] = 0;
}

// Fx che visualizza l'array
void printArray(int a[], int aSize)
{
    for(int i = 0; i < aSize; i++)  // occupato (1) / libero (0)
        cout << setw(6) << a[i];

    cout << endl;

    for(int i = 0; i < aSize; i++)  // separatore
        cout << setw(6) << "----";

    cout << endl;

    for(int i = 0; i < aSize; i++)  // nome posti
        cout << setw(4) << "a[" << i << "]";

    cout << endl;
}
// ####################################################################################### //


// #################################### giroCavallo() #################################### //
// Fx che visualizza una scacchiera e cerca di risolvere il problema del "giro del cavallo".
// E' possibile occupare tutte le caselle con le mosse del cavallo senza passare per una già
// visitata?
void inizializzaScacchiera(int s[8][8]);
void mossa(int s[8][8], int h[], int v[], int sSize, int numMossa);
void inserisciMossa(int s[8][8], int cRow, int cCol, int contaMosse);
bool checkVuoto(int s[8][8], int cRow, int cCol);
void printScacchiera(int s[8][8]);

void giroCavallo()
{
    const int sSize = 8;
    int s[sSize][sSize];                                    // scacchiera
    int horizontal[sSize] = {2, 1, -1, -2, -2, -1, 1, 2};   // mosse orizzontali
    int vertical[sSize] = {-1, -2,-2, -1, 1, 2, 2, 1};      // mosse verticali
    int numMossa = 0;

    inizializzaScacchiera(s);
    printScacchiera(s);

    mossa(s, horizontal, vertical, sSize, numMossa);

    cout << ".:SCACCHIERA FINALE:." << endl;
    printScacchiera(s);
}

// inizializza ogni casella della scacchiera a 0
void inizializzaScacchiera(int s[8][8])
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            s[i][j] = 0;
}

// Chiede il numero di mossa da eseguire ed effettua i vari controlli che permettono
// al cavallo di muoversi sulla scacchiera
void mossa(int s[8][8], int h[], int v[], int sSize, int numMossa)
{
    int currentRow = 3, currentColumn = 4;

    for(int i = 1; i <= 64; i++)    // si eseguono 64 mosse
    {
        if(numMossa != -1)
        {
            cout << "Che mossa vuoi fare? (0 - 7, -1 per uscire): ";
            cin >> numMossa;
            currentRow += v[numMossa];
            currentColumn += h[numMossa];
            if((currentRow >= 0 && currentRow <= 7) && (currentColumn >= 0 && currentColumn <= 7) && (checkVuoto(s, currentRow, currentColumn)))
            {
                inserisciMossa(s, currentRow, currentColumn, i);
                printScacchiera(s);
                cout << "Mossa numero (i): " << i  << endl;
            }
            else
            {
                // Controllo dei confini della scacchiera !!! ATTENZIONE, non viene mai effettuato !!!
                if(!(currentRow >= 0 && currentRow <= 7) && !(currentColumn >= 0 && currentColumn <= 7))
                {
                    cout << "Mossa non valida: sei fuori dalla scacchiera" << endl;
                    currentRow -= v[numMossa];
                    currentColumn -= h[numMossa];
                    i--;
                }
                // Controllo casella già visitata
                else
                {
                    cout << "Mossa non valida: casella occupata" << endl;
                    currentRow -= v[numMossa];
                    currentColumn -= h[numMossa];
                    i--;
                }
            }
        }
        else
            break;  // uscita dal programma
    }
}

// Inserisce il numero della mossa nella casella appena visitata dal cavallo
void inserisciMossa(int s[8][8], int cRow, int cCol, int contaMosse)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            if((i == cRow) && (j == cCol))
                s[i][j] = contaMosse;
    }
}

// Controlla se la casella di destinazione risulta vuota (ancora da visitare)
bool checkVuoto(int s[8][8], int cRow, int cCol)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((i == cRow) && (j == cCol))
                if(s[i][j] == 0)
                    return true;
        }
    }
}

// Disegna la scacchiera in un determinato istante
void printScacchiera(int s[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(i == 3 && j == 4)
                s[i][j] = 1;
            cout << s[i][j] << " ";
        }

        cout << endl;
    }
}
// ####################################################################################### //


// #################################### esPuntatori() #################################### //
// Fx che visualizza l'uso dei puntatori
void esPuntatori()
{
    int a;      // intero
    int *aPtr;  // puntatore ad un intero

    a = 7;
    aPtr = &a;  // aPtr contiene l'indirizzo di a

    cout << "\nIndirizzo di 'a': " << &a << endl;
    cout << "Valore di 'aPtr': " << aPtr << endl;

    cout << "Valore di 'a' = valore di '*aPtr': " << *aPtr << endl;

    cout << "* e & sono operazioni inverse, infatti:" << endl;
    cout << "&*aPtr: " << &*aPtr << endl;
    cout << "*&aPtr: " << *&aPtr << endl;
}
// ######################################################################################## //


// #################################### mescolaCarte() #################################### //
void mescola(int m[0][13]);
void distribuisci(int m[0][13], const char *s[], const char *v[]);

void mescolaCarte()
{
    const char *seme[4] = {"Cuori", "Fiori", "Quadri", "Picche"};
    const char *valore[13] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Regina", "Re"};
    int mazzo[4][13] = {0}; //matrice che rappresenta: righe -> seme, colonne -> valore (es. mazzo[2][12] = Re di Quadri)

    srand(time(0));

    mescola(mazzo);
    distribuisci(mazzo, seme, valore);
}

void mescola(int m[0][13])
{
    int riga = 0, colonna = 0;

    // riempie ogni cella con un numero contatore (da 1 a 52)
    for(int i = 1; i <= 52; i++)
    {
        do
        {
            riga = rand() % 4; // 0 + rand() % 4
            colonna = rand() % 13;  // 0 + rand() % 13
        }
        while(m[riga][colonna] != 0);    // se la cella è già segnata continua a cercare una cella vuota

        m[riga][colonna] = i;   // se la cella è vuota allora viene segnata
    }
}

void distribuisci(int m[0][13], const char *s[], const char *v[])
{
    for(int carta = 1; carta <= 52; carta++) // per ogni carta
    {
        for(int i = 0; i <= 3; i++)
        {
            for(int j = 0; j <= 12; j++)
            {
                if(m[i][j] == carta)
                    cout << setw(8) << setiosflags(ios::right) << v[j]
                         << " di "
                         << setw(2) << setiosflags(ios::left) << s[i]
                         << (carta % 2 == 0 ? '\n' : ' ');
            }
        }
    }
}
// ######################################################################################### //

// ####################################### puntRef() ####################################### //
// Fx che visualizza la differenza tra passaggio per indirizzo (puntatori) e per riferimento
int moltiplicaInd(int* x, int* y);
int moltiplicaRef(int &x, int &y);

void puntRef()
{
    int a = 5, b = 6, risultatoInd = 0, risultatoRef = 0;

    risultatoInd = moltiplicaInd(&a, &b);
    risultatoRef = moltiplicaRef(a, b);

    cout << "Risultato della moltiplicazione (per indirizzo): " << risultatoInd <<endl;
    cout << "Risultato della moltiplicazione (per riferimento): " << risultatoRef <<endl;
}

int moltiplicaInd(int* x, int*y)
{
    int ris;
    // effettua la moltiplicazione tra i valori che si trovano leggendo il contenuto della memoria
    // agli indirizzi x e y, tramite il prefisso '*' (da non confondere con l'operatore di moltiplicazione)
    ris = *x * *y;

    // Valore restituito dalla funzione
    return ris;
}

int moltiplicaRef(int &x, int &y)
{
    int ris;

    // moltiplica ciò che trova presso gli indirizzi di memoria di x e y ma non c'è bisogno di esplicitarlo
    ris = x * y;

    // Valore restituito dalla funzione
    return ris;
}
// ######################################################################################## //

// ####################################### puntFx ####################################### //
// Fx che visualizza l'uso dei puntatori a funzione (in questo caso array di puntatori a fx)
void f1(int a);
void f2(int b);
void f3(int c);

void puntFx()
{
    // f array di 3 puntatori a fx che prendono ciascuna un argomento int e restituiscono il tipo di dato void
    void (*f[3])(int) = {f1, f2, f3};
    int scelta;

    cout << "Inserire un numero tra 0 e 2 (3 per terminare): ";
    cin >> scelta;

    while(scelta >= 0 && scelta < 3)
    {
        (*f[scelta])(scelta);   // cfr. pag 301
        cout << "Inserire un numero tra 0 e 2 (3 per terminare): ";
        cin >> scelta;
    }

    cout << "Esecuzione programma terminata." << endl;
}

void f1(int a)
{
    cout << "Hai inserito " << a << " quindi è stata chiamata f1" << endl;
}

void f2(int b)
{
    cout << "Hai inserito " << b << " quindi è stata chiamata f2" << endl;
}

void f3(int c)
{
    cout << "Hai inserito " << c << " quindi è stata chiamata f3" << endl;
}
// ############################################################################################# //

// ####################################### manipString() ####################################### //
void manipString()
{
    char x[] = "Happy Birthday to You";
    char y[25], z[15];

    cout << "\nLa stringa nell'array x: " << x
         << "\nLa stringa nell'array y: " << strcpy(y, x) << endl;  // copia x in y

    // Copia i primi 14 caratteri dell'array x in y
    strncpy(z, x, 14); // non copia il carattere nullo
    // All'array z viene aggiunto il carattere terminatore perché la chiamata a strncpy non esegue
    // in automatico questa operazione. Infatti il terzo argomento è minore della lunghezza della stringa
    // passata come secondo argomento)
    z[14] = '\0';

    cout << "La stringa nell'array z: " << z << endl;

    char c1[20] = "Happy ";
    char c2[] = "New Year ";
    char c3[40] = "";

    cout << "\nc1 = " << c1 << "\nc2 = " << c2 << endl;
    cout << "strcat(c1, c2) = " << strcat(c1, c2) << endl;
    cout << "strncat(c3, c1, 6) = " << strncat(c3, c1, 6) << endl;
    cout << "strcat(c3, c1) = " << strcat(c3, c1) << endl;

    char *s1 = "Happy New Year";
    char *s2 = "Happy New Year";
    char *s3 = "Happy Holidays";

    // strcmp confronta due stringhe: 0 (uguaglianza), pos (seconda stringa maggiore) neg (prima stringa maggiore)
    cout << "\ns1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3
         << "\n\nstrcmp(s1, s2) = " << setw(2) << strcmp(s1, s2)
         << "\nstrcmp(s1, s3) = " << setw(2) << strcmp(s1, s3)
         << "\nstrcmp(s3, s1) = " << setw(2) << strcmp(s3, s1) << endl;

    cout << "\nstrncmp(s1, s3, 6) = " << setw(2) << strncmp(s1, s3, 6)
         << "\nstrncmp(s1, s3, 7) = " << setw(2) << strncmp(s1, s3, 7)
         << "\nstrncmp(s3, s1, 7) = " << setw(2) << strncmp(s3, s1, 7) << endl;

    char stringa[] = "This is a sentence with 7 tokens";
    char *tokenPtr;

    cout << "\nLa stringa da dividere in token:" << stringa << endl;
    cout << "I tokens sono:" << endl;

    // Attenzione che la fx strtok modifica la stringa originale!
    tokenPtr = strtok(stringa, " ");    // cfr. pag. 310

    while(tokenPtr != NULL)
    {
        cout << tokenPtr << endl;
        tokenPtr = strtok(NULL, " ");
    }

    char *string1 = "abcdefghijklmnopqrstuvwxyz";

    cout << "\nLa lunghezza di \"" << string1 << "\" è: " << strlen(string1) << endl;
}
// ########################################################################################### //

// ####################################### pokerHand() ####################################### //
// Fx che mescola un mazzo di carte e ne distribuisce 5 al giocatore (poker), quindi controlla
// il punteggio ottenuto con le carte (coppia, doppia coppia, full, poker ...)
// Vengono utilizzate le funzioni già implementate per inizializzare e mescolare il mazzo, viene
// modificata la fx che si occupa della distribuzione delle carte.

//void mescola(int m[0][13]);
void distribuisciMano(int m[][13], const char *s[], const char *v[]);
void checkMano(int mano[4][13], const char *s[], const char *v[]);

bool checkscala = false;    // variabile usata per contare il numero di passi necessari per trovare una scala reale

void pokerHand()
{
    const char *seme[4] = {"Cuori", "Fiori", "Quadri", "Picche"};
    const char *valore[13] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Regina", "Re"};
    int mazzo[4][13] = {0}; //matrice che rappresenta: righe -> seme, colonne -> valore (es. mazzo[2][12] = Re di Quadri)

    srand(time(0));

    mescola(mazzo);
    distribuisciMano(mazzo, seme, valore);  // occorre disabilitarlo per utilizzare il codice sottostante

    // Procedimento utilizzato per contare il numero di passi necessario a trovare un determinato tipo di punteggio
    /*
    int passo = 0;
    do
    {
        distribuisciMano(mazzo, seme, valore);
        passo++;
        cout << "Passo numero: " << passo << endl;
    } while(checkscala != true);
    cout << "Scala Reale trovata in " << passo << " passi" << endl;
    checkscala = false;
    */
}

void distribuisciMano(int m[][13], const char *s[], const char *v[])
{
    int mano[4][13] = {0};
    int cartaN = 0;

    cout << endl;
    for(int conta = 1; conta <= 5; conta++) // 5 carte casuali nel mazzo
    {
        cartaN = 1 + rand() % 52;
        for(int i = 0; i <= 3; i++)
        {
            for(int j = 0; j <= 12; j++)
            {
                if(m[i][j] == cartaN)
                {
                    cout << setw(8) << setiosflags(ios::right) << v[j]
                         << " di "
                         << setw(2) << setiosflags(ios::left) << s[i]
                         << endl;

                    mano[i][j] = 1;
                }
            }
        }
    }

    checkMano(mano, s, v);
}

void checkMano(int mano[4][13], const char *s[], const char *v[])
{
    int contaUno = 0, contaCoppia = 0;
    int contaContigue = 0;
    int coppia = 0, d_coppia = 0, tris = 0, poker = 0, colore = 0, scala_colore = 0, scala_reale = 0;

    // ciclo che scorre le colonne
    for(int j = 0; j <= 12; j++)
    {
        for(int i = 0; i <= 3; i++)
        {
            if(mano[i][j] == 1)
                contaUno += 1;  // conta quante carte dello stesso valore ci sono per ogni colonna
        }

        if(contaUno == 2)   // controlla COPPIA
        {
            cout << "Hai una coppia di: " << v[j] << endl;
            contaCoppia += 1;   // contatore per le coppie
            coppia = 1;
        }
        if(contaUno == 3)   // controlla TRIS
        {
            cout << "Hai un tris di: " << v[j] << endl;
            tris = 1;
        }
        if(contaUno == 4)   // controlla POKER
        {
            cout << "Hai un poker di: " << v[j] << endl;
            poker = 1;
        }
        if(contaCoppia == 2)    // controlla DOPPIA COPPIA
        {
            cout << "Hai una doppia coppia" << endl;
            d_coppia = 1;
            break;
        }

        contaUno = 0;   // azzera il contatore per usarlo nelle colonne successive
    }

    // ciclo che scorre le righe
    for(int i = 0; i <= 3; i++)
    {
        for(int j = 0; j <= 12; j++)
        {
            if(mano[i][j] == 1)
                contaUno += 1;  // conta quante carte dello stesso valore ci sono per ogni riga
            if(contaContigue < 4 && mano[i][j] == 1 && mano[i][j+1] == 1)
                contaContigue++;    // conta il numero di carte contigue per seme (riga)
        }

        if(contaUno == 5)   // controlla COLORE
        {
            cout << "Hai colore a " << s[i] << endl;
            colore = 1;
        }
        contaUno = 0;

        if(contaContigue == 4)  // controlla Scala Colore
        {
            cout << "Hai scala colore a " << s[i] << endl;
            scala_colore = 1;
        }
        contaContigue = 0;

        // controlla la Scala Reale (10,J,Q,K,A)
        if(mano[i][0] == 1 && mano[i][9] == 1 && mano[i][10] == 1 && mano[i][11] == 1 && mano[i][12] == 1)
        {
            cout << "Scala Reale a " << s[i] << endl;
            scala_reale = 1;
            //checkscala = true;
        }
    }

    if(coppia == 0 && d_coppia == 0 && tris == 0 && poker == 0 && colore == 0 && scala_colore == 0 && scala_reale == 0)
        cout << "Non hai niente!" << endl;
}
// ############################################################################################# //


// ####################################### intToString() ####################################### //
// Fx che legge un intero inserito dall'utente e lo traduce "a parole" in stringa
// Ad es. 12543 = "DodicimilaCinquecentoQuarantaTre"

void creaArray(int num, int aNum[], int s, int &cont);
void translateIntStr(int num, int aNum[], int s, int cont);
string unita(int num, string u[]);
string decine(int num, int aNum[], int s, string u[], string d[]);
string centinaia(int num, int aNum[], int s, string u[], string d[]);
string migliaia(int num, int aNum[], int s, string u[], string d[]);
string checkDecMig(int num, int aNum[], int s, string u[], string d[]);
string decmigl(int num, int aNum[], int s, string u[], string d[]);
string checkCenMig(int num, int aNum[], int s, string u[], string d[]);
string centmigl(int num, int aNum[], int s, string u[], string d[]);

void intToString()
{
    int num = 0;
    const int len = 6;
    int arrayNum[len] = {0};    // inizializza array dei numeri a 0
    int cifre = 0;   // conta cifre

    cout << "\nInserisci un numero intero (max 6 cifre): ";
    cin >> num;

    creaArray(num, arrayNum, len, cifre);

    for(int i = 0; i < len; i++)
        cout << "[" << i << "]=" << arrayNum[i] << " ";

    cout << endl;

    translateIntStr(num, arrayNum, len, cifre);
}

// Fx che divide il numero in cifre e le inserisce in un array
void creaArray(int num, int aNum[], int s, int &cont)
{
    // popola array con il numero inserito
    for(int i = (s-1); i >= 0; i--)
    {
        if(num > 0)
        {
            aNum[i] = num % 10;
            num /= 10;
            cont++;
        }
    }
}

// Fx che in base alla lunghezza del numero inserito chiama la corretta funzione di risoluzione
void translateIntStr(int num, int aNum[], int s, int cont)
{
    string u[20] = {"", "UNO", "DUE", "TRE", "QUATTRO", "CINQUE", "SEI", "SETTE", "OTTO", "NOVE",
                    "DIECI", "UNDICI", "DODICI", "TREDICI", "QUATTORDICI", "QUINDICI", "SEDICI",
                    "DICIASSETTE", "DICIOTTO", "DICIANNOVE"};
    string d[10] = {"", "DIECI", "VENTI", "TRENTA", "QUARANTA", "CINQUANTA", "SESSANTA", "SETTANTA", "OTTANTA", "NOVANTA"};

    switch(cont)
    {
        case 1 : (cout << unita(num, u)); break;
        case 2 : (cout << decine(num, aNum, s, u, d)); break;
        case 3 : (cout << centinaia(num, aNum, s, u, d)); break;
        case 4 : (cout << migliaia(num, aNum, s, u, d)); break;
        case 5 : (cout << decmigl(num, aNum, s, u, d)); break;
        case 6 : (cout << centmigl(num, aNum, s, u, d)); break;
    }
}

// Fx che calcola le uità (usa array u[])
string unita(int num, string u[])
{
    string tot = "";

    tot = u[num];

    return tot;
}

// Fx che calcola le decine (usa array d[])
string decine(int num, int aNum[], int s, string u[], string d[])
{
    string tot = "";

    if(aNum[4] == 0)    // utile per numeri più grandi di 2 cifre
        tot = unita(aNum[5], u);

    if(aNum[4] == 1)    // numeri speciali (11...19)
        tot = unita(10+aNum[5], u);
    else
        tot = d[aNum[4]] + unita(aNum[5], u);   // numero normale (20...99)

    return tot;
}

// Fx che calcola le centinaia
string centinaia(int num, int aNum[], int s, string u[], string d[])
{
    string cento = "CENTO", tot = "";

    if(aNum[3] == 0)    // utile per numeri più grandi di 3 cifre
        tot = decine(num, aNum, s, u, d);

    if(aNum[3] == 1)    // numeri speciali (100...199)
        tot = cento + decine(num, aNum, s, u, d);
    else
        if(aNum[3] != 0 && aNum[3] != 1)    // numeri normali (200...999)
            tot = unita(aNum[3], u) + cento + decine(num, aNum, s, u, d);

    return tot;
}

// Fx che calcola le migliaia
string migliaia(int num, int aNum[], int s, string u[], string d[])
{
    string mille = "MILLE", mila = "MILA", tot = " ";

    if(aNum[2] == 1)    // numeri speciali (1000...1199)
        tot = mille + centinaia(num, aNum, s, u, d);
    else
        tot = unita(aNum[2], u) + mila + centinaia(num, aNum, s, u, d); // numeri normali (2000...9999)

    return tot;
}

// Fx supporto che calcola le decine (nelle decine di migliaia)
string checkDecMig(int num, int aNum[], int s, string u[], string d[])
{
    string tot = "";

    if(aNum[1] == 1)    // numeri speciali (10...19)
        tot = unita(10+aNum[2], u);
    else
        tot = d[aNum[1]] + unita(aNum[2], u);   // numeri normali (20...99)

    return tot;
}

// Fx che calcola le decine di migliaia
string decmigl(int num, int aNum[], int s, string u[], string d[])
{
    string mila = "MILA", tot = " ";

    tot = checkDecMig(num, aNum, s, u, d) + mila + centinaia(num, aNum, s, u, d);

    return tot;
}

// Fx supporto che calcola le centinaia (nelle centinaia di migliaia)
string checkCenMig(int num, int aNum[], int s, string u[], string d[])
{
    string cento = "CENTO", tot = "";

    if(aNum[0] == 1)    // numeri speciali (100...199)
        tot = cento + checkDecMig(num, aNum, s, u, d);
    else
        if(aNum[0] != 0 && aNum[0] != 1)    // numeri normali (200...999)
            tot = unita(aNum[0], u) + cento + checkDecMig(num, aNum, s, u, d);

    return tot;
}

// Fx che calcola le centinaia di migliaia
string centmigl(int num, int aNum[], int s, string u[], string d[])
{
    string mila = "MILA", tot = " ";

    tot = checkCenMig(num, aNum, s, u, d) + mila + centinaia(num, aNum, s, u, d);

    return tot;
}
// #################################################################################### //



