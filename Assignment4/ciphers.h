/* Dana Curca, 250976773, dcurca
*Header file for ciphers.c
*/

/*Function caesar_encrypt
*
*Takes a null terminating string and key as argumnets,
*result is a new dynamically allocated null terminated string. 
*Shifts each letter in plaintext by amount given in key. 
*Function returns null terminated string whihch is the same length
*as the plaintext string. The string should be allocated on heap.
*/
char * caesar_encrypt(char *plaintext, int key);

/*Function caesar_decrypt
*
*Takes a null terminated string and key as arguments,
*result is a new dynamically allocated null terminated string.
*Shifts letter in the other direction by the amount in the key.
*Function returns null terminated string which is the same length 
*as the plaintext string. The string should be allocated on heap.
*/
char * caesar_decrypt(char *ciphertext, int key); 

/*Function vigen_encrypt
*
*Takes a null terminated string plaintext and key as arguments, 
*result is new dynamically allocated null terminated string.
*Letter in ciphertext is shifted by the letter in the same place in the key.
*Function returns null terminated string which is the same length, 
*as the plaintext string. The string should be allocated on heap. 
*/
char * vigen_encrypt(char *plaintext, char *key);

/*Function vigen_decrypt
*
*Takes a null terminated string plaintext and key as arguments, 
*result is new dynamically allocated null terminated string. 
*Letter in ciphertext is shifted in the other direction by the value 
*of the letter in the same place in the key.
*Function returns null terminated string which is the same length, 
*as the plaintext string. The string should be allocated on heap. 
*/
char * vigen_decrypt(char *ciphertext, char *key); 

/*Function freq_analysis
*Takes a null terminated stirng ciphertext and an array of doubles, 
*function has no return values instead it sets the values of the letters 
*in the array. This function performs a frequency analysis, it counts
*the number of occurrences of each letter.
*/
void freq_analysis(char *ciphertext, double letters[26]);
