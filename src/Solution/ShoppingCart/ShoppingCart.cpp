#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	//throw("undefined");
	this->payMethod=payMethod;
}

string &ShoppingCart::getPayMethod()
{
	//throw("undefined");
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	//throw("undefined");
	this->payMethod=payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	//throw("undefined");

	shoppingCart.insert(pair<int,int>(id,quantity));
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	//throw("undefined");
	
	//(shoppingCart.find(id))->second+=quantity;
	shoppingCart[id]+=quantity;
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	//throw("undefined");
	//(shoppingCart.find(id))->second-=quantity;
	shoppingCart[id]-=quantity;
}

int ShoppingCart::getQuantity(int productID)
{
	map<int,int>::iterator itr;
	int ok=0;
	for(itr=shoppingCart.begin();itr!=shoppingCart.end();++itr){
		if(itr->first==productID){
			ok++;
		}
	}
	//throw("undefined");
	if(ok==1){  //shoppingCart.find(productID)->second!=0
		return (shoppingCart.find(productID))->second;
	}
	else{
		return -1;
	}


}

void ShoppingCart::deleteProduct(int productID)
{
	//throw("undefined");
	shoppingCart.erase(productID);
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	//throw("undefined");
	return shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}