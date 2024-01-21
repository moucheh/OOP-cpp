#pragma once
#include <vector>
#include <string>
#include <functional>

struct Handler {
	std::string id;
	std::function<std::string(int, int)> foo;
};

std::string provjera2(
	const std::vector<Handler>&,
	const std::string&,
	const int,
	const int
);