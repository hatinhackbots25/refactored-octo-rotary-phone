#include "lfsr.h"

void free_node(Node* node){
	Node* cur;
	while((cur = node) != NULL){
		node = node->next;
		free(cur);
	}
}
void free_reg(Lfsr lf){
	int i;
	Lfsr cur;
	Node* tmp;
	while((cur = lf) != NULL){
		lf = lf->next;
		free_node(cur->indexes);
		free(cur);
	}
}


Lfsr create_reg(int length){
	int i;
	Lfsr lf = NULL;
	for(i = 0; i < length; i++){
		Lfsr new = malloc(sizeof(struct s_lfsr));
		new->val = 0;
		Node* new_node = malloc(sizeof(struct s_node));
		new_node->num = i;
		new_node->next = NULL;
		new->indexes = new_node;
		new->next = NULL;
		if(i == 0)
			lf = new;
		else{
			Lfsr cur = lf;
			while(cur->next != NULL)
				cur = cur->next;
			cur->next = new;
		}
	}
	return lf;
}

void print_reg(Lfsr lf){
	int i = 0;
	Node* tmp = NULL;
	while(lf != NULL){
		printf("Index=%d: %d -> ", i, lf->val);
		tmp = lf->indexes;
		while(tmp != NULL){
			printf("%d|", tmp->num);
			tmp = tmp->next;
		}
		printf("\n");
		lf = lf->next;
		i++;
	}
	
	/*for(i = lf->size - 1; i >= 0; --i){
		printf("Index=%d: %d -> ", i, lf[i].val);
		tmp = lf[i].indexes;
		while(tmp != NULL){
			printf("%d|", tmp->num);
			tmp = tmp->next;
		}
		printf("\n");
		}*/
}

void init_reg(Lfsr lf, int number){
	int i, c;
	unsigned short hex;
	if(number == 1)
		hex = POLY1;
	if(number == 2)
		hex = POLY2;
	if(number == 3)
		hex = POLY3;
	i = 0;
	while(hex){
		lf[i].val = hex & 1;
		hex = hex >> 1;
		i++;
	}
	print_reg(lf);
}


void add_node(Lfsr reg, Node* node, int pos){
	int i = 0;
	Lfsr cur = reg;
	for(i = 0; i < pos; i++)
		cur = cur->next;
	Node* last = node;
	if(last != NULL){
		while(last->next != NULL)
			last = last->next;
	}
	Node* cur_node = cur->indexes;
	while(cur_node != NULL){
		Node* new = malloc(sizeof(struct s_node));
		new->num = cur_node->num;
		new->next = NULL;
		if(last == NULL)
			last = new;
		else
			last->next = new;
		last = last->next;
		cur_node = cur_node->next;
	}
}

void upd_lfsr(Lfsr lf, int number){
	int out;
	int new_value;
	Node* tmp;
	
	Lfsr new = malloc(sizeof(struct s_lfsr));
	new->val = 0;
	
	Node* new_node = NULL;
	/*new_node->num = i;
	new_node->next = NULL;
	new->indexes = new_node;*/
	new->next = NULL;
	
	if(number == 1){
		/*new_value = lf[5].val^lf[3].val^lf[2].val^1;*/
		add_node(lf, new_node, 5);
		add_node(lf, new_node, 3);
		add_node(lf, new_node, 2);
		add_node(lf, new_node, 0); 
	}
	if(number == 2){
		/*new_value = lf[13].val^lf[12].val^lf[9].val^lf.val[8]^
		  lf.val[5]^lf.val[3]^lf.val[1]^1;*/
		
		add_node(lf, new_node, 13);
		add_node(lf, new_node, 12);
		add_node(lf, new_node, 9);
		add_node(lf, new_node, 8);
		add_node(lf, new_node, 5);
		add_node(lf, new_node, 3);
		add_node(lf, new_node, 1);
		add_node(lf, new_node, 0);
	}
	if(number == 3){
		/*new_value = lf[6].val^lf[5].val^lf[3].val^1;*/
		
		add_node(lf, new_node, 6);
		add_node(lf, new_node, 5);
		add_node(lf, new_node, 3);
		add_node(lf, new_node, 0);
	}
	/*int i;
	out = lf[0].val;
	for(i = 1; i < lf->size; i++)
		lf[i-1].val = lf[i].val;
	lf[lf->size-1].val = new_value;
	return out;*/

	Lfsr last = lf;
	while(last->next != NULL)
		last = last->next;
	last->next = new;
	Lfsr old = lf;
	lf = lf->next;
}

Matrix create_equations(int* xored, Lfsr reg1, Lfsr reg2, Lfsr reg3){
	Matrix m = CreateNewMatrix(131,132);
	int i, j;
	for(i = 0; i < 131; i++)
		m.matrix[i][131] = xored[i];
	for(i=0; i < 131; i++){
		/* positions des output du 1er registre */
		Node* tmp = reg1->indexes;
		while(tmp != NULL){
			m.matrix[i][tmp->num] = 1;
			tmp = tmp->next;
		}
		/* second registre */
		tmp = reg2->indexes;
		while(tmp != NULL){
			m.matrix[i][tmp->num+41] = 1;
			tmp = tmp->next;
		}
		/* troisieme registre */
		tmp = reg3->indexes;
		while(tmp != NULL){
			m.matrix[i][tmp->num+41+43] = 1;
			tmp = tmp->next;
		}
		upd_lfsr(reg1, 1);
		upd_lfsr(reg2, 2);
		upd_lfsr(reg3, 3);
	}
	return m;
}
