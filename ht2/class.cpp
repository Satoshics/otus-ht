#include "includes.h"
void statistic::push_back(double q) {
	data.emplace_back(q);
	total += q;
}
double statistic::get_total() {
	return this->total;
}
uint64_t statistic::get_qty(){
	return size(data);
}
double statistic::get_elem(uint64_t num) {
	return this->data[num];
}
vector<double>& statistic::get_arr()
{
	return data;
}
void statistic::get_min_max(vector<double>& st){

}
void statistic::get_stde_mean(vector<double>& st, double total){

}
void statistic::get_quantile(vector<double>& st){

}
double min_max::get_min() {
	return this->minimal;
}
double min_max::get_max() {
	return this->maximal;
}
double mean_stde::get_stde() {
	return this->std_e;
}
double mean_stde::get_mean() {
	return this->mean;
}
double quantile::get_qnt90() {
	return this->quantile90;
}
double quantile::get_qnt95() {
	return this->quantile95;
}
void min_max::get_min_max(vector<double>& st) {
	double min = st[0];
	double max = st[0];
	for (int i = 0; i < st.size(); i++) {
		if (st[i] < min) {
			min = st[i];
		}
		if (st[i] > max) {
			max = st[i];
		}

	}
	minimal = min;
	maximal = max;
}
void mean_stde::get_stde_mean(vector<double>& st, double total){
	double mn = total / st.size();
	double total_3rd = 0;
	for (int i = 0; i < st.size(); i++) {
		double third = abs(st[i] - mn);
		third = pow(third, 2);
		total_3rd += third;
	}
	mean = mn;
	std_e = sqrt(total_3rd / st.size());
}
void quantile::get_quantile(vector<double>& st) {
	sort(st.begin(), st.end());
	uint64_t sz = st.size();
	double quant90 = floor(sz * 0.9);
	double quant95 = floor(sz * 0.95);
	this->quantile90 = st[quant90];
	this->quantile95 = st[quant95];
}