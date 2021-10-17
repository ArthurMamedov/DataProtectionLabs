#pragma once
#include "ICryptor.h"

namespace Cryptography {
	class VigenereCipher : public Cryptography::ICryptor {
	public:
		void encrypt(std::vector<byte>& data) override;
		void decrypt(std::vector<byte>& data) override;
		void set_key(const std::string& key) override;
		size_t get_block_size() const override;
		size_t get_key_length() const override;

	private:
		size_t _block_length_;
		size_t _key_length_;
		std::vector<byte> _key_;
	};
}
