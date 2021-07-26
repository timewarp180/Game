#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>    

#define MAX 100

typedef	struct bag {
	char name[10];
	char desc[20];
	int qty;
	int usage;
} item;
typedef struct ninja {
	item inventory[MAX];
	int invCount;
	char name[25];
	int hp;
	int attack;
}character;

typedef struct list {
	character hero[MAX];
	int player;
} LIST;

void displayPlayerStats(LIST L, int i);
void insertHero(LIST *L, character C);
void pvp(LIST *L);
void initPLayer(LIST *L);
void UseAnddisplayItem(LIST *L, int i);
void delay(unsigned int milliseconds);
void pve(LIST *L);
int main(){
	int x;
	int i;
	LIST L;
	initPLayer(&L);
	
	
	printf("Enter 1 for PVP || 2 for PVE: ");
	scanf("%d", &x);
	if(x==1){
		 printf("\nYou can only use 3 move at a time\n ");
		 printf("\nHINT: You have 3 potions and 1 booster in your backpack. Using inventory when you dont have items left in your bag will make your move useless. So use it wisely \n");
		L.hero[0].invCount=0;
		L.hero[1].invCount=0;

		character c1 = {{ {"Potion", "Heals 500 hp", 3, 500},{"Booster", "Damage boost 250", 1, 250} }, 2," playerUNO", 5000, 500};
		character c2 = {{ {"Potion", "Heals 500 hp", 3, 500},{"Booster", "Damage boost 250", 1, 250} }, 2," playerDOS", 5000, 500};
		
	
		insertHero(&L, c1);
		insertHero(&L, c2);
	//	UseAnddisplayItem(L,  0);

	    pvp(&L);

	
	}else if(x==2){
    	 printf("\nYou can only use 3 move at a time\n");
    	 printf("Adventure mode up to 5 rounds, 50 percent drops healing and potion if you win a round. Monsters get stronger each round\n You only have 1 potion in your bag, earn other items by killing the monsters.");
       	L.hero[0].invCount=0;
       	
   		character c1 = { {"Potion", "Heals 500 hp", 1, 500}, 1,"Garfield", 5000, 500};

   		insertHero(&L, c1);
	//	UseAnddisplayItem(&L, 0);
       	pve(&L);
       	
       	
       	

	}
	
	
}
void delay(unsigned int milliseconds) {    
    clock_t start = clock();    
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);    
}    

void initPLayer(LIST *L){
	L->player=0;
	
}

void insertItem(LIST *L,int x, item I){
		if(L->hero[x].invCount<MAX){
			L->hero[x].inventory[L->hero[x].invCount]=I;
			L->hero[x].invCount++;
		}
}

void insertHero(LIST *L, character C){
		
		if(L->player < MAX){
		L->hero[L->player]=C;
		L->player++;		
	}
}

void UseAnddisplayItem(LIST *L, int i){
	//returns the number of item that you are going to use
	int y,x,choice;
	printf("%-10s %-15s %20s %20s \n", "Name", "Desc", "Quantity", "Usage");

	for(x=0; x<L->hero[i].invCount; x++){
		printf("#%d ", x);
		printf("%-10s", L->hero[i].inventory[x].name);
		printf("%-15s", L->hero[i].inventory[x].desc);
		printf("%20d", L->hero[i].inventory[x].qty);
		printf("%20d", L->hero[i].inventory[x].usage);
		printf("\n");
	}
	
	
	printf("\n Enter The # of the item you want to use. \n");
	scanf("%d", &choice);
	for(x=0; x<L->hero[i].invCount; x++){
	if(L->hero[i].invCount > 0){
		
	
		if(choice == x){
			if(strcmp(L->hero[i].inventory[x].name, "Potion")==0 ){
				L->hero[i].hp += L->hero[i].inventory[x].usage;
				L->hero[i].inventory[x].qty--;
			
			if(L->hero[i].inventory[x].qty <=0 ){
				for(y=x; y < L->hero[i].invCount; ++y){
					L->hero[i].inventory[y] = 	L->hero[i].inventory[y+1];
				}
				L->hero[i].invCount--;
			}
			
		}else if(strcmp(L->hero[i].inventory[x].name, "Booster")==0 ){
			L->hero[i].attack += L->hero[i].inventory[x].usage;
			L->hero[i].inventory[x].qty--;
			if(L->hero[i].inventory[x].qty <=0 ){
				for(y=x; y < L->hero[i].invCount; ++y){
					L->hero[i].inventory[y] = 	L->hero[i].inventory[y+1];
				}
				L->hero[i].invCount--;
			}
		}
	}
	
	}else if(L->hero[i].invCount <= 0){
		printf("\n You have no more items left\n ");
	}
	
	}
	
	
}

