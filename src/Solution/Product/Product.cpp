#include "Product.h"
using namespace std;

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
	//throw("undefined");
	if(requestedQuantity>quantity){
		return false;
	}
	else{
		return true;
	}
}

/////////////////////////////////// CONSTRUCTORI

Product::Product(const string &category_new, int id_new, const string &name_new, int quantity_new)
{
	//throw("undefined");
	category=category_new;
	id=id_new;
	name=name_new;
	quantity=quantity_new;
}

Product::Product(const Product &p)
{
	//throw("undefined");
	category=p.category;
	id=p.id;
	name=p.name;
	quantity=p.quantity;

}

Product::Product()
{
	//throw("undefined");
	name="undefined";
	quantity=-1;
	category="undefined";
	id=-1;
}

////////////////////////////////////////////////////////////

void Product::decreaseQuantity(int requestedQuantity)
{
	//throw("undefined");
	/*if(checkQuantity(requestedQuantity)){
		quantity-=requestedQuantity;
	}*/

	quantity-=requestedQuantity;
}

void Product::increaseQuantity(int requestedQuantity)
{
	//throw("undefined");
	quantity+=requestedQuantity;
}

///////////////////////////////////////////////////////SETERI

void Product::setCategory(const string &category_new)
{
	//throw("undefined");
	category=category_new;
}

void Product::setId(int id_new)
{
	//throw("undefined");
	id=id_new;
}

void Product::setQuantity(int quantity_new)
{
	//throw("undefined");
	quantity=quantity_new;
}

void Product::setName(const string &name_new)
{
	//throw("undefined");
	name=name_new;
}

///////////////////////////////////////////////////

//////////////////////////////////////////////////////GETERI

string &Product::getCategory()
{
	//throw("undefined");
	return category;
}

int Product::getQuantity()
{
	//throw("undefined");
	return quantity;
}

int Product::getId()
{
	//throw("undefined");
	return id;
}

string &Product::getName()
{
	//throw("undefined");
	return name;
}

////////////////////////////////////////////////////////////////

const Product &Product::operator=(const Product &a)
{
	//throw("undefined");
	category=a.category;
	id=a.id;
	name=a.name;
	quantity=a.quantity;

	return *this;
}

json Product::toJSON()
{
	return json(*this);
}
