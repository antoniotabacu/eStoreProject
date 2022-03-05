#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
    if (!instance)
    {
        instance = new Server;
    }

    return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
    if (instance != NULL)
        instance = NULL;

    if (!__UserID__ProductsCart__.empty())
        __UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
    //throw("undefined");

    list<User *>::iterator itr;
    for(itr=usr.begin();itr!=usr.end();++itr){
        ShoppingCart *empty_SC;
        empty_SC=new ShoppingCart;
        __UserID__ProductsCart__.insert(pair<int,ShoppingCart*>((*itr)->getUserID(),empty_SC));
    }
}

list<Product *> &Server::getProductsList()
{
    //throw("undefined");
    return prod;
}

list<User *> &Server::getUsersList()
{
    //throw("undefined");
    return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
    //throw("undefined");
    return __UserID__ProductsCart__;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
bool Server::requestAddProduct(int userID, int productID, int quantity)
{
    //throw("undefined");
    if(quantity<=0){
        return false;
    }

    list<User*>::iterator iU;
    list<Product*>::iterator iP;
    map<int,ShoppingCart*>::iterator iM;
    map<int,int>::iterator iS;
    int ok=0;
    int existing=0;

    for(iU=usr.begin();iU!=usr.end();iU++){
        if(userID==(*iU)->getUserID()){
            ok++;
            break;
        }
    }

    for(iP=prod.begin();iP!=prod.end();iP++){
        if(productID==(*iP)->getId()){
            if(ok==1){
                ok++;
                if((*iP)->checkQuantity(quantity)==true){
                    (*iP)->decreaseQuantity(quantity);

                    for(iM=__UserID__ProductsCart__.begin();iM!=__UserID__ProductsCart__.end();iM++){
                        if(iM->first==userID){
                            
                            for(iS=iM->second->getShoppingCart().begin();iS!=iM->second->getShoppingCart().end();iS++){
                                if(iS->first==productID){
                                    existing=1;
                                    iS->second+=quantity;
                                    return true;
                                }
                            }
                            if(existing==0){
                                iM->second->addProduct(productID,quantity);
                                return true;
                            }
                        }
                    }

                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(ok==2){
        return true;
    }
    else{
        return false;
    }

}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
    //throw("undefined");
    if(quantity<=0){
        return false;
    }

    list<User*>::iterator iU;
    list<Product*>::iterator iP;
    map<int,ShoppingCart*>::iterator iM;
    map<int,int>::iterator iS;
    int ok=0;
    int existing=0;

    for(iU=usr.begin();iU!=usr.end();iU++){
        if(userID==(*iU)->getUserID()){
            ok++;
            break;
        }
    }

    for(iP=prod.begin();iP!=prod.end();iP++){
        if(productID==(*iP)->getId()){
            if(ok==1){
                ok++;

                

                for(iM=__UserID__ProductsCart__.begin();iM!=__UserID__ProductsCart__.end();iM++){
                    if(iM->first==userID){
                        
                        for(iS=iM->second->getShoppingCart().begin();iS!=iM->second->getShoppingCart().end();iS++){
                            if(iS->first==productID){
                                existing=1;
                                //iS->second++;
                                if(iS->second<=quantity){
                                    iM->second->deleteProduct(productID);
                                    (*iP)->increaseQuantity(iS->second);
                                    return true;
                                }
                                else{
                                    iS->second-=quantity;
                                    (*iP)->increaseQuantity(quantity);
                                    return true;
                                }
                                

                                

                                //return true;
                            }
                        }
                        if(existing==0){
                            //iM->second->addProduct(productID,quantity);
                            return false;
                        }
                    }
                }
            }
            else{
                return false;
            }
        }
    }

    if(ok==2){
        return true;
    }
    else{
        return false;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
    prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
    usr = ObjectFactory::getUserList(input["useri"]);
}