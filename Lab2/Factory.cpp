#include "stdafx.h"
#include "Factory.h"

Cryptography::ICryptor* Factory::Factory::get_algorithm(std::string& algorithm)
{
    std::transform(algorithm.begin(), algorithm.end(), algorithm.begin(), [](char c) { return std::tolower(c); });
    //std::unique_ptr<Cryptography::ICryptor> res;
    if (!algorithm.compare("caesar")) {
        return new Cryptography::CaesarCipher();
    }
    else if (!algorithm.compare("vegenere"))
    {
        return new Cryptography::VigenereCipher();
    }
    else {
        throw std::runtime_error("Error: unknown algorithm!");
    }
}