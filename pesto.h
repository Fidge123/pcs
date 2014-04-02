#include <vector>

class Pesto
{
	public:
		void setPinienkerne(int num);
		void setSalzUndPfeffer(int num);
		void setKnoblauch(int num);
		void setGetrockneteTomaten(int num);
		void addWalnuss(int num);
		void addParmesan(int num);
		void addRucola(int num);
		void addCashew(int num);
		void setBasilikum(int num);
		void addOliven�l(int num);
		void p�rierePesto();
		bool doesItLookLikePesto();
		std::vector<Ingredients> getBaseIngredients();
		//std::vector<Ingredients> getExtraIngredients();
		std::vector<int> getExtraIngredients();

	private:
		struct Ingredients {};
};