void displayPlayerStats(LIST L, int i){
	printf("\n\n");
	printf("player name: %s\n", L.hero[i].name );
	printf("player HP: %d\n", L.hero[i].hp);
	printf("player attack power: %d\n", L.hero[i].attack);

}

void pvp(LIST *L){
	int i,x;
	int ret, c1Turn, c2Turn, choice1[3], choice2[3];
	int WR=0,rounds=1, win;
	int hero1=0, hero2=1;
	
	printf("\nwelcome to pvp press any key to start \n ");
	getch();
	system("cls");
	
	for(x=0; WR != 1; x++){
		for(c1Turn=3; c1Turn > 0; c1Turn--){
			if(L->hero[hero1].hp > 0){
				printf("Player 1 turn MOve: %d \n", c1Turn);
				printf("1 - Attack enemy \n");
				printf("2 - Harden, +200 hp \n");
				printf("3 - Inventory\n");
				printf("Choose only the number: ");

				scanf("%d", &choice1[c1Turn]);
				
			
					system("cls");
			}
			
		}
		
		for(c2Turn=3; c2Turn>0; c2Turn--){	
				if(L->hero[hero2].hp > 0){
				printf("Player 2 turn MOve: %d \n", c2Turn);
				printf("1 - Attack enemy \n");
				printf("2 - Harden, +200 hp \n");
				printf("3 - Inventory\n");
				printf("Choose only the number: ");
				scanf("%d", &choice2[c2Turn]);
				
				
					system("cls");
			}
			
		}
		
		if(L->hero[hero1].hp >0 && L->hero[hero2].hp >0){
			printf("\n BATTLEMODE ROUND %d: \n ", rounds);
			for(c1Turn=3; c1Turn>0; c1Turn--){
					if(choice1[c1Turn] == 1 ){
						printf("LOG: Player 1 Attacks player 2\n ");
						
						delay(1000);
						L->hero[hero2].hp -= L->hero[hero1].attack;
						if(L->hero[hero2].hp  < 0){
							WR = 1;
						}
					}else if(choice1[c1Turn] == 2 ){
						printf("LOG: Player 1 Uses Harden\n");
						delay(1000);


						L->hero[hero1].hp += 200;
					}else if(choice1[c1Turn] == 3 ){
					printf("LOG: Player 1 Uses Bag\n");
						delay(1000);


						//uses item
						UseAnddisplayItem(L, hero1);
					}
			}
			
			for(c2Turn=3; c2Turn>0; c2Turn--){
						if(choice2[c2Turn] == 1 ){
						printf("LOG: Player 2 Attacks player 1\n ");
						delay(1000);

						L->hero[hero1].hp -= L->hero[hero2].attack;
						if(L->hero[hero1].hp  < 0){
							WR = 1;
						}
						
					}else if(choice2[c2Turn] == 2 ){
						printf("LOG: Player 2 Uses Harden\n");
						delay(1000);
		
						L->hero[hero2].hp += 200;
					}else if(choice2[c2Turn] == 3 ){
					printf("LOG: Player 2 Uses Bag\n");
						//uses item
						delay(1000);

						UseAnddisplayItem(L, hero2);
					}
				
			}
			 displayPlayerStats(*L, hero1 );
			 displayPlayerStats(*L, hero2);
			 rounds++;
			 
			 if(L->hero[hero2].hp  < 0 && L->hero[hero2].hp < L->hero[hero1].hp ){
			 	printf("\n PLAYER 1 WIN!!! \n");
			 }else if(L->hero[hero1].hp  < 0 && L->hero[hero1].hp < L->hero[hero2].hp ){
			 	printf("\n PLAYER 2 WIN!!! \n");
			 }
				 printf("\n press any key: \n ");
				 getch();

			 system("cls");
						
		}
		
	}
	
	
}

