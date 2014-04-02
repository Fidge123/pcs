#include <vector>

class Pesto
{
	public:
		void setParmesan(int num);
		void setPinienkerne(int num);		void setSalzUndPfeffer(int num);		void setKnoblauch(int num);		void setGetrockneteTomaten(int num);		void addWalnuss(int num);		void addParmesan(int num);		void addRucola(int num);		void addCashew(int num);		void setBasilikum(int num);		void addOlivenöl(int num);		void pürierePesto();		bool doesItLookLikePesto();		std::vector<Ingredients> getBaseIngredients();		std::vector<Ingredients> getExtraIngredients();	private:		struct Ingredients {};};