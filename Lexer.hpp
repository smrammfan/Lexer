#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct lexem {
	lexem(int code, int line, int column, string name){
		this->code = code;
		this->line = line;
		this->column = column;
		this->name = name;
	}
	lexem(string name, int code){
		this->name = name;
		this->code = code;
		line = column = 0;
	}
	int code;
	int line;
	int column;
	string name;
};

class Lexer {
public:

	Lexer();
	~Lexer(){};

	bool lexical_analysis(string);
	vector<lexem*> get_lexems() const {return lexem_table;};
	vector<string> get_idetidiers() const {return identifier_talbe;};
	vector<string> get_digits() const {return digit_table;};
	
private:
	fstream input_file;

	int lex_counter;
	vector <lexem*> lexem_table;
	vector <string> identifier_talbe;
	vector <string> digit_table;
	vector <const lexem*> key_word_table;
	
	int line;
	int save_line;
	
	int column;
	int save_column;
	
	int lex_error_code;
	int identifier_counter;
	int digit_counter;
	int ASCIIArr[128];
	int pos;
	char sbuff;
	bool was_error;
	void add_lexem(int, int, int, string);
	bool size_out();
	void INP();
	void SPACE();
	void IDN();
	void DG();
	void BCOM(); // begin comment
	void COM(string); // comment
	void ECOM(string); // end comment
	void DM();
	void ERR(string);
	int search_in_digit_table(string);
	int search_in_identifier_table(string);
	int search_in_key_word_table(string);
	void make_listing(string);
	

	const int MIN_KEY_WORDS_CODE = 401;
	const int MIN_DIGIT_CODE = 501;
	const int MIN_IDENTIFIER_CODE = 1001;
	const int LEX_ERROR_CODE = 2000;

	const lexem* PROGRAM = new lexem("PROGRAM", 401);
	const lexem* BEGIN = new lexem("BEGIN", 402);
	const lexem* END = new lexem("END", 403);
	const lexem* LABEL = new lexem("LABEL", 404);
	const lexem* GOTO = new lexem("GOTO", 405);
	const lexem* LINK = new lexem("LINK", 406);
	const lexem* IN = new lexem("IN", 407);
	const lexem* OUT = new lexem("OUT", 408);


	
};