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
	pd credcard;
	string dayToEndCard;
	int lowLineOfMoney;
};

struct dbcard {
	pd debcard;
	string dayToEndCard;
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
	void makeAgrementDebCard();
	bool setMessageToPayMasterForDelivery(ClientOfTheBank Client, <T> ObjecOfAgreement);
	bool setMessageToPayMasterForReseptiomMoney(ClientOfTheBank Client, <T> ObjecOfAgreement);
	Manager() {
		amountOfCreditCard = 3;
		amountOfDebitCard =3;
		amountOfPayCard = 3;
		Client1 = new ClientOfTheBank();
		Card1 = new AgreementOfCreditCard();
		Card2 = new AgreementOfDebetCard();
	}
	Manager(int credit, int debit, int pay) {
		amountOfCreditCard = pay;
		amountOfDebitCard = pay;
		amountOfPayCard = pay;
		Client1 = new ClientOfTheBank();
	}
private:
	class ClientOfTheBank *Client1 = NULL;
	class AgreementOfDebetCard *Card2 = NULL;
	class AgreementOfCreditCard *Card1 = NULL;
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
	outerInformation = Client1->makeAgreement();
	
	cout << " | Данные клиента переданы."<< endl;
	return outerInformation;
}

void Manager::makeAgrementDebCard() {
	int watCardNeed = 0;
	cout << " | Выполняется заключение договора."<< endl;
	cout << " | Выберете какой договор нужно формить:" << endl;
	cout << " | Нажмите 1, если хотите оформить договор на получение кредитной карты." << endl;
	cout << " | Нажмите 2, если хотите оформить договор на получение депозитной карты." << endl;
	cin >> watCardNeed;
	switch (watCardNeed) {
		case 1: {
					Card1->AddInf(1, Client1->GiveInformation, 200, -500);
					Card1->ShowInf;
				break;

		}
		case 2: {
					Card2->AddInf(1, Client1->GiveInformation, 320);
					Card2->ShowInf;
					break;
		}
		default: {
					 cout << " | Вы ошиблись с вводом."<< endl;
		}
	}
}

class AgreementOfDebetCard {
public:
	void ShowInf();
	void AddInf(int id, pd Info, int date);
	AgreementOfDebetCard() {
		IdAgreementDC = 0;
		form.debcard.FIO = "Berezovik Grogoriy Victorovich";
		form.debcard.given = "RF, city Djankoi";
		form.debcard.Id = 1;
		form.debcard.number = "456 79852";
		form.debcard.Agreement = 0;
		form.debcard.BalanceOfMoney = 10;
		form.dayToEndCard = 490;
	}
	AgreementOfDebetCard(int id, pd Info, int date) {
		IdAgreementDC = id;
		form.debcard = Info;
		form.dayToEndCard = date;
	}
private:
	dbcard form;
	int IdAgreementDC;
};
void AgreementOfDebetCard::ShowInf(){
	cout << " | Порядковый номер - " << form.debcard.Id << endl;
	cout << " | Ф. И. О. клиентa - " << form.debcard.FIO << endl;
	cout << " | Номер паспорта - " << form.debcard.number << endl;
	cout << " | Место выдачи паспорта - " << form.debcard.given << endl;
	cout << " | Баланс счёта - " << form.debcard.BalanceOfMoney << endl;
	cout << " | Количество заключенных договоров - " << form.debcard.Agreement << endl;
	cout << " | Продолжительность действия карты - " << form.dayToEndCard << endl;
}
void AgreementOfDebetCard::AddInf(int id, pd Info, int date) {
	IdAgreementDC = id;
	form.debcard = Info;
	form.dayToEndCard = date;
}

class AgreementOfCreditCard {
public:
	void ShowInf();
	void AddInf(int id, pd Info, int date, int low);
	AgreementOfCreditCard() {
		IdAgreementDC = 0;
		form.credcard.FIO = "Berezovik Grogoriy Victorovich";
		form.credcard.given = "RF, city Djankoi";
		form.credcard.Id = 1;
		form.credcard.number = "456 79852";
		form.credcard.Agreement = 0;
		form.credcard.BalanceOfMoney = 10;
		form.dayToEndCard = 490;
		form.lowLineOfMoney = -510;
	}
	AgreementOfCreditCard(int id, pd Info, int date, int low) {
		IdAgreementDC = id;
		form.credcard = Info;
		form.dayToEndCard = date;
		form.lowLineOfMoney = low;
	}
private:
	crcard form;
	int IdAgreementDC;
};
void AgreementOfCreditCard :: ShowInf(){
	cout << " | Порядковый номер - " << form.credcard.Id << endl;
	cout << " | Ф. И. О. клиентa - " << form.credcard.FIO << endl;
	cout << " | Номер паспорта - " << form.credcard.number << endl;
	cout << " | Место выдачи паспорта - " << form.credcard.given << endl;
	cout << " | Баланс счёта - " << form.credcard.BalanceOfMoney << endl;
	cout << " | Количество заключенных договоров - " << form.credcard.Agreement << endl;
	cout << " | Продолжительность действия карты - " << form.dayToEndCard << endl;
	cout << " | Сумма блокировки карты - " << form.lowLineOfMoney << endl;
}
void AgreementOfCreditCard::AddInf(int id, pd Info, int date, int low) {
	IdAgreementDC = id;
	form.credcard = Info;
	form.dayToEndCard = date;
	form.lowLineOfMoney = low;
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	class Manager *MainManager = NULL;

	return 0;
}

