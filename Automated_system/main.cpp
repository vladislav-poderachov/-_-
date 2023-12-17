#include"header.h"

int main(){
 	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
// �� ������ ������� �������� ��� �������������
	vector<shared_ptr<Id<Person>>> users;
// ������� �� ����� ��� ������������������ ����� ��������
	accounts_ifstr(users);
	string login, password;
	int choice=0;
// ��������� ����������� ���� ��� ���� 
	do {
		cout << "������� ����� �� 1 �� 2 ��� ������� ����� 3, ����� �����." << endl;
		cout << "1.�����������" << endl;
		cout << "2.�����������" << endl;
		cout << "3.�����" << endl;
		input_check_int(choice);
		cin.clear();
		cin.ignore(1024, '\n');
		system("cls");
		if (choice == 1) {
			do {
				cout << "1.������������������ � �������� ������������" << endl;
				cout << "2.������������������ � �������� ���������" << endl;
				cout << "3.������������������ � �������� ��������������" << endl;
				cout << "4.����� � ������� ����" << endl;
				input_check_int(choice);
				cin.clear();
				cin.ignore(1024,'\n');
				system("cls");			
				if (choice == 1) {
					cout << "������� �����" << endl;
					reg_login(login);
					system("cls");
					cout << "������� ������" << endl;
					reg_password(password);
					system("cls");
					password += '1';
					ofstream out;
					out.open("accounts.txt", ios::app);
					out << password << endl;
					out.close();
					users.push_back(make_shared<Id<Person>>(new User(login, password)));
					while (true) {
						cout << "����������� ������ �������" << endl;
						cout << "1.���������� �������� �� ���� ��������" << endl;
						cout << "2.����� �� ������� ����" << endl;
						input_check_int(choice);
						system("cls");
						if (choice == 1) {
							users[users.size() - 1].operator->()->operator->()->menu();
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
					}
				}
				else if (choice == 2) {
					cout << "������� �����" << endl;
					reg_login(login);
					system("cls");
					cout << "������� ������" << endl;
					reg_password(password);
					system("cls");
					password += '2';
					ofstream out;
					out.open("accounts.txt", ios::app);
					out << password<<endl;
					out.close();
					users.push_back(make_shared<Id<Person>>(new Pharmacist(login, password)));
					while (true) {
						cout << "����������� ������ �������" << endl;
						cout << "1.���������� �������� �� ���� ��������" << endl;
						cout << "2.����� �� ������� ����" << endl;
						input_check_int(choice);
						system("cls");
						if (choice == 1) {
							users[users.size() - 1].operator->()->operator->()->menu();
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
					}
				}
				else if (choice == 3) {
					cout << "������� �����" << endl;
					reg_login(login);
					system("cls");
					cout << "������� ������" << endl;
					reg_password(password);
					system("cls");
					password += '3';
					ofstream out;
					out.open("accounts.txt", ios::app);
					out << password << endl;
					out.close();
					users.push_back(make_shared<Id<Person>>(new Administrator(login, password)));
					while (true) {
						cout << "����������� ������ �������" << endl;
						cout << "1.���������� �������� �� ���� ��������" << endl;
						cout << "2.����� �� ������� ����" << endl;
						input_check_int(choice);
						system("cls");
						if (choice == 1) {
							users[users.size() - 1].operator->()->operator->()->menu();
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout<<"������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
					}
				}
				else if (choice == 4) {
					break;
				}
				else {
					cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
				}
			} while (choice == 0 ||choice > 4);
		}
		else if (choice == 2) {
			bool log = 0, pass = 0;
			cout << "������� �����" << endl;
			getline(std::cin, login);
			cout << "������� ������" << endl;
			getline(cin, password);
			system("cls");
			encryption(password);
			password += '1';
			for (int i = 0; i < users.size(); i++) {
				if (users[i].operator->()->operator->()->get_login() == login) {
					log = 1;
					if (users[i].operator->()->operator->()->get_password() == password) {
						cout << "���� �������� �������." << endl;
						users[i].operator->()->operator->()->menu();
						pass = 1;
						break;
					}
					else {
						password[password.length() - 1] = '2';
						if (users[i].operator->()->operator->()->get_password() == password) {
							cout << "���� �������� �������." << endl;
							users[i].operator->()->operator->()->menu();
							pass = 1;
							break;
						}
						else {
							password[password.length() - 1] = '3';
							if (users[i].operator->()->operator->()->get_password() == password) {
								cout << "���� �������� �������." << endl;
								users[i].operator->()->operator->()->menu();
								pass = 1;
								break;
							}
						}
					}
				}
			}
			if (!log) {
				cout<<"�������� �����" << endl;
			}
			if (!pass) {
				cout << "�������� ������" << endl; 
			}
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
		}
	} while (true);
}