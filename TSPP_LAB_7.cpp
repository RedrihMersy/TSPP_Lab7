// TSPP_LAB_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <Windows.h>
#include <math.h>
#include <string>

using namespace std;
struct pd {
	string FIO;
	string number;
	string given;
	double BalanceOfMoney;
	int Id;
	int Agreement;
};

struct crcard {
	string FIO;
	string number;
	string given;
	double BalanceOfMoney;
	int Id;
	string dateEndCard;
	int lowLineOfMoney;
};

struct dbcard {
	string FIO;
	string number;
	string given;
	double BalanceOfMoney;
	int Id;
	string dateEndCard;
};

class ClientOfTheBank {
public:
	void ShowInformation();
	void GiveInformation(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement);
	pd makeAgreement(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement);
	ClientOfTheBank() {
		pasportData.Id = 1;
		pasportData.Agreement = 0;
		pasportData.BalanceOfMoney = 0;
		pasportData.FIO = "Pupkin Petr Petrovich";
		pasportData.number = "123 98745";
		pasportData.given = "Rf. city Velikiy Novgorod";
		cout << " | Создан объект клинета банка" << endl;
		ShowInformation();
	}
	ClientOfTheBank(int cod, int agreement, int zmoney, string fio, string number, string given) {
		pasportData.Id = cod;
		pasportData.Agreement = agreement;
		pasportData.BalanceOfMoney = zmoney;
		pasportData.FIO = fio;
		pasportData.number = number;
		pasportData.given = given;
		cout << " | Создан объект клинета банка" << endl;
		ShowInformation();
	}
private:
	pd pasportData;
};

void ClientOfTheBank::GiveInformation(pd *PasportDates, int *Ides, double *BalanceOfMones, int & Agreementes) {
	*Ides = pasportData.Id;
	*BalanceOfMones = pasportData.BalanceOfMoney;
	Agreementes = pasportData.Agreement;
	PasportDates->FIO = pasportData.FIO;
	PasportDates->given = pasportData.given;
	PasportDates->number = pasportData.number;
	
}

pd ClientOfTheBank::makeAgreement(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement) {
	return pasportData;
}
void ClientOfTheBank::ShowInformation() {
	cout << " | Порядковый номер - " << pasportData.Id << endl;
	cout << " | Ф. И. О. клиентa - " << pasportData.FIO << endl;
	cout << " | Номер паспорта - " << pasportData.number << endl;
	cout << " | Место выдачи паспорта - " << pasportData.given << endl;
	cout << " | Баланс счёта - " << pasportData.BalanceOfMoney << endl;
	cout << " | Количество заключенных договоров - " << pasportData.Agreement << endl;
}


class Manager {
public:
	bool AddDataOfClint();
	pd giveDataOfClint();
	bool conclusionAgrement(<T> ObjecOfAgreement);
	bool setMessageToPayMasterForDelivery(ClientOfTheBank Client, <T> ObjecOfAgreement);
	bool setMessageToPayMasterForReseptiomMoney(ClientOfTheBank Client, <T> ObjecOfAgreement);
	Manager() {
		amountOfCreditCard = 3;
		amountOfDebitCard =3;
		amountOfPayCard = 3;
		Client1 = new ClientOfTheBank();
	}
	Manager(int credit, int debit, int pay) {
		amountOfCreditCard = pay;
		amountOfDebitCard = pay;
		amountOfPayCard = pay;
		Client1 = new ClientOfTheBank();
	}
private:
	class ClientOfTheBank *Client1 = NULL;
	int amountOfCreditCard;
	int amountOfDebitCard;
	int amountOfPayCard;
};
bool Manager::AddDataOfClint() {
	//class ClientOfTheBank *Client1 = NULL;
	cout << " | Заполнение данных клиента" << endl;
}

pd Manager::giveDataOfClint() {
	pd outerInformation;
	outerInformation = 
	
	Client1 = new ClientOfTheBank();
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	class Manager *MainManager = NULL;

	return 0;
}

