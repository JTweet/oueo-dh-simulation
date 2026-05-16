#pragma once

#include "../gmp/include/gmp.h"
#include "../libsodium/include/sodium.h"

class DiffieHellman {
    private:
        mpz_t prime; // Prime used, controls the resulting shared secret bit length as well as the length of the private secret
        mpz_t generator;
        mpz_t privateKey; // This is the personal secret, not the resulting shared secret
        mpz_t sharedSecret; // This is the secret shared by both parties at the end of the process
        mpz_t publicKey; // Public representation of our private secret, which can be sent over an insecure channel
        mpz_t partnerPublicKey; // Public key of communication partner


        void pow(mpz_t result, const mpz_t base, const mpz_t exponent, const mpz_t modulus);
    public:
        DiffieHellman(unsigned long int generator, const char *prime);
        ~DiffieHellman();

        unsigned int getPrimeBitLength(void);
        unsigned int getPrivateKeyBitLength(void);
        void getPublicKey(char*);
        void getPrivateKey(char*);
        void getSharedSecret(char*);
        void importPartnerPublicKey(const char *publicKey);
};
