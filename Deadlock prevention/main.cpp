#include <iostream>
using namespace std;
int t;
int n;
int N; // mainigais ir vajadzigs, lai darboties ar procesiem, kuri jau pabeizda darbu (un lai counter parizi stradatu)

//funkcija kas parbauda, vai stavoklis ir dross
int CheckProcess(int process[][2]){
	int SpareResource = t;
	for (int i=0; i<n; i++){
		SpareResource -= process[i][0];
	}
	int safe; // 0 - nedross;   1 - dross
	int counter = N;
	while(counter > 0){
		safe=0;
		for(int i=0; i<n; i++){
			if(process[i][1] != 0){
				if(SpareResource + process[i][0] >= process[i][1]){
					safe = 1;
					counter--;
					SpareResource += process[i][0];
					process[i][1] = 0;
				}
			}
		}
		if(safe == 0){
			return 0;
		}
	}
	return 1;
} 

//funkcija kas pievieno resursu
void AddResource(int process[][2]){
	int testprocess[n][2];
	for (int i=0; i<n; i++){
		for (int j=0; j<2; j++){
			testprocess[i][j] = process[i][j];
		}
	}
	cout << "\nKadam procesam?(sakot ar 1.) ";
	int i;
	cin >> i;
	i--; // jo massivi numurejas sakot ar 0.
	testprocess[i][0]++;
	if(CheckProcess(testprocess) == 0) {
		cout << "\nNevar apmierinat pieprasijumus(Bus nedross stavoklis)";	
	}
	else{
		process[i][0]++;
		cout << "Dross stavoklis\n";
		if(process[i][0] == process[i][1]){
		process[i][0] = 0;
		process[i][1] = 0;
		N--;
				}
	}
}

//funkcija kas atbrivo resursu (nevajag parbaudit uz drosumu, jo dross stavoklis nevar mainities kad mes atbrivojam resursu)
void RemoveResource(int process[][2]){
	cout << "\nKadam procesam? (sakot ar 1.) ";
	int i;
	cin >> i;
	i--; // jo massivi numurejas sakot ar 0.
	process[i][0]--;
}



void ShowAll(int process[][2])
{
	int SpareResource = t;
	for (int i=0; i<n; i++){
		SpareResource -= process[i][0];
	}
	cout << "\nRezerve: " << SpareResource << "/" << t << "\nProcesi:  ";
	for(int i=0; i<n; i++){
		cout << process[i][0] << "/" << process[i][1] << "  ";
	}
	
}

int main(int argc, char** argv) {
	
	cout << "Ievadiet procesu skaitu(n): ";
	cin >>  n;
	N=n;
	cout << "Ievadiet resursa vienibu skaitu(t): ";
	cin >>  t;
	int process[n][2];
	for (int i=0; i<n; i++){
		cout << "Ievadiet " << i+1 << "-ta procesa maksimalo vajadzibu pec resursa(m): ";
		cin >> process[i][1]; 
		process[i][0] = 0;
	}
	int answer = 0;
	int ON = true;
	while (ON){
		ShowAll(process);
		cout << "\nKomandas:";
		cout << "\n1) Pieprasit resursu";
		cout << "\n2) Atrbivot resursu";
		cout <<	"\n3) Pabeigt\n";
		cin >> answer;
		switch (answer){
			case 1:
				AddResource(process);
				break;
			case 2:
				RemoveResource(process);
				break;
			case 3:
				ON = false;
				break;
		}
	}
	return 0;
}
