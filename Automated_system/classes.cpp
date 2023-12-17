#include"header.h"
void Drugstore::set_medicines(vector<Product> medicines){
	this->medicines = medicines;
}
string Drugstore::get_address() {
	return address;
}
void Drugstore::set_address(string address) {
	this->address = address;
}
Drugstore::Drugstore() {
	address = "no address";
}
Drugstore::Drugstore(vector<Product> medicines, string address){
	this->medicines = medicines;
	this->address = address;
}
Product Drugstore::get_medicines(int index) {
	return medicines[index];
}
vector<Product> Drugstore::get_medicines() {
	return medicines;
}
Warehouse::Warehouse(vector<Product> medicines) {
	this->medicines = medicines;
}	
void Warehouse::set_medicines(vector<Product> medicines) {
	this->medicines = medicines;
}
Warehouse::Warehouse() {
	
}
vector<Product>Warehouse::get_medicines() {
	return medicines;
}

