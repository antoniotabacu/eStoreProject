#include "Address.h"

using namespace std;

Address::Address()
{
	//throw("undefined");
	county="undefined";
	locality="undefined";
	street="undefined";
	number=-1;
	block="undefined";
	apartment=-1;
}

Address::Address(const Address &address)
{
	//throw("undefined");
	county=address.county;
	locality=address.locality;
	street=address.street;
	number=address.number;
	block=address.block;
	apartment=address.apartment;
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
	//throw("undefined");
	county=jud;
	locality=loc;
	street=str;
	number=nr;
	block=bl;
	apartment=ap;
	
}

const Address &Address::operator=(const Address &adr)
{
	//throw("undefined");
	county=adr.county;
	locality=adr.locality;
	street=adr.street;
	number=adr.number;
	block=adr.block;
	apartment=adr.apartment;

	return *this;
}

void Address::setStrada(const string &str)
{
	//throw("undefined");
	street=str;
}

void Address::setNumber(int nr)
{
	//throw("undefined");
	number=nr;
}

void Address::setBlock(const string &bl)
{
	//throw("undefined");
	block=bl;
}

void Address::setApartment(int ap)
{
	//throw("undefined");
	apartment=ap;
}

void Address::setCounty(const string &jud)
{
	//throw("undefined");
	county=jud;
}

void Address::setLocality(const string &loc)
{
	//throw("undefined");
	locality=loc;
}

string &Address::getStreet()
{
	//throw("undefined");
	return street;
}

int Address::getNumber()
{
	//throw("undefined");
	return number;
}
string &Address::getBlock()
{
	//throw("undefined");
	return block;
}

int Address::getApartment()
{
	//throw("undefined");
	return apartment;
}

string &Address::getCounty()
{
	//throw("undefined");
	return county;
}

string &Address::getLocality()
{
	//throw("undefined");
	return locality;
}

bool Address::operator==(const Address &address)
{
	//throw("undefined");
	if(county==address.county){
		if(locality==address.locality){
			if(street==address.street){
				if(number==address.number){
					if(block==address.block){
						if(apartment==address.apartment){
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Address::operator!=(const Address &address)
{
	if(county==address.county){
		if(locality==address.locality){
			if(street==address.street){
				if(number==address.number){
					if(block==address.block){
						if(apartment==address.apartment){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

ostream &operator<<(ostream &os, const Address &a)
{
	//throw("undefined");
	os<<a.county;
	os<<a.locality;
	os<<a.street;
	os<<a.number;
	os<<a.block;
	os<<a.apartment;

}

json Address::toJSON()
{
	return json(*this);
}