// ConsoleApplication24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class oper {
public:
	struct el {
		int a;
		el* right;
		el* left;
		el* up;
	};
	el* root;
	oper() { root = NULL; };
	void crt_tree();
	void add();
	void get_degr(int num);
	void get_lvl(int num);
	void delet(int num);
	void search(int num);
	void get_quanNode();
	void get_quanLeaf();
	void get_height();
	void deletTree();
	void predel(int num);
	void obhodQuanNode(el* tmp);
	void obhodHeight(el* tmp, int max);
	void obhodQuanLeaf(el* tmp);
	void show(el* tmp, int level);
	void showTree();
	void obhodDelet(el* tmp);
};

oper l;

void oper::crt_tree() {
	int p;
	int q;
	cout << "Введите количество узлов\n";
	cin >> p;
	for (int i = 0; i <= p-1; i++) {
		q = 0;
		el* temp = new el;
		int a = rand() % 200;
		temp->a = a;
		if (root == NULL) {
			root = temp;
			temp->left = NULL;
			temp->right = NULL;
			temp->up = NULL;
		}
		else {
			el* tmp = root;
			while ((tmp != NULL)&(q==0)) {
				if (tmp->a > a) {
					if (tmp->left == NULL) {
						tmp->left = temp;
						temp->left = NULL;
						temp->right = NULL;
						temp->up = tmp;
						q = 1;
					}
					else {
						tmp = tmp->left;
					};
				}
				else {
					if (tmp->right == NULL) {
						tmp->right = temp;
						temp->left = NULL;
						temp->right = NULL;
						temp->up = tmp;
						q=1;
					}
					else {
						tmp = tmp->right;
					}
				}
			}
		}
	}
}

void oper::add() {
	int a;
	int q = 0;
	el* temp = new el;
	cout << "Введите значение узла\n";
	cin >> a;
	temp->a = a;
	if (root == NULL) {
		root = temp;
		temp->left = NULL;
		temp->right = NULL;
		temp->up = NULL;
	}
	else {
		el* tmp = root;
		while ((tmp != NULL)&(q==0)) {
			if (tmp->a > a) {
				if (tmp->left == NULL) {
					tmp->left = temp;
					temp->left = NULL;
					temp->right = NULL;
					temp->up = tmp;
					q = 1;
				}
				else {
					tmp = tmp->left;
				};
			}
			else {
				if (tmp->right == NULL) {
					tmp->right = temp;
					temp->left = NULL;
					temp->right = NULL;
					temp->up = tmp;
					q = 1;
				}
				else {
					tmp = tmp->right;
				}
			}
		}
	}
}

int hgt;

void oper::showTree() {
	if (root != NULL) {
		el* tmp = root;
		l.show(tmp, 0);
	}
}

void oper::show(el* tmp, int level) {
	if (tmp != NULL) {
		show(tmp->left, level + 1);
		for (int i = 0; i <= level; i++)
			cout << "  ";
		cout << tmp->a << endl;
		show(tmp->right, level + 1);
	}
}


void oper::get_degr(int num) {
	el* tmp=root;
	int p=0;
	int q;
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		while (tmp != NULL) {
			q = 0;
			if (tmp->a == num) {
				if (tmp->left != NULL) { q = q + 1; };
				if (tmp->right != NULL) { q = q + 1; };
				p = p + 1; cout << "Степень " << p << "-го узла, равного " << num <<" = " << q;
				cout << endl;
				tmp = tmp->right;
			}
			else {
				if (tmp->a > num) { tmp = tmp->left; }
				else { tmp = tmp->right; }
			}
		};
		if (p == 0) { cout << "Нет таких элементов\n"; };
	}
}

void oper::get_lvl(int num) {
	cout << "Введите значение узла\n";
	el* tmp=root;
	int p = -1;
	int q = 0;
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		while (tmp != NULL) {
			p = p + 1;
			if (tmp->a == num) {
				q = q + 1;
				cout << "Уровень " << q << "-го узла, равного " << num << " = " << p;
				cout << endl;
				tmp = tmp->right;
			}
			else {
				if (tmp->a > num) { tmp = tmp->left; }
				else { tmp = tmp->right; }
			}
		};
		if (q == 0) { cout << "Нет таких элементов\n"; }
	}
}

void oper::obhodDelet(oper::el* tmp) {
	if (tmp->left != NULL) {
		oper::obhodDelet(tmp->left);
	}
	if (tmp->right != NULL) {
		oper::obhodDelet(tmp->right);
	}
	el* tep = tmp->up;
	if (tmp->up != NULL) {
		if (tmp->a < tmp->up->a) { tmp->up->left = NULL; }
		else { tmp->up->right = NULL; };
	};
	if (tmp->a == root->a) { root = NULL; }
	tmp->up = NULL;
		delete tmp;
}

