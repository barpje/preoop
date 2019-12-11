#include "rifle.h"

using namespace std;

Rifle::Rifle(int size,double caliber): _size{size}, _count{size}{
       
        _kom=nullptr;
       _mag= new Bullet *[_size];
        for(int i = 0; i<size; i++)
            _mag[i]=new Bullet(caliber);
}
 void Rifle::load(){
        if(_count==0){
                mag_empty();
                _kom=nullptr;
                return;
        }
        _kom=_mag[_count-1];
        _kom->click();
        _mag[_count-1]=nullptr;
        _count--;
}

void Rifle::pull_trigger(){
     if(_kom==nullptr){
            chamb_empty();
            return;
            }
    bang();
    delete _kom;
    _kom=nullptr;
}
void Rifle::pull_trigger(int ile){
    for(int i=0;i<ile;i++){  
        load();
        pull_trigger();
    }
}
void Rifle::new_magazine(){
    for(int i = 0; i < _size; i++)
        _mag[i]= new Bullet(1.0);
    _count = _size;    
}


Rifle::Rifle(const Rifle& tmp){
    _size=tmp._count;
    _kom =tmp._kom;
    _count=tmp._count;
    _mag=new Bullet*[_count];
    for(int i = 0; i<_count;i++)
        _mag[i]=new Bullet(tmp._mag[i]->get_caliber());
}    
Rifle::Rifle(Rifle&& tmp){
     _size=tmp._size;
     _kom=tmp._kom;
     _count=tmp._count;
     _mag=tmp._mag;
    tmp._size=0;
    tmp._kom =nullptr;
    tmp._count=0;
    tmp._mag=nullptr;
}

Rifle::~Rifle(){
    for(int i = 0 ;i < _size; i++){
        if(_mag[i]!=nullptr)
            delete _mag[i];}
    delete [] _mag;
}
        
    
