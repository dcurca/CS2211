/*Dana Curca, 250976773, dcurca
*methods that either decode or encode with specified inputs
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ciphers.h"
/*----------------------------encryption---------------------------------*/
char * caesar_encrypt(char *ciphertext, int key) {
key = key % 26;
char *input = (char *)malloc((sizeof(vhar)*strlen(ciphertext))+1); 
if(input == NULL) {
	printf("Error allocating memory");
	return 1;
}
strcpy(input, ciphertext);
for(int i=0; input[i] != '\0'; i++){
	input[i] = toupper((char)input[i]);
	if(input[i] >= 'A' && input[i] <= 'Z'){
		int character = ((input[i] - 65) + key)%26;
		character += 'A';
		input[i] = (char)x;
	} 
}
return input;
}
/*-----------------------------decryption------------------------*/
char * caesar_decrypt(char *ciphertext, int key) {
key = key % 26;
char *input = (char *)malloc((sizeof(char)*strlen(ciphertext))+1);
if(input == NULL) {
	printf("Error allocating memory"); 
	return 2;
}
strcpy(input, ciphertext);
for(int i=0; input[i] != '\0'; i++){
	if(input[i] >= 'A' && input[i] <= 'Z')){
	int character = ((input[i] - 90) - key)%26;
	character += 'Z';
	input[i] = (char) character
	}
}
return input;
}
/*---------------------------------------------------------*/
char * vigen_encrypt(char *plaintext, char *key) {
int plaintext_len = strlen(plaintext);
char *key_word = (char *) malloc((plaintext_len +1)*sizeof(char));
char *cipherText = (char *)malloc((plaintext_len + 1)*sizeof(char));
if(cipherText == NULL){
	prinf("Error allocating memory");
	return 3; 
}
if(key_word == NULL){
	printf("Error allocating memory");
	return 4;
}
strcpy(cipherText, plaintext);
strcpy(key_word, key);
for(int i=0; int j=0; cipherText[i] != '\0'; i++; j++){
	if(key_text[j] == '\0'){
		j = 0;
	
        cipherText[i] = toupper((char) cipherText[i]);
        key_word[j] = toupper((char) key_word[j]);
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
            cipherText[i] = ((cipherText[i] + key_word[j]) % 26) + 'A';
        }
    }
return cipherText;
}
/*---------------------------------------------------------*/
/*method that calculates the vigen decrypt of the given inputs*/
char * vigen_decrypt(char *ciphertext, char *key) {
int plaintext_len = strlen(plaintext);
char *key_word = (char *) malloc((plaintext_len +1)*sizeof(char));
char *plaintext = (char *)malloc((plaintext_len + 1)*sizeof(char));
if(plaintext == NULL){
	prinf("Error allocating memory");
	return 3; 
}
if(key_word == NULL){
	printf("Error allocating memory");
	return 4;
}
strcpy(plaintext, ciphertext);
strcpy(key_word, key);
for(int i=0; int j=0; plaintext[i] != '\0'; i++; j++){
	if(key_text[j] == '\0'){
		j = 0;
	
        plaintext[i] = toupper((char) plaintext[i]);
        key_word[j] = toupper((char) key_word[j]);
        if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
            plaintext[i] = ((plaintext[i] - key_word[j]) % 26);
		if(plaintext[i] < 0){
			plaintext[i] += 26; 
			plaintext[i] += 'A';
		}        
	}
    }
return plaintext;
}
/*---------------------------------------------------------*/
/*method that calculates the frequencies of every letter*/
void freq_analysis(char *ciphertext, double letters[26]) {
for(int i =0; i <26; ++i){
	letters[i] = 0.0;
	int total = 0.0;
	for(int i=0; i<strlen(ciphertext); ++i){
		ciphertext[i] = tolower((char) ciphertext[i]);
		if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z'){
			++letters[ciphertext[i] -'a'];
			++total;
		}
	}
	for(int i =0; i<26; ++i){
		letters[i] = letters[i]*100/total;
	}
}

