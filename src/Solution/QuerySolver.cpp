#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
  //throw("undefined");
  list<Product*> espressors;

  list<Product*>::iterator itr;
  for(itr=server->getProductsList().begin();itr!=server->getProductsList().end();++itr){
    if(((*itr)->getProductType()=="redus")&&((*itr)->getCategory()=="espressor")){
      espressors.push_back((*itr));
    }
  }

  return espressors;
}

list<User*> QuerySolver::Query_3b(){
  //throw("undefined");
  list<User*> users;

  list<User*>::iterator itr;

  for(itr=server->getUsersList().begin();itr!=server->getUsersList().end();++itr){
    if(((*itr)->getUserType()=="nonpremium")&&((*itr)->getTransportCost()<=11.5)){
      users.push_back((*itr));
    }
  }

  return users;
}

bool price_sort(Product* p1,Product* p2){

    ReturnedProduct *pp1 = dynamic_cast<ReturnedProduct *>(p1);
    ReturnedProduct *pp2 = dynamic_cast<ReturnedProduct *>(p2);

    if(pp1->getPrice()<pp2->getPrice()){
      return true;
    }
    else{
      return false;
    }

}

bool pKG_sort(Product* p1,Product* p2){

  FoodProduct *pp1 = dynamic_cast<FoodProduct *>(p1);
  FoodProduct *pp2 = dynamic_cast<FoodProduct *>(p2);

   if(pp1->getName()==pp2->getName()){
      if(pp1->getCountryOfOrigin()==pp2->getCountryOfOrigin()){
        if(pp1->getLeiPerKg()<pp2->getLeiPerKg()){
          return true;
        }
        else{
          return false;
        }
      }
   }
}

bool country_sort(Product* p1,Product* p2){

  FoodProduct *pp1 = dynamic_cast<FoodProduct *>(p1);
  FoodProduct *pp2 = dynamic_cast<FoodProduct *>(p2);

  if(pp1->getName()==pp2->getName()){
      if(pp1->getCountryOfOrigin()<pp2->getCountryOfOrigin()){
        return true;
      }
      else{
        return false;
      }
  }

}

bool name_sort(Product* p1,Product* p2){

    FoodProduct *pp1 = dynamic_cast<FoodProduct *>(p1);
    FoodProduct *pp2 = dynamic_cast<FoodProduct *>(p2);

    if(pp1->getName()<pp2->getName()){
      return true;
    }
    else{
      return false;
    }

}

list<Product*> QuerySolver::Query_3c(){
  //throw("undefined");
  list<Product*> resealed_products;

  list<Product*>::iterator itr;
  list<Product*>::iterator jtr;


  for(itr=server->getProductsList().begin();itr!=server->getProductsList().end();++itr){
    if((*itr)->getProductType()=="resigilat"){

      ReturnedProduct *itr2 = dynamic_cast<ReturnedProduct *>(*itr);

      if((itr2)->getReason()=="lipsa_accesorii"){
        resealed_products.push_back(itr2);
      }
    }
  }

  

  /*for(itr=resealed_products.begin();itr!=prev(resealed_products.end());itr++){

    for(jtr=next(itr);jtr!=resealed_products.end();jtr++){

      ReturnedProduct *itr2=dynamic_cast<ReturnedProduct*>(*itr);
      ReturnedProduct *jtr2=dynamic_cast<ReturnedProduct*>(*jtr);

      if(itr2->getPrice() < jtr2->getPrice()){

        ReturnedProduct *aux;

        aux=itr2;
        itr2=jtr2;
        jtr2=aux;
      }
    }
  }*/

  

  resealed_products.sort(price_sort);
  

  return resealed_products;

}

list<Product*> QuerySolver::Query_3d(){
  //throw("undefined");
  list<Product*> food_products;

  list<Product*>::iterator itr;
  list<Product*>::iterator jtr;

  for(itr=server->getProductsList().begin();itr!=server->getProductsList().end();++itr){
    if((*itr)->getProductType()=="alimentar"){
      //FoodProduct *itrf = dynamic_cast<FoodProduct *>(*itr);
      food_products.push_back(*itr);
    }
  }

  food_products.sort(name_sort);
  food_products.sort(country_sort);
  food_products.sort(pKG_sort);

  return food_products;

}


