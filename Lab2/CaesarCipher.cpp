#include "stdafx.h"
#include "CaesarCipher.h"

namespace Cryptography {
	void Cryptography::CaesarCipher::encrypt(std::vector<byte>& data) {
		data[0] += _key_;
	}

	void Cryptography::CaesarCipher::decrypt(std::vector<byte>& data) {
		data[0] -= _key_;
	}

	void CaesarCipher::set_key(const std::string& key) {
		if (key.size() != _block_length_) {
			std::stringstream ss;
			ss << "CeasereCipher error: key size must be " << _key_length_ << " symbol(s)";
			throw std::runtime_error(ss.str());
		}
		_key_ = key[0];
	}

	size_t Cryptography::CaesarCipher::get_block_size() const {
		return _block_length_;
	}

	size_t Cryptography::CaesarCipher::get_key_length() const {
		return _key_length_;
	}
}
