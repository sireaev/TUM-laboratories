#include <cmath>
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

class Gibbs {
    int i, j;
    int n = 10; // numarul valorilor stocate
    float Matrice[10][2]; //matricea care va stoca valorile
    double x = 0, y = 0;
    public:
        Gibbs() {
            cout << "Initializare Paradoxul lui Gibbs...\n" << endl;
        };

    // Functia Gamma - care se defineste ca factorial
    //pentru numerele complexe si reale
    double Gamma(double z, unsigned Nterms) {
        double g = 0.577216; //constanta Euler-Mascheroni
        double retVal = z * exp(g * z);

        // aplicam produsele
        for (unsigned n = 1; n <= Nterms; ++n)
            retVal *= (1 + z / n) * exp(-z / n);

        retVal = 1.0 / retVal; // inversarea rezultatului

        return retVal;
    }
    //calculul numarului de distributie
    double randn(double mu, double sigma) {
        double U1, U2, W, mult;
        static double X1, X2;
        static int call = 0;

        if (call == 1) {
            call = !call;
            return (mu + sigma * (double) X2);
        }
        //GENERAREA VALORILOR ALEATORII
        do {
            U1 = -1 + ((double) rand() / RAND_MAX) * 2;
            U2 = -1 + ((double) rand() / RAND_MAX) * 2;
            W = pow(U1, 2) + pow(U2, 2);
        }
        while (W >= 1 || W == 0);

        mult = sqrt((-2 * log(W)) / W);
        X1 = U1 * mult;
        X2 = U2 * mult;

        call = !call;

        return (mu + sigma * (double) X1);
    }
    // n - numarul de simulari, d - numarul aditional de simulari prin simplificare
    float calculare(int number, int d) {

        cout << "\n N = " << (float) n << endl;
        cout << "\n D = " << (float) d << endl;

        for (i = 0; i < number; i++) {
            for (j = 0; j < d; j++) {
                //Calculul paradoxul lui Gibbs pentru 2 gaze
                x = Gamma(3.0, 1.0 / (y * y + 4)); //calculul prin functia Gamma care primeste 2 valori
                y = randn(1.0 / (x + 1), 1.0 / sqrt(2 * x + 2)); //calcul simplificat norma distributiei
            };
            Matrice[0][i] = x;
            Matrice[1][i] = y;
        };
    };
    //AFISAREA TABELULUI DE INTERVALURI
    void afisare() {
        cout << "  ________________________________________" << endl;
        cout << "  |" << setw(2) << "NR" << "|" << setw(20) << "CALCULUL GIBBS" << "\t\t |" << endl;
        cout << "  |______________________________________|" << endl;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < n; j++) {
                if (i == 1 && j == 0) {
                    cout << "  ________________________________________" << endl;
                }
                cout << "  | " << setw(2) << j + 1 << "|" << setw(20) << Matrice[i][j] << "\t\t |" << endl;;
            }
            cout << "  |______________________________________|" << endl;
            cout << "\n" << endl;
        }
    }
};

int main() {
    Gibbs interval;

    interval.calculare(2.9999, 50);
    interval.afisare();
    return 0;
}
