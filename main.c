#include "header.h"

/* Programmer name: Genevieve Kochel
Date created: December 9th 2023
Program purpose: This program implements and tests several string processing functions
File purpose: This file tests all functions for this program */

int main(void) {

	FILE* infile = fopen("input.txt", "r");
	FILE* outfile = fopen("output.txt", "w");
	
	int num_chars = 0;
	int char_returned = -1, result_fputc = 0;

	/* fgets() testing */
	char my_string_arr[100] = "";

	my_fgets(my_string_arr, 100, infile);
	
	printf("Case 1, my_fgets() - This is my_string_arr after my_fgets() is called: %s\n", my_string_arr);

	/* fputs() testing */
	num_chars = my_fputs("I am in CPTS 121", outfile);
	printf("\nCase 1, my_fputs() - This is the return/# chars printed of myfputs() with the string literal 'I am in CPTS 121': %d\n", num_chars);

	/* fgetc() testing */
	char_returned = my_fgetc(infile);

	printf("\nCase 1, my_fgetc() - my_fgetc() returns: %d or the letter '%c'\n", char_returned, char_returned);

	/* fputc() testing */
	result_fputc = my_fputc('!', outfile);

	printf("\nCase 1, my_fputc(): fputc() printed the character '%c' to the outfile or the ascii value: %d\n", result_fputc, result_fputc);

	/* gets() testing */
	char new_string[100] = ""; // testing string for mygets

	printf("\nCase 1, my_gets() - Type a message to store via my_gets(): ");
	my_gets(new_string);

	printf("\nThe new_string array contains the following via my_gets(): %s\n", new_string);

	putchar('\n'); // for output window formatting purposes

	/* puts() testing */
	int returned = my_puts("Case 1, my_puts(): Happy Holidays!");
	printf("\nThis is the number of characters my_puts() printed from the string literal 'Case 1, my_puts(): Happy Holidays!': %d\n", returned);

	/* getchar() testing */
	printf("\nCase 1, my_getchar(): Please enter a character to test the my_getchar() function: ");
	int ascii_val = my_getchar();
	printf("\nThis is the ascii value returned by my_getchar() or the character '%c': %d\n", ascii_val, ascii_val);

	printf("\n**** Continue the program to print the outputs for the rest of the test cases; Note: The screen will clear ****");

	putchar('\n'); // for output window formatting purposes
	system("pause");
	system("cls");


	/* putchar() testing */
	printf("\nCase 1, my_putchar(): This is the result of my_putchar() with the character 'G': ");
	my_putchar('G');

	/* strcpy() testing */
	char* source = "Go Cougs";
	char destination[100] = "Go Huskies";

	printf("\nThis is destination string literal 'Go Huskies' before my_stringcpy() is called: %s\n", destination);

	my_strcpy(destination, source);

	printf("\nCase 1, my_strcpy(): This is the destination string literal 'Go Huskies' after my_strcpy() is called\n" 
		"with the source string literal 'Go Cougs': ");
	for (int index = 0; index < 10; ++index)
	{
		if (destination[index] == '\0')
		{
			printf("/0"); // print this to indicate when null character is in array while testing
		}
		else {
			printf("%c", destination[index]);
		}
	}

	putchar('\n'); // for output window formatting purposes

	/* strncpy () testing */

	char* source2 = "!!!";
	char destination2[100] = "CPTS 121 is cool";

	printf("\n\nThis is destination2 string literal before any calls to my_strncpy(): %s\n", destination2);

	my_strncpy(destination2, source2, 5);

	printf("\nCase 1, my_strncpy(): This is destination2 string literal 'CPTS 121 is cool' after strncpy()\n"
		"if the source string literal '!!!' is less than 'n': ");

	for (int i = 0; i < 16; ++i) // print out character by character
	{
		if (destination2[i] == '\0')
		{
			printf("/0"); // print this to indicate when null character is in array while testing
		}
		else {

			printf("%c", destination2[i]);
		}
	}

	putchar('\n'); // for output window formatting purposes

	my_strncpy(destination2, "eggs", 4);

	printf("\nCase 2, my_strncpy(): This is destination2 string literal 'CPTS 121 is cool' after strncpy()\n"
		"if the source string literal 'eggs' is equal in length to 'n': ");

	for (int i = 0; i < 16; ++i) // print out character by character
	{
		if (destination2[i] == '\0')
		{
			printf("/0"); // print this to indicate when null character is in array while testing
		}
		else {
			printf("%c", destination2[i]);
		}

	}

	putchar('\n'); // for output window formatting purposes

	/* strcat() testing */
	char* source3 = "Let it snow!";
	char destination3[100] = "Holly Jolly Christmas";

	printf("\n\nThis is destination string literal 'Holly Jolly Christmas' before any calls to my_strcat(): %s\n", destination3);

	my_strcat(destination3, source3);

	putchar('\n'); // for output window fomatting purposes

	printf("\nCase 1, my_strcat(): This is destination3 string literal\n"
		"'Holly Jolly Christmas' after my_strcat() with source string literal 'Let it snow!': %s\n", destination3); 

	/* strncat() testing */

	char* source4 = "abcdefghij";
	char destination4[100] = "Hello";

	printf("\nThis is destination string (literal) before any calls to strncat(): %s\n", destination4);

	my_strncat(destination4, source4, 3);

	printf("\nCase 1, my_strncat(): This is destination4 string (literal) 'Hello' after my_strncat()\n"
		"with source string (literal) 'abcdefghij' when n = 3: %s\n", destination4);

	my_strncat(destination4, "World", 10);

	printf("\nCase 2, my_strncat(): This is destination4 string (literal) after a second call to\n"
		"my_strncat() with source string (literal) 'World' when n = 10: %s\n", destination4);

	/* strcmp() testing */
	char* s1 = "Aba";
	char* s2 = "Aa";

	int result = my_strcmp(s1, s2);

	printf("\nCase 1, my_strcmp(): The result of my_strcmp() when s1 is 'Aba' and s2 is 'Aa': % d\n", result);

	 result = my_strcmp("Dog", "Dog");

	printf("\nCase 2, my_strcmp(): The result of my_strcmp() when s1 (literal) is 'Dog' and s2 (literal) is 'Dog': % d\n", result);

	result = my_strcmp("Aaa", "Aba");

	printf("\nCase 3, my_strcmp(): The result of my_strcmp() when s1 (literal) is 'Aaa' and s2 (literal) is 'Aba': % d\n", result);


	/* strncmp() testing */

	char* new_s1 = "daz";
	char* new_s2 = "daa";

	int result2 = my_strncmp(new_s1, new_s2, 2);
	
	printf("\nCase 1, my_strncmp(): The result of my_strncmp() when s1 (literal) is 'daz' and s2 (literal) is 'daa' and n = 2: %d\n", result2);

	result2 = my_strncmp(new_s1, new_s2, 3);
	printf("\nCase 2, my_strncmp(): The result of my_strncmp() when s1 (literal) is 'daz' and s2 (literal) is 'daa' and n = 3: %d\n", result2);

	result2 = my_strncmp(new_s1, new_s2, 10);
	printf("\nCase 3, my_strncmp(): The result of my_strncmp() when s1 (literal) is 'daz' and s2 (literal) is 'daa' and n = 10: %d\n", result2);

	/* strlen() testing */
	result = my_strlen(new_s1);

	printf("\nCase 1 - my_strlen(): The length of the new_s1 string (literal) 'daz' is: %d", result);

	result = my_strlen("");

	putchar('\n'); // for output window fomatting purposes

	printf("\nCase 2 - my_strlen(): The length of an empty string (literal) '' is: %d", result);



	fclose(infile);
	fclose(outfile);

	putchar('\n');

	return 0;
}
