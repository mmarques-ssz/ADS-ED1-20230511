#include <iostream>
using namespace std;

#define MAX 10

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha();
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return (p->qtde);
}

void freePilha(Pilha *p) {
	free(p);
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	float v;
	int podeDesempilhar = (! isEmpty(p));
	if (podeDesempilhar) {
		v = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else {
		v = -1;
	}
	return v;
}

void print(Pilha *p) {
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "-----------------------" << endl;
	for(int i=p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "-----------------------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = new Pilha();
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	cout << "Valor empilhado: " << (push(pilhaFloat, 5)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 10)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 15)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 20)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 25)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 30)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 35)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 40)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 45)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 50)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 55)?"SIM":"NAO") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 60)?"SIM":"NAO") << endl;
	
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