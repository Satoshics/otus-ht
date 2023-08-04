#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <sstream>
using std::cout, std::cin, std::vector, std::string, std::endl, std::sort, std::getline, std::istringstream;
class statistics;
class min_max;
class mean_stde;
class quantile;
class storage;
class statistic {
private:
	double total;
	vector<double> data;
public:
	statistic():total(0)
	{ data.reserve(15);}
	void push_back(double q);
	double get_total();
	uint64_t get_qty();
	double get_elem(uint64_t num);
	vector<double>& get_arr();
	virtual void get_min_max(vector<double>& st);
	virtual void get_stde_mean(vector<double>& st, double total);
	virtual void get_quantile(vector<double>& st);
};
class min_max : public statistic {
private:
	double minimal, maximal;
public:
	min_max() : minimal(0), maximal(0)
	{ };
	void get_min_max(vector<double>& st);
	double get_min();
	double get_max();
};

class mean_stde : public statistic {
private:
	double mean, std_e;
public:
	mean_stde() :std_e(0), mean(0)
	{ };
	void get_stde_mean(vector<double>& st, double total);
	double get_stde();
	double get_mean();
};
class quantile: public statistic {
private:
	double quantile90, quantile95;
public:
	void buble_sort(vector<double>& st);
	quantile(): quantile90(0), quantile95(0)
	{ };
	void get_quantile(vector<double>& st);
	double get_qnt90();
	double get_qnt95();
};
class storage {
public:
	 min_max minm;
	 mean_stde mstd;
	 quantile qnt;
	 statistic statist;
};
