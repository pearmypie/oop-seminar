#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};


class Student
{	
	string nume;
	char* adresa;
	int varsta;
	int an_studii;
public:
	//constructori
	Student()
	{

	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	// CERINTA
	void set_nume(string nume) {
		this->nume = nume;
	}

	void set_adresa(char* _adresa) {
		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);
	}

	void set_varsta(int varsta) {
		if (varsta < 18 || varsta > 100) {
			throw "Invalid";
		}
		else
			this->varsta = varsta;
	}

	void set_an_studii(int _an) {
		if (_an < 1 || _an > 4) {
			throw "Invalid";
		}
		else
			this->an_studii = _an;
	}

   //setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete this->adresa;
		delete this->note;
	}

private:
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;
};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	Student s0;

	s0.set_nume("Anghel Mihai");

	s0.set_adresa((char*)"Bucuresti, Sector 1");

	s0.set_varsta(21);
	s0.set_an_studii(2);

	//de ce este generata eroarea?
	//s0.note = new int[20];

	s0.set_numar_matricol("A689867");
	s0.set_finantare(finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);


	Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	//Student s2 = s1;
	//s2.nume = "Ionescu C";
}
