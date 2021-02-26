#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;
const int k = 100;

struct Studentas {
	string var;    //vardas
	string pav;    //pavarde
	int nkiek;
	vector <int> nd;     //namu darbu rezultatas
	int egz;    //egzamino rezultatas
	double vid;
	double med;
	
};


int main(){
		int k;
//	double sum = 0;
	int r;
	
	cout << "Kiek studentu ivesite? ";
	do {
	cin >> k;
	} while (k <= 0);
	
	vector <Studentas> S;
	
	srand ( time ( NULL ));
	
	char ats;
	
	for (int i = 0; i < k; i++){
        S.push_back(Studentas());
		cout << "Iveskite studento varda ir pavarde ";
        S.push_back(Studentas());
		cin >> S[i].var >> S[i].pav;
		cout << endl;
		
		cout << "Ar ivesite namu darbu kieki? (t/n) ";
		cin >> ats;
		
		if (ats == 't' || ats == 'T') {                          //zinomas namu darbu kiekis
			cout << "Iveskite namu darbu kieki ";
		    cin >> S[i].nkiek;
		    cout << endl;
	    	cout << "Ar ivesite namu darbu rezultatus? (t/n) ";
		    cin >> ats;
		    
		    if (ats == 't' || ats == 'T'){                       //zinomi namu darbu rezultatai
		    	cout << "Iveskite namu darbu rezultatus ( > 0) ";
		    	for (int j = 0; j < S[i].nkiek; j++){
		    		int paz;
					do{
						cin >> paz;
						S[i].nd.push_back(paz);
					} while (paz < 1 || paz > 10);
					
					}
				cout << endl;
			}
			if (ats == 'n' || ats == 'N'){
				cout << "Sugeneruoti namu darbu rezultatai ";   //nezinomi namu darbu rezultatai
				for (int j = 0; j < S[i].nkiek; j++){
					int paz = rand() % 10 + 1;
					S[i].nd.push_back(paz);
					cout << S[i].nd[j] << " ";
				} cout << endl;
			}
		}
		
		
		else if (ats == 'n' || ats == 'N'){                          //nezinomas namu darbu kiekis
			cout << "Ar ivesite namu darbu rezultatus? (t/n) ";
			cin >> ats;
			
			if (ats == 't' || ats == 'T'){                      //zinomi namu darbu rezultatai
				char paz; 
				cout << "Iveskite namu darbu rezultatus ";
				do {
				S[i].nkiek = 1;
				for (int j = 0; j < S[i].nkiek; j++){
					cin >> paz;
					S[i].nd.push_back(paz);
				//	cout << S[j].nd;
					S[i].nkiek++;
				}
				} while (paz != '\n');
			}	
			
			if (ats == 'n' || ats == 'N'){
				S[i].nkiek = rand()% 10 + 1;
				cout << "Sugeneruoti pazymiai ";
				for (int j = 0; j < S[i].nkiek; j++){
					int paz  = rand() % 10 + 1;
					S[i].nd.push_back(paz);
					cout << S[i].nd[j] << " ";
				}
			}	
		}
		
		
		cout << "Ar ivesite egzamino rezultata? (t/n) ";       //egzaminas
		cin >> ats;
	
		if (ats == 't' || ats == 'T'){ 
		cout << "Iveskite egzamino rezultata ( > 0) "    ;   
		int paz;              
		do {
		cin >> paz;
		S[i].egz = paz;
		} while (paz <1 || paz > 10);
		}
	
		if (ats == 'n' || ats == 'N'){
		cout << "Sugeneruotas egzamino rezultatas ";
		S[i].egz = rand() % 10 + 1;
		cout << S[i].egz;
		}
		cout << endl;
	}
	
	

//vidurkis
	double sum = 0;
	double nv;
   for (int i = 0; i < k; i++){
   	  for (int j = 0; j < S[i].nkiek; j++){
   	  	sum += S[i].nd[j];
	 }
	S[i].vid = (sum / S[i].nkiek)* 0.4 + S[i].egz * 0.6;
}


//pazymiu rikiavimas
	for (int i = 0; i < k; i++){
		for (int j = 0; j < S[i].nkiek - 1; j++){
			for (int x = j + 1; x < S[i].nkiek; x++){
				if (S[i].nd[j] < S[i].nd[x]) swap (S[i].nd[j], S[i].nd[x]);
		}
}}
//mediana
	double median;
	int d = 0;
    for (int i = 0; i < k; i++){
    	for (int j = 0; j < S[i].nkiek; j++){
    	d = S[i].nkiek;
		if (S[i].nkiek % 2 != 0) median = S[i].nd[d / 2];
    else median = (S[i].nd[d / 2 - 1] + S[i].nd[d / 2]) / 2.0;
	}
	S[i].med = median * 0.4 + S[i].egz * 0.6;
    }



//	char ats;
	cout << "Spausdinti vidurki ar mediana? (v/m) ";
	cin >> ats;
	cout << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15); 
	if (ats == 'v' || ats == 'V') cout << "Galutinis (vid.)" << endl;
	if (ats == 'm' || ats == 'M') cout << "Galutinis (med.)" <<endl;
	cout << left;
	for (int i = 0; i < 45; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < k; i++){
		cout << left << setw(12) << S[i].var << setw(15) << S[i].pav << setw(15) << fixed << setprecision(2);
		if (ats == 'v' || ats == 'V') cout << S[i].vid << endl;
		if (ats == 'm' || ats == 'M') cout << S[i].med << endl;
	}

	
}
