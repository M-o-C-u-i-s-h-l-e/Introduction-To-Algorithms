#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
	int info;
	Node *next;
};

class List {
public:
	Node *first, *last;
	List() {
		first = NULL;
		last = NULL;
	}
	void create();
	void insert();
	void del();
	void display();
	void search();
};

void List::create() {
	Node *temp = new Node;
	int n;
	cout << "Enter an element: ";
	cin >> n;
	temp->info = n;
	temp->next = NULL;
	if (first == NULL) {
		first = temp;
		last = temp;
	} else {
		last->next = temp;
		last = temp;
	}
}

void List::insert() {
	Node *prev = NULL;
	Node *cur = first;
	int Count = 1, pos, ch, n;
	Node *temp = new Node;
	cout << "Enter an element: ";
	cin >> n;
	temp->info = n;
	temp->next = NULL;
	cout << "1.As first\n2.As last\n3.In between first and last\n";
	cout << "Enter your choice: ";
	cin >> ch;
	switch(ch) {
		case 1:
			temp->next = first;
			first = temp;
			break;
		case 2:
			last->next = temp;
			last = temp;
			break;
		case 3:
			cout << "Enter the position to insert: ";
			cin >> pos;
			while (Count != pos) {
				prev = cur;
				cur = cur->next;
				Count++;
			}
			if (Count == pos) {
				prev->next = temp;
				temp->next = cur;
			} else {
				cout << "Not able to insert at the choosen position\n";
			}
			break;
	}
}

void List::del() {
	Node *prev = NULL;
	Node *cur = first;
	int Count = 1, pos, ch;
	cout << "1.fisrt\n2.last\n3.In between first and last\n";
	cout << "Enter your choice: ";
	cin >> ch;
	switch(ch) {
		case 1:
			if (first != NULL) {
				cout << "Deleted element is " << first->info << endl;
				first = first->next;
			} else {
				cout << "Not able to delete\n";
			}
			break;
		case 2:
			while (cur != last) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == last) {
				cout << "Deleted element is " << cur->info << endl;
				prev->next = NULL;
				last = prev;
			} else {
				cout << "Not able to delete\n";
			}
			break;
		case 3:
			cout << "Enter the position of deletion: ";
			cin >> pos;
			while (Count != pos) {
				prev = cur;
				cur = cur->next;
				Count++;
			}
			if (Count == pos) {
				cout << "Deleted element is " << cur->info << endl;
				prev->next = cur->next;
			} else {
				cout << "Not able to delete\n";
			}
			break;
	}
}

void List::display() {
	Node *temp = first;
	while (temp != NULL) {
		cout << temp->info << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

void List::search() {
	int value, pos = 0;
	bool flag = false;
	if (first == NULL) {
		cout << "List is empty\n";
		return;
	}
	cout << "Enter the value to be searched: ";
	cin >> value;
	Node *temp = first;
	while (temp != NULL) {
		pos++;
		if (temp->info == value) {
			flag = true;
			cout << "Element is found at " << pos << " position\n";
			return;
		}
		temp = temp->next;
	}
	if (!flag) {
		cout << "Element is not found\n";
	}
}

int main(void) {
	List ls;
	int ch;
	while (true) {
		cout << "\n***** MENU *****\n";
		cout << "1.Create\n2.Insert\n3.Delete\n4.Search\n5.Display\n6.Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;
		switch(ch) {
			case 1:
				ls.create();
				break;
			case 2:
				ls.insert();
				break;
			case 3:
				ls.del();
				break;
			case 4:
				ls.search();
				break;
			case 5:
				ls.display();
				break;
			case 6:
				return 0;
		}
	}
}
