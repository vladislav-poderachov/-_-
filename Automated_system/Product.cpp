#include"header.h"
Product::Product() {
	product_name = "no name";
	expiration_date = "no date";
	price = 0;
	description = "no description";
	count = 0;
};
Product::Product(string product_name, string expiration_date, string description, float price, int count) {
	this->product_name = product_name;
	this->expiration_date = expiration_date;
	this->description = description;
	this->price = price;
	this->count = count;
}
void Product::set_count(int count) {
	this->count=count;
}
int Product::get_count() {
	return count;
}
Product::~Product() {
}
string Product::get_product_name() {
	return product_name;
}
void Product::set_product_name() {
	getline(cin, product_name);
}
void Product::set_product_name(string prod_name) {
	product_name = prod_name;
}
string Product::get_expiration_date() {
	return expiration_date;
}
void Product::set_expiration_date() {
	getline(cin, expiration_date);
}
string Product::get_description() {
	return description;
}
void Product::set_description() {
	getline(cin, description);
}
float Product::get_price() {
	return price;
}
void Product::set_price() {
	input_check_float(price);
}
