#include <vector>
#include "pesto.h"

using namespace std;

struct Pestobowl{};
struct Ingredients{};

struct RGB {
	short R, G, B;
};

RGB getRGBColor(Pesto* myPesto){
	RGB color = {255, 255, 0};
	return color;
}

int getNumberOfServings(){
	return 1;
}

void setbaseIngredients(Pesto* myPesto, int servings){
	myPesto->setParmesan(75 * servings);
	myPesto->setPinienkerne(50 * servings);
	myPesto->setSalzUndPfeffer(servings);
	myPesto->setKnoblauch(2 * servings);
}

void createPestoRosso(Pesto* myPesto, int servings, vector<int> extras){
	myPesto->setGetrockneteTomaten(125 * servings);
	for(auto iterator : extras){
		switch(iterator){
			case 0: myPesto->addWalnuss(100 * servings); break;
			case 1: myPesto->addParmesan(25 * servings); break;
		}
	}
}

void createPestoVerde(Pesto* myPesto, int servings, vector<int> extras){
	myPesto->setBasilikum(5 * servings);
	for(auto iterator : extras){
		switch(iterator){
			case 0: myPesto->addRucola(50 * servings); break;
			case 1: myPesto->addCashew(50 * servings); break;
			case 2: myPesto->addParmesan(25 * servings); break;
		}
	}
}

bool isPurchased(vector<Ingredients> allIngredients, vector<Ingredients> purchasedStuff){
	return true;
}

void buyIngredients(){
}

Pesto createPesto(vector<Ingredients> purchasedStuff, Pesto* myPesto){
	Pestobowl bowl ();
	bool texture;
	RGB myColor = getRGBColor(myPesto);
	RGB rosso = {255, 0, 0};
	RGB verde = {0, 255, 0};
	int servings = getNumberOfServings();

	vector<Ingredients> baseIngredients = myPesto->getBaseIngredients();
	//vector<Ingredients> extras = myPesto->getExtraIngredients();
	vector<int> extras = myPesto->getExtraIngredients();
	vector<Ingredients> allIngredients = baseIngredients;
	allIngredients.insert(allIngredients.end(), extras.begin(), extras.end());

	if(!isPurchased(allIngredients, purchasedStuff))
		buyIngredients();
	
	setbaseIngredients(myPesto, servings); 
	
	if(myColor.R == rosso.R){
		createPestoRosso(myPesto, servings, extras);
	}
	
	if(myColor.G == verde.G){
		createPestoVerde(myPesto, servings, extras);
	}

	while(!texture){
		myPesto->addOlivenöl(3 * servings);
		myPesto->pürierePesto();
		texture = myPesto->doesItLookLikePesto();
	}
	
	// schmeckt am besten zu nudeln oder baguette
	return *myPesto;
}