int county_check(map<string,int> counties,string county){
  map<string,int>::iterator itrM;
  for(itrM=counties.begin();itrM!=counties.end();itrM++){
      if(itrM->first==county){
        return 1;
      }
  }

  return 0;
}

bool user_id_sort(User* u1, User* u2){
  if(u1->getUserID()<u2->getUserID()){
    return true;
  }
  else{
    return false;
  }
}

list<User*> QuerySolver::Query_3e(){
  //throw("undefined");

  list<User*> top_county_house_users;

  list<User*>::iterator itr;

  map<string,int> counties;
  map<string,int>::iterator itrM;


  for(itr=server->getUsersList().begin();itr!=server->getUsersList().end();itr++){
    if(county_check(counties,(*itr)->getBillingData().getCounty())==0){
      counties.insert(pair<string,int>((*itr)->getBillingData().getCounty(),1));
    }
    else{
      counties[(*itr)->getBillingData().getCounty()]++;
    }
  }

  int max=0;
  string top_county;
  for(itrM=counties.begin();itrM!=counties.end();itrM++){
    if(itrM->second>max){
      max=itrM->second;
      top_county=itrM->first;
    }
  }

  //top_county="Dolj";

  for(itr=server->getUsersList().begin();itr!=server->getUsersList().end();itr++){
    if((*itr)->getBillingData().getCounty()==top_county){
      if((((*itr)->getBillingData().getApartment()==0) && ((*itr)->getBillingData().getBlock()=="-"))&&(((*itr)->getDeliveryData().getApartment()==0) && ((*itr)->getDeliveryData().getBlock()=="-"))){
        top_county_house_users.push_back(*itr);
      }
    }
  }

  top_county_house_users.sort(user_id_sort);

  return top_county_house_users;

}



int identify_id(int id){
  
  int r=0;

  while(id>9){
    r=r*10+id%10;
    id=id/10;
  }

  //return(r*10+id);

  r=(r*10+id)/10;

  return (r%10);
}

list<User*> QuerySolver::Query_3f()
{
  //throw("undefined");
  list<User*> premium_users;
  list<User*>::iterator itr;
  list<Product*>::iterator itrP;
  map<int,int>::iterator itrD;
  int ok=0;

  /*for(itr=server->getUsersList().begin();itr!=server->getUsersList().end();itr++){
    if((*itr)->getUserType()=="premium"){

      ok=0;

      PremiumUser *itr2 = dynamic_cast<PremiumUser *>(*itr);

      for(itrD=itr2->getDiscounts().begin();itrD!=itr2->getDiscounts().end();itrD++){
        if((identify_id(itrD->first)==1) || (identify_id(itrD->first)==6)){
          for(itrP=server->getProductsList().begin();itrP!=server->getProductsList().end();itrP++){
            if((*itrP)->getId()==itrD->first && ok==0){
              ok=1;
              premium_users.push_back(*itr);
            }
            
          }
        }
      }
    }
  }*/

  for(itr=server->getUsersList().begin();itr!=server->getUsersList().end();itr++){
    if((*itr)->getUserType()=="premium"){
      ok=0;

      PremiumUser *itr2 = dynamic_cast<PremiumUser *>(*itr);

      for(itrP=server->getProductsList().begin();itrP!=server->getProductsList().end();itrP++){
        if((*itrP)->getCategory()=="telefon" || (*itrP)->getCategory()=="imprimanta"){
          for(itrD=itr2->getDiscounts().begin();itrD!=itr2->getDiscounts().end();itrD++){
            if((*itrP)->getId()==itrD->first && ok==0){
              ok=1;
              premium_users.push_back(*itr);
            }
          }
        }
      }
    }
  }

  return premium_users;

}
