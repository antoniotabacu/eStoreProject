#include "DiscountedProduct.h"
using namespace std;

///////////////////////////////////////////////////////////////////CONSTRUCTORI
DiscountedProduct::DiscountedProduct() : NonFoodProduct()
{
	//throw("undefined");
	discountPercentage=-1;
}

DiscountedProduct::DiscountedProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int discountPercentage_new, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity)
{
	//throw("undefined");
	discountPercentage=discountPercentage_new;
}

DiscountedProduct::DiscountedProduct(const DiscountedProduct &discountedProduct) : NonFoodProduct(discountedProduct)
{
	//throw("undefined");
	discountPercentage=discountedProduct.discountPercentage;
}
/////////////////////////////////////////////////////////////////

float DiscountedProduct::priceAfterDiscount() const
{
	//throw("undefined");
	//return (price-discountPercentage*price);
	return price*(100-discountPercentage);
}

float DiscountedProduct::getDiscountPercentage()
{
	//throw("undefined");
	return discountPercentage;
}

const DiscountedProduct &DiscountedProduct::operator=(const DiscountedProduct &a)
{
	//throw("undefined");
	category=a.category;
	id=a.id;
	name=a.name;
	quantity=a.quantity;

	price=a.price;
	producer=a.producer;
	yearsOfWarranty=a.yearsOfWarranty;

	discountPercentage=a.discountPercentage;

	return *this;
}

void DiscountedProduct::setDiscountPercentage(int discountPercentage_new)
{
	//throw("undefined");
	discountPercentage=discountPercentage_new;
}

string DiscountedProduct::getProductType()
{
	//throw("undefined");
	return "redus";
}

json DiscountedProduct::toJSON()
{
	return json(*this);
}

void DiscountedProduct::display()
{
	cout << "Product Redus" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent reducere : " << this->discountPercentage << endl
		 << endl;
}