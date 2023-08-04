#include "includes.h"
int main() {
	string str;
	double q;
	storage stg;
	vector<double>& arr = stg.statist.get_arr();
	cout << "Input subsequence: " ;
	getline(cin, str);
	istringstream iss(str);
	while (iss >> q) {
		stg.statist.push_back(q);
	}
	stg.minm.get_min_max(arr);
	stg.mstd.get_stde_mean(arr, stg.statist.get_total());
	stg.qnt.get_quantile(stg.statist.get_arr());
	cout << "Minimal: " << stg.minm.get_min() << endl << "Maximal: " << stg.minm.get_max() << endl << "Mean: " << stg.mstd.get_mean() << endl << "Std: " << stg.mstd.get_stde() << endl << "pct 90: " << stg.qnt.get_qnt90()<< endl << "pct 95: " << stg.qnt.get_qnt95();
	getch();
	return 0;
}