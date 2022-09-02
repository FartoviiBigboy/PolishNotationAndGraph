#ifndef SRC_POLISH_NOTATION_H_
#define SRC_POLISH_NOTATION_H_

#include <math.h>
#include <stdio.h>

#include "lex_analyzer.h"

struct node *polishNotation(struct token *data, int n);
int priority(char c);
int pushAll(struct node **node_char, struct node **node_double);
void clearNodeCharStack(struct node **node_double, struct node **node_char);
int stackOnDouble(struct node **node_double, struct node **node_char, struct token data);

double execPFR(struct token *root, double x, int n);
void inverse(struct node **execution);
void sinus(struct node **execution);
void cosinus(struct node **execution);
void tangent(struct node **execution);
void cotangent(struct node **execution);
void base(struct node **execution);
void logarithm(struct node **execution);
void add(struct node **execution);
void sub(struct node **execution);
void mult(struct node **execution);
void divis(struct node **execution);
void power(struct node **execution);
void replace(struct node **execution, double x);
int chooseRes(char c);

#endif  // SRC_POLISH_NOTATION_H_
