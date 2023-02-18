#include "Dwelling.h"

Dwelling::Dwelling(){
    workers_cost_ = 1;
    coins_cost_ = 2; 
}

Dwelling::Dwelling(bool provides_worker) 
 : provides_worker_(provides_worker){}

Dwelling::Dwelling(uint8_t workers_cost, uint8_t coins_cost, bool provides_worker)
 : provides_worker_(provides_worker) {
    workers_cost_ = workers_cost;
    coins_cost_ = coins_cost; 
 }
 