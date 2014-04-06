#include "pesto.h"

using namespace std;

struct GlassOfPesto{};

struct Rezept{
	vector<Ingredients> getBaseIngredients();
	vector<Ingredients> getExtraIngredients();
};

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

bool isPurchased(vector<Ingredients> all, vector<Ingredients> purchasedStuff){
	return true;
}

void buyIngredients(){
}

bool looksNotPesto(){
	return false;
}

#define gramm
#define zehen
#define blätter
#define EL

// the interesting stuff begins here
void setBaseIngredients(Pesto* pesto, int servings, Bowl *bowl){
	pesto->setParmesan(75 gramm * servings, bowl);
	pesto->setPinienkerne(50 gramm * servings, bowl);
	pesto->setSalzUndPfeffer(servings, bowl);
	pesto->setKnoblauch(2 zehen * servings, bowl);
}

void createPestoRosso(Pesto* pesto, int servings, vector<Ingredients> extras, Bowl *bowl){
	pesto->setGetrockneteTomaten(125 gramm * servings, bowl);
	for(auto iterator : extras){
		if(iterator.name == "Walnuss")
			pesto->addWalnuss(100 gramm * servings, bowl);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25 gramm * servings, bowl);
	}
}

void createPestoVerde(Pesto* pesto, int servings, vector<Ingredients> extras, Bowl *bowl){
	pesto->setBasilikum(5 blätter * servings, bowl);
	for(auto iterator : extras){
		if(iterator.name == "Rucola")
			pesto->addRucola(50 gramm * servings, bowl);
		if(iterator.name == "Cashew")
			pesto->addCashew(50 gramm * servings, bowl);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25 gramm * servings, bowl);
	}
}

GlassOfPesto createPesto(vector<Ingredients> purchasedStuff, Rezept* myPesto){
	Bowl *bowl = new Bowl();
	bool texture = looksNotPesto();
	RGB myColor = getRGBColor(myPesto);
	RGB rosso = {255, 0, 0};
	RGB verde = {0, 255, 0};
	int servings = getNumberOfServings();

	Pesto *pesto = new Pesto();

	vector<Ingredients> base = myPesto->getBaseIngredients();
	vector<Ingredients> extras = myPesto->getExtraIngredients();
	vector<Ingredients> all = base;
	all.insert(all.end(), extras.begin(), extras.end());

	if(!isPurchased(all, purchasedStuff))
		buyIngredients();
	
	setBaseIngredients(pesto, servings, bowl); 
	if(myColor.R == rosso.R)
		createPestoRosso(pesto, servings, extras, bowl);
	if(myColor.G == verde.G)
		createPestoVerde(pesto, servings, extras, bowl);

	while(!texture){
		pesto->addOlivenöl(3 EL * servings, bowl);
		pesto->pürierePesto(bowl);
		texture = pesto->doesItLookLikePesto();
	}
	
	GlassOfPesto glass = pesto->konservierePesto();
	bowl->clean();

	// schmeckt gut zu Nudeln oder Baguette
	return glass;
}