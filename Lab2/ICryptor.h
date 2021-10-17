#pragma once
#include "stdafx.h"

namespace Cryptography {
	struct Block {
		uint32_t length;
		uint8_t* data;
	};

	using byte = uint8_t;

	class ICryptor {
	public:
		virtual void encrypt(std::vector<byte>& data) = 0;
		virtual void decrypt(std::vector<byte>& data) = 0;
		virtual void set_key(const std::string& key) = 0;
		virtual size_t get_block_size() const = 0;
		virtual size_t get_key_length() const = 0;
		virtual ~ICryptor() = default;
	};
}