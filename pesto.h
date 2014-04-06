#include <vector>

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
		GlassOfPesto konservierePesto(Pesto *pesto);

	private:
		struct Ingredients {};
		struct GlassOfPesto {};
};

GlassOfPesto konservierePesto(Pesto *pesto){
	delete pesto;
	GlassOfPesto *glass = new GlassOfPesto();
	return *glass;
};