void pve(LIST *L){
	
	time_t t;
	srand((unsigned) time(&t));
	int i,x;
	int ret, c1Turn, c2Turn, choice1[3], choice2[3];
	int WR=0,rounds=1, win,WW=0,ct=0;
	int hero1=0, monster=1, bonus;
	
	printf("\nwelcome to ADVENTURE press any key to start \n ");
	getch();
	system("cls");
	
		character m = { {}, 0,"Monster", 5000, 500};

   		insertHero(L, m);
//	 displayPlayerStats(*L, 1);

	
	for(x=0; WR != 1 && ct != 5; x++){
		
		printf("Monster: %d\n", ct);
		
		for(c1Turn=3; c1Turn > 0; c1Turn--){
			if(L->hero[hero1].hp > 0){
				printf("Player 1 turn MOve: %d \n", c1Turn);
				printf("1 - Attack enemy \n");
				printf("2 - Harden, +200 hp \n");
				printf("3 - Inventory\n");
				printf("Choose only the number: ");

				scanf("%d", &choice1[c1Turn]);
				
			
					system("cls");
			}
			
		}
		
		for(c2Turn=3; c2Turn>0; c2Turn--){	
				if(L->hero[monster].hp > 0){
			
				// random movement AI
				
				 choice2[c2Turn]=rand() % 2;
				
			}
			
		}
		
		if(L->hero[hero1].hp >0 && L->hero[monster].hp >0){
			printf("\n BATTLEMODE ROUND %d: \n ", rounds);
			for(c1Turn=3; c1Turn>0; c1Turn--){
					if(choice1[c1Turn] == 1 ){
						printf("\nLOG: Player 1 Attacks The Monster \n ");
						
						delay(1000);
						L->hero[monster].hp -= L->hero[hero1].attack;
						if(L->hero[monster].hp  < 0){
							
							WW++;
							
						}
					}else if(choice1[c1Turn] == 2 ){
						printf("\nLOG: Player 1 Uses Harden\n");
						delay(1000);


						L->hero[hero1].hp += 200;
					}else if(choice1[c1Turn] == 3 ){
					printf("\nLOG: Player 1 Uses Bag\n");
						delay(1000);


						//uses item
						UseAnddisplayItem(L, hero1);
					}
			}
			
			for(c2Turn=3; c2Turn>0; c2Turn--){
						if(choice2[c2Turn] == 0 ){
						printf("\nLOG: Monster Attacks player 1\n ");
						delay(1000);

						L->hero[hero1].hp -= L->hero[monster].attack;
						if(L->hero[hero1].hp  < 0){
							WR = 1;
						}
						
					}else if(choice2[c2Turn] == 1 ){
						printf("\nLOG: Monster Uses Harden\n");
						delay(1000);
		
						L->hero[monster].hp += 200;
					}
				
			}
			 displayPlayerStats(*L, hero1 );
			 displayPlayerStats(*L, monster);
			 rounds++;
		
		
			 if(ct < WW ){
			 	printf("\nRefreshing hero and monster...");
			 	delay(1000);
				 ct = WW;
			 
			 	insertHero(L, m);
			 	
			 	L->hero[hero1].hp=5000;
			 	
			    
			 	L->hero[monster].attack =	L->hero[monster].attack + (ct*100);
			 	
			 	
			 	L->hero[monster].hp =	L->hero[monster].hp + (ct*150);

				 bonus=rand() % 100;
				 printf("\nBonus droprate percentage: %d\n", bonus);
				 if(bonus >= 50){
				 	printf("\nCONGRATULATIONS YOU HAVE FOUND AN ITEM\n");
				 	item I =  {"Potion", "Heals 500 hp", 1, 500};
				 	item E = {"Booster", "Damage boost 250", 1, 250};
				
				 	insertItem(L,hero1, E);
			 		insertItem(L,hero1, I);
				 	
				 	
				 }
				 
			 }
			 
			 
			 
			 if(L->hero[monster].hp  < 0 && L->hero[monster].hp < L->hero[hero1].hp){
			 	printf("\n PLAYER 1 WIN!!! GET READY FOR ROUND %d\n", WW);
			 }else if(L->hero[hero1].hp  < 0 && L->hero[hero1].hp < L->hero[monster].hp){
			 	printf("\n YOU LOSE! \n");
			 }else if(ct == 5){
			 	printf("YOU ARE THE ChAMPION!");
			 }
			 
			 
			 
			 
			 
		 	printf("\n press any key: \n ");
			 getch();
			 system("cls");					
		}
		
	}
	
}
