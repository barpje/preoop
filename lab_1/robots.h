#ifndef robots_h
#define robots_h
#include <iostream>
#include <string>
///struktura pomocnicza przechowywujaca pozycje x oraz y
typedef struct PositionXY{
    int x;
    int y;
}PositionXY;
///struktura przechowywujaca imie oraz pozycje robota
typedef struct Robot{
    const char* name;
    PositionXY poz;
}Robot;
///funkcja odpowiadajaca za "odzywanie sie robota"
void Speak(const Robot *p){
    if(p==nullptr) 
        printf("No such robot \n");
    else printf("Hi, I'm robot %s standing at x= %d y= %d \n",p->name,p->poz.x,p->poz.y);   
}

int count=0;
Robot *lista[5] = {nullptr};

///funkcja poruszajaca robotem po osi x
void ShiftX(Robot* a, int val){
int temp=0;
for(int i=0;i<count;i++){
    if(lista[i]->poz.x==a->poz.x+val && lista[i]->poz.y==a->poz.y){
        std::cout<<"ShiftX: Robots cannot stand at the same position"<<std::endl; 
        temp=1;
             }
    } 
if(temp!=1)     
    a->poz.x= a->poz.x + val;
}
///funkcja poruszajaca robotem po osi y
void ShiftY(Robot *a, int val){
int temp=0;
for(int i=0;i<count;i++){
    if(lista[i]->poz.x==a->poz.x && lista[i]->poz.y==a->poz.y + val){
        std::cout<<"ShiftY: Robots cannot stand at the same position"<<std::endl;
        temp=1;
            }
    } 
if(temp!=1) 
    a->poz.y=a->poz.y + val;       
}  

int check(Robot *p,PositionXY c){
	
	if(count>=5){
		std::cout<<"CreateRobot: Reached maximal number of robots."<<std::endl;
        return 0;
    }
	else 
	{
		for(int i=0;i<count;i++){
			if(lista[i]->poz.x==c.x && lista[i]->poz.y==c.y){
				std::cout<<"CreateRobot: Robots connot stand at the same position"<<std::endl;
                return 0;
		}
       }
	}	
return 1;
}

typedef void(*Operation)(Robot *p,int x);
///funkcja tworzaca robota 
Robot *CreateRobot(PositionXY k){
   // Robot *nowy=(Robot*) malloc(sizeof( Robot));
   Robot *nowy = new Robot;
    nowy->name="noname";
    nowy->poz.x=k.x;
    nowy->poz.y=k.y;
    if(check(nowy,k)){
        lista[count]=nowy;
        count++;
        return nowy;
    } else {
            delete nowy;
            return nullptr;
    }
}    

Robot *CreateRobot(const char *n, PositionXY k){
    Robot *nowy=new Robot;
    nowy->name=n;
    nowy->poz.x=k.x;
    nowy->poz.y=k.y;
    if(check(nowy,k)){
        lista[count]=nowy;
        count++;
        return nowy;
    } else {
            delete nowy;
            return nullptr;
    }
}  

///funkcja usuwajaca roboty
void RemoveRobots(){
    for(int j=0;j<count;j++){
	    if(lista[j]!=nullptr)
		    delete lista[j];
    }
}

#endif
