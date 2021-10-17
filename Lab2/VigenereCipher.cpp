#include "stdafx.h"
#include "VigenereCipher.h"

void Cryptography::VigenereCipher::encrypt(std::vector<byte>& data) {
    auto key_iter = _key_.cbegin();
    std::for_each(data.begin(), data.end(), [&key_iter](byte& chr) {
        chr += *key_iter++;
    });
}

void Cryptography::VigenereCipher::decrypt(std::vector<byte>& data) {
    auto key_iter = _key_.cbegin();
    std::for_each(data.begin(), data.end(), [&key_iter](byte& chr) {
        chr -= *key_iter++;
    });
}

void Cryptography::VigenereCipher::set_key(const std::string& key) {
    if (key.size() < 1) {
        throw std::runtime_error("VigenereCipher error: Key length is 0.");
    }
    _block_length_ = _key_length_ = key.size();
    _key_.resize(_key_length_);
    std::memcpy(_key_.data(), key.data(), _key_length_);
}

size_t Cryptography::VigenereCipher::get_block_size() const {
    return _block_length_;
}

size_t Cryptography::VigenereCipher::get_key_length() const
{
    return _key_length_;
}
