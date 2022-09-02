#ifndef SRC_LEX_ANALYZER_H_
#define SRC_LEX_ANALYZER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token {
    int type;
    char operation;
    double operand;
};

void shifter(char** copy, const char* temp, int* counter, char*** data);
int operationType(char* data, char* oper, char** operations, int size);
void detectUnaryMinus(struct token** dst, int n);
int lexConverter(struct token** dst, char** data, int n);
void charCleaner(char** data, int n);
void getLexems(char* str, char*** data, int* n);
int getWords(char* str, char*** lexems);
int getLexors(char* str, int n, char** lexems, char*** data);

#endif  // SRC_LEX_ANALYZER_H_
