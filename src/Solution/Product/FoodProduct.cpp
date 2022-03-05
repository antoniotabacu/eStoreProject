#include "FoodProduct.h"

///////////////////////////////////////////CONSTRUCTORI

FoodProduct::FoodProduct()
{
	//throw("undefined");
	countryOfOrigin="undefined";
	leiPerKg=0-1;
}

FoodProduct::FoodProduct(const string &categorie, int id_new, const string &nume, float leiPerKg_new, const string &taraOrigine, int cantitate) : Product(categorie, id_new, nume, cantitate)
{
	//throw("undefined");
	leiPerKg=leiPerKg_new;
	countryOfOrigin=taraOrigine;
}

FoodProduct::FoodProduct(const FoodProduct &pa) : Product(pa)
{
	//throw("undefined");
	countryOfOrigin=pa.countryOfOrigin;
	leiPerKg=pa.leiPerKg;

}

////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////SETERI
void FoodProduct::setLeiPerKg(float leiPerKg_new)
{
	//throw("undefined");
	leiPerKg=leiPerKg_new;
}

void FoodProduct::setCountryOfOrigin(const string &countryOfOrigin_new)
{
	//throw("undefined");
	countryOfOrigin=countryOfOrigin_new;
}
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////GETERI
float FoodProduct::getLeiPerKg()
{
	//throw("undefined");
	return leiPerKg;
}

string &FoodProduct::getCountryOfOrigin()
{
	//throw("undefined");
	return countryOfOrigin;
}
/////////////////////////////////////////////////////

const FoodProduct &FoodProduct::operator=(const FoodProduct &a)
{
	//throw("undefined");
	category=a.category;
	id=a.id;
	name=a.name;
	quantity=a.quantity;
	
	countryOfOrigin=a.countryOfOrigin;
	leiPerKg=a.leiPerKg;

	return *this;
}

string FoodProduct::getProductType()
{
	//throw("undefined");
	return "alimentar";
}

json FoodProduct::toJSON()
{
	return json(*this);
}

void FoodProduct::display()
{
	cout << "Product alimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Categorie : " << this->category << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->quantity << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->countryOfOrigin << endl
		 << endl;
}