void oper::delet(int num) {
	el* tmp = root;
	int p = 0;
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		while ((tmp != NULL) & (p == 0)) {
			if (tmp->a == num) {
				p = 1;
				oper::obhodDelet(tmp);
				tmp = NULL;
				oper::showTree();
			}
			else {
				if (tmp->a > num) { tmp = tmp->left; }
				else { tmp = tmp->right; }
			}
		};
		if (p == 0) { cout << "Нет таких элементов\n"; };
	}
}

void oper::search(int num) {
	el* tmp = root;
	int q = 0;
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		while (tmp != NULL) {
			if (tmp->a == num) {
				q = q + 1;
				cout << q << "-й элемент, равный " << num << ":\n";
				if (tmp->left!= NULL) {
					cout << "Левый сын: " << tmp->left->a << endl;
				}
				if (tmp->right != NULL) {
					cout << "Правый сын: " << tmp->right->a << endl;
				}
				if (tmp->up != NULL) {
					cout << "Родитель: " << tmp->up->a << endl;
				}
				tmp=tmp->right;
			}
			else {
				if (tmp->a > num) { tmp = tmp->left; }
				else { tmp = tmp->right; }
			}
		};
		if (q == 0) { cout << "Нет таких элементов\n"; }
	}
}

int quanNode;
int height;
int quanLeaf;

void oper::obhodQuanNode(el* tmp) {
	if (tmp->left != NULL) {
		tmp = tmp->left;
		quanNode = quanNode + 1;
		l.obhodQuanNode(tmp);
		tmp = tmp->up;
	};
	if (tmp->right != NULL) {
		tmp = tmp->right;
		quanNode = quanNode + 1;
		l.obhodQuanNode(tmp);
		tmp = tmp->up;
	};
}

void oper::get_quanNode() {
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		quanNode = quanNode = quanNode + 1;
		el* tmp = root;
		l.obhodQuanNode(tmp);
		cout << "Количество узлов: " << quanNode << endl;
	}
}

void oper::obhodHeight(el* tmp, int max) {
	if (tmp->left != NULL) {
		max = max + 1;
		if (max > height) {
			height = max;
		};
		tmp = tmp->left;
		l.obhodHeight(tmp, max);
		tmp = tmp->up;
		max = max - 1;
	};
	if (tmp->right != NULL) {
		max = max + 1;
		if (max > height) {
			height = max;
		};
		tmp = tmp->right;
		l.obhodHeight(tmp,max);
		tmp = tmp->up;
		max = max - 1;
	};
}

void oper::get_height() {
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		height = 0;
		int max = 0;
		el* tmp = root;
		l.obhodHeight(tmp, max);
		cout << "Высота дерева: " << height << endl;
	}
}


void oper::obhodQuanLeaf(el* tmp) {
	if ((tmp->left == NULL)&(tmp->right == NULL)) { quanLeaf = quanLeaf + 1; };
	if (tmp->left != NULL) {
		tmp = tmp->left;
		l.obhodQuanLeaf(tmp);
		tmp = tmp->up;
	};
	if (tmp->right != NULL) {
		tmp = tmp->right;
		l.obhodQuanLeaf(tmp);
		tmp = tmp->up;
	};
}

void oper::get_quanLeaf() {
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		quanLeaf = 0;
		el* tmp = root;
		l.obhodQuanLeaf(tmp);
		cout << "Количество листьев: " << quanLeaf << endl;
	}
}

void oper::deletTree() {
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		oper::delet(root->a);
	}
}

void oper::predel(int num) {
	el* tmp = root;
	int p = 0;
	if (root == NULL) {
		cout << "Нет ни одного элемента!\n";
	}
	else {
		while ((tmp != NULL)&(p == 0)) {
			if (tmp->a == num) {
				p = 1;
				if ((tmp->left != NULL)&(tmp->right == NULL)) {
					if (tmp->up != NULL) {
						tmp->left->up = tmp->up;
						if (tmp->up->a > tmp->a) {
							tmp->up->left = tmp->left;
						}
						else {
							tmp->up->right = tmp->left;
						};
					}
					else {root = tmp->left; }
				}
				else if ((tmp->right != NULL)&(tmp->left == NULL)) {
					if (tmp->up != NULL) {
						tmp->right->up = tmp->up;
						if (tmp->up->a > tmp->a) {
							tmp->up->left = tmp->left;
						}
						else {
							tmp->up->right = tmp->left;
						};
					}
					else { root = tmp->right; }
				}
				else if ((tmp->right != NULL)&(tmp->left != NULL)) {
					el* temp = tmp->right;
					while (temp->left != NULL) {
						temp = temp->left;
					};
					if (temp->right != NULL) {
						temp->up->left = temp->right;
						temp->right->up = temp->up;
					}
					else { temp->up->left = NULL; }
					temp->up = tmp->up;
					temp->left = tmp->left;
					temp->right = tmp->right;
					tmp->right->up = temp;
					tmp->left->up = temp;
					if (tmp->up != NULL) {
						if (tmp->up->a > temp->a) {
							tmp->up->left = temp;
						}
						else {
							tmp->up->right = temp;
						};
					}
					if (tmp->up == NULL) { root = tmp->right; }
				}
				else
				{
					if (tmp->up != NULL) {
						if (tmp->up->a > tmp->a) {
							tmp->up->left = NULL;
							tmp->up = NULL;
						}
						else {
							tmp->up->right = NULL;
							tmp->up = NULL;
						};
					}
					else { root = NULL; }
				}
				if (tmp->a==root->a)
				tmp = NULL;
				delete tmp;
			}
			else {
				if (tmp->a > num) { tmp = tmp->left; }
				else { tmp = tmp->right; }
			}
		};
		if (p == 0) { cout << "Нет таких элементов\n"; };
	}
}

