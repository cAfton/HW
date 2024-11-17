#pragma once

class roots {
	int a;
	int b;
	int c;
protected:
	int A();
	int B();
	int C();
	bool isLogocal();
	void A(int a);
	void B(int b);
	void C(int c);
public:
	roots();
	roots(int a, int b, int c);
	roots(int a, int b);

	virtual void calculation() = 0;
};