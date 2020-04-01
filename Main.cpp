#include "Lexer.hpp"

int main(){
	string file_name;
	cout << "This is lexer of subset of SIGNAL programming language. Made by Maksym Sadovenko." << endl;
	cout << "Write file name:" << endl;
	cin >> file_name;
	Lexer lexer;
	lexer.lexical_analysis(file_name);
	return 0;
}