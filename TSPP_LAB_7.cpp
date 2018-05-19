// TSPP_LAB_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <Windows.h>
#include <math.h>
#include <string.h>

using namespace std;
struct pd {
	string FIO;
	string number;
	string given;
};

class ClientOfTheBank {
public:
	void GiveInformation(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement);
	bool makeAgreement(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement);
	ClientOfTheBank() {
		Id = 1;
		Agreement = 0;
		BalanceOfMoney = 0;
		pasportData.FIO = "Pupkin Petr Petrovich";
		pasportData.number = "123 98745";
		pasportData.given = "Rf. city Velikiy Novgorod";
		cout << " | Создан объект клинета банка" << endl;
	}
	ClientOfTheBank(int cod, int agreement, int zmoney, string fio, string number, string given) {
		Id = cod;
		Agreement = agreement;
		BalanceOfMoney = zmoney;
		pasportData.FIO = fio;
		pasportData.number = number;
		pasportData.given = given;
		cout << " | Создан объект клинета банка" << endl;
	}
private:
	pd pasportData;
	double BalanceOfMoney;
	int Id;
	int Agreement;
};

void ClientOfTheBank::GiveInformation(pd *PasportDates, int *Ides, double *BalanceOfMones, int & Agreementes) {
	*Ides = Id;
	*BalanceOfMones = BalanceOfMoney;
	Agreementes = Agreement;
	PasportDates->FIO = pasportData.FIO;
	PasportDates->given = pasportData.given;
	PasportDates->number = pasportData.number;

}

bool ClientOfTheBank::makeAgreement(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement) {

}


class Manager {
public:
	bool AddDataOfClint(ListOfClient Object);
	bool giveDataOfClint(ListOfClient Object);
	bool conclusionAgrement(<T> ObjecOfAgreement);
	bool setMessageToPayMasterForDelivery(ClientOfTheBank Client, <T> ObjecOfAgreement);
	bool setMessageToPayMasterForReseptiomMoney(ClientOfTheBank Client, <T> ObjecOfAgreement);
private:
	int amountOfCreditCard;
	int amountOfDebitCard;
	int amountOfPayCard;
};


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	return 0;
}

