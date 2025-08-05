#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class CLiquid {
protected:

	string m_name;
	double m_density;

public:

	CLiquid() : m_name(""), m_density(0) {}
	CLiquid(string mn, double md) : m_name(mn), m_density(md) {}
	~CLiquid() {}

	string get_name();
	double get_densite();
	virtual void set_info() = 0;

};


class CAlcohol : public CLiquid {
private:
	double m_strenght;

public:
	CAlcohol() : CLiquid(), m_strenght(0) {}
	CAlcohol(string mn, double md, double ms) : CLiquid(mn, md), m_strenght(ms) {}
	CAlcohol(CAlcohol& obj) : CLiquid(obj.m_name, obj.m_density), m_strenght(obj.m_strenght) {}
	~CAlcohol() {}

	double get_strenght();
	void set_info() override;

};


class CPetrol : public CLiquid {
private:
	unsigned int m_oct_num;

public:
	CPetrol() : CLiquid(), m_oct_num(0) {}
	CPetrol(string mn, double md, unsigned int mon) : CLiquid(mn, md), m_oct_num(mon) {}
	CPetrol(CPetrol& obj) : CLiquid(obj.m_name, obj.m_density), m_oct_num(obj.m_oct_num) {}
	~CPetrol() {}

	unsigned int get_oct_num();
	void set_info() override;
};


class CMenu {
public:
	void set_info(CLiquid* liquid);
};

