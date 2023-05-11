#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha();
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

int count(Pilha *p) {
	int i = 0;
	No *no = p->topo;
	while (no != NULL) {
		i++;
		no = no->prox;
	}
	return i;
}

void print(Pilha *p) {
	No *no = p->topo;
	cout << "--------------" << endl;
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "--------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
    cout << "--------------" << endl;
}

void push(Pilha *p, float v) {
	No *no = new No();
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha *p) {
	float ret;
	int podeDesempilhar = (!isEmpty(p));
	if (podeDesempilhar) {
		No *no = p->topo;
		ret = no->dado;
		p->topo = p->topo->prox;
		free(no);
	}
	else {
		ret = -1;
	}
	return ret;
}

void freePilha(Pilha *p) {
	No *no = p->topo;
	while (no != NULL) {
		No *aux = no->prox;
		free(no);
		no = aux;
	}
	free(p);
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	push(pilhaFloat, 5);
    push(pilhaFloat, 10);
	push(pilhaFloat, 15);
    push(pilhaFloat, 20);
	push(pilhaFloat, 25);
    push(pilhaFloat, 30);
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	print(pilhaFloat);
	
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
			
    print(pilhaFloat);
    
    freePilha(pilhaFloat);
				
	return 0;
}