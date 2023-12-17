#include"header.h"
Person::Person(string login, string password) {
	this->login = login;
	this->password = password;
}
Person::Person() {
	login = "no login";
	password = "no password";
}
Person::~Person() {}
void Person::set_login() {
	getline(cin, login);
}
void Person::set_login(string login) {
	this->login = login;
}
void Person::set_password() {
	bool error_count, numbers, letters;
	do {
		error_count = false, letters = false, numbers = false;
		try {
			getline(cin, password);
			if (password.empty()) {
				throw 1;
			}
			else if (password.length() < 8) {
				throw 1.23;
			}
			else {
				for (int i = 0;i < password.length(); i++) {
					if (password[i] == ' ') {
						exception e1;
						throw e1;
					}
					if (password[i] == '0' || password[i] == '1' || password[i] == '2' || password[i] == '3' || password[i] == '4' || password[i] == '5' || password[i] == '6' || password[i] == '7' || password[i] == '8' || password[i] == '9') {
						numbers = true;
					}
					else if (isalpha(password[i])) {
						letters = true;
					}
					else if (!isascii(password[i])) {
						throw ' ';
					}
				}
				if (letters == false) {
					throw true;
				}
				if (numbers == false) {
					throw "";
				}
			}
		}
		catch (int) {
			cout << "�� ����� ������ ������. ���������� ������ ��� ���." << endl;
			error_count = true;
		}
		catch (float) {
			cout << "����� ������ ������ ���� �� ����� 8 ��������" << endl;
			error_count = true;
		}
		catch (const char*) {
			cout << "� ������ ������ ���� ���� �� 1 �����" << endl;
			error_count = true;
		}
		catch (bool) {
			cout << "� ������ ������ ���� ���� �� 1 �����" << endl;
			error_count = true;
		}
		catch (const char) {
			cout << "������� ������ ���������� �������." << endl;
			error_count = true;
		}
		catch (exception) {
			cout << "�� ������� �������" << endl;
			error_count = true;
		}

	} while (error_count);
}
void Person::set_password(string password) {
	this->password = password;
}
string Person::get_login() {
	return login;
}
string Person::get_password() {
	return password;
}
User::User() :Person() {

}
User::~User() {
}
User::User(string login, string password) : Person(login, password) {
}
vector<Product> User::get_medicine_cabinet() {
	return medicine_cabinet;
}
void User::set_medicine_cabinet() {
	this->medicine_cabinet = medicine_cabinet;
}
ostream& operator<<(ostream& os, vector<Product> medicine_cabinet) {
	if (medicine_cabinet.size() != 0) {
		horizontalLine(43);
		os << "| " << setw(30) << left << "�������� ������" << " | " << " ���� " << " |" << endl;
		for (int i = 0; i < medicine_cabinet.size(); i++) {
			os << "| " << setw(30) << medicine_cabinet[i].get_product_name() << " | " << setw(6) << medicine_cabinet[i].get_price() << " |" << endl;
			horizontalLine(43);
			return os << medicine_cabinet;
		}
	}
	else {
		return os << "�������� ���" << endl;
	}
}
ostream& operator<<(ostream& os, Product product) {
	horizontalLine(75);
	os << "| " << setw(30) << "�������� ������" << " | " << "���� ��������" << " | " << "�������� ������" << " | " << "����" << " |" << endl;
	os << product.get_product_name() << product.get_expiration_date() << product.get_description() << product.get_price() << endl;
	return os << product;
}
void User::menu() {
	int choice = 0;
	string medicine = "";
	while (true) {
		cout << "1.����� ��������" << endl;
		cout << "2.��� �������" << endl;
		cout << "3.������������" << endl;
		cout << "4.�����" << endl;
		input_check_int(choice);
		system("cls");
		if (choice == 1) {
			ifstream out;
			out.open("drugstores.txt");
			int i;
			string line = "";
			vector<Drugstore> drugstore_net;
			while (getline(out,line)) {
				i = 0;
				drugstore_net.push_back(Drugstore());
				out.read((char*)&drugstore_net[i], sizeof(Drugstore));
				i++;
			}
			out.close();
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������� �������� ���������" << endl;
			while (true) {
				getline(cin, medicine);
				if (medicine.empty()) {
					cout << "�� ����� ������ ������." << endl;
				}
				else {
					break;
				}
			}
			for (int i = 0; i < drugstore_net.size();i++) {
				for (int j = 0; j < drugstore_net[i].get_medicines().size();j++) {
					if (drugstore_net[i].get_medicines(j).get_product_name() == medicine) {
						while (true) {
							cout << drugstore_net[i].get_medicines()[j] << endl;
							cout << "1.�������� � ��� �������" << endl;
							cout << "2.����� � ������� ����" << endl;
							input_check_int(choice);
							system("cls");
							if (choice == 1) {
								vector<Product> medicine_cabinets;
								medicine_cabinets.push_back(drugstore_net[i].get_medicines(j));
								ifstream inp;
								inp.open("medicine_cabinets.bin", ios::binary);
								if (inp.is_open()) {
									int i = 0;
									while (inp) {
										i++;
									}
								}
								out.close();
								ofstream out;
								out.open("medicine_cabinets.bin", ios::app);
								for (int i = 0; i < medicine_cabinets.size(); i++) {
									out.write((char*)&medicine_cabinet[i], sizeof(Product));
								}
								out.close();
							}
							else if (choice == 2) {
								break;
							}
							else {
								cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
						}
						break;
					}
				}
			}
		}
		else if (choice == 2) {
			int input = 0;
			while (true) {
				cout << "1.����������� ��� �������" << endl;
				cout << "2.������ �� ���� �������" << endl;
				cout << "3.����� � ������� ����" << endl;
				input_check_int(choice);
				system("cls");
				if (input == 0 && choice < 3) {
					ifstream out;
					string line = "", m_login = "", prod_name = "", address = "";
					out.open("medicine_cabinets.txt");
					if (out.is_open()) {
						while (getline(out, line)) {
							int i = 0, j = 0;
							while (line[i] != '\t') {
								m_login += line[i];
								i++;
							}
							i++;
							while (i != line.length() - 1) {
								prod_name += line[i];
								i++;
							}
							if (m_login == get_login()) {
								get_medicine_cabinet().push_back(Product());
								get_medicine_cabinet()[j].set_product_name(prod_name);
							}
						}

					}
					else {
						ofstream out;
						out.open("medicine_cabinets.txt");
						out.close();
					}
					out.close();
					input++;
				}
				if (choice == 1) {
					cout << medicine_cabinet;
					system("pause");
					system("cls");
				}
				else if (choice == 2) {
					vector<string> products, logins;
					string medicine;
					while (true) {
						cout << medicine_cabinet;
						if (medicine_cabinet.size() != 0) {
							cin.clear();
							cin.ignore(1024, '\n');
							cout << "������� �������� ��������� � ������, ������� ������ ������� �� ����� �������." << endl;
							getline(cin, medicine);
							system("cls");
							int j = 0;
							for (j = 0; j < medicine_cabinet.size(); j++) {
								if (medicine_cabinet[j].get_product_name() == medicine) {
									vector<Product>::iterator it = medicine_cabinet.begin() += j;
									medicine_cabinet.erase(it);
									ifstream out;
									out.open("medicine_cabinets.txt");
									if (out.is_open()) {
										string line = "", m_login = "", prod_name = "";
										while (getline(out, line)) {
											int i = 0;
											while (line[i] != '\t') {
												m_login += line[i];
												i++;
											}
											i++;
											while (i != line.length() - 1) {
												prod_name += line[i];
											}
											if (m_login != get_login() || prod_name != medicine) {
												logins.push_back(m_login);
												products.push_back(prod_name);
											}
										}
									}
									out.close();
									ofstream inp;
									inp.open("medicine_cabinets.txt", ios::out);
									if (inp.is_open()) {
										for (int i = 0; i < logins.size(); i++) {
											inp << logins[i] << '\t' << products[i] << endl;
										}
									}
									inp.close();
									break;
								}
							}
							if (j == medicine_cabinet.size()) {
								cout << "������ ��������� � ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
							else if (medicine_cabinet.size() != 0) {
								while (true) {
									cout << "1.���������� ������� ��������� �� <���� �������>" << endl;
									cout << "2.�����" << endl;
									input_check_int(choice);
									system("cls");
									if (choice == 1) {
										break;
									}
									else if (choice == 2) {
										break;
									}
									else {
										cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
									}
								}
								if (choice == 2) {
									break;
								}
							}
						}
						else {
							system("pause");
							system("cls");
							break;
						}
					}
				}
				else if (choice == 3) {
					break;
				}
				else {
					cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
				}
			}
		}
		else if (choice == 3) {
			while (true) {
				cout << "1.�������� ������" << endl;
				cout << "2.����� � ������� ����" << endl;
				input_check_int(choice);
				system("cls");
				if (choice == 1) {
					change_password(get_login(), get_password());
					system("pause");
					break;
				}
				else if (choice == 2) {
					break;
				}
				else {
					cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
				}
			}
		}
		else if (choice == 4) {
			break;
		}
		else {
			cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
		}
	}
}
Pharmacist::Pharmacist(string login, string password) :Person(login, password) {
}
void Pharmacist::set_drugstore_net(vector<Drugstore> drugstore_net) {
	this->drugstore_net = drugstore_net;
}
vector<Drugstore> Pharmacist::get_drugstore_net() {
	return drugstore_net;
}
void Administrator::set_drugstore_net(vector<Drugstore> drugstore_net) {
	this->drugstore_net = drugstore_net;
}
vector<Drugstore> Administrator::get_drugstore_net() {
	return drugstore_net;
}
Administrator::Administrator(string login, string password) : Person(login, password) {
}
void Pharmacist::menu() {
	ifstream out;
	out.open("warehouse.bin", ios::binary);
	Warehouse warehouse;
	while (out) {
		out.read((char*)&warehouse, sizeof(Warehouse));
	}
	int choice = 0, address = 0, input=0;
		while (true) {
		cout << "1.������� ������ ������" << endl;
		cout << "2.������� ����� �� ������" << endl;
		cout << "3.��������� ����� �� �����" << endl;
		cout << "4.������� ������ �� �����" << endl;
		cout << "5.��������� ����� � ��������� ������" << endl;
		cout << "6.����������� �����" << endl;
		cout << "7.�����" << endl;
		input_check_int(choice);
		system("cls");
		if (input == 0 && choice < 7) {
			ifstream out;

		}
		if (choice == 1) {
			if (address == 0) {
				while (true) {
					for (address = 0; address < drugstore_net.size(); address++) {
						cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
					}
					cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
					input_check_int(address);
					system("cls");
					if (address > drugstore_net.size()) {
						cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
					}
					else {
						break;
					}
				}
			}
			else {
				while (true) {
					cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
					cout << "2.������ �������� � ������ �� ������� ������" << endl;
					input_check_int(choice);
					if (choice == 1) {
						break;
					}
					else if (choice == 2) {
						while (true) {
							int p = 0;
							for (p = 0; p < drugstore_net.size(); p++) {
								cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(p);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								if (p == address) {
									while (true) {
										cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
										cout << "1.��" << endl;
										cout << "2.���" << endl;
										input_check_int(choice);
										if (choice == 1) {
											break;
										}
										else if (choice == 2) {
											continue;
										}
										else {
											cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
										}
									}
								}
								break;
							}
						}
					}
					else {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
					}
				}
			}
			int count = 0;
			string product_name, expiration_date, description;
			float price;
			vector<Product> products=drugstore_net[address-1].get_medicines();
			while (true) {
				cout << "������� �������� ������" << endl;
				getline(cin, product_name);
				cout << "������� ���� �������� ������" << endl;
				getline(cin, expiration_date);
				cout << "������� �������� ������" << endl;
				getline(cin, description);
				cout << "������� ���� ������" << endl;
				input_check_float(price);
				cout << "������� ���������� ������" << endl;
				input_check_int(count);
				products.push_back(Product(product_name, expiration_date, description, price, count));
				while (true) {
					cout << "1.���������� ������ ��������� ������" << endl;
					cout << "2.��������� ������ ��������� ������" << endl;
					input_check_int(choice);
					system("cls");
					if (choice == 1) {
						continue;
					}
					else if (choice == 2) {
						drugstore_net[address - 1].set_medicines(products);
						ofstream out;
						out.open("products.bin", ios::binary||out);
						for (int i = 0; i < products.size(); i++) {

						}
						out.close();
						break;
					}
					else {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
					}
				}
			}
		}
		else if (choice == 2) {
			if (address == 0) {
				while (true) {
					for (address = 0; address < drugstore_net.size(); address++) {
						cout << address + 1 << "." << drugstore_net[address].get_address() << endl;
					}
					cout << "������� ����� ������, � ������� ������ ������� �����" << endl;
					input_check_int(address);
					system("cls");
					if (address > drugstore_net.size()) {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
					}
					else {
						break;
					}

				}
			}
			else {
				while (true) {
					cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
					cout << "2.������ �������� � ������ �� ������� ������" << endl;
					input_check_int(choice);
					if (choice == 1) {
						break;
					}
					else if (choice == 2) {
						while (true) {
							int p = 0;
							for (p = 0; p < drugstore_net.size(); p++) {
								cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(p);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								if (p == address) {
									while (true) {
										cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
										cout << "1.��" << endl;
										cout << "2.���" << endl;
										input_check_int(choice);
										if (choice == 1) {
											break;
										}
										else if (choice == 2) {
											continue;
										}
										else {
											cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
										}
									}
								}
								break;
							}
						}
					}
					else {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
					}
				}
			}
			ifstream out;
			out.open("warehouse.bin", ios::binary);
			Warehouse warehouse;
			while (out) {
				out.read((char*)&warehouse, sizeof(Warehouse));
			}
			out.close();
			for (int i = 0; i < warehouse.get_medicines().size(); i++) {
				cout << warehouse.get_medicines() << endl;
			}
			string product;
			cout << " ������� �������� ���������, ������� ������ ������� �� ������" << endl;
			getline(cin, product);
			int i = 0;
			for (i = 0; i < warehouse.get_medicines().size(); i++) {
				if (product == warehouse.get_medicines()[i].get_product_name()) {
					int counter = 0;
					for (int j = 0; j < warehouse.get_medicines().size(); j++) {
						if (product == warehouse.get_medicines()[j].get_product_name()) {
							counter++;
						}
					}
					while (true) {
						cout << "������� ���������� ������ <" << warehouse.get_medicines()[i].get_product_name() << ">, ������� ������ �������" << endl;
						input_check_int(choice);
						if (choice > counter) {
							cout << " ������ �� ������ ��� � ����� ����������. ���������� ������ ��� ���" << endl;
							cout << "������� �� �� ������� ������ ����������?" << endl;
							cout << "1.��" << endl;
							cout << "2.���" << endl;
							input_check_int(choice);
							if (choice == 1) {
								continue;
							}
							else if (choice == 2) {
								break;
							}
							else {
								cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
						}
						else {
							for (int p = 0; p < warehouse.get_medicines().size(); p++) {
								if (product == warehouse.get_medicines()[p].get_product_name()) {
									drugstore_net[address - 1].get_medicines().push_back(warehouse.get_medicines()[p]);
									vector<Product>::iterator it = warehouse.get_medicines().begin() += p;
									warehouse.get_medicines().erase(it);
								}
							}
						}
					}
				}
			}
			if (i == warehouse.get_medicines().size()) {
				cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
			}
			else {
				break;
			}
		}
		else if (choice == 3) {
			if (address == 0) {
				while (true) {
					for (address = 0; address < drugstore_net.size(); address++) {
						cout << address + 1 << "." << drugstore_net[address].get_address() << endl;
					}
					cout << "������� ����� ������, � ������� ������ ������� �����" << endl;
					input_check_int(address);
					system("cls");
					if (address > drugstore_net.size()) {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
					}
					else {
						break;
					}

				}
			}
			else {
				while (true) {
					cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
					cout << "2.������ �������� � ������ �� ������� ������" << endl;
					input_check_int(choice);
					if (choice == 1) {
						break;
					}
					else if (choice == 2) {
						while (true) {
							int p = 0;
							for (p = 0; p < drugstore_net.size(); p++) {
								cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(p);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								if (p == address) {
									while (true) {
										cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
										cout << "1.��" << endl;
										cout << "2.���" << endl;
										input_check_int(choice);
										if (choice == 1) {
											break;
										}
										else if (choice == 2) {
											continue;
										}
										else {
											cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
										}
									}
								}
								break;
							}
						}
					}
					else {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
					}
				}
			}
			for (int i = 0; i < drugstore_net[address - 1].get_medicines().size(); i++) {
				cout << drugstore_net[address - 1].get_medicines() << endl;
			}
			while (true) {
				string product;
				vector<Product> products = drugstore_net[address - 1].get_medicines();
				cout << "�������� �������� ������, ������� ������ ��������� �� �����" << endl;
				getline(cin, product);
				for (int i = 0; i < drugstore_net[address - 1].get_medicines().size(); i++) {
					if (product == drugstore_net[address - 1].get_medicines()[i].get_product_name()) {
						int counter = 0;
						for (int j = 0; j < drugstore_net[address - 1].get_medicines().size(); j++) {
							if (product == drugstore_net[address - 1].get_medicines()[j].get_product_name()) {
								counter++;
							}
						}
						cout << "������� ���������� ������ " << product << ", ������� ������ ��������� �� ����� (����� ��������� �� ����� " << counter << ")" << endl;
						input_check_int(choice);
						if (choice > counter) {
							cout << "������ ��� � ����� ����������. ���������� ������ ��� ���" << endl;
						}
						else {
							int j = 0;
							while (counter != 0) {
								if (product == drugstore_net[address - 1].get_medicines()[j].get_product_name()) {
									counter--;
									products.push_back(drugstore_net[address - 1].get_medicines()[j]);
									vector<Product>::iterator it = drugstore_net[address - 1].get_medicines().begin() + j;
									drugstore_net[address - 1].get_medicines().erase(it);
									j--;
								}
								j++;
							}
						}
						break;
					}
				}
			while (true) {
				cout << "1.���������� ������ ������ ��� ����������� �� �����" << endl;
				cout << "2.��������� ������ ������ ��� ����������� �� �����" << endl;
				input_check_int(choice);
				if (choice == 1) {
					continue;
				}
				else if (choice == 2) {
					drugstore_net[address - 1].set_medicines(products);
				}
				else {
					cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
					continue;
				}
				break;
			}
		}
	}
		else if (choice == 4) {
			cout << "1.������� ������ �� ����� � ����� ������" << endl;;
			cout << "2.������� ������ �� ����� �� ���� �������" << endl;
			cout << "3.�����" << endl;
			input_check_int(choice);
			if (choice == 1) {
				if (address == 0) {
					while (true) {
						for (address = 0; address < drugstore_net.size(); address++) {
							cout << address + 1 << "." << drugstore_net[address].get_address() << endl;
						}
						cout << "������� ����� ������, � ������� ������ ������� �����" << endl;
						input_check_int(address);
						system("cls");
						if (address > drugstore_net.size()) {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
						else {
							break;
						}

					}
				}
				else {
					while (true) {
						cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
						cout << "2.������ �������� � ������ �� ������� ������" << endl;
						input_check_int(choice);
						if (choice == 1) {
							break;
						}
						else if (choice == 2) {
							while (true) {
								int p = 0;
								for (p = 0; p < drugstore_net.size(); p++) {
									cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
								}
								cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
								input_check_int(p);
								system("cls");
								if (address > drugstore_net.size()) {
									cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
								}
								else {
									if (p == address) {
										while (true) {
											cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
											cout << "1.��" << endl;
											cout << "2.���" << endl;
											input_check_int(choice);
											if (choice == 1) {
												break;
											}
											else if (choice == 2) {
												continue;
											}
											else {
												cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
											}
										}
									}
									break;
								}
							}
						}
						else {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
						}
					}
				}
			}
			while (true) {
				cout << drugstore_net[address - 1].get_medicines();
				int answer=0;
				cout << "�������� �����, �� ������� ������ ������� ������" << endl;
				input_check_int(choice);
				system("cls");
				if (choice > drugstore_net[address - 1].get_medicines().size()) {
					cout << " ������ ������ �� ����������. ���������� ������ ��� ���" << endl;
				}
				else {
					ifstream e;
					e.open("reduction.txt");
					string line;
					while (getline(e, line)) {
						string prod_name;
						int i = 0;
						while (i != ' ') {
							prod_name += line[i];
						}
						if (prod_name == drugstore_net[address - 1].get_medicines()[choice - 1].get_product_name()) {
							while (true) {
								cout << "������ ����� ��� ������� �� �������. �������� ������" << endl;
								cout << "1.��" << endl;
								cout << "2.���" << endl;
								input_check_int(answer);
								if (answer== 1) {
									int procent;
									cout << "������� ����� ������ ������ � ��������� (�� ����� 10%) �� ����� " << drugstore_net[address - 1].get_medicines()[choice - 1].get_product_name() << endl;
									input_check_int(procent);
									if (procent > 10) {
										cout << "������ �� ����� ���� ����� 10%. ������� ��� ���" << endl;
									}
									else {
										e.seekg(0, ios::beg);
										vector<string> reduction_products;
										vector<int > reductions;
										string line;
										while (getline(e, line)) {
											int i = 0;
											string prod_name = "", reduction = "";
											while (i != ' ') {
												prod_name += line[i];
											}
											i++;
											reduction_products.push_back(prod_name);
											if (prod_name == drugstore_net[address - 1].get_medicines()[choice - 1].get_product_name()) {
												reductions.push_back(procent);
											}
											else {
												while (i != line.length()) {
													reduction += line[i];
												}
												reductions.push_back(stoi(reduction));
											}
										}
										e.close();
										ofstream inp;
										inp.open("reduction.txt", ios::out);
										for (int i = 0; i < reductions.size(); i++) {
											inp << reduction_products[i] << " " << reductions[i] << endl;
										}
										inp.close();
										break;
									}
								}
								else if (answer== 2) {
									break;
								}
								else {
									cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
								}
							}
						}
					}
					if (answer!=0) {
						int procent;
						while (true) {
							cout << "������� � ��������� ������ ������, ������� ������ ������� �� ����� " << drugstore_net[address - 1].get_medicines()[choice - 1].get_product_name() << "(�� ����� 10%)" << endl;
							input_check_int(procent);
							if (procent > 10) {
								cout << "������ ����� ���� �� ����� 10%. ���������� ������ ��� ���" << endl;
							}
							else {
								ofstream out;
								out.open("reduction.txt", ios::app);
								out << drugstore_net[address - 1].get_medicines()[choice - 1].get_product_name() << " " << procent;
								out.close();
								break;
							}
						}
					}
				}
			}
		}
		else if (choice == 5) {
			if (address == 0) {
				while (true) {
					for (address = 0; address < drugstore_net.size(); address++) {
						cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
					}
					cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
					input_check_int(address);
					system("cls");
					if (address > drugstore_net.size()) {
						cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
					}
					else {
						break;
					}
				}
			}
			else {
				while (true) {
					cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
					cout << "2.������ �������� � ������ �� ������� ������" << endl;
					input_check_int(choice);
					if (choice == 1) {
						break;
					}
					else if (choice == 2) {
						while (true) {
							int p = 0;
							for (p = 0; p < drugstore_net.size(); p++) {
								cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(p);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								if (p == address) {
									while (true) {
										cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
										cout << "1.��" << endl;
										cout << "2.���" << endl;
										input_check_int(choice);
										if (choice == 1) {
											break;
										}
										else if (choice == 2) {
											continue;
										}
										else {
											cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
										}
									}
								}
								break;
							}
						}
					}
					else {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
					}
				}
			}
			int count = 0;
			string product_name, expiration_date, description;
			float price;
			vector<Product> products = drugstore_net[address - 1].get_medicines();
			while (true) {
				cout << drugstore_net[address - 1].get_medicines().size();
				cout << "������� �������� ������������ ������" << endl;
				getline(cin, product_name);
				for (int i = 0; i < drugstore_net[address - 1].get_medicines().size(); i++) {
					if (product_name == drugstore_net[address - 1].get_medicines()[i].get_product_name()) {
						count++;
					}
				}
				if (count == 0) {
					cout << "������ ������ ��� � �������. " << endl;
				}
				else {
					while (true) {
						cout << "������� ���������� ������������ ������ " << product_name << " (����� ������� �� ����� " << count << ")" << endl;
						input_check_int(choice);
						if (choice > count) {
							cout << "������ ������� ����� � ����� ����������. ���������� ������ ��� ���" << endl;
						}
						else {
							vector<Product>::iterator it = drugstore_net[address - 1].get_medicines().begin();
							while (choice != 0) {
								if (product_name == it->get_product_name()) {
									products.erase(it);
									it--;
								}
								it++;
							}
							drugstore_net[address - 1].set_medicines(products);
							break;
						}
					}
					while (true) {
						cout << "1.���������� ���������� ����� � ����������� ������" << endl;
						cout << "2.��������� ����������� ������" << endl;
						input_check_int(choice);
						if (choice == 1) {
							continue;
						}
						else if (choice == 2) {
							break;
						}
						else {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
					}
				}
			}
		}
		else if (choice == 6) {
			while (true) {
				cout << "1.����������� ���� �����" << endl;
				cout << "2.����������� �������� ���������� ������" << endl;
				cout << "3.����������� �������� ���������� ������" << endl;
				cout << "4.����������� ������, ������� ����� ����������" << endl;
				cout << "5.����������� ������, � ������� ����� ���������� ���� ��������" << endl;
				cout << "6.����������� ������, � ������� ���� ���� ��������" << endl;
				cout << "7.�����" << endl;
				input_check_int(choice);
				if (choice == 1) {
					while (true) {
						cout << "1.����������� ����� � ���������� ������" << endl;
						cout << "2.����������� ���� ����� �� ���� �������" << endl;
						cout << "3.�����" << endl;
						input_check_int(choice);
						if (choice == 1) {
							if (address == 0) {
								while (true) {
									for (address = 0; address < drugstore_net.size(); address++) {
										cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
									}
									cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
									input_check_int(address);
									system("cls");
									if (address > drugstore_net.size()) {
										cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
									}
									else {
										break;
									}
								}
							}
							else {
								while (true) {
									cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
									cout << "2.������ �������� � ������ �� ������� ������" << endl;
									input_check_int(choice);
									if (choice == 1) {
										break;
									}
									else if (choice == 2) {
										while (true) {
											int p = 0;
											for (p = 0; p < drugstore_net.size(); p++) {
												cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
											}
											cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
											input_check_int(p);
											system("cls");
											if (address > drugstore_net.size()) {
												cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
											}
											else {
												if (p == address) {
													while (true) {
														cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
														cout << "1.��" << endl;
														cout << "2.���" << endl;
														input_check_int(choice);
														if (choice == 1) {
															break;
														}
														else if (choice == 2) {
															continue;
														}
														else {
															cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
														}
													}
												}
												break;
											}
										}
									}
									else {
										cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
									}
								}
							}
							cout << drugstore_net[address - 1].get_medicines() << endl;
						}
						else if (choice == 2) {
							for (int i = 0; i < drugstore_net.size(); i++) {
								cout << drugstore_net[i].get_medicines() << endl;
							}
						}
						else {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
					}
				}
				else if (choice == 2) {
					vector<int> sales_counts;
					vector<string> sales_products;
					string sales, salescount, salesproduct;
					ifstream out;
					out.open("sales.txt");
					while (getline(out, sales)) {
						int i = sales.length();
						while (i != ' ') {
							salescount += sales[i];
							i--;
						}
						sales_counts.push_back(stoi(salescount));
						i--;
						while (i >= 0) {
							salesproduct += sales[i];
							i--;
						}
						sales_products.push_back(salesproduct);
					}
					out.close();
				}
				else if (choice == 3) {
					vector<int> sales_counts;
					vector<string> sales_products;
					string sales, salescount, salesproduct;
					ifstream out;
					out.open("sales.txt");
					while (getline(out, sales)) {
						int i = sales.length();
						while (i != ' ') {
							salescount += sales[i];
							i--;
						}
						sales_counts.push_back(stoi(salescount));
						i--;
						while (i >= 0) {
							salesproduct += sales[i];
							i--;
						}
						sales_products.push_back(salesproduct);
					}
					out.close();
				}
				else if (choice == 4) {
					for (int i = 0; i < drugstore_net.size(); i++) {
						for (int j = 0; j < drugstore_net[i].get_medicines().size(); j++) {
							int counter = 0;
							string prod_name = drugstore_net[i].get_medicines()[j].get_product_name();
							vector<Product> prod_out = drugstore_net[i].get_medicines();
							for (int f = 0; f < prod_out.size(); f++) {
								if (prod_name == prod_out[f].get_product_name()) {
									counter++;
								}
							}

						}
					}
				}
				else if (choice == 5) {
					while (true) {
						cout << "1.������� ������, � ������� ����� ���������� ���� �������� � ����� ������" << endl;
						cout << "2.������� ������, � ������� ����� ���������� ���� �������� �� ���� �������" << endl;
						cout << "�����" << endl;
						input_check_int(choice);
						if (choice == 1) {
							if (address == 0) {
								while (true) {
									for (address = 0; address < drugstore_net.size(); address++) {
										cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
									}
									cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
									input_check_int(address);
									system("cls");
									if (address > drugstore_net.size()) {
										cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
									}
									else {
										break;
									}
								}
							}
							else {
								while (true) {
									cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
									cout << "2.������ �������� � ������ �� ������� ������" << endl;
									input_check_int(choice);
									if (choice == 1) {
										break;
									}
									else if (choice == 2) {
										while (true) {
											int p = 0;
											for (p = 0; p < drugstore_net.size(); p++) {
												cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
											}
											cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
											input_check_int(p);
											system("cls");
											if (address > drugstore_net.size()) {
												cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
											}
											else {
												if (p == address) {
													while (true) {
														cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
														cout << "1.��" << endl;
														cout << "2.���" << endl;
														input_check_int(choice);
														if (choice == 1) {
															break;
														}
														else if (choice == 2) {
															continue;
														}
														else {
															cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
														}
													}
												}
												break;
											}
										}
									}
									else {
										cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
									}
								}
							}
							time_t t = time(nullptr);
							tm now;
							localtime_s(&now, &t);
							bool out = false;
							for (int i = 0; i < drugstore_net[address - 1].get_medicines().size(); i++) {
								string month = "", year="";
								year+= drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[3] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[4]+=drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[5] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[6];
								month+= drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[0] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[1];
								if (stoi(month) == now.tm_mon&&stoi(year)== now.tm_year + 1900) {
									cout << drugstore_net[address - 1].get_medicines()[i] << endl;
									out = true;
									
								}
							}
							if (!out) {
								cout<<"�������, � ������� ����� ���������� ���� ��������, �� ������ " << drugstore_net[address - 1].get_address()<<" �� �������" << endl;
							}
						}
						else if (choice == 2) {
							time_t t = time(nullptr);
							tm now;
							bool outp = false;
							localtime_s(&now, &t);
							for (int j = 0; j < drugstore_net.size(); j++) {
								for (int i = 0; i < drugstore_net[j].get_medicines().size(); i++) {
									string month = "", year = "";
									year += drugstore_net[j].get_medicines()[i].get_expiration_date()[3] += drugstore_net[j].get_medicines()[i].get_expiration_date()[4] += drugstore_net[j].get_medicines()[i].get_expiration_date()[5] += drugstore_net[j].get_medicines()[i].get_expiration_date()[6];
									month += drugstore_net[j].get_medicines()[i].get_expiration_date()[0] += drugstore_net[j].get_medicines()[i].get_expiration_date()[1];
									if (stoi(month) == now.tm_mon && stoi(year) == now.tm_year + 1900) {
										cout << drugstore_net[j].get_medicines()[i] << endl;
										outp = true;
									}
								}
							}
							if (!outp) {
								cout<<"�������, � ������� ����� ���������� ���� ��������, �� ���� ������� �� �������." << endl;
							}
						}
						else if (choice == 3) {
							break;
						}
						else {
							cout<<"������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
					}
				}
				else if (choice == 6) {
				while (true) {
					cout << "1.������� ������, � ������� ���� ���� �������� � ����� ������" << endl;
					cout << "2.������� ������, � ������� ���� ���� �������� �� ���� �������" << endl;
					cout << "�����" << endl;
					input_check_int(choice);
					if (choice == 1) {
						if (address == 0) {
							while (true) {
								for (address = 0; address < drugstore_net.size(); address++) {
									cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
								}
								cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
								input_check_int(address);
								system("cls");
								if (address > drugstore_net.size()) {
									cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
								}
								else {
									break;
								}
							}
						}
						else {
							while (true) {
								cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
								cout << "2.������ �������� � ������ �� ������� ������" << endl;
								input_check_int(choice);
								if (choice == 1) {
									break;
								}
								else if (choice == 2) {
									while (true) {
										int p = 0;
										for (p = 0; p < drugstore_net.size(); p++) {
											cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
										}
										cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
										input_check_int(p);
										system("cls");
										if (address > drugstore_net.size()) {
											cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
										}
										else {
											if (p == address) {
												while (true) {
													cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
													cout << "1.��" << endl;
													cout << "2.���" << endl;
													input_check_int(choice);
													if (choice == 1) {
														break;
													}
													else if (choice == 2) {
														continue;
													}
													else {
														cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
													}
												}
											}
											break;
										}
									}
								}
								else {
									cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
								}
							}
						}
						time_t t = time(nullptr);
						tm now;
						localtime_s(&now, &t);
						bool out = false;
						for (int i = 0; i < drugstore_net[address - 1].get_medicines().size(); i++) {
							string month = "", year = "";
							year += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[3] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[4] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[5] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[6];
							month += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[0] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[1];
							if (stoi(month) >= now.tm_mon+1 && stoi(year) == now.tm_year + 1900 || stoi(year) > now.tm_year + 1900) {
								cout << drugstore_net[address - 1].get_medicines()[i] << endl;
								out = true;
							}
						}
						if (!out) {
							cout << "�������, � ������� ���� ���� ��������, �� ������ " << drugstore_net[address - 1].get_address() << " �� �������" << endl;
						}
						else {
							while (true) {
								cout << "1.����� ����� � ������� ������ �������� � ������� � ������ �� ������ "<< drugstore_net[address - 1].get_address() << endl;
								cout << "2.�����" << endl;
								input_check_int(choice);
								if (choice == 1) {
									for (int j = 0; j < drugstore_net.size(); j++) {
										vector<Product> products = drugstore_net[j].get_medicines();
										vector<Product>::iterator it = products.begin();
										for (int i = 0; i < drugstore_net[j].get_medicines().size(); i++) {
											string month = "", year = "";
											year += drugstore_net[j].get_medicines()[i].get_expiration_date()[3] += drugstore_net[j].get_medicines()[i].get_expiration_date()[4] += drugstore_net[j].get_medicines()[i].get_expiration_date()[5] += drugstore_net[j].get_medicines()[i].get_expiration_date()[6];
											month += drugstore_net[j].get_medicines()[i].get_expiration_date()[0] += drugstore_net[j].get_medicines()[i].get_expiration_date()[1];
											if (stoi(month) >= now.tm_mon + 1 && stoi(year) == now.tm_year + 1900 || stoi(year) > now.tm_year + 1900) {
												it += i;
												products.erase(it);
											}
										}
										drugstore_net[j].set_medicines(products);
									}

								}
								else if (choice == 2) {
									break;
								}
								else {
									cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
								}
							}
						}
					}
					else if (choice == 2) {
						time_t t = time(nullptr);
						tm now;
						bool outp = false;
						localtime_s(&now, &t);
							for (int i = 0; i < drugstore_net[address-1].get_medicines().size(); i++) {
								string month = "", year = "";
								year += drugstore_net[address-1].get_medicines()[i].get_expiration_date()[3] += drugstore_net[address-1].get_medicines()[i].get_expiration_date()[4] += drugstore_net[address-1].get_medicines()[i].get_expiration_date()[5] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[6];
								month += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[0] += drugstore_net[address - 1].get_medicines()[i].get_expiration_date()[1];
								if (stoi(month) >= now.tm_mon+1 && stoi(year) == now.tm_year + 1900|| stoi(year) > now.tm_year + 1900) {
									cout << drugstore_net[address - 1].get_medicines()[i] << endl;
									outp = true;
								}
							}
						if (!outp) {
							cout << "�������, � ������� ���� ���� ��������, �� ���� ������� �� �������." << endl;
						}
						else {
							while (true) {
								cout << "1.����� ����� � ������� ������ �������� � �������" << endl;
								cout << "2.�����" << endl;
								input_check_int(choice);
								if (choice == 1) {
									for (int j = 0; j < drugstore_net.size(); j++) {
									vector<Product> products= drugstore_net[j].get_medicines();
									vector<Product>::iterator it= products.begin();
										for (int i = 0; i < drugstore_net[j].get_medicines().size(); i++) {
											string month = "", year = "";
											year += drugstore_net[j].get_medicines()[i].get_expiration_date()[3] += drugstore_net[j].get_medicines()[i].get_expiration_date()[4] += drugstore_net[j].get_medicines()[i].get_expiration_date()[5] += drugstore_net[j].get_medicines()[i].get_expiration_date()[6];
											month += drugstore_net[j].get_medicines()[i].get_expiration_date()[0] += drugstore_net[j].get_medicines()[i].get_expiration_date()[1];
											if (stoi(month) >= now.tm_mon + 1 && stoi(year) == now.tm_year + 1900 || stoi(year) > now.tm_year + 1900) {
												it += i;
												products.erase(it);
											}
										}
										drugstore_net[j].set_medicines(products);
									}
									
								}
								else if (choice == 2) {
									break;
								}
								else {
									cout<<"������ ������ �� ����������. ���������� ������ ��� ���" << endl;
								}
							}
						}
					}
					else if (choice == 3) {
						break;
					}
					else {
						cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
					}
				}
				}
				else if (choice == 7) {
					break;
				}
				else {
					cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
				}
			}
		}
		else if (choice == 7) {
			break;
		}
		else {
			cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
		}
	}
}
void Administrator::menu() {
	while (true) {
		int choice, address=0;
		cout << "1.������������" << endl;
		cout<<"2.������ � �������" << endl;
		cout << "3.�����" << endl;
		input_check_int(choice);
		system("cls");
		if (choice == 1) {
			cout<<"1.�������� ������" << endl;
			cout<<"2.������ ����� ��������������" << endl;	
			cout<<"3.�����" << endl;
			input_check_int(choice);
			cin.clear();
			cin.ignore(1024, '\n');
			system("cls");
			if (choice == 1) {
				if (choice == 1) {					
					change_password(get_login(), get_password());
					system("cls");
					ifstream out;
					string line = "";
					out.open("accounts.txt");
					while (getline(out, line)) {
						int i = 0; 
						string ch_log="";
						while (line[i] != ' ') {
							ch_log += line[i];
							i++;
						}
						i++;
						if (ch_log == get_login()) {
							string passw="";
							while (i != line.length()) {
								passw += line[i];
								i++;
							}
							set_password(passw);
						}
					}
					out.close();
				}
			}
			else if (choice == 2) {
				while (true) {
					string line;
					ifstream out;
					bool outp = false;
					vector<shared_ptr<Id<Person>>> users;
					out.open("accounts.txt");
					int j = 0;
					while (getline(out, line)) {
						int i = 0;
						string ch_login = "";
						while (i != ' ') {
							ch_login += line[i];
							i++;
						}
						i++;
						users[j]->operator->()->set_login(ch_login);
						string ch_password;
						while (i != line.length()) {
							ch_password += line[i];
						}
						users[j]->operator->()->set_password(ch_password);
						if (ch_password[line.length() - 1] == '1' || ch_password[line.length() - 1] == '2') {
							cout << users[j] << endl;
							outp = true;
						}

					}
					if (!outp) {
						cout << "�� ���������������� �� ������ ������������ � ���������" << endl;
						system("pause");
						break;
					}
					else {
						cout << "������� ���� ������������, �������� ������ ������ ����� ��������������" << endl;
						input_check_int(choice);
						system("cls");
						if (choice > Id<Person>::get_count()) {
							cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
						}
						else if (users[choice - 1]->operator->()->get_password()[users[choice - 1]->operator->()->get_password().length() - 1] == '3') {
							cout << "������ ������������ ��� ����� ����� ��������������" << endl;
						}
						else {
							string new_role = "";
							for (int i = 0; i < users[j]->operator->()->get_password().length() - 1; i++) {
								new_role += users[j]->operator->()->get_password()[i];
							}
							new_role += '3';
							users[j]->operator->()->set_password(new_role);
							ofstream inp;
							inp.open("accounts.txt", ios::out);
							for (int i = 0;i < Id<Person>::get_count(); i++) {
								inp << users[i]->operator->()->get_login() << ' ' << users[i]->operator->()->get_password() << endl;
							}
							inp.close();
							while (true) {
								cout << "1.���������� �������� ����� ��������������" << endl;
								cout << "2.��������� �������� ����� ��������������" << endl;
								if (choice == 1) {
									break;
								}
								else if (choice == 2) {
									break;
								}
								else {
									cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
								}
							}
							if (choice == 2) { 
								break; 
							}
						}
					}
				}
			}
			else if (choice == 3) {
				break;
			}
			else {
				cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
			}
		}
		else if (choice == 2) {
			int input = 0;
			cout << "1.�������� �����" << endl;
			cout << "2.������� �����" << endl;
			cout << "3.����������� �����" << endl;
			cout << "4.����� ������" << endl;
			cout << "5.�����" << endl;
			vector<Drugstore> fdrugstore_net;
			vector<string> products, descriptions, dates, addresses;
			vector<float> prices;
			vector<int> counts;
			input_check_int(choice);
			if (input == 0 && choice < 5) {
				ifstream out;
				out.open("drugstore_net.txt");
				if (out.is_open()) {
					string line = "";
					while (getline(out, line)) {
						string prod_name = "", description = "", expiration_date = "", price = "", count = "", address="";
						int i = 0;
						while (line[i] != '\t') {
							prod_name += line[i];
							i++;
						}
						i++;
						while (line[i] != '\t') {
							expiration_date += line[i];
							i++;
						}
						i++;
						while (line[i] != '\t') {
							description+= line[i];
							i++;
						}
						i++;
						while (line[i] != '\t') {
							price += line[i];
							i++;
						}
						i++;
						while (line[i] != '\t') {
							count += line[i];
							i++;
						}
						i++;
						while (i != line.length() - 1) {
							address+= line[i];
							i++;
						}
						products.push_back(prod_name);
						descriptions.push_back(description);
						dates.push_back(expiration_date);
						prices.push_back(stof(price));
						counts.push_back(stoi(count));
						addresses.push_back(address);
						for (int i = 0; i < addresses.size(); i++) {
							int rep = 0;
							for (int j = 0; j < fdrugstore_net.size(); j++) {
								if (addresses[i] == fdrugstore_net[j].get_address()) {
									rep++;
								}
							}
							if (rep == 0) {
								fdrugstore_net.push_back(Drugstore());
								fdrugstore_net[fdrugstore_net.size() - 1].set_address(address);
							}
						}
						for (int i = 0; i < fdrugstore_net.size(); i++) {
							vector<Product> prods;
							for (int j = 0; j < counts.size(); j++) {
								if (fdrugstore_net[i].get_address() == addresses[i]) {
									prods.push_back(Product(products[i], dates[i], descriptions[i], prices[i], counts[i]));
								}
							}
							fdrugstore_net[i].set_medicines(prods);
						}
					}
				}
				else {
					ofstream inp;
					inp.open("drugstore_net.txt");
					inp.close();
				}
				out.close();
			}
			if (choice == 1) {
				for (int i = 0; i < drugstore_net.size(); i++) {
					cout << i + 1 << "." << drugstore_net[i].get_address() << endl;
				}
				cout << "�������� ������, � ������� ������ �������� �����" << endl;
				input_check_int(choice);
				if (choice > drugstore_net.size()) {
					cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
				}
				else {
					string prod_name = "", description, expiration_date;
					float price;
					int count;
					cout << "������� �������� ������, ������� ������ �������� � ������ �� ������" << drugstore_net[choice - 1].get_address() << endl;
					getline(cin, prod_name);
					cout << "������� �������� ������ " << prod_name << endl;
					getline(cin, description);
					cout << "������� ���� �������� ������ " << prod_name << endl;
					input_check_date(expiration_date);
					cout << "������� ���� �� ����� " << prod_name << endl;
					input_check_float(price);
					cout << "������� ���������� ������ " << prod_name << ", ������� ������ ��������" << endl;
					input_check_int(count);
					drugstore_net[choice - 1].get_medicines().push_back(Product(prod_name, expiration_date, description, price, count));
				}
			}
			else if (choice == 2) {
				for (int i = 0; i < drugstore_net.size(); i++) {
					cout << i + 1 << drugstore_net[i].get_address() << endl;
				}
				cout << "�������� ������, � ������� ������ ������� �����" << endl;
				input_check_int(choice);
				if (choice > drugstore_net.size()) {
					cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
				}
				else {
					string prod_name;
					for (int i = 0; i < drugstore_net[choice - 1].get_medicines().size(); i++) {
						cout << drugstore_net[choice - 1].get_medicines()[i];
					}
					cout << "������� ����� ������ � ������, ������� ������ ������� � ������ �� ������ " << drugstore_net[choice - 1].get_address() << endl;
					getline(cin, prod_name);
					for (int i = 0; i < drugstore_net[choice - 1].get_medicines().size(); i++) {
						if (drugstore_net[choice - 1].get_medicines()[i].get_product_name() == prod_name) {
							vector<Product> products = drugstore_net[choice - 1].get_medicines();
							vector<Product>::iterator it = drugstore_net[choice - 1].get_medicines().begin() + i;
							products.erase(it);
							drugstore_net[choice - 1].set_medicines(products);
						}
					}
				}
			}
			else if (choice == 3) {
				cout << "1.����������� �� �������� ������" << endl;
				cout << "2.����������� �� ����" << endl;
				cout << "3.����������� �� ����� ��������" << endl;
				cout << "4.����������� �� ����������" << endl;
				cout << "5.�����" << endl;
				input_check_int(choice);
				if (choice == 1) {
					if (address == 0) {
						while (true) {
							for (address = 0; address < drugstore_net.size(); address++) {
								cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(address);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								break;
							}
						}
					}
					else {
						while (true) {
							cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
							cout << "2.������ �������� � ������ �� ������� ������" << endl;
							input_check_int(choice);
							if (choice == 1) {
								break;
							}
							else if (choice == 2) {
								while (true) {
									int p = 0;
									for (p = 0; p < drugstore_net.size(); p++) {
										cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
									}
									cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
									input_check_int(p);
									system("cls");
									if (address > drugstore_net.size()) {
										cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
									}
									else {
										if (p == address) {
											while (true) {
												cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
												cout << "1.��" << endl;
												cout << "2.���" << endl;
												input_check_int(choice);
												if (choice == 1) {
													break;
												}
												else if (choice == 2) {
													continue;
												}
												else {
													cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
												}
											}
										}
										break;
									}
								}
							}
							else {
								cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
						}
					}
					sort(drugstore_net[address - 1].get_medicines().begin(), drugstore_net[address - 1].get_medicines().end(), [](Product& p1, Product& p2) {
						return p1.get_product_name() < p2.get_product_name();
						});
				}
				else if (choice == 2) {
					if (address == 0) {
						while (true) {
							for (address = 0; address < drugstore_net.size(); address++) {
								cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(address);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								break;
							}
						}
					}
					else {
						while (true) {
							cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
							cout << "2.������ �������� � ������ �� ������� ������" << endl;
							input_check_int(choice);
							if (choice == 1) {
								break;
							}
							else if (choice == 2) {
								while (true) {
									int p = 0;
									for (p = 0; p < drugstore_net.size(); p++) {
										cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
									}
									cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
									input_check_int(p);
									system("cls");
									if (address > drugstore_net.size()) {
										cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
									}
									else {
										if (p == address) {
											while (true) {
												cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
												cout << "1.��" << endl;
												cout << "2.���" << endl;
												input_check_int(choice);
												if (choice == 1) {
													break;
												}
												else if (choice == 2) {
													continue;
												}
												else {
													cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
												}
											}
										}
										break;
									}
								}
							}
							else {
								cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
						}
					}
					sort(drugstore_net[address - 1].get_medicines().begin(), drugstore_net[address - 1].get_medicines().end(), [](Product& p1, Product& p2) {
						return p1.get_price() < p2.get_price();
						});
				}
				else if (choice == 3) {
					if (address == 0) {
						while (true) {
							for (address = 0; address < drugstore_net.size(); address++) {
								cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(address);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								break;
							}
						}
					}
					else {
						while (true) {
							cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
							cout << "2.������ �������� � ������ �� ������� ������" << endl;
							input_check_int(choice);
							if (choice == 1) {
								break;
							}
							else if (choice == 2) {
								while (true) {
									int p = 0;
									for (p = 0; p < drugstore_net.size(); p++) {
										cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
									}
									cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
									input_check_int(p);
									system("cls");
									if (address > drugstore_net.size()) {
										cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
									}
									else {
										if (p == address) {
											while (true) {
												cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
												cout << "1.��" << endl;
												cout << "2.���" << endl;
												input_check_int(choice);
												if (choice == 1) {
													break;
												}
												else if (choice == 2) {
													continue;
												}
												else {
													cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
												}
											}
										}
										break;
									}
								}
							}
							else {
								cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
						}
					}
					sort(drugstore_net[address - 1].get_medicines().begin(), drugstore_net[address - 1].get_medicines().end(), [](Product& p1, Product& p2) {
						return p1.get_expiration_date() < p2.get_expiration_date();
						});
				}
				else if (choice == 4) {
					if (address == 0) {
						while (true) {
							for (address = 0; address < drugstore_net.size(); address++) {
								cout << address + 1 << ".�������� �� ������ " << drugstore_net[address].get_address() << endl;
							}
							cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
							input_check_int(address);
							system("cls");
							if (address > drugstore_net.size()) {
								cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
							}
							else {
								break;
							}
						}
					}
					else {
						while (true) {
							cout << "1.���������� ������ � ������ �� ������" << drugstore_net[address - 1].get_address() << endl;
							cout << "2.������ �������� � ������ �� ������� ������" << endl;
							input_check_int(choice);
							if (choice == 1) {
								break;
							}
							else if (choice == 2) {
								while (true) {
									int p = 0;
									for (p = 0; p < drugstore_net.size(); p++) {
										cout << p + 1 << ".�������� �� ������ " << drugstore_net[p].get_address() << endl;
									}
									cout << "�������� ����� ������, � ������� ���������� ������ ������" << endl;
									input_check_int(p);
									system("cls");
									if (address > drugstore_net.size()) {
										cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
									}
									else {
										if (p == address) {
											while (true) {
												cout << "�� �������, ��� ������ �������� �� ���� �� ������, �� �������� �������� �� �����?" << endl;
												cout << "1.��" << endl;
												cout << "2.���" << endl;
												input_check_int(choice);
												if (choice == 1) {
													break;
												}
												else if (choice == 2) {
													continue;
												}
												else {
													cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
												}
											}
										}
										break;
									}
								}
							}
							else {
								cout << "������ ������ �� ����������. ���������� ������ ��� ���." << endl;
							}
						}
					}
					sort(drugstore_net[address - 1].get_medicines().begin(), drugstore_net[address - 1].get_medicines().end(), [](Product& p1, Product& p2) {
						return p1.get_count() < p2.get_count();
						});
				}
				else if (choice == 5) {
					break;
				}
				else {
					cout << "������ ������ �� ����������. ���������� ������ ��� ���" << endl;
				}
				cout << "" << endl;
			}
			else if (choice == 4) {
			}
			else if (choice == 5) {
				break;
			}
			else if (choice == 6) {}
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout<<"������ ������ �� ����������. ���������� ������ ��� ���" << endl;
		}
	}
}
int User::get_type() {
	return 1;
}
int Pharmacist::get_type() {
	return 2;
}
int Administrator::get_type() {
	return 3;
}
