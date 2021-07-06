#pragma once

#include "Engine/Datatypes.hpp"

#include <functional>
#include <string>

class Hasher
{
public:

	static Hasher& Instance()
	{
		static Hasher instance;
		return instance;
	}

	Id Hash(const std::string& str) const;

private:
	Hasher() = default;

	std::hash<std::string> m_Hasher;
};
