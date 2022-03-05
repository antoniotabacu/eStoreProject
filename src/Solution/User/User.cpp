#include "User.h"
using namespace std;

User::~User()
{
	//throw("undefined");
	/*Address empty_address;
	billingData=empty_address;
	deliveryData=empty_address;*/
}

User::User():billingData(), deliveryData()
{
	//throw("undefined");
	/*Address empty_address;
	billingData=empty_address;
	deliveryData=empty_address;*/
	lastName="undefined";
	firstName="undefined";
	email="undefined";
	UserID=-1;
}

User::User(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int UserId, const string &lastName, const string &prenume, const string &email)
	: billingData(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf),
	  deliveryData(judetl, localitatel, stradal, nr_stradal, blocl, apartamentl)
{
	//throw("undefined");
	this->UserID=UserID;
	this->lastName=lastName;
	this->firstName=prenume;
	this->email=email;
}

User::User(const User &u)
{
	//throw("undefined");
	billingData=u.billingData;
	deliveryData=u.deliveryData;
	lastName=u.lastName;
	firstName=u.firstName;
	email=u.email;
	UserID=u.UserID;
}

const User &User::operator=(const User &u)
{
	//throw("undefined");
	billingData=u.billingData;
	deliveryData=u.deliveryData;
	lastName=u.lastName;
	firstName=u.firstName;
	email=u.email;
	UserID=u.UserID;

	return *this;
}

void User::setLastName(const string &lastName)
{
	//throw("undefined");
	this->lastName=lastName;
}
void User::setFirstName(const string &firstName)
{
	//throw("undefined");
	this->firstName=firstName;
}
void User::setEmail(const string &email)
{
	//throw("undefined");
	this->email=email;
}
void User::setUserID(int userID)
{
	//throw("undefined");
	this->UserID=userID;
}
void User::setBillingData(const Address &billingData)
{
	//throw("undefined");
	this->billingData=billingData;
}
void User::setDeliveryData(const Address &deliveryData)
{
	//throw("undefined");
	this->deliveryData=deliveryData;
}

string &User::getLastName()
{
	//throw("undefined");
	return lastName;

}
string &User::getFirstName()
{
	//throw("undefined");
	return firstName;
}
string &User::getEmail()
{
	//throw("undefined");
	return email;
}
int User::getUserID() const
{
	//throw("undefined");
	return UserID;
}

Address &User::getBillingData()
{
	//throw("undefined");
	return billingData;
}
Address &User::getDeliveryData()
{
	//throw("undefined");
	return deliveryData;
}

json User::toJSON()
{
	return json(*this);
}
