// TSPP_LAB_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <Windows.h>
#include <math.h>
#include <string>

using namespace std;
// Структура данных клиента банка.
struct pd {
	string FIO;
	string number;
	string given;
	double BalanceOfMoney;
	int Id;
	int Agreement;
};
// Сутруктура кредитной карты.
struct crcard {
	pd credcard;
	int dayToEndCard;
	int lowLineOfMoney;
};
// Структура дебетовой карты. 
struct dbcard {
	pd debcard;
	int dayToEndCard;
};
// Структура список валют
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
	bool pledge; // Залог.
	double value;
};


// ======================== Класс соглашения на дебетовую карту.
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
		ShowInf();
		cout << " | Создан объект соглашение на дебетовую карту." << endl;
	}
	AgreementOfDebetCard(int id, pd Info, int date) {
		IdAgreementDC = id;
		form.debcard = Info;
		form.dayToEndCard = date;
		cout << " | Создан объект соглашение на дебетовую карту." << endl;
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

//======================= Класс на соглашение на кредитную карту.
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
		cout << " | Создан объект соглашение на кредитную карту." << endl;
	}
	AgreementOfCreditCard(int id, pd Info, int date, int low) {
		IdAgreementDC = id;
		form.credcard = Info;
		form.dayToEndCard = date;
		form.lowLineOfMoney = low;
		cout << " | Создан объект соглашение на кредитную карту." << endl;
	}
private:
	crcard form;
	int IdAgreementDC;
};

// Метод обзора информации.
void AgreementOfCreditCard::ShowInf(){
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


class ClientOfTheBank {
public:
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
		cout << " | Создан объект клиента банка" << endl;
		ShowInformation();
	}
	ClientOfTheBank(int cod, int agreement, int zmoney, string fio, string number, string given) {
		pasportData.Id = cod;
		pasportData.Agreement = agreement;
		pasportData.BalanceOfMoney = zmoney;
		pasportData.FIO = fio;
		pasportData.number = number;
		pasportData.given = given;
		cout << " | Создан объект клиента банка" << endl;
		ShowInformation();
	}
private:
	pd pasportData;
};

pd ClientOfTheBank::GiveInformation() {
	return pasportData;
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
void ClientOfTheBank::EnterInf(pd listOfDate) {
	pasportData = listOfDate;
}

//Класс кассир
class PayMasterOperator {
public:
	PayMasterOperator() {
		listOfCurrecies.DolToRub = 1,26;
		listOfCurrecies.RubToDol = 0,25;
		//listOfCurrecies;
		ClientOfTheBank* OunClient = NULL;
		//ClientOfTheBank OunClient();
		cout << " | Создан объект кассир банка" << endl;
	}
	PayMasterOperator(double ruToUsa, double usaToru/*, Manager Object*/) {
		listOfCurrecies.DolToRub = usaToru;
		listOfCurrecies.RubToDol = ruToUsa;
		//MainManger = Object;
		ClientOfTheBank* OunClient = NULL;
		cout << " | Создан объект кассир банка" << endl;
	}

	ClientOfTheBank* inputMessageToPayMasterForReseptiomMoney(ClientOfTheBank *Client, double outMoney) {
		cout << " | Передать кассиру нужно - " << outMoney << endl;
		OunClient = Client;
		ReseptiomMoney(outMoney);
		return OunClient;
	}
	bool ReseptiomMoney(double money);
	bool Delivery(double money);
	ClientOfTheBank* inputMessageToPayMasterForDelivery(ClientOfTheBank *Client, double inMoney) {
		cout << " | Передать клиенту нужно - " << inMoney << endl;
		OunClient = Client;
		Delivery(inMoney);
		return OunClient;
	};

	//bool ReplenishmentOfDeposit(ClientOfTheBank Client, AgreementDeposit Object, double money);
	//bool creditContribution(ClientOfTheBank Client, AgreementOfCredit Object, double money);

	bool СurrencyeExchange(double money, string currencySet, exchangeRaters exchangeRates, string currencyGet);
	exchangeRaters get_set_ExchangeRates(exchangeRaters listOfCurrecies);
private:
	ClientOfTheBank* OunClient;
	exchangeRaters listOfCurrecies;
};

bool PayMasterOperator::ReseptiomMoney(double money)  {
	cout << " | Присходит процесс передачи денег от клиента к кассиру." << endl;
	cout << " | Клиент передаёт денег - " << money << endl;
	pd NewClient;
	NewClient = OunClient->GiveInformation();
	NewClient.BalanceOfMoney = NewClient.BalanceOfMoney - money;
	OunClient->EnterInf(NewClient);
	cout << " | Процесс закончен." << endl;
	OunClient->ShowInformation();
	return true;
}

bool PayMasterOperator::Delivery(double money) {
	cout << " | Присходит процесс передачи денег от кассира к клиенту." << endl;
	cout << " | Кассир передаёт деньги - " << money << endl;
	pd NewClient;
	NewClient = OunClient->GiveInformation();
	NewClient.BalanceOfMoney = NewClient.BalanceOfMoney + money;
	OunClient->EnterInf(NewClient);
	cout << " | Процесс закончен." << endl;
	OunClient->ShowInformation();
	return true;
}

exchangeRaters PayMasterOperator::get_set_ExchangeRates(exchangeRaters listOfCurrecies) {
	double DTR = 0, RTD = 0;
	cout << " | Введите индекс перевеода доллара в рубль: ";
	cin >> DTR;
	cout << " | Введдите индекс перевода рубля в доллар: " ;
	cin >> RTD;
	listOfCurrecies.DolToRub = DTR;
	listOfCurrecies.RubToDol = RTD;
	return listOfCurrecies;
}

bool PayMasterOperator::СurrencyeExchange(double money, string currencySet, exchangeRaters exchangeRates, string currencyGet) {
	int update = 0;
	double toClint = 0;
	exchangeRaters list = exchangeRates;
	cout << " | Происходит перевод денежных средств!" << endl;
	cout << " | Валюта которую нужно перевести - " << currencySet  << endl;
	cout << " | Количество - " << money << endl;
	cout << " | Валюта в котрую нужно перевести деньги - " << currencyGet  << endl;
	cout << " | Если хотите изменить количество средств для перевода, нажмите 1: ";
	cin >> update;
	if (update == 1) {
		cout << " | Введите новое количество денег - ";
		cin >> money;
	}
	cout << " | Если хотите обновить курс валют нажмите 1: ";
	cin >> update;
	if (update == 1) {
		list = get_set_ExchangeRates(exchangeRates);
	}
	if ((currencySet == "dollars") && (currencyGet == "rubli")) {
		cout << " | Индекс перевода - " << list.DolToRub << endl;
		toClint = money* list.DolToRub;
	}
	if ((currencySet == "rubli") && (currencyGet == "dollars")) {
		cout << " | Индекс перевода - " << list.RubToDol << endl;
		toClint = money* list.RubToDol;
	}
	cout << " | Клиенту передаётся денег: " << toClint << " В валюте - " << currencyGet << endl;
	cout << " | Перевод закончен." << endl;
	return true;
}



// ===================== Класс главного менеджера. 
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
		cout << " | Создан объект менеджера банка" << endl;
	}
	Manager(int credit, int debit, int pay, PayMasterOperator *ObjectCash) {
		amountOfCreditCard = credit;
		amountOfDebitCard = debit;
		amountOfPayCard = pay;
		Card1 = new AgreementOfCreditCard();
		Card2 = new AgreementOfDebetCard();
		Client1 = new ClientOfTheBank();
		Cash1 = ObjectCash;
		cout << " | Создан объект менеджера банка |" << endl;
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
	return true;
}

