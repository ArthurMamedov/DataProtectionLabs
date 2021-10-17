#include "stdafx.h"
#include "FileEncryptor.h"
#include "ICryptor.h"

namespace Filesystem {
	void FileEncryptor::encrypt(const std::string& file_path, Cryptography::ICryptor* encryptor)
	{
		const size_t block_size = encryptor->get_block_size();
		std::ifstream file_in(file_path, std::ios_base::in | std::ios_base::binary);
		std::ofstream file_out(file_path + ".enc", std::ios_base::out | std::ios_base::binary);
		if (!file_in.is_open() || !file_out.is_open()) {
			throw std::runtime_error("File opening failed");
		}
		std::vector<Cryptography::byte> buffer(block_size, 0);
		while (file_in.read(reinterpret_cast<char*>(buffer.data()), block_size)) {
			encryptor->encrypt(buffer);
			file_out.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
		}
		if (block_size != 1) {
			std::fill(buffer.begin() + file_in.gcount(), buffer.end(), 0);
			encryptor->encrypt(buffer);
			file_out.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
			char bytes_in_last_block = static_cast<char>(file_in.gcount());
			file_out.write(&bytes_in_last_block, 1);
		}
	}

	void FileEncryptor::decrypt(const std::string& file_path, Cryptography::ICryptor* encryptor)
	{
		const size_t block_size = encryptor->get_block_size();
		std::ifstream file_in(file_path, std::ios_base::in | std::ios_base::binary);
		std::ofstream file_out(file_path + ".dec", std::ios_base::out | std::ios_base::binary);
		if (!file_in.is_open() || !file_out.is_open()) {
			throw std::runtime_error("File opening failed");
		}
		std::vector<Cryptography::byte> buffer(block_size, 0);
		char last_bytes[2];
		while (file_in.read(reinterpret_cast<char*>(buffer.data()), block_size)) {
			encryptor->decrypt(buffer);
			auto current = file_in.tellg();
			if (block_size != 1 && !file_in.read(last_bytes, 2)) {
				file_out.write(reinterpret_cast<char*>(buffer.data()), last_bytes[0]);
				break;
			} else {
				file_out.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
				file_in.seekg(current);
			}
		}

	}
}