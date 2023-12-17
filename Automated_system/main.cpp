#include"header.h"

int main(){
 	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
// Мы должны создать аккаунты для пользователей
	vector<shared_ptr<Id<Person>>> users;
// Считаем из файла все зарегистрированные ранее аккаунты
	accounts_ifstr(users);
	string login, password;
	int choice=0;
// Запускаем бесконечный цикл для меню 
	do {
		cout << "Введите число от 1 до 2 или введите число 3, чтобы выйти." << endl;
		cout << "1.Регистрация" << endl;
		cout << "2.Авторизация" << endl;
		cout << "3.Выход" << endl;
		input_check_int(choice);
		cin.clear();
		cin.ignore(1024, '\n');
		system("cls");
		if (choice == 1) {
			do {
				cout << "1.Зарегистрироваться в качестве пользователя" << endl;
				cout << "2.Зарегистрироваться в качестве провизора" << endl;
				cout << "3.Зарегистрироваться в качестве администратора" << endl;
				cout << "4.Выход в главное меню" << endl;
				input_check_int(choice);
				cin.clear();
				cin.ignore(1024,'\n');
				system("cls");			
				if (choice == 1) {
					cout << "Введите логин" << endl;
					reg_login(login);
					system("cls");
					cout << "Введите пароль" << endl;
					reg_password(password);
					system("cls");
					password += '1';
					ofstream out;
					out.open("accounts.txt", ios::app);
					out << password << endl;
					out.close();
					users.push_back(make_shared<Id<Person>>(new User(login, password)));
					while (true) {
						cout << "Регистрация прошла успешно" << endl;
						cout << "1.Продолжить работать на этом аккаунте" << endl;
						cout << "2.Выйти во входное меню" << endl;
						input_check_int(choice);
						system("cls");
						if (choice == 1) {
							users[users.size() - 1].operator->()->operator->()->menu();
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout << "Такого выбора не существует. Попробуйте ввести ещё раз" << endl;
						}
					}
				}
				else if (choice == 2) {
					cout << "Введите логин" << endl;
					reg_login(login);
					system("cls");
					cout << "Введите пароль" << endl;
					reg_password(password);
					system("cls");
					password += '2';
					ofstream out;
					out.open("accounts.txt", ios::app);
					out << password<<endl;
					out.close();
					users.push_back(make_shared<Id<Person>>(new Pharmacist(login, password)));
					while (true) {
						cout << "Регистрация прошла успешно" << endl;
						cout << "1.Продолжить работать на этом аккаунте" << endl;
						cout << "2.Выйти во входное меню" << endl;
						input_check_int(choice);
						system("cls");
						if (choice == 1) {
							users[users.size() - 1].operator->()->operator->()->menu();
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout << "Такого выбора не существует. Попробуйте ввести ещё раз" << endl;
						}
					}
				}
				else if (choice == 3) {
					cout << "Введите логин" << endl;
					reg_login(login);
					system("cls");
					cout << "Введите пароль" << endl;
					reg_password(password);
					system("cls");
					password += '3';
					ofstream out;
					out.open("accounts.txt", ios::app);
					out << password << endl;
					out.close();
					users.push_back(make_shared<Id<Person>>(new Administrator(login, password)));
					while (true) {
						cout << "Регистрация прошла успешно" << endl;
						cout << "1.Продолжить работать на этом аккаунте" << endl;
						cout << "2.Выйти во входное меню" << endl;
						input_check_int(choice);
						system("cls");
						if (choice == 1) {
							users[users.size() - 1].operator->()->operator->()->menu();
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout<<"Такого выбора не существует. Попробуйте ввести ещё раз" << endl;
						}
					}
				}
				else if (choice == 4) {
					break;
				}
				else {
					cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
				}
			} while (choice == 0 ||choice > 4);
		}
		else if (choice == 2) {
			bool log = 0, pass = 0;
			cout << "Введите логин" << endl;
			getline(std::cin, login);
			cout << "Введите пароль" << endl;
			getline(cin, password);
			system("cls");
			encryption(password);
			password += '1';
			for (int i = 0; i < users.size(); i++) {
				if (users[i].operator->()->operator->()->get_login() == login) {
					log = 1;
					if (users[i].operator->()->operator->()->get_password() == password) {
						cout << "Вход завершён успешно." << endl;
						users[i].operator->()->operator->()->menu();
						pass = 1;
						break;
					}
					else {
						password[password.length() - 1] = '2';
						if (users[i].operator->()->operator->()->get_password() == password) {
							cout << "Вход завершён успешно." << endl;
							users[i].operator->()->operator->()->menu();
							pass = 1;
							break;
						}
						else {
							password[password.length() - 1] = '3';
							if (users[i].operator->()->operator->()->get_password() == password) {
								cout << "Вход завершён успешно." << endl;
								users[i].operator->()->operator->()->menu();
								pass = 1;
								break;
							}
						}
					}
				}
			}
			if (!log) {
				cout<<"Неверный логин" << endl;
			}
			if (!pass) {
				cout << "Неверный пароль" << endl; 
			}
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
		}
	} while (true);
}