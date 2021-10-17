#pragma once
#include "stdafx.h"
#include "ICryptor.h"
#include "VigenereCipher.h"
#include "CaesarCipher.h"

namespace Factory {
	class Factory
	{
	public:
		static Cryptography::ICryptor* get_algorithm(std::string& algorithm);
	};
}