// Tokenizer.cpp : Defines the entry point for the application.
//

#include "Tokenizer.h"

std::unordered_map<std::string, TokenType> keywords = {
	{"si", KEYWORD}, //if
	{"aliud", KEYWORD}, //else
	{"dum", KEYWORD}, //while
	{"reditus", KEYWORD}, //return
	{"verus", KEYWORD}, //true
	{"falsus", KEYWORD}, //false
	{"supernatet", KEYWORD}, //float
	{"bool", KEYWORD},
	{"inanis", KEYWORD}, //void
	{"nota", KEYWORD}, //print


};


bool isKeyWord(const std::string& pkw) {
	return keywords.find(pkw) != keywords.end();
}


std::vector<Token> tokenize(const std::string& input) {

	std::vector<Token> tokens;

	size_t i = 0;


	//Whitespaces
	while (i < input.length()) {
		if (std::isspace( input[i])) {
			++i;
			continue;
		}
	}

	//Keywords
	if (std::isalpha(input[i])) {
		std::string word;

		while (i < input.length() && std::isalpha(input[i])) {
			word += input[i++];
		}

		Token token;

		if (isKeyWord(word)) {
			token.type = KEYWORD;
		}
		else {
			token.type = IDENTIFIER;
		}

		token.value = word;
		tokens.push_back(token);
	} //Digits
	else if (std::isdigit(input[i])) {
		std::string number;

		while (i < input.length() && std::isdigit(input[i])) {
			number += input[i++];

		}
		tokens.push_back({ NUMBER, number });
	} //String literal
	else if (input[i] == '""') {
		std::string stringliteral;

		stringliteral += input[i++];
		//Opening
		while (i < input.length() && input[i] != '"') {
			stringliteral += input[i++];
		}
		//Ending
		if (i < input.length() && input[i] == '"') {
			stringliteral += input[i++];
		}
		tokens.push_back({ STRING, stringliteral });
	}
	else if (input[i] == '/' && i + 1 < input.length() && (input[i + 1] == '/' || input[i + 1] == '*')) {
		//Comments
		std::string comment;

		//Single line
		if (input[i + 1] == '/') {
			comment += input[i++];
			comment += input[i++];

			while (i < input.length() && input[i] != '\n') {
				comment += input[i++];
			}
		}//Multi line
		else if (input[i +1] == '*') {
			comment += input[i++];
			comment += input[i++];

			while (i + 1 < input.length() && !(input[i] == '*' && input[i + 1] == '/')) {
				comment += input[i++];
			}
			if (i+1 < input.length()) {
				comment += input[i++];
				comment += input[i++];
			}

		}
		tokens.push_back({ COMMENT, comment });
	}//Operators
	else if (std::ispunct(input[i])) {
		std::string punctuation;
		punctuation += input[i++];

		if (i < input.length() && (punctuation == "<" || punctuation == ">" || punctuation == "!" || punctuation == "=") && input[i] == '=') {
			punctuation += input[i++];
		}

		if (punctuation == "+" || punctuation == "-" || punctuation == "/" || punctuation == "*" || punctuation == "<=" || punctuation == ">=" || 
			punctuation == "==" || punctuation == "==" || punctuation == "!=" || punctuation == "&&" || punctuation == "||") {
			tokens.push_back({ OPERATOR, punctuation });

		}
		else {
			tokens.push_back({ PUNCTUATION, punctuation });
		}
	}//Unknown characters
	else {
		tokens.push_back({ UNKNOWN, std::string(1, input[i++]) });
	}


	return tokens;

};

void printTokens(const std::vector<Token>& tokens) {
	for (const auto& token : tokens) {
		std::string type;
		switch (token.type) {
		case KEYWORD: type = "KEYWORD"; break;
		case IDENTIFIER: type = "IDENTIFIER"; break;
		case NUMBER: type = "NUMBER"; break;
		case STRING: type = "STRING"; break;
		case OPERATOR: type = "OPERATOR"; break;
		case PUNCTUATION: type = "PUNCTUATION"; break;
		case COMMENT: type = "COMMENT"; break;
		case WHITESPACE: type = "WHITESPACE"; break;
		default: type = "UNKOWN"; break;
		}

		std::cout << "Type: " << type << ", Value: \"" << token.value << "\" \n";
	}
}

