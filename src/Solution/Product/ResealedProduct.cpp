#include "ResealedProduct.h"

using namespace std;

ResealedProduct::ResealedProduct():NonFoodProduct(),DiscountedProduct(),ReturnedProduct()
{
	//throw("undefined");
	wearPercentage=-1;
}

ResealedProduct::ResealedProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int discountPercentage, const string &reason, int wearPercentage_new, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity),
		DiscountedProduct(category, id, producer, name, price, yearsOfWarranty, discountPercentage, quantity),
		ReturnedProduct(category, id, producer, name, price, yearsOfWarranty, reason, quantity)
{
	//throw("undefined");
	wearPercentage=wearPercentage_new;
}

ResealedProduct::ResealedProduct(const ResealedProduct &pr) : NonFoodProduct(pr), DiscountedProduct(pr), ReturnedProduct(pr)
{
	//throw("undefined");
	wearPercentage=pr.wearPercentage;
}

void ResealedProduct::setWearPercentage(int wearPercentage_new)
{
	//throw("undefined");
	wearPercentage=wearPercentage_new;
}

float ResealedProduct::getWearPercentage()
{
	//throw("undefined");
	return wearPercentage;
}

const ResealedProduct &ResealedProduct::operator=(const ResealedProduct &a)
{
	//throw("undefined");
	category=a.category;
	id=a.id;
	name=a.name;
	quantity=a.quantity;

	price=a.price;
	producer=a.producer;
	yearsOfWarranty=a.yearsOfWarranty;

	reason=a.reason;

	discountPercentage=a.discountPercentage;

	wearPercentage=a.wearPercentage;

	return *this;
}

string ResealedProduct::getProductType()
{
	//throw("undefined");
	return "resigilat";
}

json ResealedProduct::toJSON()
{
	return json(*this);
}

void ResealedProduct::display()
{
	cout << "Product Resigilat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent Reducere: " << this->discountPercentage << endl;
	cout << "Procent Uzura: " << this->wearPercentage << endl;
	cout << "Motiv retur: " << this->reason << endl
         << endl;
}
