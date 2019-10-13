#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

//CREAREA MODELULUI DE DECIZIE
class V {
	protected:
		//CONSECINTE
		string puterePermisa;
		string utilizareCumbustibil;
		string consumKWh;
		string dotareNecesara;
		string tehnologiaNecesara;
		string calificarePersonal;
		
		//UTILITATI PENTRU CONSECINTE TEHNICO-ECONOMICE
		float putereInstanta;
		float utilizareCombustibilInferior;
		float consumSpecific;
		float dotareTehnica;
		float tehnologie;
		float calificare;
		
	public: 
	//SETAREA CONSECINTELOR
	void setareConsecinte(string puterePermisa,string utilizareCumbustibil,
						string consumKWh,string dotareNecesara,
						string tehnologiaNecesara,string calificarePersonal) {
							
		this -> puterePermisa = puterePermisa;
		this -> utilizareCumbustibil = utilizareCumbustibil;
		this -> consumKWh = consumKWh;
		this -> dotareNecesara = dotareNecesara;
		this -> tehnologiaNecesara = tehnologiaNecesara;
		this -> calificarePersonal = calificarePersonal;
	}

};

class Fuel : public V {
	float suma;
	
	public:
		Fuel(){};
		//SETAREA UTILITATILOR TEHNICO-ECONOMICE
		void setarePuterea(float param) {
			putereInstanta = param;
		}
		
		void setareUtilizare(float param) {
			utilizareCombustibilInferior = param;
		}
		
		void setareConsumSpecific(float param) {
			consumSpecific = param;
		}
		
		void setareDotareTehnica(float param) {
			dotareTehnica = param;
		}
		
		void setareTehnologie(float param) {
			tehnologie = param;
		}
		
		void setareCalificare(float param) {
			calificare = param;
		}
		
		//SETAREA UTILITATILOR CONSECINTE FINANCIARE
//		void setarePuterea(float param) {
//			putereInstanta = param;
//		}
//		
//		void setareUtilizare(float param) {
//			utilizareCombustibilInferior = param;
//		}
//		
//		void setareConsumSpecific(float param) {
//			consumSpecific = param;
//		}
//		
//		void setareDotareTehnica(float param) {
//			dotareTehnica = param;
//		}
//		
//		void setareTehnologie(float param) {
//			tehnologie = param;
//		}
//		
//		void setareCalificare(float param) {
//			calificare = param;
//		}
		
		
		//------------------------------------------
		
		void afisareUtilitati() {
			cout << putereInstanta << " " << utilizareCombustibilInferior << " " << consumSpecific << " " << 
			dotareTehnica << " " << tehnologie << " " << calificare << " " << endl;
		}
		
		//CALCULUL PENTRU TEHNICO-ECONOMIC
		float calculareSuma() {
			return this -> suma = putereInstanta + utilizareCombustibilInferior + consumSpecific + dotareTehnica + tehnologie + calificare;
		}
		
		void afisareAntet() {
			cout << "\n Putere permisa " << " " << " Utilizare combustibil " << " " << " consum kWh " << " " << " Dotare necesara " << "  " << " Tenhnologie necesara " << " Calificare personal " << endl;
		}
		
		void afisareConsecinte() {
//			cout << "\n Putere permisa " << " " << " Utilizare combustibil " << " " << " consum kWh " << " " << " Dotare necesara " << "  " << " Tenhnologie necesara " << " Calificare personal " << endl;
			cout << "\n" << setw(10) << this -> puterePermisa << setw(20) << this -> utilizareCumbustibil << setw(20) << this -> consumKWh << setw(13) << 
			this -> dotareNecesara << setw(23) << this -> tehnologiaNecesara << setw(22) << this -> calificarePersonal << endl;
		}
		
		void afisareSuma() {
			cout << "\n Suma: " << suma << endl;
			this -> suma = 0;
		}
		
		void newRow() {
			cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		}
};

int main() {
	Fuel v[6];
	float valoriConsecinte[5][6] = {
		{0.1, 0.1, 0, 1, 1, 0.9},
		{1, 0.3, 1, 1, 1, 1},
		{0.7, 0.2, 0.5, 0.7, 0.7, 0.7},
		{1, 1, 1, 0, 0, 0},
		{1, 0.8, 1, 0.7, 0.7, 0.7}
	};
	string consecinteTehnice[][6] = {
		{"Mica", "5%", "Mare", "Nu", "Nu", "Mica"},
		{"F.mare", "10%", "Mic", "Nu", "Nu", "Nu"},
		{"Mare", "5-10%", "Mediu", "Mare", "Mare", "Mare"},
		{"F.mare", "40-50%", "Mic", "F.mare", "F.mare", "F.mare"},
		{"F.mare", "30-40%", "Mic", "Mare", "Mare", "Mare"}
	};
	v[0].afisareAntet();
	for(int i = 0, j=0; i < 5; i++) {
			v[i].setareConsecinte(consecinteTehnice[i][j], consecinteTehnice[i][j+1], consecinteTehnice[i][j+2],
			consecinteTehnice[i][j+3], consecinteTehnice[i][j+4], consecinteTehnice[i][j+5]);
			
			v[i].setarePuterea(valoriConsecinte[i][j]);
			v[i].setareUtilizare(valoriConsecinte[i][j+1]);
			v[i].setareConsumSpecific(valoriConsecinte[i][j+2]);
			v[i].setareDotareTehnica(valoriConsecinte[i][j+3]);
			v[i].setareTehnologie(valoriConsecinte[i][j+4]);
			v[i].setareCalificare(valoriConsecinte[i][j+5]);
			
			v[i].calculareSuma();
			v[i].afisareConsecinte();
			v[i].afisareSuma();
			v[i].newRow();
	};
	for(int i = 0; i < 6; i++) {
		cout << " " << valoriConsecinte[1][i];
	}
	return 0;
}
