#include <string.h>
#include <openssl/aes.h>
#include <openssl/des.h>

typedef unsigned char   UC8;

#define KEY_BIT 128

int main(int argc, char *args[])
{
    static const UC8 cipher_key[AES_BLOCK_SIZE];

    //char      inputData[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    UC8 inputData[] = {'t', 'e', 's', 't'};

    UC8 encrypt[1024];
    UC8 decrypt[1024];
    UC8 temp[1024];

    int encrypt_size;

    AES_KEY enc_key, dec_key;

    UC8 iv_des[AES_BLOCK_SIZE];
    bzero(iv_des, sizeof(iv_des));

    //encrypt
    UC8 iv_aes[AES_BLOCK_SIZE];
    bzero(iv_aes, sizeof(iv_aes));

    AES_set_encrypt_key(cipher_key, KEY_BIT, &enc_key); //key setting
    AES_cbc_encrypt( inputData, encrypt, sizeof(inputData), &enc_key , iv_aes, AES_ENCRYPT); //encrypt

    FILE* fp = fopen("encrypt.txt","rw");//save textfile

    fputs(encrypt, fp);
    fgets(temp,sizeof(temp),fp);

    fclose(fp);

    //decrypt case1. (copy to variable) //암호화된 데이터를 변수에 복사한 뒤 복호화 해줄때에는 inputData의 크기가 아닌 128bit/16byte에 맞춰줘야함
    //encrypt_size = (sizeof(inputData) + AES_BLOCK_SIZE)/16 * 16;
    //memcpy(temp, encrypt, encrypt_size); //sizeof(inputData))

    //decrypt case2.- (use file variable)
    AES_set_decrypt_key(cipher_key, KEY_BIT, &dec_key);
    AES_cbc_encrypt(temp, decrypt, sizeof(inputData), &dec_key , iv_des, AES_DECRYPT);


    for (int ndx = 0; ndx < sizeof(inputData); ndx++){
        printf( "encrypt : 0x%02x\n", encrypt[ndx]);
        printf( "decrypt : 0x%02x(%c) \n", decrypt[ndx], decrypt[ndx]);
        printf("-------------------------\n");
    }

    return 0;
}
