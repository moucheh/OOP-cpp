#pragma once
#include <string>
#include <vector>
#include <list>

struct Predmet {
	std::string naziv;
	std::string odsjek;
};

struct OcjenaIzPredmeta {
	int ocjena{};
	std::list<Predmet>::const_iterator predmet;
};

struct Student {
	std::string brojIndeksa;
	std::string ime;
	std::string prezime;
	std::string grad;
	std::vector<OcjenaIzPredmeta> ocjene;
};

int unesi_ocjenu();
void dodaj_ocjenu(
	const std::list<Predmet>&,
	Student&
);
void unesi_predmet(std::list<Predmet>&);
void unesi_studenta(
	std::list<Student>&,
	std::list<Predmet>&
);
void ispisi_studente(const std::list<Student>&);
void edituj_studenta(
	const std::list<Predmet>&,
	std::list<Student>&
);
