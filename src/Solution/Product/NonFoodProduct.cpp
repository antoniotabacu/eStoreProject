#include "NonFoodProduct.h"

///////////////////////////////////////////CONSTRUCTORI
NonFoodProduct::NonFoodProduct()
{
	//throw("undefined");
	producer="undefined";
	yearsOfWarranty=-1;
	price=-1;
}

NonFoodProduct::NonFoodProduct(const string &category_new, int id_new, const string &producer_new, const string &name_new, float price_new, int yearsOfWarranty_new, int quantity_new) : Product(category_new, id_new, name_new, quantity_new)
{
	//throw("undefined");
	producer=producer_new;
	yearsOfWarranty=yearsOfWarranty_new;
	price=price_new;

}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	//throw("undefined");
	producer=pn.producer;
	yearsOfWarranty=pn.yearsOfWarranty;
	price=pn.price;
}
///////////////////////////////////////////////////

//////////////////////////////////////////////////////SETERI

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	//throw("undefined");
	yearsOfWarranty=garantieAni;
}

void NonFoodProduct::setPrice(float price_new)
{
	//throw("undefined");
	price=price_new;
}

void NonFoodProduct::setProducer(const string &producer_new)
{
	//throw("undefined");
	producer=producer_new;
}
//////////////////////////////////////////

/////////////////////////////////////////////////GETERI

int NonFoodProduct::getYearsOfWarranty()
{
	//throw("undefined");
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	//throw("undefined");
	return price;
}

string &NonFoodProduct::getProducer()
{
	//throw("undefined");
	return producer;
}

/////////////////////////////////////////////////

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	//throw("undefined");
	/*if ( (name==obj.name)&&(id==obj.id) ){
		return true;
	}
	else{
		return false;
	}*/

	int ok=0;

	if(name==obj.name){
		if(category==obj.category){
			if(id==obj.id){
				if(producer==obj.producer){
					if(yearsOfWarranty==obj.yearsOfWarranty){
						if(price==obj.price){
							ok++;
							return true;
						}
					}
				}
			}
		}
	}
	if(ok==0){
		return false;
	}
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	//throw("undefined");
	category=a.category;
	id=a.id;
	name=a.name;
	quantity=a.quantity;

	price=a.price;
	producer=a.producer;
	yearsOfWarranty=a.yearsOfWarranty;

	return *this;

}

string NonFoodProduct::getProductType()
{
	//throw("undefined");
	return "nealimentar";
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
