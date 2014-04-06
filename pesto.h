#include <vector>

// Einheiten fuer bessere Lesbarkeit
#define gramm
#define zehen
#define blaetter
#define EL // Essloeffel

typedef struct GlassOfPesto{
	// Ein Glass voll Pesto
} GlassOfPesto;


typedef struct Ingredients{
	// Eine Zutat mit Namen
	const char* name;
} Ingredients;

typedef struct Rezept{
	// Ein Rezept mit Zutaten
	std::vector<Ingredients> getBaseIngredients();
	std::vector<Ingredients> getExtraIngredients();
} Rezept;

typedef struct Bowl{
	// Eine Schuessel fuer das Pesto
	void clean(){
		delete this;
	}
} Bowl;

typedef struct RGB {
   // Farbe in RGB Werten
   short R, G, B;
   bool equals(struct RGB second) const{
      return ((R == second.R) && (G == second.G) && (B == second.B));
   }
} RGB;

class Pesto
{
	public:
		void setParmesan(int num, Bowl *bowl);
		void setPinienkerne(int num, Bowl *bowl);
		void setSalzUndPfeffer(int num, Bowl *bowl);
		void setKnoblauch(int num, Bowl *bowl);
		void setGetrockneteTomaten(int num, Bowl *bowl);
		void addWalnuss(int num, Bowl *bowl);
		void addParmesan(int num, Bowl *bowl);
		void addRucola(int num, Bowl *bowl);
		void addCashew(int num, Bowl *bowl);
		void setBasilikum(int num, Bowl *bowl);
		void addOlivenoel(int num, Bowl *bowl);
		void puerierePesto(Bowl *bowl);
		bool doesItLookLikePesto();
		std::vector<Ingredients> getBaseIngredients();
		std::vector<Ingredients> getExtraIngredients();
		GlassOfPesto konservierePesto();
};
