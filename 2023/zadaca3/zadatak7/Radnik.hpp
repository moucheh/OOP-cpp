#pragma once
#include <string>
#include <list>
#include <stdexcept>

struct Radnik {
	std::string ime;
	double plata;
	int godine;
};

bool daLiPostojiRadnik(const std::list<Radnik>&, const std::string&);