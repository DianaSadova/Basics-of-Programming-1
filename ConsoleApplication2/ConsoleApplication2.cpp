#include <iostream>

using namespace std;

struct tovar
{
	string name;
	float price;
	int amount;
	tovar* next;
};

void addfirst(tovar*& tlist, string n, float p, int am) {
	tovar* newtovar = new tovar;
	newtovar->name = n;
	newtovar->amount = am;
	newtovar->price = p;
	newtovar->next = tlist;
	tlist = newtovar;
}

int addbefove(tovar*& tlist, string n, float p, int am, string nabefove) {
	if (tlist == NULL) return 1;
	if (tlist->name == n)
	{
		addfirst(tlist, n, p, am);
		return 0;
	}
	if (tlist->next == NULL) return 1;
	tovar* newt = tlist, * tmp = tlist->next;
	while (tmp->next != NULL && tmp->name != nabefove)
	{
		newt = newt->next;
		tmp = tmp->next;
	}
	if (tmp->next == NULL && tmp->name != nabefove) return 1;
	tovar* newtovar = new tovar;
	newtovar->name = n;
	newtovar->price = p;
	newtovar->amount = am;
	newtovar->next = tmp;
	newt->next = newtovar;
	return 0;
}

int addafter(tovar*& bufet, string n, float p, int am, string nafter) {
	if (bufet == NULL) return 1;
	tovar* tmp = bufet;
	while (tmp != NULL && tmp->name != nafter) {
		tmp = tmp->next;
	}
	if (tmp == NULL) return 1;
	tovar* newtovar = new tovar;
	newtovar->name = n;
	newtovar->price = p;
	newtovar->amount = am;
	newtovar->next = tmp->next;
	tmp->next = newtovar;
	return 0;
}

void addend(tovar*& bufet, string n, float p, int am)
{
	tovar* tmp = bufet;
	if (bufet == NULL) {
		addfirst(bufet, n, p, am);
		return;
	}
	while (tmp->next) tmp = tmp->next;
	tovar* newtovar = new tovar;
	newtovar->name = n;
	newtovar->price = p;
	newtovar->amount = am;
	newtovar->next = NULL;
	tmp->next = newtovar;
}

void printlist(tovar* bufet) {
	while (bufet != NULL) {
		cout << "Name:" << bufet->name << " Price:" << bufet->price << " Amount:" << bufet->amount << "\n";
		bufet = bufet->next;
	}
}


int DelNode(tovar*& bufet, string DelName) {
	if (bufet == NULL) return 1;
	tovar* tmp = bufet;
	if (bufet->name == DelName) {
		bufet = bufet->next;
		delete tmp;
		return 0;
	}
	if (bufet->next == NULL) return 1;
	tovar* prev = bufet;
	tmp = bufet->next;
	while (tmp->next != NULL && tmp->name != DelName) {
		prev = prev->next;
		tmp = tmp->next;
	}
	if (tmp->next == NULL && tmp->name != DelName) return 1;
	prev->next = tmp->next;
	delete tmp;
	return 0;
}


int main()
{
	//  Функция позволяет устанавливать географического положения пользователя и изменять текст под алфавит этой странны
	setlocale(LC_ALL, "rus");

	tovar* bufet = NULL; // Создали укозатель на bufet как на односвязный список и задаои ему значение NULL

	// Заполняем наш список используя функции описанные выше
	addfirst(bufet, "Cake1", 20.34f, 10);
	addfirst(bufet, "Cake2", 19.43f, 8);

	addafter(bufet, "Cake3", 54.77f, 3, "Cake2");

	addbefove(bufet, "Cake4", 1.43f, 6, "Cake3");
	addbefove(bufet, "Cake5", 190.43f, 15, "Cake4");

	addend(bufet, "Cake6", 200.43f, 90);

	addbefove(bufet, "Cake7", 50.43f, 45, "Cake6");

	// Выводим наш список 
	cout << "list:" << endl;
	printlist(bufet);

	// Удаляем весь список используя имена объектов
	DelNode(bufet, "Cake1");
	DelNode(bufet, "Cake2");
	DelNode(bufet, "Cake3");
	DelNode(bufet, "Cake4");
	DelNode(bufet, "Cake5");
	DelNode(bufet, "Cake6");
	DelNode(bufet, "Cake7");

	// Еще раз выводим наш список для проверки, что все элементы односвязного списка успешно удалились 
	cout << "\n" << "Список после удаления элементов" << "\n";
	printlist(bufet);
	cout << "\n" << "Как видим список пуст";
	return 0;
}

