#pragma once
#include "stdafx.h"
#include "ICryptor.h"

namespace Filesystem {
	class FileEncryptor {
	public:
		void encrypt(const std::string& file_path, Cryptography::ICryptor* encryptor);
		void decrypt(const std::string& file_path, Cryptography::ICryptor* encryptor);
	private:
	};
}