#pragma once

#include "utils.h"

#include <functional>

std::string solve(
	int day, int part,
	const std::function<std::string(const std::vector<std::string>&)>& solver
);
