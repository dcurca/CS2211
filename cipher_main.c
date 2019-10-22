#include <stdio.h>
#include <stdlib.h>

/*Dana Curca, 250976773, dcurca
*Method that calls functions in cipher.c and produces encrypting
*and decrypting analysis
*/
int main() {

	char plaintext[100], cipher, word;
	int key;
	printf("Input Plaintext:\n");
	fgets(plaintext, 100, stdin);

	printf("Available Ciphers:\n1)\tCaesar\n2)\tVigenere\n");
	printf("Choose your option: ");
	scanf("%c", &cipher);
	printf("Plaintext: \n");
	puts(plaintext);

	if(cipher == 1){ 
		printf("Please enter the key: ");
		int check = scanf("%d", &key);

		if(check != 1){
			printf("Error: Invalid Key");
			return 1; 
		}
		else{
			printf("Ciphertext: \n");
			char *encrypt = caesar_encrypt(plaintext,key);
			printf("%s",encrypt);
			printf("\n");
			printf("Decrypted plaintext: \n");
			char *decrypt = caesar_decrypt(encrypt,key);
			printf("%s",decrypt);

			double letters[26];
			freq_analysis(plaintext, letters);
			for(int i=0; i<26; ++i){ 
				if((i % 4) == 0){
					printf("\n");
				}
				printf("%c ----- %;f %%\t",i+'a', letters[i]);
			}
			free(encrypt);
			free(decrypt);
		}
	else if(cipher == 2){
		printf("Input string key: ");
		scanf("%s", &word);
		if(getchar() == ' '){
			printf("Error: Invalid input");
			return 2; 
		} 
		printf("\n");
		printf("Plaintext: \n%s", plaintext);
		printf("\n");
		printf("Ciphertext: \n");
		char *vencrypt = vigen_encrypt(plaintext, &key); 
		printf("\n"); 
		printf("Decrypted Plaintext: \n"); 
		char *vdecrypt = vigen_decrypt(vencrypt,&key); 
		printf("%s",vdecrypt); 

		double letters[26];
		freq_analysis(plaintext, letters); 
		for(int i=0; i<26; ++i){
			if((i % 4) == 0){
				printf("\n");
			}
			printf("%c" ----- %lf %%\t,i+'A',letters[i]);
		}
		printf("\n"); 
		free(vencrypt);
		free(vdecrypt);
	}
	else { 
		printf("Bad Input: Not an Option"); 
		return 3;
	}
}

