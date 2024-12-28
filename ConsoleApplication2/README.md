# ���������� �� ���� �������

����������� ������ � ��� ��������� ������, ������� ������������ ����� ������������������ ���������, ��������� ���� � ������ �����������. ������ ������� ������ �������� ������ � ��������� �� ��������� �������. ��� ��������� ���������� ��������� � ������� �������� �� ������, ������������ ������� ������ � ���������, � ����� ��������� ����������� ��������� �������� ��� �������, ����� ��� �����, �������, �������� � �. �. ����������� ������ ������ ������������ � ���������������� � ����� ��������� ��������, ����� ��� ����������� ������ � ���������� ������.

����������� ������ �������� ����� ����������� � �����������. ����� ����������� ����� �������� �������� ����������, ������������� �������� ���������� � �������� ��������� � ������ ������, � ����� ������������� ������������� ������ (�� ��������� � ���������, ��� ���������� ������� �������� ������ ��� ������������ ���������� ���������). ������ ����������� ����������� ������� �������� ������������� ����������������� ������� �� ���� ��������� ��� ������� � ����������� ��������, ��� ������ �������� ������ ����� ���������� �� �������.

## �������� ������ ���������

��������� ���������� � ����������� ��������� `tovar`, ������� �������� ���������� � ������: �������� (`name`), ���� (`price`), ���������� (`amount`) � ��������� �� ��������� ������� ������ (`next`).

c++
struct tovar
{
 string name;
 float price;
 int amount;
 tovar* next;
};

```

����� ���� ������� ��� ������ � ����������� �������:

?addfirst - ���������� �������� � ������ ������

�� ������ ����� ��� �� ����� �������� "������ �� ������?". ���� ���� �� �������� ������, �� � ��������� ��������� � ���� ������ �������� � ���������� ������� ������.


```
c++
void addfirst(tovar*& tlist, string n, float p, int am) {
 tovar? newtovar = new tovar;
 newtovar->name = n;
 newtovar->amount = am;
 newtovar->price = p;
 newtovar->next = tlist;
 tlist = newtovar;
}

```

?addbefove - ���������� �������� ����� ��������� ��������� � ������

�� ������ ��� ������� �� �int�, ��� ��� ��� ��� ����� �������� ������� ������. ����� ����, ��� �� ���������, ��� ��� ������ �� ������, ���������� � ������ ������� �������� �� �����, ����� ��������� ����� ��� ����� ������� ������������. ����� ������� �������� ���������� �������� ����� ������ ��������. � ��������� �������� �� ��, ��� ���� ��������� ������� ����� ������ NULL � ��� ������ ��������, ��� �� ��� �������� ������� ������. ���� ��� �������� ��������� true, �� �� ��������� ����� ������� ����� ������.


```

c++
int addbefove(tovar*& tlist, string n, float p, int am, string nabefove) {
 if (tlist == NULL) return 1;
 if (tlist->name == n)
 {
  addfirst(tlist, n, p, am);
  return 0;
 }
 if (tlist->next == NULL) return 1;
 tovar? newt = tlist, ?tmp = tlist->next;
 while (tmp->next != NULL && tmp->name != nabefove)
 {
  newt = newt->next;
  tmp = tmp->next;
 }
 if (tmp->next == NULL && tmp->name != nabefove) return 1;
 tovar? newtovar = new tovar;
 newtovar->name = n;
 newtovar->price = p;
 newtovar->amount = am;
 newtovar->next = tmp;
 newt->next = newtovar;
 return 0;
}

```

?addafter - ���������� �������� ����� ���������� �������� � ������

��� ��� ��, ��� � � ���������� ������� ������ �� �int�, ��� ��� � ����� ��� ����������� �������� �� ������. � ������ ������� ��� ����������� ��� ��������. ������ ���������, ���� �� � ����� ������ ��������, ���� ���, ������ ������. ����� �� ���������, ��� ������ �� ������� �� ������ � ��� �� ����� �����������, � ���� ������ �� ��������� ������. ���� ��� �� ������ ����������� ������, ��������� ������. �� ���� ��������� ������� �� ��������� ������ ����� ���������.


```
c++
int addafter(tovar*& bufet, string n, float p, int am, string nafter) {
 if (bufet == NULL) return 1;
 tovar? tmp = bufet;
 while (tmp != NULL && tmp->name != nafter) {
  tmp = tmp->next;
 }
 if (tmp == NULL) return 1;
 tovar? newtovar = new tovar;
 newtovar->name = n;
 newtovar->price = p;
 newtovar->amount = am;
 newtovar->next = tmp->next;
 tmp->next= newtovar;
 return 0;
}

```

### `addend` - ���������� �������� � ����� ������.

������� `addend` ��������� ����� ������� � ����� ������������ ������ `tovar`.

1.  **�������� �� ������ ������:** ������� �����������, �������� �� ������ `bufet` ������ (����� `NULL`).
2.  **���������� � ������ ������:** ���� ������ ����, ���������� ������� `addfirst`, ������� ��������� ������� � ������ ������.
3.  **����� ���������� ��������:** ���� ������ �� ����, ������� �������� �� ������, ���� �� ��������� ���������� �������� (��������, � �������� `next` ����� `NULL`).
4.  **�������� ������ ��������:** ����� ���������� ���������� �������� ��������� ����� ������� `newtovar` ���� `tovar`, �������� ������������� ���������� �������� (`n`, `p`, `am`) � `next` ��������������� � `NULL`.
5.  **�������� ������ ��������:** ���� `next` ���������� �������� ������ ��������������� �� `newtovar`, ��� ����� ����� ������� ����������� � ����� ������.

```