pd Manager::giveDataOfClint() {
	pd outerInformation;
	outerInformation = Client1->GiveInformation();
	
	cout << " | Данные клиента переданы."<< endl;
	return outerInformation;
}

// Заключение договоров на офорление пластиковых карт.
void Manager::makeAgrement() {
	int watCardNeed = 0;
	double moneyToCard = 0;
	pd dataOfClient;
	dataOfClient = Client1->GiveInformation();
	cout << " | Данные клиента - "<< endl;
	Client1->ShowInformation();
	//pd Data;
	cout << " | Выполняется заключение договора."<< endl;
	cout << " | Выберете какой договор нужно формить:" << endl;
	cout << " | Нажмите 1, если хотите оформить договор на получение кредитной карты." << endl;
	cout << " | Нажмите 2, если хотите оформить договор на получение депозитной карты." << endl;
	cin >> watCardNeed;
	switch (watCardNeed) {
		case 1: {
					if ((amountOfCreditCard != 0) && (amountOfCreditCard > 0)) {
						cout << " | Ввидете сумму кредитных средств, которую хотите взять в банке (целое число): " << endl;
						cin >> moneyToCard;
						if (moneyToCard > 0 ) {
							cout << " | За оформление карты снимется 200 рублей. " << endl;
							moneyToCard - 200;
						}
						amountOfCreditCard--;
						Card1->AddInf(1, dataOfClient, 200, -500);
						Card1->ShowInf();
						Client1->ChangeColOfAgreements(1);
						setMessageToPayMasterForDelivery(Client1, moneyToCard);
					}
					else {
						cout << " | Карт больше нет." << endl;
						system("pause");
					}
				break;

		}
		case 2: {
					if ((amountOfDebitCard != 0) && (amountOfDebitCard >= 0)) {
						cout << " | Ввидете сумму денежных средств, которую хотите положить в банк: " << endl;
						cin >> moneyToCard;
						if (moneyToCard > 0) {
							cout << " | За оформление карты снимется 200 рублей. " << endl;
							moneyToCard - 200;
						}
						Card2->AddInf(1, Client1->GiveInformation(), 320);
						Card2->ShowInf();
						amountOfDebitCard--;
						Client1->ChangeColOfAgreements(1);
						setMessageToPayMasterForReseptiomMoney(Client1, moneyToCard);
					}
					else {
						cout << " | Карт больше нет." << endl;
						system("pause");
					}
					break;
		}
		default: {
					 cout << " | Вы ошиблись с вводом."<< endl;
		}
	}
}

