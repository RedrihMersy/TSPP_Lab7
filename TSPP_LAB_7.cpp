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
		cout << " | ������ ������ ������� �����" << endl;
		ShowInformation();
	}
	ClientOfTheBank(int cod, int agreement, int zmoney, string fio, string number, string given) {
		pasportData.Id = cod;
		pasportData.Agreement = agreement;
		pasportData.BalanceOfMoney = zmoney;
		pasportData.FIO = fio;
		pasportData.number = number;
		pasportData.given = given;
		cout << " | ������ ������ ������� �����" << endl;
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
	cout << " | ���������� ����� - " << pasportData.Id << endl;
	cout << " | �. �. �. ������a - " << pasportData.FIO << endl;
	cout << " | ����� �������� - " << pasportData.number << endl;
	cout << " | ����� ������ �������� - " << pasportData.given << endl;
	cout << " | ������ ����� - " << pasportData.BalanceOfMoney << endl;
	cout << " | ���������� ����������� ��������� - " << pasportData.Agreement << endl;
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
	cout << " | ���������� ������ �������" << endl;
}

pd Manager::giveDataOfClint() {
	pd outerInformation;
	outerInformation = Client1->makeAgreement();
	
	cout << " | ������ ������� ��������."<< endl;
	return outerInformation;
}

void Manager::makeAgrementDebCard() {
	int watCardNeed = 0;
	cout << " | ����������� ���������� ��������."<< endl;
	cout << " | �������� ����� ������� ����� �������:" << endl;
	cout << " | ������� 1, ���� ������ �������� ������� �� ��������� ��������� �����." << endl;
	cout << " | ������� 2, ���� ������ �������� ������� �� ��������� ���������� �����." << endl;
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
					 cout << " | �� �������� � ������."<< endl;
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
	cout << " | ���������� ����� - " << form.debcard.Id << endl;
	cout << " | �. �. �. ������a - " << form.debcard.FIO << endl;
	cout << " | ����� �������� - " << form.debcard.number << endl;
	cout << " | ����� ������ �������� - " << form.debcard.given << endl;
	cout << " | ������ ����� - " << form.debcard.BalanceOfMoney << endl;
	cout << " | ���������� ����������� ��������� - " << form.debcard.Agreement << endl;
	cout << " | ����������������� �������� ����� - " << form.dayToEndCard << endl;
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
	cout << " | ���������� ����� - " << form.credcard.Id << endl;
	cout << " | �. �. �. ������a - " << form.credcard.FIO << endl;
	cout << " | ����� �������� - " << form.credcard.number << endl;
	cout << " | ����� ������ �������� - " << form.credcard.given << endl;
	cout << " | ������ ����� - " << form.credcard.BalanceOfMoney << endl;
	cout << " | ���������� ����������� ��������� - " << form.credcard.Agreement << endl;
	cout << " | ����������������� �������� ����� - " << form.dayToEndCard << endl;
	cout << " | ����� ���������� ����� - " << form.lowLineOfMoney << endl;
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

