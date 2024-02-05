#include "header.h"

/* Programmer name: Genevieve Kochel 
Date created: December 9th 2023
Program purpose: This program implements and tests several string processing functions
File purpose: This file contains all function declarations */

char* my_fgets(char* s, int n, FILE* stream)
{

	int char_count = 0;
	char c = '\0';

		for (; !feof(stream) && char_count < n; ++s, ++char_count) 
		{
			c = getc(stream);

			*s = c;

			if (c == '\n')
			{
				break;
			}

		}

		// append null character after done reading 
		*s = '\0';
	
		if (char_count > 0)
		{
			return s;
		}
		else {
			return NULL;
		}
}

int my_fputs(const char* s, FILE* stream)
{
	int char_count = 0;

	if (stream == NULL)
	{
		return MY_EOF;
	}

	for (; *s != '\0'; ++s, ++char_count)
	{
		fprintf(stream, "%c", *s);
	}

	return char_count;
}

int my_fgetc(FILE* stream)
{
	char c = '\0';

	if (feof(stream) || fscanf(stream, "%c", &c) == EOF) // while not at end of file and if fscanf returns EOF..there was an error reading
	{
		return MY_EOF;
	}

	return c;

}

int my_fputc(int c, FILE* stream)
{
	if (fprintf(stream, "%c", c) == EOF) 
	{
		return MY_EOF;
	}

	return c;
}

char* my_gets(char* s)
{
	char c = '\0';

	
	while (c != '\n')
	{
		scanf("%c", &c);
		if (c == '\n')
		{
			break;
		}
		*s = c;

		++s;
	}
	*s = '\0'; // add null character to end of array

	return s;
}

int my_puts(const char* s)
{
	int char_count = 0;

	while (*s != '\0')
	{
		printf("%c", *s);
		++char_count;
		++s;
	}

	putc('\n', stdout);
	++char_count;

	return char_count;
}

int my_getchar(void)
{
	char c = '\0';

	fscanf(stdin, "%c", &c); // could also use scanf() here

	return c;
}

int my_putchar(int c)
{
	printf("%c", c);

	return c;
}

char* my_strcpy(char* destination, const char* source)
{

	while (*source != '\0')
	{
		*destination = *source;

		++destination;
		++source;
	}

	*destination = '\0'; // copy over null character

	return destination;

}


char* my_strncpy(char* destination, const char* source, int n)
{
	int chars_copied = 0, index = 0, length = 0;

	// determine length of source
	for (; *(source + length) != '\0'; ++length);

	length++; // + 1 to account for length including null character

	for (; chars_copied < n; ++chars_copied, ++index)
	{
		if (*(source + index) == '\0') // at end of source and n characters haven't been copied
		{
			*(destination + index) = *(source + index); // copy over null character then break
			++chars_copied;
			++index;
			break;
		}
		
		*(destination + index) = *(source + index);
	}

	if (length < n)
	{
		for (; length != n; ++length, ++index)
		{
			*(destination + index) = '\0'; // copy null until n characters have been copied
		}

	}
	

	return destination;

}

char* my_strcat(char* destination, const char* source)
{
	// find index of null character in destination
	int length = 0, dest_index = 0, index = 0;

	for (; *(destination + length) != '\0'; ++length);

	dest_index = length;

	for (; *(source + index) != '\0'; ++index, ++dest_index)
	{
		*(destination + dest_index) = *(source + index);
	}

	*(destination + dest_index) = '\0'; // append null character

	return destination;
}

char* my_strncat(char* destination, const char* source, int n)
{
	int length = 0, dest_index = 0, index = 0, chars_appen = 0;

	for (; *(destination + length) != '\0'; ++length); // find index to start appending to 

	dest_index = length;

	for (; *(source + index) != '\0' && chars_appen < n; ++chars_appen, ++index, ++dest_index)
	{

		*(destination + dest_index) = *(source + index);
	}

	*(destination + dest_index) = '\0'; // append null character

	return destination;
}

int my_strcmp(const char* s1, const char* s2)
{
	int compare = 1, s1_len = 0, s2_len = 0;

	for (; *(s1 + s1_len) != '\0'; ++s1_len); // determine length of s1, does not include null char
	for (; *(s2 + s2_len) != '\0'; ++s2_len);// determine length of s2, does not include null char

	for (; *s1 != '\0' && *s2 != '\0'; ++s1, ++s2)
	{
		if (*s1 > *s2)
		{
			compare = -1;
			return compare;

		}
		else if (*s2 == *s1 && s1_len == s2_len) // only can be same string if have same length
		{

			compare = 0;

		}
		else if (*s2 > *s1) // *s2 > *s1
		{
			compare = 1;
			return compare;
		}
	}


	// still returns 1 if strings are the same characters but different lengths, not specified if special case in assignment instructions
	return compare;
}

int my_strncmp(const char* s1, const char* s2, int n)
{
	int compare = 1, chars_compared = 0;

	for (; chars_compared < n && *s1 != '\0' && *s2 != '\0'; ++s1, ++s2, ++chars_compared)
	{
		if (*s1 > *s2)
		{
			compare = -1;
			return compare;

		}
		else if (*s2 == *s1) // only can be same string if have same length
		{

			compare = 0;

		}
		else // *s2 > *s1 
		{
			compare = 1;
			return compare;
		}

	}

	return compare;
}

int my_strlen(const char* s)
{
	int length = 0;

	for (; *s != '\0'; ++s, ++length);

	return length;

}