cpp
void addend(tovar*& bufet, string n, float p, int am)
{
 tovar? tmp = bufet;
 if (bufet == NULL) {
  addfirst(bufet, n, p, am);
  return;
 }
 while (tmp->next) tmp = tmp->next;
 tovar? newtovar = new tovar;
 newtovar->name = n;
 newtovar->price = p;
 newtovar->amount = am;
 newtovar->next = NULL;
 tmp->next = newtovar;
}

```

?printlist - ������ ����������� ������.

������� printlist ������� �� ����� ���������� ������ tovar.

1. �������� �� ������ ������: �����������, �������� �� ������ ������. ���� ������ ����, �� �������� ������.
2. ����� ������: ���� ������ �� ����, ������� �������� �� ������, ���� �� ��������� ����� ������.
3. ����� ������: ��� ������� �������� ������ ��������� �� ����� ��� ��� (name), ���� (price) � ���������� (amount).


```

cpp
void printlist(tovar* bufet) {
  while (bufet != NULL) {
    cout << "Name:" << bufet->name << " Price:" << bufet->price << " Amount:" << bufet->amount << "\n";
    bufet = bufet->next;
  }
}

```

?DelNode - �������� �������� �� ������.

������� DelNode ������� �� ������ tovar ������� � �������� ������ DelName.

1. �������� �� ������ ������: �����������, �������� �� ������ ������. ���� ������ ����, ������� ���������� 1, ������� �� ������.
2. �������� ������� ��������: ���� ������ ������� ������ ����� ��� DelName, �� ��������� bufet ��������� �� ��������� �������, ������ ������� ���������, � ������� ���������� 0.
3. �������� �� ������������ �������: ���� ������ ������� �� �������� ��������� � �� ������������ � ������, ������� ���������� 1, ������� �� ������.
4. ����� ���������� ��������: ������� �������� �� ������, ���� �� ������ ������� � ������ DelName ��� �� ��������� ����� ������.
5. �������� ��������: ���� ������� � ������ DelName ������, �� ������� ��������� �� ������ ����� ��������������� ��������� next ����������� �������� �� ��������� ������� �� ���������.
6. ��������� ������ �� ���������� ��������: ���� ��� ������ ������, ������� � ������ DelName �� ������, �� ������� ���������� 1, ������� �� ������.


```

cpp
int DelNode(tovar * &bufet, string DelName) {
 if (bufet == NULL) return 1;        
  tovar? tmp = bufet;
  if (bufet->name == DelName) {
    bufet = bufet->next;
    delete tmp;            
    return 0;
  }        
  if (bufet->next == NULL) return 1;
  tovar? prev = bufet;        
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

```

?main - ������� ������� ���������.

������� main ������������� ������������� ������� ��� ������ �� ������� tovar.

1. ������������� ������: ��������� ��������� bufet �� ������ ������������ ������ � ���������������� ��������� NULL.
2. ���������� ������: ���������� ������� addfirst, addafter, addbefove � addend ��� ���������� ��������� � ������.
3. ����� ������: ���������� ������� printlist ��� ������ ����������� ������ �� �����.
4. �������� ���������: ���������� ������� DelNode ��� �������� ���� ��������� �� ������.
5. ����� ������ ����� ��������: ���������� ������� printlist ��� ��� ��� ��������, ��� ������ ����.


```

cpp
int main()
{
  setlocale(LC_ALL, "rus");
  tovar* bufet = NULL; 
  addfirst(bufet, "Cake1", 20.34f, 10);
  addfirst(bufet, "Cake2", 19.43f, 8);
  addafter(bufet, "Cake3", 54.77f, 3, "Cake2");
  addbefove(bufet, "Cake4", 1.43f, 6, "Cake3");
  addbefove(bufet, "Cake5", 190.43f, 15, "Cake4");
  addend(bufet, "Cake6", 200.43f, 90);
  addbefove(bufet, "Cake7", 50.43f, 45, "Cake6");
  cout << "list:" << endl;
  printlist(bufet);
  DelNode(bufet, "Cake1");
  DelNode(bufet, "Cake2");
  DelNode(bufet, "Cake3");
  DelNode(bufet, "Cake4");
  DelNode(bufet, "Cake5");
  DelNode(bufet, "Cake6");
  DelNode(bufet, "Cake7");
  cout << "\n" << "������ ����� �������� ���������" << "\n";
  printlist(bufet);
  cout << "\n" << "��� ����� ������ ����";
  return 0;
}


```

� ���������� ���������� ��������� �� ����� ����� ������� ������ ������� � ������ � �� ����������, ������ � ������������, � ����� ������ ������ ����� �������� ���� ���������. ���� ��� ������������� ������������� �������� ������ � ������� ��� ������ � ����������� ������� � ����� ���������������� C++ ����� ������������� ����������� ������ ��� ����������� ����������� ��������.

```