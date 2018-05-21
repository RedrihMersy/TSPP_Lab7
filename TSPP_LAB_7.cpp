// TSPP_LAB_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <Windows.h>
#include <math.h>
#include <string>

using namespace std;
// ��������� ������ ������� �����.
struct pd {
	string FIO;
	string number;
	string given;
	double BalanceOfMoney;
	int Id;
	int Agreement;
};
// ���������� ��������� �����.
struct crcard {
	pd credcard;
	int dayToEndCard;
	int lowLineOfMoney;
};
// ��������� ��������� �����. 
struct dbcard {
	pd debcard;
	int dayToEndCard;
};
// ��������� ������ �����
struct exchangeRaters{
	double DolToRub = 1.64;
	double RubToDol = 0.25;
};
struct deposit {
	pd data;
	double percent;
	int days;
	string valute;
	double value;
};
struct credit {
	pd data;
	double percent;
	int days;
	string valute;
	bool pledge; // �����.
	double value;
};


// ======================== ����� ���������� �� ��������� �����.
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
		//ShowInf();
		cout << " | ������ ����������� ���������� �� ��������� �����. |" << endl;
	}
	AgreementOfDebetCard(int id, pd Info, int date) {
		IdAgreementDC = id;
		form.debcard = Info;
		form.dayToEndCard = date;
		cout << " | ������ ����������� ���������� �� ��������� �����. |" << endl;
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

//======================= ����� �� ���������� �� ��������� �����.
class AgreementOfCreditCard {
public:
	void ShowInf();
	void AddInf(int id, pd Info, int date, int low);
	AgreementOfCreditCard() {
		form.credcard.FIO = "Berezovik Grogoriy Victorovich";
		form.credcard.given = "RF, city Djankoi";
		form.credcard.Id = 1;
		form.credcard.number = "456 79852";
		form.credcard.Agreement = 0;
		form.credcard.BalanceOfMoney = 10;
		form.dayToEndCard = 490;
		form.lowLineOfMoney = -510;
		IdAgreementDC = 0;
		cout << " | ������ ����������� ���������� �� ��������� ����� |" << endl;
	}
	AgreementOfCreditCard(int id, pd Info, int date, int low) {
		IdAgreementDC = id;
		form.credcard = Info;
		form.dayToEndCard = date;
		form.lowLineOfMoney = low;
		cout << " | ������ ����������� ���������� �� ��������� ����� |" << endl;
	}
private:
	crcard form;
	int IdAgreementDC;
};

// ����� ������ ����������.
void AgreementOfCreditCard::ShowInf(){
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


class ClientOfTheBank {
public:
	void ChangeMoney(double money);
	void ShowInformation();
	void EnterInf(pd listOfDate);
	void ChangeColOfAgreements(int col) {
		pasportData.Agreement = pasportData.Agreement + col;
	};
	void ChangeCash(double cash) {
		pasportData.BalanceOfMoney = pasportData.BalanceOfMoney + cash;
	}
	pd GiveInformation();
	pd makeAgreement(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement);
	ClientOfTheBank() {
		pasportData.Id = 1;
		pasportData.Agreement = 0;
		pasportData.BalanceOfMoney = 0;
		pasportData.FIO = "Pupkin Petr Petrovich";
		pasportData.number = "123 98745";
		pasportData.given = "Rf. city Velikiy Novgorod";
		cout << " | ������ ������ ������� �����" << endl;
		//ShowInformation();
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

pd ClientOfTheBank::GiveInformation() {
	return pasportData;
}
void ClientOfTheBank::ChangeMoney(double money) {
	if (money > 0) {
		pasportData.BalanceOfMoney = pasportData.BalanceOfMoney + money;
	}
	else {
		pasportData.BalanceOfMoney = pasportData.BalanceOfMoney - money;
	}
}
pd ClientOfTheBank::makeAgreement(pd *PasportData, int *Id, double *BalanceOfMoney, int & Agreement) {
	return pasportData;
}
void ClientOfTheBank::ShowInformation() {
	cout << " |=============================================================================" << endl;
	cout << " | ���������� ����� - " << pasportData.Id << endl;
	cout << " | �. �. �. ������a - " << pasportData.FIO << endl;
	cout << " | ����� �������� - " << pasportData.number << endl;
	cout << " | ����� ������ �������� - " << pasportData.given << endl;
	cout << " | ������ ����� - " << pasportData.BalanceOfMoney << endl;
	cout << " | ���������� ����������� ��������� - " << pasportData.Agreement << endl;
}
void ClientOfTheBank::EnterInf(pd listOfDate) {
	pasportData = listOfDate;
}

//����� ������
class PayMasterOperator {
public:
	PayMasterOperator() {
		listOfCurrecies.DolToRub = 1,26;
		listOfCurrecies.RubToDol = 0,25;
		//listOfCurrecies;
		ClientOfTheBank* OunClient = NULL;
		//ClientOfTheBank OunClient();
		OunClient = new ClientOfTheBank();
		cout << " | ������ ����������� ������� ������� �����" << endl;
	}
	PayMasterOperator(double ruToUsa, double usaToru/*, Manager Object*/) {
		listOfCurrecies.DolToRub = usaToru;
		listOfCurrecies.RubToDol = ruToUsa;
		//MainManger = Object;
		ClientOfTheBank* OunClient = NULL;
		OunClient = new ClientOfTheBank();
		cout << " | ������ ����������� ������� ������� �����" << endl;
	}

	ClientOfTheBank* inputMessageToPayMasterForReseptiomMoney(ClientOfTheBank *Client, double outMoney) {
		cout << " | �������� ������� ����� - " << outMoney << endl;
		//OunClient->EnterInf(Client->GiveInformation());
		OunClient = Client;
		OunClient->ChangeMoney(outMoney);
		ReseptiomMoney(outMoney);
		return OunClient;
	}
	bool ReseptiomMoney(double money);
	bool Delivery(double money);
	ClientOfTheBank* inputMessageToPayMasterForDelivery(ClientOfTheBank *Client, double inMoney) {
		cout << " | �������� ������� ����� - " << inMoney << endl;
		OunClient = Client;
		//OunClient->EnterInf(Client->GiveInformation());
		OunClient->ChangeMoney(inMoney);
		Delivery(inMoney);
		return OunClient;
	};

	//bool ReplenishmentOfDeposit(ClientOfTheBank Client, AgreementDeposit Object, double money);
	//bool creditContribution(ClientOfTheBank Client, AgreementOfCredit Object, double money);

	bool �urrencyeExchange(double money, string currencySet, exchangeRaters exchangeRates, string currencyGet);
	exchangeRaters get_set_ExchangeRates(exchangeRaters listOfCurrecies);
private:
	ClientOfTheBank* OunClient;
	exchangeRaters listOfCurrecies;
};

bool PayMasterOperator::ReseptiomMoney(double money)  {
	cout << " |=============================================================================" << endl;
	cout << " | ��������� ������� �������� ����� �� ������� � �������." << endl;
	cout << " | ������ ������� ����� - " << money << endl;
	cout << " | ������ ��������� ������ - " << money << endl;
//	pd NewClient;
//	NewClient = OunClient->GiveInformation();
//	NewClient.BalanceOfMoney = NewClient.BalanceOfMoney - money;
//	OunClient->EnterInf(NewClient);
	cout << " | ������� ��������." << endl;
	OunClient->ShowInformation();
	return true;
}

bool PayMasterOperator::Delivery(double money) {
	cout << " |=============================================================================" << endl;
	cout << " | ��������� ������� �������� ����� �� ������� � �������." << endl;
	cout << " | ������ ������� ������ - " << money << endl;
	cout << " | ������ ��������� ������ - " << money << endl;
//	pd NewClient;
//	NewClient = OunClient->GiveInformation();
//	NewClient.BalanceOfMoney = NewClient.BalanceOfMoney + money;
//	OunClient->EnterInf(NewClient);
	cout << " | ������� ��������." << endl;
	OunClient->ShowInformation();
	return true;
}

exchangeRaters PayMasterOperator::get_set_ExchangeRates(exchangeRaters listOfCurrecies) {
	double DTR = 0, RTD = 0;
	cout << " |=============================================================================" << endl;
	cout << " | ������� ������ ��������� ������� � �����: ";
	cin >> DTR;
	cout << " | �������� ������ �������� ����� � ������: " ;
	cin >> RTD;
	listOfCurrecies.DolToRub = DTR;
	listOfCurrecies.RubToDol = RTD;
	return listOfCurrecies;
}

bool PayMasterOperator::�urrencyeExchange(double money, string currencySet, exchangeRaters exchangeRates, string currencyGet) {
	int update = 0;
	double toClint = 0;
	exchangeRaters list = exchangeRates;
	cout << " |=============================================================================" << endl;
	cout << " | ���������� ������� �������� �������!" << endl;
	cout << " | ������ ������� ����� ��������� - " << currencySet  << endl;
	cout << " | ���������� - " << money << endl;
	cout << " | ������ � ������ ����� ��������� ������ - " << currencyGet  << endl;
	cout << " | ���� ������ �������� ���������� ������� ��� ��������, ������� 1: ";
	cin >> update;
	if (update == 1) {
		cout << " | ������� ����� ���������� ����� - ";
		cin >> money;
	}
	cout << " | ���� ������ �������� ���� ����� ������� 1: ";
	cin >> update;
	if (update == 1) {
		list = get_set_ExchangeRates(exchangeRates);
	}
	if ((currencySet == "dollars") && (currencyGet == "rubli")) {
		cout << " | ������ �������� - " << list.DolToRub << endl;
		toClint = money* list.DolToRub;
	}
	if ((currencySet == "rubli") && (currencyGet == "dollars")) {
		cout << " | ������ �������� - " << list.RubToDol << endl;
		toClint = money* list.RubToDol;
	}
	cout << " | ������� ��������� �����: " << toClint << " � ������ - " << currencyGet << endl;
	cout << " | ������� ��������." << endl;
	return true;
}



// ===================== ����� �������� ���������. 
class Manager {
protected:
	bool setMessageToPayMasterForDelivery(ClientOfTheBank* Client, double money);
	bool setMessageToPayMasterForReseptiomMoney(ClientOfTheBank* Client, double money);
	PayMasterOperator* Cash1;
public:
	bool AddDataOfClint();
	pd giveDataOfClint();
	void makeAgrement();

	Manager() {
		amountOfCreditCard = 3;
		amountOfDebitCard =3;
		amountOfPayCard = 3;
		Client1 = new ClientOfTheBank();
		Card1 = new AgreementOfCreditCard();
		Card2 = new AgreementOfDebetCard();
		PayMasterOperator Cash1();
		cout << " | ������ ����������� ������� ��������� �����. |" << endl;
	}
	Manager(int credit, int debit, int pay, PayMasterOperator *ObjectCash) {
		amountOfCreditCard = credit;
		amountOfDebitCard = debit;
		amountOfPayCard = pay;
		Card1 = new AgreementOfCreditCard();
		Card2 = new AgreementOfDebetCard();
		Client1 = new ClientOfTheBank();
		Cash1 = ObjectCash;
		cout << " | ������ ����������� ������� ��������� �����. |" << endl;
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
	return true;
}

pd Manager::giveDataOfClint() {
	pd outerInformation;
	outerInformation = Client1->GiveInformation();
	
	cout << " | ������ ������� ��������."<< endl;
	return outerInformation;
}

// ���������� ��������� �� ��������� ����������� ����.
void Manager::makeAgrement() {
	cout << " |=============================================================================" << endl;
	cout << " | ����������� ���������� �������� �� ���������� ����������� �����. " << endl;
	int watCardNeed = 0;
	double moneyToCard = 0;
	pd dataOfClient;
	dataOfClient = Client1->GiveInformation();
	cout << " | ������ ������� - "<< endl;
	Client1->ShowInformation();
	//pd Data;
	cout << " | ����������� ���������� ��������."<< endl;
	cout << " | �������� ����� ������� ����� �������:" << endl;
	cout << " | ������� 1, ���� ������ �������� ������� �� ��������� ��������� �����." << endl;
	cout << " | ������� 2, ���� ������ �������� ������� �� ��������� ���������� �����." << endl;
	cin >> watCardNeed;
	switch (watCardNeed) {
		case 1: {
					if ((amountOfCreditCard != 0) && (amountOfCreditCard > 0)) {
						cout << " | ������� ����� ��������� �������, ������� ������ ����� � ����� (����� �����): " << endl;
						cin >> moneyToCard;
						if (moneyToCard > 0 ) {
							cout << " | �� ���������� ����� �������� 200 ������. " << endl;
							moneyToCard = moneyToCard - 200;
						}
						amountOfCreditCard--;
						Card1->AddInf(1, dataOfClient, 200, -500);
						//Card1->ShowInf();
						Client1->ChangeColOfAgreements(1);
						setMessageToPayMasterForDelivery(Client1, moneyToCard);
					}
					else {
						cout << " | ���� ������ ���." << endl;
						system("pause");
					}
				break;

		}
		case 2: {
					if ((amountOfDebitCard != 0) && (amountOfDebitCard >= 0)) {
						cout << " | ������� ����� �������� �������, ������� ������ �������� � ����: " << endl;
						cin >> moneyToCard;
						if (moneyToCard > 0) {
							cout << " | �� ���������� ����� �������� 200 ������. " << endl;
							moneyToCard = moneyToCard - 200;
						}
						Card2->AddInf(1, Client1->GiveInformation(), 320);
						Card2->ShowInf();
						amountOfDebitCard--;
						Client1->ChangeColOfAgreements(1);
						setMessageToPayMasterForReseptiomMoney(Client1, moneyToCard);
					}
					else {
						cout << " | ���� ������ ���." << endl;
						system("pause");
					}
					break;
		}
		default: {
					 cout << " | �� �������� � ������."<< endl;
		}
	}
}

bool Manager::setMessageToPayMasterForDelivery(ClientOfTheBank* Client, double money) {
	Cash1->inputMessageToPayMasterForDelivery(Client, money);
	return true;
}
bool Manager::setMessageToPayMasterForReseptiomMoney(ClientOfTheBank* Client, double money) {
	Cash1->inputMessageToPayMasterForReseptiomMoney(Client, money);
	return true;
}

// ����� ��������� �� ���������.
class ManagerOfDepost : Manager {
public:
	ManagerOfDepost() :Manager(){
		//cout << " -|- ������ ����������� ������� ��������� �� ��������� -|-" << endl;
		Client3 = new ClientOfTheBank();
		blanc.data = Client3->GiveInformation();
		blanc.days = 240;
		blanc.percent = 5;
		blanc.valute = "rubl";
		blanc.value = 50000;
		cout << " _|_ ������ ����������� ������� ��������� �� ��������� _|_" << endl;
	}
	ManagerOfDepost(double value, string values, double per, int days, int credit, int debit, int pay, PayMasterOperator *ObjectCash) :Manager(credit, debit, pay, ObjectCash) {
		
		Client3 = new ClientOfTheBank();
		blanc.data = Client3->GiveInformation();
		blanc.days = days;
		blanc.percent = per;
		blanc.valute = values;
		blanc.value = value;
		cout << " _|_ ������ ����������� ������� ��������� �� ��������� _|_" << endl;
	}
	void OpenDeposit();
private:
	class ClientOfTheBank *Client3 = NULL;
	deposit blanc;
};

void ManagerOfDepost::OpenDeposit(){ 
	cout << " |=============================================================================" << endl;
	cout << " | ����������� ���������� ������ ��������." << endl;
	int Yes = 0;
	cout << " | �������� ���������� �� ���������. 2 - ������ ����� ����������."<< endl;
	cin >> Yes;
	if (Yes == 2) {
		cout << " | �� ����� ��������� ����������: " << endl;
		blanc.data.FIO = "Fominov Igor Kirlovich";
		blanc.data.Id = 241;
		blanc.data.BalanceOfMoney = 1500;
		blanc.data.Agreement = 2;
		blanc.data.given = "RF, city Moscov";
		blanc.data.number = "230 55221";
		blanc.days = 360;
		blanc.percent = 10;
		blanc.valute = "rubl";
		blanc.value = 10000;
		cout << " | ���������� ����� - " << blanc.data.Id << endl;
		cout << " | �. �. �. ������a - " << blanc.data.FIO << endl;
		cout << " | ����� �������� - " << blanc.data.number << endl;
		cout << " | ����� ������ �������� - " << blanc.data.given << endl;
		cout << " | ������ ����� - " << blanc.data.BalanceOfMoney << endl;
		cout << " | ���������� ����������� ��������� - " << blanc.data.Agreement << endl;
		cout << " | ����������������� ��������� �������� - " << blanc.days << endl;
		cout << " | ������� - " << blanc.percent << endl;
		cout << " | ������ �������� - " << blanc.valute << endl;
		cout << " | ���������� ����� - " << blanc.value << endl;
	}
	Client3->EnterInf(blanc.data);
	cout << " | ������ ������� �� ������ �������� - " << endl;
	Client3->ShowInformation();
	Client3->ChangeColOfAgreements(1);
//	Client3->ShowInformation();
	system("pause");
	setMessageToPayMasterForReseptiomMoney(Client3, blanc.value);
}

// ����� ��������� �� ��������.
class ManagerOfCredit : Manager {
public:
	ManagerOfCredit() :Manager() {
		Client2 = new ClientOfTheBank();
		blanc.data = Client2->GiveInformation();
		blanc.days = 240;
		blanc.percent = 5;
		blanc.valute = "rubl";
		blanc.pledge = false;
	}
	ManagerOfCredit(bool zalog, string value, double per, int days,/* int credit, int debit, int pay*/,/* Manager* Object,*/ PayMasterOperator *ObjectCash) :Manager(/*credit, debit, pay, */ObjectCash) {
		Client2 = new ClientOfTheBank();
		blanc.data = Client2->GiveInformation();
		blanc.days = days;
		blanc.percent = per;
		blanc.valute = value;
		blanc.pledge = zalog;
	}
	void OpenCredit();
private:
	class ClientOfTheBank *Client2 = NULL;
	credit blanc;
};
void ManagerOfCredit::OpenCredit() {
	cout << " |=============================================================================" << endl;
	cout << " | ����������� ���������� ������ �������." << endl;
	int Yes = 0;
	cout << " | �������� ���������� �� ���������. 2 - ������ ����� ����������." << endl;
	cin >> Yes;
	if (Yes == 2) {
		cout << " | �� ����� ��������� ����������: " << endl;
		blanc.data.FIO = "Ivanov Ivan Ivanovich";
		blanc.data.Id = 06;
		blanc.data.BalanceOfMoney = 510;
		blanc.data.Agreement = 9;
		blanc.data.given = "RF, Omsk";
		blanc.data.number = "632 74523";
		blanc.valute = "rubli";
		blanc.days = 360;
		blanc.percent = 5;
		blanc.value = 1000000;
		blanc.pledge = true;
		cout << " | ���������� ����� - " << blanc.data.Id << endl;
		cout << " | �. �. �. ������a - " << blanc.data.FIO << endl;
		cout << " | ����� �������� - " << blanc.data.number << endl;
		cout << " | ����� ������ �������� - " << blanc.data.given << endl;
		cout << " | ������ ����� - " << blanc.data.BalanceOfMoney << endl;
		cout << " | ���������� ����������� ��������� - " << blanc.data.Agreement << endl;
		cout << " | ����������������� ��������� �� ������� - " << blanc.days << endl;
		cout << " | ������� ������� - " << blanc.percent << endl;
		cout << " | ������ ���������� �������� - " << blanc.valute << endl;
		cout << " | ���������� ��������� ������� - " << blanc.value << endl;
		if (blanc.pledge) {
			cout << " | ������������ ����� - " << endl;
		}
		
	}
	Client2->EnterInf(blanc.data);
	cout << " | ������ ������� �� ������ �������� - " << endl;
	Client2->ShowInformation();
	Client2->ChangeColOfAgreements(1);
	//	Client3->ShowInformation();
	system("pause");
	setMessageToPayMasterForDelivery(Client2, blanc.value);
}
// ����� �����������.
class Insurer: Manager {
public:
	Insurer() :Manager(){
		Client4 = new ClientOfTheBank();
		blanc.data = Client4->GiveInformation();
		blanc.days = 240;
		blanc.percent = 5;
		blanc.valute = "rubl";
	}
	Insurer(string value,double per, int days ,int credit, int debit, int pay, PayMasterOperator *ObjectCash) :Manager(credit,debit,pay, ObjectCash) {
		Client4 = new ClientOfTheBank();
		blanc.data = Client4->GiveInformation();
		blanc.days = days;
		blanc.percent = per;
		blanc.valute = value;
	}
	void Open();
private:
	class ClientOfTheBank *Client4 = NULL;
	deposit blanc;
};
void Insurer::Open() {
	cout << " |=============================================================================" << endl;
	cout << " | ����������� ���������� ������ �������." << endl;
	int Yes = 0;
	cout << " | �������� ���������� �� ���������. 2 - ������ ����� ����������." << endl;
	cin >> Yes;
	if (Yes == 2) {
		cout << " | �� ����� ��������� ����������: " << endl;
		blanc.data.FIO = "Baron Graf Lordovich";
		blanc.data.Id = 555;
		blanc.data.BalanceOfMoney = 1000000;
		blanc.data.Agreement = 100;
		blanc.data.given = "RF, city Moscov, Palati";
		blanc.data.number = "111 225522";
		blanc.valute = " Strahovanie domashego petomca. Petomec - kuznechik. Imia - Diktator.";
		blanc.days = 999999;
		blanc.percent = 0;
		blanc.value = 444333;
		//blanc.pledge = true;
		cout << " | ���������� ����� - " << blanc.data.Id << endl;
		cout << " | �. �. �. ������a - " << blanc.data.FIO << endl;
		cout << " | ����� �������� - " << blanc.data.number << endl;
		cout << " | ����� ������ �������� - " << blanc.data.given << endl;
		cout << " | ������ ����� - " << blanc.data.BalanceOfMoney << endl;
		cout << " | ���������� ����������� ��������� - " << blanc.data.Agreement << endl;
		cout << " | ����������������� ��������� ����������� - " << blanc.days << endl;
		cout << " | ������� ������� ������ ����� - " << blanc.percent << endl;
		cout << " | ��� ��������� - " << blanc.valute << endl;
		cout << " | ������� � ������ �������������� ������ - " << blanc.value << endl;
		//if (blanc.pledge) {
		//	cout << " | ������������ ����� - " << endl;
		//}

	}
	Client4->EnterInf(blanc.data);
	cout << " | ������ ������� �� ������ �������� - " << endl;
	Client4->ShowInformation();
	Client4->ChangeColOfAgreements(1);
	//	Client3->ShowInformation();
	system("pause");
	setMessageToPayMasterForReseptiomMoney(Client4, blanc.value);
}




// ����������.
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int action = -1;
	exchangeRaters Rates; // ������ ����� � �� �������� ����.
	// ������ ������.
	// �������� ������ ������� �����.
	class PayMasterOperator *Casier1 = NULL;
	Casier1 = new PayMasterOperator(0.25, 1.25);
	// ����.
	do {
		system("cls");
		cout << " | �� ���������� ����� ������ � ��������� �����, ���� ��������." << endl;
		cout << " | �������� ����� ��������������� �����:" << endl;
		cout << " | 1 - ����� � ���� � ��������� ����� �����." << endl;
		cout << " | 2 - ����� � ���� � �������� ����������� �����." << endl;
		cout << " | 3 - ����� � ���� � �������� �������." << endl;
		cout << " | 4 - ����� � ���� � �������� ������." << endl;
		cout << " | 5 - ����� � ���� � �������� ���������." << endl;
		cout << " | 0 - ����� �����." << endl;
		cout << " | =======================================================================" << endl;
		cin >> action;
		if (action == 0) {
			return 0;
		}
		switch (action) {
			case 1: {
						class Manager *MainManager = NULL;
						MainManager = new Manager(3, 3, 3, Casier1);

						Casier1->�urrencyeExchange(850, "dollars", Rates, "rubli");
						cout << " | �� ����� �� ������ �����."<< endl;
						system("pause");
						break;

			}
			case 2: {
						class Manager *MainManager = NULL;
						MainManager = new Manager(3, 3, 3, Casier1);
						MainManager->makeAgrement();
						cout << " | �� ����� �� ������ �����." << endl;
						system("pause");
						break;

			}
			case 3: {
						cout << " |=============================================================================" << endl;
						cout << " | ����������� ���������� ��������!" << endl;
						cout << " |=============================================================================" << endl;
						cout << " -|- ������ ����������� ������� ��������� �� ��������� -|-" << endl;
						class ManagerOfDepost* OperatorOfDeposit = NULL;
						OperatorOfDeposit = new ManagerOfDepost(90000, "rubl", 5, 200, 3, 3, 3, Casier1);
						OperatorOfDeposit->OpenDeposit();
						cout << " | �� ����� �� ������ �����." << endl;
						system("pause");
						break;

			}
			case 4: {

						cout << " | �� ����� �� ������ �����." << endl;
						system("pause");
						break;

			}
			case 5: {

						cout << " | �� ����� �� ������ �����." << endl;
						system("pause");
						break;

			}
			default: {
						 cout << " | �� ����� ������������ �����! "<< endl;
						 system("pause");
			}
		}
	} while (true);
	//class PayMasterOperator *Casier2 = NULL;
	//class	Search *Step = NULL;
	//Casier2 = new PayMasterOperator();
	// �������� ������� ��������� �����.
	//ManagerOfDepost(double value, string values, double per, int days, int credit, int debit, int pay, PayMasterOperator *ObjectCash) :Manager(credit, debit, pay, ObjectCash) {

	system("pause");
	return 0;
}



