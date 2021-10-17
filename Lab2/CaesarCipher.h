#pragma once
#include "stdafx.h"
#include "ICryptor.h"

namespace Cryptography {
    class CaesarCipher : public ICryptor {
    public:
        virtual void encrypt(std::vector<byte>& data) override;
        virtual void decrypt(std::vector<byte>& data) override;
        virtual void set_key(const std::string& key) override;
        virtual size_t get_block_size() const override;
        virtual size_t get_key_length() const override;
    
    private:
        byte _key_;
        const size_t _key_length_ = 1;
        const size_t _block_length_ = 1;
    };
}