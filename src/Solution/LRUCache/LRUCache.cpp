#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	//throw("undefined");
	this->capacity=capacity;
	lru.resize(capacity);
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	//throw("undefined");
	vector<int>::iterator itr;
	vector<int>::iterator j_erase;
	int i=0;
	int j;
	int ok=0;

	for(itr=requestsNo.begin();itr!=requestsNo.end();itr++){

		for(j_erase=lru.begin();j_erase!=lru.end();j_erase++){
			if(j_erase==itr){
				//ok=1;
				//(*j_erase)=j;
				lru.erase(j_erase);
			}
		}

		for(i=capacity;i>0;i--){
			lru[i]=lru[i-1];
		}
		lru[0]=(*itr);
		
	}

	return lru;
}

int LRUCache::getCapacity()
{
	//throw("undefined");
	return capacity;
}

int LRUCache::getSize()
{
	//throw("undefined");
	return size;
}

vector<int> LRUCache::getLRU()
{
	//throw("undefined");
	return lru;
}

int LRUCache::getLRUCapacity()
{
	//throw("undefined");
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	//throw("undefined");
	this->capacity=capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	//throw("undefined");
	this->lru=aux;
}
