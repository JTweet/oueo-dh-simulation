#include <dh/dh.hpp>

DiffieHellman::DiffieHellman(unsigned long int generator, const char *prime) {
    // MPZ integers require initialization
    mpz_init_set_str(DiffieHellman::prime, prime, 16);
    mpz_init_set_ui(DiffieHellman::generator, generator);
    mpz_init(DiffieHellman::privateKey);
    mpz_init(DiffieHellman::sharedSecret);
    mpz_init(DiffieHellman::publicKey);
    mpz_init(DiffieHellman::partnerPublicKey);

    // The prime length is returned as bits, randombytes_buf excepts full bytes
    int randomnessBytes = DiffieHellman::getPrimeBitLength() / 8;
    // randombytes_buf output is not null-terminated, no need to adjust for this
    char *randomBuffer = (char *)malloc(randomnessBytes * sizeof(char));
    // Fill buffer with random values
    randombytes_buf(randomBuffer, randomnessBytes);
    mpz_import(DiffieHellman::privateKey, randomnessBytes, 1, 1, 0, 0, randomBuffer);
    // Release allocated memory
    free(randomBuffer);

    // Calculate the public key
    mpz_powm(DiffieHellman::publicKey, DiffieHellman::generator, DiffieHellman::privateKey, DiffieHellman::prime);
}

DiffieHellman::~DiffieHellman() {
    mpz_clear(DiffieHellman::prime);
    mpz_clear(DiffieHellman::generator);
    mpz_clear(DiffieHellman::privateKey);
    mpz_clear(DiffieHellman::sharedSecret);
    mpz_clear(DiffieHellman::publicKey);
    mpz_clear(DiffieHellman::partnerPublicKey);
}

void DiffieHellman::pow(mpz_t result, const mpz_t base, const mpz_t exponent, const mpz_t modulus) {
    mpz_powm(result, base, exponent, modulus);
}

unsigned int DiffieHellman::getPrimeBitLength(void) {
    return static_cast<unsigned int>(mpz_sizeinbase(DiffieHellman::prime, 2));
}

unsigned int DiffieHellman::getPrivateKeyBitLength(void) {
    return static_cast<unsigned int>(mpz_sizeinbase(DiffieHellman::privateKey, 2));
}

void DiffieHellman::getPublicKey(char* outputBuffer) {
    mpz_get_str(outputBuffer, 16, DiffieHellman::publicKey);
}

void DiffieHellman::getPrivateKey(char* outputBuffer) {
    mpz_get_str(outputBuffer, 16, DiffieHellman::privateKey);
}

void DiffieHellman::getSharedSecret(char* outputBuffer) {
    mpz_get_str(outputBuffer, 16, DiffieHellman::sharedSecret);
}

// Allow importing the partners public key. This function also triggers the calculation of the shared secret
void DiffieHellman::importPartnerPublicKey(const char *publicKey) {
    mpz_set_str(DiffieHellman::partnerPublicKey, publicKey, 16);
    mpz_powm(DiffieHellman::sharedSecret, DiffieHellman::partnerPublicKey, DiffieHellman::privateKey, DiffieHellman::prime);
}