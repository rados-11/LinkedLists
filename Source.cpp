#include <iostream>
#include "Header.h"
#include <iomanip>

struct Student {
	int id;
	std::string name;
	float grade;
	Student* next;
	Student(int id, std::string name, float grade, Student* next = nullptr) : id(id), name(name), grade(grade), next(next) {}
};

int listLenght(Student* head) {
	int i = 0;
	while (head) {
		i++;
		head = head->next;
	}
	return i;
}

void addAtBeginning(Student * &head, int i, std::string n, float g) {
	Student* s = new Student(i, n, g);
	if (head) s->next = head;
	head = s;
}

void addAtEnd(Student* &head, int i, std::string n, float g) {
	Student* s = new Student(i, n, g);
	if (!head) head = s;
	else {
		Student* last = nullptr;
		for (Student* curr = head; curr; curr = curr->next) last = curr;
		last->next = s;
	}
}

void addAtIndex(Student* &head, int i, std::string n, float g, int j) {
	if (!head && j > 1) throw InvalidList();
	else if (j <= 0) throw InvalidIndex();
	else if (j == 1) { addAtBeginning(head, i, n, g); return; }
	else if (j > listLenght(head) + 1) throw IndexOutOfRange();
	else {
		Student* s = new Student(i, n, g);
		int k = 1;
		Student* curr = head;
		while (curr) {
			if (k == j - 1) {
				s->next = curr->next;
				curr->next = s;
				break;
			}
			curr = curr->next;
			k++;
		}
	}
}

void deleteById(Student* &head, int i) {
	if (!head) throw InvalidList();
	if (head->id == i) {
		Student* temp = head;
		head = temp->next;
		delete temp;
		return;
	}
	else {
		Student* last = head;
		for (Student* curr = head; curr; curr = curr->next) {
			if (curr->id == i) {
				last->next = curr->next;
				delete curr;
				break;
			}
			last = curr;
		}
		return;
	}
}

void deleteByPostition(Student* &head, int k) {
	if (!head) throw InvalidList();
	else if (k > listLenght(head)) { throw IndexOutOfRange(); }
	else if (k < 0 && k != -1) { throw InvalidIndex(); }
	else if (k == 1) {
		Student* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	else {
		if (k == -1) k = listLenght(head);
		Student* curr = head;
		int i = 1;
		while (curr) {
			if (i == k - 1) {
				Student* temp = curr->next;
				curr->next = temp->next;
				delete temp;
				break;
			}
			curr = curr->next;
			i++;
		}
	}
}

void updateStudent(Student* head, int id, std::string n, float g, int i = 0) {
	if (!head) throw InvalidList();
	bool check = false;
	for (Student* curr = head; curr; curr = curr->next) {
		if (id == curr->id) {
			curr->name = n;
			curr->grade = g;
			curr->id = i == 0 ? id : i;
			check = true;
		}
	}
	if (!check) throw InvalidId();
}

void printStudents(Student* head) {
	if (!head) throw InvalidList();
	for (Student* curr = head; curr; curr = curr->next) {
		std::cout << curr->id << ' ' << curr->name << ' ' << curr->grade << std::endl;
	}
}

void printStudent(Student* head, int i) {
	if (!head) throw InvalidList();
	bool check = false;
	for (Student* curr = head; curr; curr = curr->next) {
		if (int i = curr->id) {
			std::cout << std::setw(2) << std::setfill('0') << curr->id << ' ' << curr->name << ' ' << curr->grade << std::endl;
			check = true;
		}
	}
	if (!check) throw InvalidId();
}

int main() {

	try {

		Student* head = nullptr;

		addAtBeginning(head, 1, "Andjela", 9.5);
		addAtEnd(head, 2, "Jovana", 9.5);
		addAtEnd(head, 3, "Darija", 9.5);
		addAtEnd(head, 4, "Nebojsa", 9.5);

		updateStudent(head, 2, "Jovana", 8.9);
		updateStudent(head, 4, "Nebojsa", 8.7, 5);
		updateStudent(head, 3, "Darija", 9.5, 4);
		addAtIndex(head, 3, "Nikola", 10, 1);

		deleteById(head, 1);
		deleteById(head, 4);

		addAtIndex(head, 11, "Rados", 6.5, 4);
		deleteByPostition(head, -1);

		updateStudent(head, 3, "Nikola", 10, 22);

		printStudents(head);

	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}