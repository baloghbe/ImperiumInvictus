// Tokenizer.h : Include file for standard system include files,
// or project specific include files.

#ifndef TOKENIZER_H
#define TOKENIZER_H



#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>


enum TokenType {
	KEYWORD,
	IDENTIFIER,
	NUMBER,
	STRING,
	OPERATOR,
	PUNCTUATION,
	COMMENT,
	WHITESPACE,
	UNKNOWN
};

/*struct TextPosition
{
	long int pos = 0;
	long int line = 0;
	long int absolutepos = 0;

	void newline() {
		pos = 0;
		absolutepos++;
		line++;
	}

	void increment() {
		pos++;
		absolutepos++;
	}
};*/

struct Token {

	TokenType type;
	std::string value;
};

std::unordered_map<std::string, TokenType> keywords;

//Function to check if something is a token

bool isKeyWord(const std::string& pkw);


//Tokenizer

std::vector<Token> tokenize(const std::string& input);

//Token printer

void printTokens(const std::vector<Token>& tokens);


#endif
