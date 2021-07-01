#include "Engine/Hasher.hpp"

uint32 Hasher::Hash(const std::string& str) const
{
	return static_cast<uint32>(m_Hasher(str));
}
