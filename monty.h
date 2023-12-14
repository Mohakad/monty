#ifndef MONTYH_
#define MONTYH_
#define _GNU_SOURCE

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef void (*funct)(stack_t **, unsigned int);
void f_opn(char *file);
extern stack_t *head;
int toknizz(char *buffer, int line_number, int format);
void fl_read(FILE *);
void ad_q(stack_t **ad_nd, unsigned int ln);
int len_chars(FILE *);
void finder(char *opc, char *value, int ln, int f);
void _errors(int error_code, ...);
void handl_err(int error_code, ...);
void ch_err(int error_code, ...);
stack_t *nod(int n);
void freeall(void);
void _pall(stack_t **, unsigned int);
void add_st(stack_t **, unsigned int);
void exec(funct, char *, char *, int, int);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swp(stack_t **stack, unsigned int line_number);
void add_two(stack_t **stack, unsigned int line_number);
void nop(stack_t **, unsigned int);
void sub(stack_t **stack, unsigned int line_number);

#endif
