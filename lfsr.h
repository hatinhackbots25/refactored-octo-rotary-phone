#ifndef LFSR
#define LFSR

#include "matrix.h"

#define MASK1 0x3FFFFFFFFFFL
#define MASK2 0xFFFFFFFFFFFL
#define MASK3 0xFFFFFFFFFFFFL
#define POLY1 0x2D
#define POLY2 0x332B
#define POLY3 0x69

typedef struct s_node Node;
struct s_node{
	int num;
	struct s_node* next;
};

typedef struct s_lfsr* Lfsr;
struct s_lfsr{
	int val;
	Node* indexes;
	struct s_lfsr* next;
};

void free_node(Node* node);

/* free register */
void free_reg(Lfsr lf);

/* create struct for reg */
Lfsr create_reg(int length);

/* print register state at t*/ 
void print_reg(Lfsr lf);

/* init register */
void init_reg(Lfsr lf, int number);

/* new node */
void add_node(Lfsr reg, Node* node, int pos);

/* lfsr updating */
void upd_lfsr(Lfsr lf, int number);

/* Create 131 equations for SCEX_T2 */
Matrix create_equations(int* xored, Lfsr reg1, Lfsr reg2, Lfsr reg3);

#endif
