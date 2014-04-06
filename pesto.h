#include <vector>

// Einheiten für bessere Lesbarkeit
#define gramm
#define zehen
#define blätter
#define EL // Esslöffel

typedef struct GlassOfPesto{
        // Ein Glass voll Pesto
} GlassOfPesto;

typedef struct Rezept{
        // Ein Rezept mit Zutaten
        vector<Ingredients> getBaseIngredients();
        vector<Ingredients> getExtraIngredients();
} Rezept;

typedef struct Bowl{
        // Eine Schüssel für das Pesto
        void clean(){
                delete this;
        }
} Bowl;

typedef struct Ingredients{
        // Eine Zutat mit Namen
        const char* name;
} Ingredients;

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
		void addOlivenöl(int num, Bowl *bowl);
		void pürierePesto(Bowl *bowl);
		bool doesItLookLikePesto();
		std::vector<Ingredients> getBaseIngredients();
		std::vector<Ingredients> getExtraIngredients();
		GlassOfPesto konservierePesto();
};
