#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex_analyzer.h"
#include "polish_notation.h"
#include "stack.h"

#define WIDTH 80
#define HEIGHT 25

char *getString(int *len);
void drawField(struct token *finalArray, int n);
void reversePolishNotation();
int input(struct token **finalArray, int *n);
int anotherInput(struct token **finalArray, int *n, struct token **data_2, int *finalCount);

int main() {
    reversePolishNotation();
    return 0;
}

void reversePolishNotation() {
    struct token *finalArray;
    int n;
    if (input(&finalArray, &n)) {
        drawField(finalArray, n);
        free(finalArray);
    } else {
        printf("n/a");
    }
}

char *getString(int *len) {
    *len = 0;
    int capacity = 1;
    char *s = (char *)malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') {
        s[(*len)++] = c;
        if (*len >= capacity) {
            capacity *= 2;
            char *tmp = (char *)realloc(s, capacity * sizeof(char));
            s = tmp;
        }
        c = getchar();
    }
    s[*len] = '\0';
    return s;
}

int input(struct token **finalArray, int *n) {
    int finalCount = 0;
    int check = 1;
    int len;
    char *s = getString(&len);
    if (strlen(s) == 0) {
        check = 0;
    }
    if (check) {
        char **data;
        struct token *data_2;
        getLexems(s, &data, n);
        if (lexConverter(&data_2, data, *n)) {
            check = anotherInput(finalArray, n, &data_2, &finalCount);
            free(data_2);
        } else {
            check = 0;
        }
        for (int i = 0; i < *n; i++) {
            free(data[i]);
        }
        free(data);
    }
    free(s);
    *n = finalCount;
    return check;
}

int anotherInput(struct token **finalArray, int *n, struct token **data_2, int *finalCount) {
    struct node *root = polishNotation(*data_2, *n);
    int check = 1;
    if (root != NULL) {
        struct token tempToken = (peek(&root))->data;
        struct node *root_2 = init(&tempToken);
        free(pop(&root));
        while (root) {
            (*finalCount)++;
            tempToken = (peek(&root))->data;
            push(&root_2, &tempToken);
            free(pop(&root));
        }
        (*finalCount)--;

        *finalArray = malloc(*finalCount * sizeof(struct token));
        free(pop(&root_2));
        for (int i = 0; i < *finalCount; i++) {
            (*finalArray)[i] = (peek(&root_2))->data;
            free(pop(&root_2));
        }
        free(pop(&root_2));
        destroy(root);
        destroy(root_2);
    } else {
        check = 0;
    }
    return check;
}

void drawField(struct token *finalArray, int n) {
    double shiftH = M_PI * 4.0 / (WIDTH - 1);
    double shiftV = 2.0 / (HEIGHT - 1);
    double y;
    double x;
    for (int j = 0; j < HEIGHT; j++) {
        double yUp = shiftV * j - 1;
        double yDo = shiftV * (j - 1) - 1;
        for (int i = 0; i < WIDTH; i++) {
            x = i * shiftH;
            y = execPFR(finalArray, x, n);
            (y >= yDo && y < yUp) ? printf("*") : printf(".");
        }
        printf("\n");
    }
}
