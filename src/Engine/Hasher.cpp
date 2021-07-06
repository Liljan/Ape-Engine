#include "Engine/Hasher.hpp"

Id Hasher::Hash(const std::string& str) const
{
	return static_cast<Id>(m_Hasher(str));
}
