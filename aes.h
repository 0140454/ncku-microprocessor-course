/*
 * Header file for AES 128-bit Encryption/Decryption
 */
#include "stdint.h"

/*
 * AES - Constants
 */
#define KEY_LENGTH              16

/*
 * AES - Public methods
 */
void Encrypt(uint8_t *data, uint8_t *key);
void Decrypt(uint8_t *data, uint8_t *key);

void EncryptECB(uint8_t *data, uint32_t blocks, uint8_t *key);
void DecryptECB(uint8_t *data, uint32_t blocks, uint8_t *key);

void EncryptCBC(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);
void DecryptCBC(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);

void EncryptCFB(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);
void DecryptCFB(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);

void EncryptOFB(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);
void DecryptOFB(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);

void EncryptCTR(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);
void DecryptCTR(uint8_t *data, uint32_t blocks, uint8_t *key, uint8_t *iv);