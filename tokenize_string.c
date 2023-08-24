#include <stdlib.h>


char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


/**
 * strtow - to a str and seperates its words
 * @str: str to seperate into words
 * @delims: delimtrs to use to delmit words
 * Return: 2D aray of pointrs to each word
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}

		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - checks if stream has delimtr char
 * @ch: char in stream
 * @delims: ptr to null termintd aray of delimitrs
 * Return: 1 success, 0 on failure
 */
int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - gets word length of curent word in str
 * @str: str to get word length from the current word
 * @delims: delimtrs to use to delmit words
 * Return: word length of a current word
 */
int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - gets the word count of str
 * @str: str to get the word count from
 * @delims: delimtrs to use to delimit words
 * Return: the word count of str
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - gets next word in str
 * @str: str to get the next word from
 * @delims: delmitrs to use to delimt of words
 * Return: ptr to first char of next word
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;


	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