oper q;
oper t;
int srav;

void obhodCompar(oper::el* qt, oper::el* tt) {
	if (srav == 0) {
		if (tt->a != qt->a) {
			srav = 1;
		}
		if ((qt->left != NULL) & (tt->left!=NULL)) {
			obhodCompar(qt->left, tt->left);
		}
		else {
			if ((qt->left == NULL) & (tt->left == NULL)) {
				int kek;
			}
			else { srav = 1; }
		}
		if ((qt->right != NULL) & (tt->right != NULL)) {
			obhodCompar(qt->right, tt->right);
		}
		else {
			if ((qt->right == NULL) & (tt->right == NULL)) {
				int kek;
			}
			else { srav = 1; }
		}
	}
}

void compar() {
	system("cls");
	int nd;
	int pd;
	cout << "Введите количество узлов деревьев. \nКоличество узлов должно быть одинаковым.\nИначе можно сразу сказать, что деревья \nне являются зеркальным отражением друг друга.\n";
	cin >> nd;
	while (nd < 1) {
		cout << "Введите число, большее нуля\n";
		cin >> pd;
		nd = pd;
	}
	system("cls");
	cout << "Первое дерево\n";
	for (int i = 0; i <= nd - 1; i++) {
		q.add();
		system("cls");
		cout << "Первое дерево\n";
		q.showTree();
	}
	system("cls");
	for (int i = 0; i <= nd - 1; i++) {
		cout << "Первое дерево\n";
		q.showTree();
		cout << "Второе дерево\n";
		t.showTree();
		t.add();
		system("cls");
	}
	srav = 0;
	obhodCompar(q.root, t.root);
	if (srav == 0) {
		cout << "Деревья являются зеркальным отражением друг друга\n";
	}
	else { cout << "Деревья не являются зеркальным отражением друг друга\n"; }
}

void action() {
	int p;
	l.showTree();
	cout << "1.Создать рандомное дерево\n";
	cout << "2.Добавить узел\n";
	cout << "3.Вывести дерево\n"; 
	cout << "4.Поиск образца\n";
	cout << "5.Получить количество узлов дерева\n";
	cout << "6.Получить количетсво листьев дерева\n";
	cout << "7.Узнать степень вершины\n";
	cout << "8.Узнать уровень вершины \n";
	cout << "9.Получить высоту дерева\n";
	cout << "10.Удалить узел дерева с поддеревом\n";
	cout << "11.Удалить все дерево\n";
	cout << "12.Сравнить два дерева \n";
	cout << "13.Выйти из программы\n";
	cin >> p;
	switch (p) {
	case 1: {
		l.deletTree();
		system("cls");
		l.crt_tree();
		system("cls");
		action();
		break;
	}
	case 2: {
		l.add();
		system("cls");
		action();
		break;
	}
	case 3: {
		l.showTree();
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 4: {
		int num;
		cout << "Введите значение узла\n";
		cin >> num;
		l.search(num);
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 5: {
		l.get_quanNode();
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 6: {
		l.get_quanLeaf();
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 7: {
		int num;
		cout << "Введите значение узла\n";
		cin >> num;
		l.get_degr(num);
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 8: {
		int num;
		cout << "Введите значение узла\n";
		cin >> num;
		l.get_lvl(num);
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 9: {
		l.get_height();
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 10: {
		int num;
		cout << "Введите значение узла\n";
		cin >> num;
		l.delet(num);
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 11: {
		l.deletTree();
		system("cls");
		action();
		break;
	}
	//case 12: {
		//int num;
		//cout << "Введите значение узла\n";
		//cin >> num;
		//l.predel(num);
		//l.showTree();
		//cin.ignore().get();
		//system("cls");
		//action();
		//break;
	//}
	case 12: {
		q.deletTree();
		t.deletTree();
		system("cls");
		compar();
		cin.ignore().get();
		system("cls");
		action();
		break;
	}
	case 13: {
		exit(0);
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	action();
	_gettch();
    return 0;
}

