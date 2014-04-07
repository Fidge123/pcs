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

typedef struct Recipe{
	// Ein Rezept mit Zutaten
	std::vector<Ingredients> getBaseIngredients(){
		std::vector<Ingredients> vect;
		return vect;
	}
	std::vector<Ingredients> getExtraIngredients(){
		std::vector<Ingredients> vect;
		return vect;
	}
} Recipe;

typedef struct Bowl{
	// Eine Schuessel fuer das Pesto
	void clean(){
		delete this;
	}
} Bowl;

typedef struct Blender{
	// Pürierstab
	void clean(){
		delete this;
	}
} Blender;

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
		void setParmesan(int num, Bowl* bowl);
		void setPinienkerne(int num, Bowl* bowl);
		void setSalzUndPfeffer(int num, Bowl* bowl);
		void setKnoblauch(int num, Bowl* bowl);
		void setGetrockneteTomaten(int num, Bowl* bowl);
		void addWalnuss(int num, Bowl* bowl);
		void addParmesan(int num, Bowl* bowl);
		void addRucola(int num, Bowl* bowl);
		void addCashew(int num, Bowl* bowl);
		void setBasilikum(int num, Bowl* bowl);
		void addOlivenoel(int num, Bowl* bowl);
		void puerierePesto(Blender* blender, Bowl* bowl);
		bool doesItLookLikePesto();
		GlassOfPesto* putPestoInAGlass(Pesto* pesto);
};
