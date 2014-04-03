#include <vector>
#include "pesto.h"

using namespace std;

struct Rezept{
	vector<Ingredients> getBaseIngredients();
	vector<Ingredients> getExtraIngredients();
};

struct Pestoglass{};

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

RGB getRGBColor(Rezept* myPesto){
	RGB color = {255, 255, 0};
	return color;
}

int getNumberOfServings(){
	return 1;
}

void setBaseIngredients(Pesto* pesto, int servings){
	pesto->setParmesan(75 * servings);
	pesto->setPinienkerne(50 * servings);
	pesto->setSalzUndPfeffer(servings);
	pesto->setKnoblauch(2 * servings);
}

void createPestoRosso(Pesto* pesto, int servings, vector<Ingredients> extras){
	pesto->setGetrockneteTomaten(125 * servings);
	for(auto iterator : extras){
		if(iterator.name == "Walnuss")
			pesto->addWalnuss(100 * servings);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25 * servings);
	}
}

void createPestoVerde(Pesto* pesto, int servings, vector<Ingredients> extras){
	pesto->setBasilikum(5 * servings);
	for(auto iterator : extras){
		if(iterator.name == "Rucola")
			pesto->addRucola(50 * servings);
		if(iterator.name == "Cashew")
			pesto->addCashew(50 * servings);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25 * servings);
	}
}

bool isPurchased(vector<Ingredients> all, vector<Ingredients> purchasedStuff){
	return true;
}

void buyIngredients(){
}

Pestoglass createPesto(vector<Ingredients> purchasedStuff, Rezept* myPesto){
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

	Pesto *pesto = new Pesto();

	if(!isPurchased(all, purchasedStuff))
		buyIngredients();
	
	setBaseIngredients(pesto, servings); 
	if(myColor.R == rosso.R)
		createPestoRosso(pesto, servings, extras);
	if(myColor.G == verde.G)
		createPestoVerde(pesto, servings, extras);

	while(!texture){
		pesto->addOlivenöl(3 * servings);
		pesto->pürierePesto();
		texture = pesto->doesItLookLikePesto();
	}
	
	Pestoglass glass = pesto->konservierePesto();
	bowl->clean();
	// schmeckt am besten zu nudeln oder baguette
	return glass;
}