bool Manager::setMessageToPayMasterForDelivery(ClientOfTheBank* Client, double money) {
	Cash1->inputMessageToPayMasterForDelivery(Client1, money);
	return true;
}
bool Manager::setMessageToPayMasterForReseptiomMoney(ClientOfTheBank* Client, double money) {
	Cash1->inputMessageToPayMasterForReseptiomMoney(Client1, money);
	return true;
}
// Класс Менеджера по депозитам.
class ManagerOfDepost : Manager {
public:
	ManagerOfDepost() :Manager(){
		Client3 = new ClientOfTheBank();
		blanc.data = Client3->GiveInformation;
		blanc.days = 240;
		blanc.percent = 5;
		blanc.valute = "rubl";
		blanc.value = 50000;
	}
	ManagerOfDepost(double value, string values, double per, int days, int credit, int debit, int pay, PayMasterOperator *ObjectCash) :Manager(credit, debit, pay, ObjectCash) {
		Client3 = new ClientOfTheBank();
		blanc.data = Client3->GiveInformation;
		blanc.days = days;
		blanc.percent = per;
		blanc.valute = values;
		blanc.value = value;
	}
	void OpenDeposit();
private:
	class ClientOfTheBank *Client3 = NULL;
	deposit blanc;
};
void ManagerOfDepost::OpenDeposit(){ 
	int Yes = 0;
	cout << " | Оставить информацию по умолчанию. 2 - Ввести новую информацию."<< endl;
	cin >> Yes;
	if (Yes == 2) {
		cout << " | Вы ввели следующую информацию: " << endl;
		blanc.data.FIO = "Fominv Igor Kirlovich";
		blanc.data.Id = 241;
		blanc.data.BalanceOfMoney = 1500;
		blanc.data.Agreement = 2;
		blanc.data.given = "RF, city Moscov";
		blanc.data.number = "230 55221";
		blanc.days = 360;
		blanc.percent = 10;
		blanc.valute = "rubl";
		blanc.value = 10000;
		cout << " | Порядковый номер - " << blanc.data.Id << endl;
		cout << " | Ф. И. О. клиентa - " << blanc.data.FIO << endl;
		cout << " | Номер паспорта - " << blanc.data.number << endl;
		cout << " | Место выдачи паспорта - " << blanc.data.given << endl;
		cout << " | Баланс счёта - " << blanc.data.BalanceOfMoney << endl;
		cout << " | Количество заключенных договоров - " << blanc.data.Agreement << endl;

		cout << " | Продолжительность контракта депозита - " << blanc.days << endl;
		cout << " | Процент - " << blanc.percent << endl;
		cout << " | Валюта депозита - " << blanc.valute << endl;
		cout << " | КОЛИЧЕСТВО ДЕНЕГ - " << blanc.value << endl;
	}
	Client3->ChangeColOfAgreements(1);
	setMessageToPayMasterForReseptiomMoney(Client3, blanc.value);
}
// Класс Менеджера по кредитам.
class ManagerOfCredit : Manager {
public:
	ManagerOfCredit() :Manager() {
		Client2 = new ClientOfTheBank();
		blanc.data = Client2->GiveInformation;
		blanc.days = 240;
		blanc.percent = 5;
		blanc.valute = "rubl";
		blanc.pledge = false;
	}
	ManagerOfCredit(bool zalog, string value, double per, int days, int credit, int debit, int pay, PayMasterOperator *ObjectCash) :Manager(credit, debit, pay, ObjectCash) {
		Client2 = new ClientOfTheBank();
		blanc.data = Client2->GiveInformation;
		blanc.days = days;
		blanc.percent = per;
		blanc.valute = value;
		blanc.pledge = zalog;
	}
private:
	class ClientOfTheBank *Client2 = NULL;
	credit blanc;
};
// Класс страховщика.
class Insurer: Manager {
public:
	Insurer() :Manager(){
		Client4 = new ClientOfTheBank();
		blanc.data = Client4->GiveInformation;
		blanc.days = 240;
		blanc.percent = 5;
		blanc.valute = "rubl";
	}
	Insurer(string value,double per, int days ,int credit, int debit, int pay, PayMasterOperator *ObjectCash) :Manager(credit,debit,pay, ObjectCash) {
		Client4 = new ClientOfTheBank();
		blanc.data = Client4->GiveInformation;
		blanc.days = days;
		blanc.percent = per;
		blanc.valute = value;
	}
private:
	class ClientOfTheBank *Client4 = NULL;
	deposit blanc;
};


// Выполнение.
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");


	exchangeRaters Rates;
	// Создание оъекта кассира банка.
	class PayMasterOperator *Casier1 = NULL;
	//class PayMasterOperator *Casier2 = NULL;
	//class	Search *Step = NULL;
	Casier1 = new PayMasterOperator(0.25, 1.25);
	//Casier2 = new PayMasterOperator();
	// Создание объекта Менеджера банка.
	class Manager *MainManager = NULL;
	MainManager = new Manager(3, 3, 3, Casier1);
	
	Casier1->СurrencyeExchange(850, "dollars", Rates, "rubli");
	MainManager->makeAgrement();

	system("pause");
	return 0;
}



