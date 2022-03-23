#include "pch.h"

#include "../include/Monom.h"
#include "../include/Polinom.h"

TEST(Monom, constructor1)
{
	ASSERT_NO_THROW(Monom monom());
}

TEST(Monom, constructor2)
{
	ASSERT_NO_THROW(Monom monom(1, 345));
}

TEST(Monom, equal)
{
	Monom monom1(1, 456);
	Monom monom2(1, 456);
	EXPECT_EQ(true, monom1 == monom2);
}

TEST(Monom, sum)
{
	Monom monom1(1, 123);
	Monom monom2(1, 123);
	Monom monom3(2, 123);
	EXPECT_EQ(monom3, monom1 + monom2);
}

TEST(Monom, mnoj)
{
	Monom monom1(1, 123);
	Monom monom2(2, 123);
	Monom monom3(2, 246);
	EXPECT_EQ(monom3, monom1 * monom2);
}

TEST(Polinom, constructor_polinom_list)
{
	List<Monom> monoms;
	monoms.addNode(Monom(2, 123));
	ASSERT_NO_THROW(Polinom poli(monoms));
}

TEST(Polinom, mnoj)
{
	List<Monom> monoms1;
	monoms1.addNode(Monom(2, 123));
	monoms1.addNode(Monom(-3, 212));
	Polinom poli1(monoms1);

	List<Monom> monoms2;
	monoms2.addNode(Monom(-5, 246));
	monoms2.addNode(Monom(6, 713));
	Polinom poli2(monoms2);
	
	Polinom res = poli1 * poli2;

	List<Monom> monoms3;
	monoms3.addNode(Monom(-10, 369));
	monoms3.addNode(Monom(15, 458));
	monoms3.addNode(Monom(12, 836));
	monoms3.addNode(Monom(-18, 925));

	auto tmp1 = res.monoms.head;
	auto tmp2 = monoms3.head;
	while (tmp1 != nullptr) {
		EXPECT_EQ(tmp2->value, tmp1->value);
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}	
}

TEST(Polinom, sum)
{
	List<Monom> monoms1;
	monoms1.addNode(Monom(2, 123));
	monoms1.addNode(Monom(-3, 212));
	Polinom poli1(monoms1);

	List<Monom> monoms2;
	monoms2.addNode(Monom(3, 123));
	monoms2.addNode(Monom(6, 713));
	Polinom poli2(monoms2);

	Polinom res = poli1 + poli2;

	List<Monom> monoms3;
	monoms3.addNode(Monom(5, 123));
	monoms3.addNode(Monom(-3, 212));
	monoms3.addNode(Monom(6, 713));

	auto tmp1 = res.monoms.head;
	auto tmp2 = monoms3.head;
	while (tmp1 != nullptr) {
		EXPECT_EQ(tmp2->value, tmp1->value);
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}

}