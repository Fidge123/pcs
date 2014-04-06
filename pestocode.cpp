#include "pesto.h"

using namespace std;

RGB getRGBColor(Rezept* pesto){
	// Welche Farbe hat das Pesto laut Rezept?
	RGB color = {255, 255, 0};
	return color;
}

int getNumberOfServings(){
	// Platzhalter fuer die Anzahl der Portionen
	// Eine Portion reicht normalerweise fuer 3-4 Mahlzeiten/Personen
	return 1;
}

bool isPurchased(vector<Ingredients> all, vector<Ingredients> purchasedStuff){
	// Platzhalter fuer die Ueberpruefung ob alles gekauft wurde
	return true;
}

void buyIngredients(){
	// Platzhalter fuer den Supermarktbesuch
}

bool looksNotLikePesto(){
	// Eine leere Schuessel ist kein Pesto
	return false;
}

GlassOfPesto* Pesto::konservierePesto(Pesto* pesto){
   delete pesto;
	GlassOfPesto* newPestoGlass = new GlassOfPesto;
	return newPestoGlass;
}

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
	pesto->setBasilikum(5 blaetter * servings, bowl);
	for(auto iterator : extras){
		if(iterator.name == "Rucola")
			pesto->addRucola(50 gramm * servings, bowl);
		if(iterator.name == "Cashew")
			pesto->addCashew(50 gramm * servings, bowl);
		if(iterator.name == "Parmesan")
			pesto->addParmesan(25 gramm * servings, bowl);
	}
}

GlassOfPesto* createPesto(vector<Ingredients> purchasedStuff, Rezept* myPesto){
	Bowl* bowl = new Bowl();
	bool texture = looksNotLikePesto();
	RGB myColor = getRGBColor(myPesto);
	RGB rosso = {255, 0, 0};
	RGB verde = {0, 255, 0};
	int servings = getNumberOfServings();

	Pesto* pesto = new Pesto();

	vector<Ingredients> base = myPesto->getBaseIngredients();
	vector<Ingredients> extras = myPesto->getExtraIngredients();
	vector<Ingredients> all = base;
	all.insert(all.end(), extras.begin(), extras.end());

	if(!isPurchased(all, purchasedStuff))
		buyIngredients();
	
	setBaseIngredients(pesto, servings, bowl); 
	if(myColor.equals(rosso))
		createPestoRosso(pesto, servings, extras, bowl);
	if(myColor.equals(verde))
		createPestoVerde(pesto, servings, extras, bowl);

	while(!texture){
		pesto->addOlivenoel(3 EL * servings, bowl);
		pesto->puerierePesto(bowl);
		texture = pesto->doesItLookLikePesto();
	}
	
	GlassOfPesto* glass = pesto->konservierePesto(pesto);
	bowl->clean();

	// schmeckt gut zu Nudeln oder Baguette
	return glass;
}

// komplette Version auf http://bit.ly/1gApXLs

void Pesto::setParmesan(int num, Bowl *bowl){}
void Pesto::setPinienkerne(int num, Bowl *bowl){}
void Pesto::setSalzUndPfeffer(int num, Bowl *bowl){}
void Pesto::setKnoblauch(int num, Bowl *bowl){}
void Pesto::setGetrockneteTomaten(int num, Bowl *bowl){}
void Pesto::addWalnuss(int num, Bowl *bowl){}
void Pesto::addParmesan(int num, Bowl *bowl){}
void Pesto::addRucola(int num, Bowl *bowl){}
void Pesto::addCashew(int num, Bowl *bowl){}
void Pesto::setBasilikum(int num, Bowl *bowl){}
void Pesto::addOlivenoel(int num, Bowl *bowl){}
void Pesto::puerierePesto(Bowl *bowl){}
bool Pesto::doesItLookLikePesto(){
	return true;
}

int main(){
	vector<Ingredients> purchasedStuff;
	Rezept* myPesto = new Rezept();
	GlassOfPesto* glass = createPesto(purchasedStuff, myPesto);
	delete glass;
	printf("success\n");
	return 0;
}


