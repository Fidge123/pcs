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

// VS2012 does not support user-defined literals yet
// feel free to correct this part as I didnt test it

/**
constexpr Units operator "" _g(int g)
{
  return Units{Units::IntIsGramm{}, static_cast<int>(g)};
}

constexpr Units operator "" _EL(int el)
{
  return Units{Units::IntIsEL{}, static_cast<int>(el)};
}

constexpr Units operator "" _zehen(int z)
{
  return Units{Units::IntIsZehen{}, static_cast<int>(z)};
}

constexpr Units operator "" _blätter(int b)
{
  return Units{Units::IntIsBlätter{}, static_cast<int>(b)};
}
**/

// the interesting stuff begins here
void setBaseIngredients(Pesto* pesto, int servings, Bowl *bowl){
	pesto->setParmesan(75_g * servings, bowl);
	pesto->setPinienkerne(50_g * servings, bowl);
	pesto->setSalzUndPfeffer(servings, bowl);
	pesto->setKnoblauch(2_zehen * servings, bowl);
}

void createPestoRosso(Pesto* pesto, int servings, vector<Ingredients> extras, Bowl *bowl){
	pesto->setGetrockneteTomaten(125_g * servings, bowl);
	for(auto iterator : extras){
		if(iterator.name == "Walnuss")
			pesto->addWalnuss(100_g * servings, bowl);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25_g * , bowl);
	}
}

void createPestoVerde(Pesto* pesto, int servings, vector<Ingredients> extras, Bowl *bowl){
	pesto->setBasilikum(5_blätter * servings, bowl);
	for(auto iterator : extras){
		if(iterator.name == "Rucola")
			pesto->addRucola(50_g * servings, bowl);
		if(iterator.name == "Cashew")
			pesto->addCashew(50_g * servings, bowl);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25_g * servings, bowl);
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
		pesto->addOlivenöl(3_EL * servings);
		pesto->pürierePesto(bowl);
		texture = pesto->doesItLookLikePesto();
	}
	
	GlassOfPesto glass = pesto->konservierePesto();
	bowl->clean();

	// schmeckt gut zu Nudeln oder Baguette
	return glass;
}