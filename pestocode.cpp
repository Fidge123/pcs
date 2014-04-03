#include <vector>
#include "pesto.h"

using namespace std;

struct Bowl{
	void clean(){
		delete this;
	}
};

struct Ingredients{
	const char* name;
};

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

void createPestoRosso(Pesto* myPesto, int servings, vector<Ingredients> extras){
	myPesto->setGetrockneteTomaten(125 * servings);
	for(auto iterator : extras){
		if(iterator.name == "Walnuss")
			myPesto->addWalnuss(100 * servings);
		if(iterator.name == "Parmesan")
			myPesto->addParmesan(25 * servings);
	}
}

void createPestoVerde(Pesto* myPesto, int servings, vector<Ingredients> extras){
	myPesto->setBasilikum(5 * servings);
	for(auto iterator : extras){
		if(iterator.name == "Rucola")
			myPesto->addRucola(50 * servings);
		if(iterator.name == "Cashew")
			myPesto->addCashew(50 * servings);
		if(iterator.name == "Parmesan")
			myPesto->addParmesan(25 * servings);
	}
}

bool isPurchased(vector<Ingredients> all, vector<Ingredients> purchasedStuff){
	return true;
}

void buyIngredients(){
}

Pesto createPesto(vector<Ingredients> purchasedStuff, Pesto* myPesto){
	Bowl *bowl = new Bowl();
	bool texture;
	RGB myColor = getRGBColor(myPesto);
	RGB rosso = {255, 0, 0};
	RGB verde = {0, 255, 0};
	int servings = getNumberOfServings();

	vector<Ingredients> base = myPesto->getBaseIngredients();
	vector<Ingredients> extras = myPesto->getExtraIngredients();
	vector<Ingredients> all = base;
	all.insert(all.end(), extras.begin(), extras.end());

	if(!isPurchased(all, purchasedStuff))
		buyIngredients();
	
	setbaseIngredients(myPesto, servings); 
	if(myColor.R == rosso.R)
		createPestoRosso(myPesto, servings, extras);
	if(myColor.G == verde.G)
		createPestoVerde(myPesto, servings, extras);

	while(!texture){
		myPesto->addOlivenöl(3 * servings);
		myPesto->pürierePesto();
		texture = myPesto->doesItLookLikePesto();
	}
	

	bowl->clean();
	// schmeckt am besten zu nudeln oder baguette
	return *myPesto;
}