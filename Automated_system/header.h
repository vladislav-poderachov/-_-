#pragma once
#include<iostream>
#include<algorithm>
#include<Windows.h>	
#include<string>
#include <iomanip>
#include<fstream>
#include<vector>
#include<array>
#include<time.h>
using namespace std;
void horizontalLine(int linelength);
void input_check_float(float &number);
void input_check_int(int &a);
void input_check_date(string& date);// изменить реализацию только для ввода по типу мм.гггг
void reg_login(string &login);
void reg_password(string &password);
void change_password(string login, string passw);
template<class F>
class Id {
	static int count;
	F * ptr;
	int id;
public:
	Id();
	Id(F *ptr);
	~Id();
	F* operator->()const;
	static void set_count(int ext) {
		count = ext;
	}
	static int get_count() {
		return count;
	}
};
class Product {	
	string product_name;
	string expiration_date;
	string description;
	float price;
	int count;
public:
	Product();
	Product(string product_name, string expiration_date, string description, float price, int count);
	string get_product_name();
	void set_product_name(string prod_name);
	void set_product_name();
	string get_expiration_date();
	void set_expiration_date();
	string get_description();
	void set_description();
	float get_price();
	void set_price();
	void set_count(int count);
	int get_count();
	~Product();
};
class Person {
	string login;
	string password;
public:
	Person();
	Person(string login, string password);
	~Person();
	void set_login();
	void set_login(string login);
	string get_login();
	void set_password();
	void set_password(string password);
	string get_password();
	virtual int get_type() = 0;
	virtual void menu() = 0;
};
class User :public Person {
	vector<Product>medicine_cabinet;
public:
	void virtual menu();
	User();
	User(string login, string password);
	friend ostream& operator<<(ostream& os, vector<Product> medicine_cabinet);
	friend ostream& operator<<(ostream& os, Product product);
	~User();
	void  set_medicine_cabinet();
	vector<Product> get_medicine_cabinet();
	virtual int get_type();
};
class Drugstore {
	vector<Product> medicines;
	string address;
public:
	Drugstore();
	Drugstore(vector<Product> medicines, string address);
	void set_address(string address);
	string get_address();
	void set_medicines(vector<Product> medicines);
	Product get_medicines(int index);
	vector<Product> get_medicines();
};
class Pharmacist:public Person {
	vector<Drugstore> drugstore_net;
public:
	void virtual menu();
	virtual int get_type();
	Pharmacist(string login, string password);
	void set_drugstore_net(vector<Drugstore> drugstore_net);
	vector<Drugstore> get_drugstore_net();
};
class Administrator :public Person {
	vector<Drugstore> drugstore_net;
public:
	void set_drugstore_net(vector<Drugstore> drugstore_net);	
	vector<Drugstore> get_drugstore_net();
	void virtual menu();
	Administrator();
	Administrator(string login, string password);
	~Administrator();
	virtual int get_type();
};
class Warehouse {
	vector<Product> medicines;
public:
	Warehouse();
	void set_medicines(vector<Product> medicines);
	vector<Product> get_medicines();
	Warehouse(vector<Product> medicines);
};
template<class F>
Id<F>::Id() {
	F = NULL;
}
template<class F>
Id<F>::Id(F* ptr):ptr(ptr) {
	count++;
	id = count;
	}
template<class F>
F* Id<F>::operator->()const {
	return ptr;
}
template<class F>
Id<F>::~Id() {
	count--;
	delete ptr;
}
void encryption(string &password);
void accounts_ifstr(vector<shared_ptr<Id<Person>>> &users);
void products_ifstr(vector<Product> &products);
void drugstores_ifstr(vector<Drugstore> &drugstore_net);
void warehouse_ifstr(Warehouse &warehouse);
int Id<Person>::count = 0;