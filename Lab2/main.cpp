#include "stdafx.h"
#include "FileEncryptor.h"
#include "Factory.h"

bool shall_encrypt(std::string& mode) {
	std::transform(mode.begin(), mode.end(), mode.begin(), [](char c) { return std::tolower(c); });
	if (!mode.compare("encrypt") || !mode.compare("e")) {
		return true;
	} else if (!mode.compare("decrypt") || !mode.compare("d")) {
		return false;
	} else {
		throw std::runtime_error("Wrong encryption mode.");
	}
}

int main()
{
	std::string algorithm;
	Filesystem::FileEncryptor encryptor;
	std::string file_path;
	std::string key;
	std::string mode;

	try {
		std::cout << "Enter the algorithm: "; std::cin >> algorithm;
		std::unique_ptr<Cryptography::ICryptor> cipher; cipher.reset(Factory::Factory::get_algorithm(algorithm));
		std::cout << "Encrypt or decrypt? "; std::cin >> mode;
		std::cout << "Enter the file path: ";   std::cin >> file_path;
		std::cout << "Enter the key, please: "; std::cin >> key;
		cipher->set_key(key);

		if (shall_encrypt(mode)) {
			encryptor.encrypt(file_path, cipher.get());
			std::cout << "Your data encrypted successfully!" << std::endl;
		} else {
			encryptor.decrypt(file_path, cipher.get());
			std::cout << "Your data decrypted successfully!" << std::endl;
		}
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}