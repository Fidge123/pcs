#include "pesto.h"

class Pesto
{
	private:
		RGB getRGBColor(Recipe* pesto);
		int getNumberOfServings();
		bool isPurchased(std::vector<Ingredients> all, std::vector<Ingredients> purchasedStuff);
		void buyIngredients();
		bool looksNotLikePesto();
		void setBaseIngredients(Pesto* pesto, int servings, Bowl *bowl);
		void createPestoRosso(Pesto* pesto, int servings, std::vector<Ingredients> extras, Bowl *bowl);
		void createPestoVerde(Pesto* pesto, int servings, std::vector<Ingredients> extras, Bowl *bowl);
		GlassOfPesto* createPesto(std::vector<Ingredients> purchasedStuff, Recipe* myPesto);
		int main();
};