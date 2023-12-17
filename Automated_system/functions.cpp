#include"header.h"
void horizontalLine(int linelength) {
	for (int i = 0; i < linelength; i++) {
		cout << "-";
	}
	cout << endl;

}
void input_check_float(float& number) {
	while (true) {
		try {
			cin >> setprecision(2) >> number;
			if (cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(1024, '\n');
				exception e1;
				throw e1;
			}
			else {
				break;
			}
		}
		catch (exception) {
			cout<<"Некорректное значение. Попробуйте ввести ещё раз" << endl;
		}
	}
}
void encryption(string& password) {
	reverse(password.begin(), password.end());
	for (int i = 0; i < password.length(); i++) {
		password[i] = password[i] + 1;
	}
}
// Сделаем функцию для ввода целых чисел с проверками
void input_check_int(int &number) {
	while (true) {
		cin >> number;
		if (cin.good()) {
			break;
		}
		else if (cin.bad() || cin.fail()||number<0 ) {
			cout << "Вводите только натуральные числа" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}
//void input_check_int(string& str) {
//	int i = 0;
//	bool error = 0;
//	do {
//		try {
//			getline(std::cin, str);
//			if (str.empty()) {
//				throw 1;
//			}
//			for (i = 0; i < str.length(); i++) {
//				if (str[i] == ' ') {
//					if (i == 0) {
//						continue;
//					}
//					else if (str[i - 1] == '0' || isdigit(str[i - 1])) {
//						throw 1.23;
//						error = 1;
//						break;
//					}
//				}
//				else if (str[i] == '-') {
//					throw "";
//					cout << "Вводите только натуральные числа" << endl;
//					break;
//				}
//				else if (iswalpha((unsigned char)str[i])) {
//					throw true;
//					break;
//				}
//				else if (!isdigit(str[i])) {
//					throw ' ';
//					break;
//				};
//			}
//		}
//		catch (int) {
//			cout << "Введите хотя бы одно число" << endl;
//		}
//		catch (float) {
//			cout << "Не вводите пробелы" << endl;
//		}
//		catch (const char*) {
//			cout << "Вводите только натуральные числа" << endl;
//		}
//		catch (bool) {
//			cout << "Вводите только числа. Никаких букв." << endl;
//		}
//		catch (const char) {
//			cout << "Вводите только числа." << endl;
//		}
//		} while (error==1);
//}
void reg_login(string& login) {
	bool error_count, numbers, letters, count_empty;
		do {
			error_count = false, numbers=false, letters=false, count_empty=false;
			try {
				getline(cin, login);
				system("cls");	
				if (login.empty()) {
					if (count_empty == true) {
						throw 1;
					}
					count_empty = true;
				}
				else if (login.length() < 8) {
					float e = 1.23;
					throw e;
				}
				else {
					for (int i = 0;i < login.length(); i++) {
						if(login[i]==' ') {
							exception e1;
							throw e1;
						}
						else if (login[i] == '0' || login[i] == '1' || login[i] == '2' || login[i] == '3' || login[i] == '4' || login[i] == '5' || login[i] == '6' || login[i] == '7' || login[i] == '8' || login[i] == '9') {
							numbers = true;
						}
						else if (!isascii(login[i])) {
							throw ' ';
						}
						else if (isalpha(login[i])) {
							letters = true;
						}
						
					}
					if (letters == false) {
						throw true;
					}
					if (numbers == false) {
						throw "";
					}
				}
				ifstream out("accounts.txt");
				if (out.is_open()) {
					string line;
					while (getline(out, line)) {
						int i = 0;
						string check_login = "";
						if (!line.empty()) {
							while (line[i] != ' ') {
								check_login += line[i];
								i++;
							}
							if (check_login == login) {
								error_count = true;
								cout << "Данный логин уже существует. Придумайте другой." << endl;
							}
						}	
					}
					out.close();
				}
				else {
					error_count = true;
					cout << "Не удалось открыть файл" << endl;
				}
				
			}
			catch(int){
				cout << "Вы ввели пустую строку. Попробуйте ввести ещё раз." << endl;
				error_count = true;
			}
			catch (float) {
				cout << "Длина логина должна быть не менее 8 символов" << endl;
				error_count = true;
			}
			catch (const char*) {
				cout << "В логине должна быть хотя бы 1 цифра" << endl;
				error_count = true;
			}
			catch (bool) {
				cout << "В логине должна быть хотя бы 1 буква" << endl;
				error_count = true;
			}
			catch (const char) {
				cout << "Вводите только английские символы." << endl;
				error_count = true;
			}
			catch (exception) {
				cout<<"Не вводите пробелы." << endl;
			}
		} while (error_count);
		ofstream out;
		out.open("accounts.txt", ios::app);
		out<<login<<" ";
		out.close();
}
void reg_password(string& password) {
	bool error_count, numbers, letters;	
	do {
		error_count = false, letters=false, numbers=false;
		try {
			getline(cin, password);
			if (password.empty()) {
				throw 1;
			}
			else if (password.length() < 8) {
				float f = 1.2;
				throw f;
			}
			else{
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
			cout << "Вы ввели пустую строку. Попробуйте ввести ещё раз." << endl;
			error_count = true;
		}
		catch (float) {
			cout << "Длина пароля должна быть не менее 8 символов" << endl;
			error_count = true;
		}
		catch (const char*) {
			cout << "В пароле должна быть хотя бы 1 цифра" << endl;
			error_count = true;
		}
		catch (bool) {
			cout << "В пароле должна быть хотя бы 1 буква" << endl;
			error_count = true;
		}
		catch (const char) {
			cout << "Вводите только английские символы." << endl;
			error_count = true;
		}
		catch (exception) {
			cout << "Не вводите пробелы" << endl;
			error_count = true;
		}
		
	} while (error_count);
	encryption(password);
}
void change_password(string login, string passw) {
	ifstream out;
	vector<string> logins, passwords;
	out.open("accounts.txt");
	if (out.is_open()) {
		int count = 0;
		string line = "";
		while (getline(out, line)) {
			string password = "", ch_login = "";
			int i = 0;
			while (line[i] != ' ') {
				ch_login += line[i];
				i++;
			}
			i++;
			while (i != line.length()) {
				password += line[i];
				i++;
			}
			if (ch_login == login) {
				cout<<"Введите новый пароль" << endl;
				reg_password(password);
				if (passw[passw.length() - 1] == '1') {
					password += '1';
				}
				else if (passw[passw.length() - 1] == '2') {
					password += '2';
				}
				else {
					password += '3';
				}
			}
			logins.push_back(ch_login);
			passwords.push_back(password);
		}
	}
	
	out.close();
	ofstream inp;
	inp.open("accounts.txt", ios::out);
	if (inp.is_open()) {
		for (int i = 0; i < logins.size(); i++) {
		inp <<logins[i]<<" " << passwords[i] << endl;
		}
	}
	inp.close();
}
void drugstores_ifstr(vector<Drugstore>& drugstore_net) {
	ifstream out;
	string line = "";
	string login, password;
	out.open("drugstores.bin", ifstream::out);
	if (out.is_open()) {
		int i = 0;
		while (out) {
			drugstore_net.push_back(Drugstore());
			out.read((char*)&drugstore_net[i], sizeof(Drugstore));
			i++;
		}
	}
	else {
		ofstream out;
		out.open("drugstores.bin", ios::binary);
		out.close();
	}
}
void accounts_ifstr(vector<shared_ptr<Id<Person>>>& users){
	ifstream out;
	string line = "";
	string login, password;
	out.open("accounts.txt", ifstream::out);
	if (out.is_open()) {
		while (getline(out, line)) {
			int i = 0;
			login = "", password = "";
			if (!line.empty()) {
				while (line[i] != ' ') {
					login += line[i];
					i++;
				}
				i++;
				while (i != line.length()) {
					password += line[i];
					i++;
				}
				if (line[i - 1] == '1') {
					users.push_back(make_shared<Id<Person>>(new User(login, password)));
				}
				if (line[i - 1] == '2') {
					users.push_back(make_shared<Id<Person>>(new Pharmacist(login, password)));
				}
				if (line[i - 1] == '3') {
					users.push_back(make_shared<Id<Person>>(new Administrator(login, password)));
				}
				line = "";
			}
		}
		out.close();
	}
	else {
		ofstream out;
		out.open("accounts.txt");
		out.close();
	}
}
void products_ifstr(vector<Product> &products) {
	ifstream out;
	string line;
	out.open("products.bin", ios::binary);
	if (out.is_open()) {
		int i = 0;
		while (out) {
			products.push_back(Product());
			out.read((char*)&products[i], sizeof(Product));
			i++;
		}
		out.close();
	}
	else {
		ofstream out;
		out.open("products.bin", ios::binary);
		out.close();
	}
}
void warehouse_ifstr(Warehouse& warehouse) {
	ifstream out;
	string line;
	vector<Product> products;
	out.open("warehouse.bin", ios::binary);
	if (out.is_open()) {
		int i = 0;
		while (out) {
			products.push_back(Product());
			out.read((char*)&products[i], sizeof(Product));
			i++;
		}
		out.close();
		warehouse.set_medicines(products);
	}
	else {
		ofstream out;
		out.open("warehouse.bin", ios::binary);
		out.close();
	}
}
void input_check_date(string& date) {
	string day = "", month = "", year = "";
	int i = 0, pointCount = 0, errorCount = 0;
	do {
		do {
			errorCount = 0;
			getline(std::cin, date);
			if (date.empty()) {
				cout << "Вы ничего не ввели." << endl;
				continue;
			}
			for (i = 0; i < date.length(); i++) {
				if (date[i] == '.') {
					pointCount++;
					continue;
				}
				if (date[i] == ' ') {
					cout << "Не вводите пробелы" << endl;
					errorCount = 1;
					break;
				}
				else if (!isdigit(date[i])) {
					cout << "Вводите только числа." << endl;
					errorCount = 1;
					break;
				};
			}
			if (errorCount == 0 && pointCount != 2) {
				cout << "Вы ввели неверное количество точек." << endl;
			}
		} while (errorCount == 1 || date.empty() || pointCount != 2);
		pointCount = 0;
		for (i = 0; i < date.length(); i++) {
			if (date[i] != '.') {
				if (pointCount == 0) {
					day += date[i];
				}
				else if (pointCount == 1) {
					month += date[i];
				}
				else if (pointCount == 2) {
					year += date[i];
				}
			}
			else {
				pointCount++;
			}
		}
		if (day.length() == 0 || day.length() > 2 || month.length() == 0 || month.length() > 2 || year.length() < 2 || year.length() > 4 || year.length() == 3) {
			cout << "Неправильно введена дата. Попробуйте ещё раз." << endl;
			errorCount = 1;
		}
		else {
			if (day.length() == 1) {
				day[1] = day[0];
				day[0] = '0';
			}
			if (month.length() == 1) {
				month[1] = month[0];
				month[0] = '0';
			}
			if (year.length() == 2) {
				year[3] = year[0];
				year[4] = year[1];
				year[1] = '0';
				year[0] = '2';
			}
		}
	} while (errorCount == 1);
}
template <class F>
void QuickSort(std::vector<F>& arr, int left, int right) {
	if (left < right) {
		F pivot = arr[(left + right) / 2];
		int i = left;
		int j = right;
		while (i <= j) {
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i <= j) {
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		if (left < j) QuickSort(arr, left, j);
		if (i < right) QuickSort(arr, i, right);
	}
}
