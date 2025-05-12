#pragma once
#include "Student.hpp"
#include <iostream>
#include <limits>
#include <list>
#include <string>

#if _WIN32
	#include <conio.h>
#else
	#include <cstdlib>
#endif

void clrscr();

const int unesi_izbor(const int);
int menu();
int edit_menu();
void fixCin();

bool provjeri_da_li_predmet_postoji(
	const std::list<Predmet>&,
	const std::string&
);
bool provjeri_da_li_student_postoji(
	const std::list<Student>&,
	const std::string&
);