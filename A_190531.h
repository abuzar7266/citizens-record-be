#ifndef  _ASSIGN_DATA_STRUCT_
#define _ASSIGN_DATA_STRUCT_
/*
		Student Name : Abuzar
		Roll ID : 19i-0531
		Section : CS-A

*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<class T>
struct CBID_NODE;//Forward Declaration of CBID_NODE 
template <class T>
struct QueueNode
{
	T *data;
	QueueNode<T>* next;
	QueueNode(T *dat)
	{
		data = dat;
		next = NULL;
	}
	~QueueNode()
	{

	}
};//DataNodes we'll be using to Store Data in queue
template <class T, class Count>
class AlienQueue {
	QueueNode<T>* Front;
	QueueNode<T>* Rear;
	Count QueueItems;
public:

	AlienQueue() {
		Front = NULL;
		Rear = NULL;
		QueueItems = 0;
	}

	T front() {
		return Front->data;
	}
	T back() {
		return Rear->data;
	}

	bool enqueue(T *data)
	{
		if (is_empty())
		{
			Front = new QueueNode<T>(data);
			Rear = Front;
			QueueItems++;
		}
		else
		{
			Rear->next = new QueueNode<T>(data);
			Rear = Rear->next;
			QueueItems++;
		}
		return true;
	}

	T* dequeue()
	{
		T *data = NULL;
		if (!is_empty())
		{
			if (QueueItems == 1)
			{
				data = Front->data;
				delete Front;
				Front = NULL;
				Rear = NULL;
				QueueItems--;
			}
			else
			{
				QueueNode<T>* Temp = Front->next;
				data = Front->data;
				Front = Temp;
				QueueItems--;
			}
		}
		return data;
	}
	bool is_empty()
	{
		if (QueueItems == 0)
			return true;
		else
			return false;
	}
	~AlienQueue()
	{
		while (QueueItems != 0)
		{
			T *data = dequeue();
		}
	}
};
template <class T>
struct DataNode
{
	T data;
	DataNode<T>* next;
	DataNode(T dat)
	{
		data = dat;
		next = NULL;
	}
	~DataNode()
	{
		
	}
};//DataNodes we'll be using to Store Data in queue
template <class T,class Count>
class DataPipeline {
	DataNode<T>* Front;
	DataNode<T>* Rear;
	Count QueueItems;
public:

	DataPipeline() {
		Front = NULL;
		Rear = NULL;
		QueueItems = 0;
	}

	T front() {
		return Front->data;
	}
	T back() {
		return Rear->data;
	}

	bool enqueue(T data)
	{
		if (is_empty())
		{
			Front = new DataNode<T>(data);
			Rear = Front;
			QueueItems++;
		}
		else
		{
			Rear->next = new DataNode<T>(data);
			Rear = Rear->next;
			QueueItems++;
		}
		return true;
	}

	T dequeue()
	{
		T data = "";
		if (!is_empty())
		{
			if (QueueItems == 1)
			{
				data = Front->data;
				delete Front;
				Front = NULL;
				Rear = NULL;
				QueueItems--;
			}
			else
			{
				DataNode<T>* Temp = Front->next;
				data = Front->data;
				Front = Temp;
				QueueItems--;
			}
		}
		return data;
	}
	bool is_empty()
	{
		if (QueueItems == 0)
			return true;
		else
			return false;
	}
	~DataPipeline()
	{
		while (QueueItems != 0)
		{
			T data = dequeue();
		}
	}
};
template<class T>
struct Crimes
{
	T crime;
	T punish;
	T fine;
	Crimes<T>* next;
	Crimes()
	{
		crime = "";
		punish = "";
		fine = "";
		next = NULL;
	}
	Crimes(T c,T p,T f)
	{
		crime = c;
		punish = p;
		fine = f;
		next = NULL;
	}
	~Crimes()
	{
		
	}
};
template<class T>
struct CCID_NODE
{
	T Cnic;
	Crimes<T>* CrimeList;
	int NoCrimes;
	CBID_NODE<T>* CBID;
	CCID_NODE* first, * next, * previous;
	CCID_NODE(T cnic)
	{
		Cnic = cnic;
		CrimeList = NULL;
		NoCrimes = 0;
		first = NULL;
		next = NULL;
		previous = NULL;
		CBID = NULL;
	}
	void AddCrime(Crimes<T> *Crime)
	{
		if (CrimeList==NULL)
		{
			CrimeList = Crime;
			NoCrimes++;
		}
		else
		{
			Crimes<T>* Curr = CrimeList;
			while (Curr->next != NULL)
			{
				Curr = Curr->next;
			}
			Curr->next = Crime;
			NoCrimes++;
		}
	}
	bool is_empty()
	{
		if (NoCrimes == 0)
			return true;
		else
			return false;
	}
	void Remove_End()
	{
		if (NoCrimes != 0)
		{
			if (NoCrimes == 1)
			{
				delete CrimeList;
				NoCrimes--;
			}
			else
			{
				Crimes<T>* Curr = CrimeList;
				Crimes<T>* Temp = NULL;
				while (Curr->next != NULL)
				{
					Temp = Curr;
					Curr = Curr->next;
				}
				delete Curr;
				Temp->next = NULL;
				NoCrimes--;
			}
		}
	}
	~CCID_NODE()
	{
		/*while (NoCrimes != 0)
		{
			Remove_End();
		}*/
	}
};
template<class T>
struct Numbers
{
	T SimNo;
	T network;
	T activate;
	T deactivate;
	T status;
	Numbers* next;
	Numbers()
	{
		SimNo = "";
		network = "";
		activate = "";
		deactivate = "";
		status = "";
		next = NULL;
	}
	void SetNumber(T num, T net, T act, T deact, T status)
	{
		SimNo = num;
		network = net;
		activate = act;
		deactivate = deact;
		this->status = status;
	}
};
template<class T>
struct CCND_NODE {
	T Cnic;
	Numbers<T>* NumberList;
	int TotalNum;
	int ActiveNum;
	CBID_NODE<T>* CBID;
	CCND_NODE *first,* next, * previous;
	CCND_NODE(T cnic)
	{
		Cnic = cnic;
		NumberList = NULL;
		TotalNum = 0;
		ActiveNum = 0;
		first = NULL;
		next = NULL;
		previous = NULL;
		CBID = NULL;
	}
	bool AddNumber(Numbers<T>* Num)
	{
		if (TotalNum<4)
		{
			if (is_empty())
			{
				NumberList = Num;
				TotalNum++;
				if (Num->status == "active")
					ActiveNum++;
			}
			else
			{
				Numbers<T>* Curr = NumberList;
				while (Curr->next != NULL)
				{
					Curr = Curr->next;
				}
				Curr->next = Num;
				TotalNum++;
				if (Num->status == "active")
					ActiveNum++;
			}
			return true;
		}
		else
			return false;
	}
	bool is_empty()
	{
		if (TotalNum == 0)
			return true;
		else
			return false;
	}
	bool is_full()
	{
		if (TotalNum > 4)
			return true;
		else
			return false;
	}
	~CCND_NODE()
	{

	}
};
#define CCID_NODE CCID_NODE<string>
#define CCND_NODE CCND_NODE<string>
template<class T>
struct CBID_NODE
{
	T Cnic;
	T Address;
	T Name;
	T FatherName;
	T Gender;
	T Nationality;
	CCID_NODE* CCID;
	CCND_NODE* CCND;
	CBID_NODE* next, * previous;
public:
	CBID_NODE()
	{
		Cnic = "";
		Address = "";
		Name = "";
		FatherName = "";
		Gender = "";
		Nationality = "";
		next = NULL;
		previous = NULL;
		CCID = NULL;
		CCND = NULL;
	}
	CBID_NODE(T c, T n, T f, T g, T a, T na)
	{
		Cnic = c;
		Address = a;
		Name = n;
		FatherName = f;
		Gender = g;
		Nationality = na;
		next = NULL;
		previous = NULL;
		CCID = NULL;
		CCND = NULL;
	}
	void setCBID(T c, T n, T f, T g, T a, T na)
	{
		Cnic = c;
		Address = a;
		Name = n;
		FatherName = f;
		Gender = g;
		Nationality = na;
	}
	~CBID_NODE()
	{
		if (CCID != NULL)
		{
			delete CCID;
		}
		if (CCND != NULL)
		{
			delete CCND;
		}
	}
};
#define CBID_NODE CBID_NODE<string>
#define DataPipeline DataPipeline<string,int>
template<class T>
struct AD
{
	T* Data;
	AD* next;
	AD()
	{
		Data = NULL;
		next = NULL;
	}
	~AD()
	{
		
	}
};
template<class T,class T2>
struct DataLink
{
	AD<T> *Top;
	T2 NoItems;
	
	DataLink()
	{
		Top = NULL;
		NoItems = 0;
	}
	void push(T *data)
	{
		AD<T>* Data = new AD<T>;
		Data->Data = data;
		if (Top == NULL)
		{
			Top = Data;
			NoItems++;
		}
		else
		{
			AD<T>* Curr = Top;
			while (Curr->next != NULL)
			{
				Curr = Curr->next;
			}
			Curr->next = Data;
			NoItems++;
		}
	}
	T* pop()
	{
		if (Top != NULL)
		{
			T* data = Top->Data;
			if (NoItems == 1)
			{
				delete Top;
				Top = NULL;
				NoItems = 0;
			}
			else
			{
				AD<T>* Curr = Top;
				AD<T>* Temp = NULL;
				while (Curr->next != NULL)
				{
					Temp = Curr;
					Curr = Curr->next;
				}
				Temp->next = NULL;
				data = Curr->Data;
				delete Curr;
				NoItems--;
			}
			return data;
		}
		else
			return NULL;
	}
	AD<T>* top()
	{
		if (Top != NULL)
		{
			AD<CBID_NODE>* data = NULL;
			if (NoItems == 1)
			{
				data = Top;
			}
			else
			{
				AD<T>* Curr = Top;
				AD<T>* Temp = NULL;
				while (Curr->next != NULL)
				{
					Temp = Curr;
					Curr = Curr->next;
				}
				data = Curr;
			}
			return data;
		}
		else
			return NULL;
	}
	~DataLink()
	{
		while (NoItems != 0) {
			T *X = pop();
			delete X;
		}
	}
};
template<class T,class T2>
class Database
{
	CBID_NODE *CBID;
	CCID_NODE *CCID;
	CCND_NODE *CCND;
	T2 countCCID;
	T2 countCCND;
	T2 countCBID;
public:
	DataLink<CBID_NODE,int> Aliens;
	DataPipeline dataPipeline;
public:
	Database(const T& filename, const T& filename1, const T& filename2)
	{
		CBID = NULL;
		CCID = NULL;
		CCND = NULL;
		countCCID = 0;
		countCCND = 0;
		countCBID = 0;
		Read_In_Queue(filename);
		Populate_In_CBID();
		Read_In_Queue(filename1);
		Populate_In_CCID();
		Read_In_Queue(filename2);
		Populate_In_CCND();
		SortCBID();
		SortCCID();
		SortCCND();
	}
	void Read_In_Queue(T txt)
	{
		string data = "";
		fstream File(txt, ios::in);
		while (!File.eof())
		{
			getline(File, data);
			dataPipeline.enqueue(data);
		}
	}
	void PrintQueue()
	{
		while (!dataPipeline.is_empty())
		{
			string X = dataPipeline.dequeue();
			cout << X << endl;
		}
	}
	void Populate_In_CCID()
	{
		while (!dataPipeline.is_empty())
		{	T data =  dataPipeline.dequeue();
			T cnic = "";
			T crime = "";
			T punishment = "";
			T fine = "";
			int count = 0;
			while (data[count] != ' ') {
				cnic = cnic + data[count];
				count++;
			}
			count++;
			while (data[count] != ' ')
			{
				crime = crime + data[count];
				count++;
			}
			count++;
			int count_spaces = 0;
			int length = 0;
			while (data[length] != '\0')
				length++;
			for (int i = 0; i < length; i++)
			{
				if (data[i] == ' ')
					count_spaces++;
			}
			for (int i = count; i < length && count_spaces > 2; i++)
			{
				if (data[i] == ' ')
					count_spaces--;
				if (count_spaces > 2)
					punishment = punishment + data[i];
				count++;
			}
			while (count < length)
			{
				fine = fine + data[count];
				count++;
			}

			bool CheckID = Search_CBID(cnic);
			bool CrimeExist = Search_CCID(cnic);
			if (CheckID)
			{
				//cout << cnic << " " << crime << " " << punishment << " " << fine << endl;
				if (CrimeExist)
				{
					Crimes<T>* NewCrime = new Crimes<T>(crime, punishment, fine);
					AddCrime(cnic, NewCrime);
				}
				else
				{
					Crimes<T>* NewCrime = new Crimes<T>(crime, punishment, fine);
					CCID_NODE *Temp = new CCID_NODE(cnic);
					Temp->AddCrime(NewCrime);
					CBID_NODE* temp2 = GetCBID(cnic);
					(temp2->CCID) = Temp;
					AddCCID(Temp);
				}
			}
		}
	}
	void Populate_In_CCND()
	{
		while (!dataPipeline.is_empty())
		{
			T data = dataPipeline.dequeue();
			T cnic = "";
			T SimNo = "";
			T Company = "";
			T Activation = "";
			T Deactivation = "";
			T SimStatus = "";
			int count = 0;
			while (data[count] != ' ')
			{
				cnic = cnic + data[count];
				count++;
			}
			count++;
			//cout << cnic << endl;
			while (data[count] != ' ')
			{
				SimNo = SimNo + data[count];
				count++;
			}
			count++;
			//cout << SimNo << endl;
			while (data[count] != ' ')
			{
				Company = Company + data[count];
				count++;
			}
			count++;
			//cout << Company << endl;
			while (data[count] != ' ')
			{
				Activation = Activation + data[count];
				count++;
			}
			count++;
			//cout << Activation << endl;
			while (data[count] != ' ')
			{
				Deactivation = Deactivation + data[count];
				count++;
			}
			count++;
			//cout << Deactivation << endl;
			while (data[count] != '\0')
			{
				SimStatus = SimStatus + data[count];
				count++;
			}
			//cout << SimStatus << endl;
			bool CheckExist = Search_CBID(cnic);
			bool NetExist = Search_CCND(cnic);
			if (CheckExist)
			{
				Numbers<T>* NewNet = new Numbers<T>;
				NewNet->SetNumber(SimNo, Company, Activation, Deactivation, SimStatus);
				if (NetExist)
				{
					CBID_NODE* Temp = GetCBID(cnic);
					(Temp->CCND)->AddNumber(NewNet);
				}
				else
				{
					CCND_NODE* Temp = new CCND_NODE(cnic);
					Temp->AddNumber(NewNet);
					CBID_NODE* temp2 = GetCBID(cnic);
					(temp2->CCND) = Temp;
					Temp->CBID = temp2;
					AddCCND(Temp);
					Temp->CBID = temp2;
				}
			}
		}
	}
	void AddCrime(T cnic, Crimes<T>* New)
	{
		CBID_NODE* Temp = GetCBID(cnic);
		(Temp->CCID)->AddCrime(New);
	}
	bool Search_CCID(T cnic)
	{
		if (CCID != NULL)
		{
			CCID_NODE* Curr = CCID;
			while (Curr != NULL)
			{
				if (Curr->Cnic == cnic)
				{
					return true;
				}
				Curr = Curr->next;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	bool Search_CCND(T cnic)
	{
		if (CCND != NULL)
		{
			CCND_NODE* Curr = CCND;
			while (Curr != NULL)
			{
				if (Curr->Cnic == cnic)
				{
					return true;
				}
				Curr = Curr->next;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	void Populate_In_CBID()
	{
		while (!dataPipeline.is_empty())
		{
			T data = dataPipeline.dequeue();
			T cnic = "";
			T Address = "";
			T Name = "";
			T Father_Name = "";
			T Gender = "";
			T Nationality = "";
			int count = 0;
			while (data[count] != ' ') {
				cnic = cnic + data[count];
				count++;
			}
			count++;
			while (data[count] != ' ')
			{
				Name = Name + data[count];
				count++;
			}
			count++;
			while (data[count] != ' ')
			{
				Father_Name = Father_Name + data[count];
				count++;
			}
			count++;
			Gender = Gender + data[count];
			count += 2;
			int count2 = 3;
			while (count2 > 0)
			{
				Address = Address + data[count];
				count++;
				if (data[count] == ' ')
					count2--;
			}
			count++;
			count2 = 0;
			while (data[count2] != '\0')
				count2++;
			while (count < count2) {
				Nationality = Nationality + data[count];
				count++;
			}
			//cout << cnic << " " << Name << " " << Father_Name << " " << Gender << " " << Address << " " << Nationality << endl;
			CBID_NODE* NewNode = new CBID_NODE(cnic, Name, Father_Name, Gender, Address, Nationality);
			AddCBID(NewNode);//T c, T a, T n, T f, T g, T na
		}
	}
	void AddCBID(CBID_NODE *Data)
	{
		if (CBID == NULL)
		{
			CBID = Data;
			countCBID++;
		}
		else
		{
			CBID_NODE *Curr = CBID;
			while (Curr->next != NULL)
			{
				Curr = Curr->next;
			}
			Curr->next = Data;
			Data->previous = Curr;
			countCBID++;
		}
	}
	bool Search_CBID(T cnic)
	{
		if (CBID != NULL)
		{
			CBID_NODE* Curr = CBID;
			while (Curr != NULL)
			{
				if (Curr->Cnic == cnic)
				{
					return true;
				}
				Curr = Curr->next;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	void Print_CBID()
	{
		if (CBID != NULL)
		{
			CBID_NODE *Curr = CBID;
			while (Curr != NULL)
			{
				cout << Curr->Cnic << endl;
				Curr = Curr->next;
			}
		}
	}
	void Print_CCID()
	{
		if (CCID != NULL)
		{
			CCID_NODE* Curr = CCID;
			int x = countCCID;
			while (x>0)
			{
				cout << Curr->Cnic << endl;
				Curr = Curr->next;
				x--;
			}
		}
	}
	void Print_CCND()
	{
		if (CCND != NULL)
		{
			CCND_NODE* Curr = CCND;
			while (Curr != NULL)
			{
				cout << Curr->Cnic << " :" << Curr->TotalNum << " : "<< Curr->ActiveNum<< endl;
				Curr = Curr->next;
			}
		}
	}
	CBID_NODE* GetCBID(T cnic)
	{
		if (CBID != NULL)
		{
			CBID_NODE* Curr = CBID;
			while (Curr != NULL)
			{
				if (Curr->Cnic == cnic)
				{
					return Curr;
				}
				Curr = Curr->next;
			}
			return NULL;
		}
		else
			return NULL;
	}
	void AddCCID(CCID_NODE *Data)
	{
		if (Search_CBID(Data->Cnic)) 
		{
			if (CCID == NULL)
			{
				CCID = Data;
				Data->first = CCID;
				Data->previous = Data;
				CBID_NODE* Temp = GetCBID(Data->Cnic);
				Temp->CCID = Data;
				Data->CBID = Temp;
				countCCID++;
			}
			else
			{
				CCID_NODE* Curr = CCID;
				Data->first = Curr;
				Curr = CCID->previous;
				Curr->next = Data;
				CCID->previous = Curr->next;
				Data->previous = Curr;
				Data->next = NULL;
				CBID_NODE* Temp = GetCBID(Data->Cnic);
				Temp->CCID = Data;
				Data->CBID = Temp;
				countCCID++;
			}
		}
	}
	void AddCCND(CCND_NODE * Data)
	{
		if (Search_CBID(Data->Cnic))
		{
			if (CCND == NULL)
			{
				CCND = Data;
				Data->first = CCND;
				CBID_NODE* Temp = GetCBID(Data->Cnic);
				Temp->CCND = Data;
				Data->CBID = Temp;
				countCCND++;
			}
			else
			{
				CCND_NODE* Curr = CCND;
				while (Curr->next != NULL)
					Curr = Curr->next;
				Curr->next = Data;
				Data->previous = Curr;
				CBID_NODE* Temp = GetCBID(Data->Cnic);
				Temp->CCND = Data;
				Data->CBID = Temp;
				Data->first = CCND;
				countCCND++;
			}
		}
	}
	T CBID_Search_by_CNIC(T2 cnic)
	{
		if (CBID != NULL)
		{
			CBID_NODE *curr = CBID;
			T CBID_DATA_STRING = "";
			if (CBID != NULL)
			{
				while (curr != NULL)
				{
					if (stoi(curr->Cnic) == cnic)
					{
							CBID_DATA_STRING = CBID_DATA_STRING + curr->Name + " ";
							CBID_DATA_STRING = CBID_DATA_STRING + curr->FatherName + " ";
							CBID_DATA_STRING = CBID_DATA_STRING + curr->Gender + " " + curr->Address + " " + curr->Nationality;
							Crimes<T>* FetchCrime = (curr->CCID)->CrimeList;
							if (FetchCrime != NULL)
								CBID_DATA_STRING = CBID_DATA_STRING + " " + FetchCrime->crime + " " + FetchCrime->punish + " " + FetchCrime->fine;
							Numbers<T>* FetchNum = (curr->CCND)->NumberList;
							if (FetchNum != NULL)
								CBID_DATA_STRING = CBID_DATA_STRING + " " + FetchNum->SimNo + " " + FetchNum->network + " " + FetchNum->activate + +" " + FetchNum->deactivate + +" " + FetchNum->status;
					}
					curr = curr->next;
				}
			}
			return CBID_DATA_STRING;
		}
	}
	T CCID_Search_by_CNIC(T2 cnic)
	{
		if (CBID != NULL)
		{
			CCID_NODE* Data = CCID;
			T CBID_DATA_STRING = "";
			if (CCID != NULL)
			{
				while (Data != NULL)
				{
					if (stoi(Data->Cnic) == cnic)
					{
						CBID_NODE* curr = Data->CBID;
						CBID_DATA_STRING = CBID_DATA_STRING + curr->Name + " ";
						CBID_DATA_STRING = CBID_DATA_STRING + curr->FatherName + " ";
						CBID_DATA_STRING = CBID_DATA_STRING + curr->Gender + " " + curr->Address + " " + curr->Nationality;
						if (curr->CCID != NULL) {
							Crimes<T>* FetchCrime = (curr->CCID)->CrimeList;
								if (FetchCrime != NULL)
									CBID_DATA_STRING = CBID_DATA_STRING + " " + FetchCrime->crime + " " + FetchCrime->punish + " " + FetchCrime->fine;
						}
							Numbers<T>* FetchNum = (curr->CCND)->NumberList;
						if (FetchNum != NULL)
							CBID_DATA_STRING = CBID_DATA_STRING + " " + FetchNum->SimNo + " " + FetchNum->network + " " + FetchNum->activate + +" " + FetchNum->deactivate + +" " + FetchNum->status;
						break;
					}
					Data = Data->next;
				}
			}
			return CBID_DATA_STRING;
		}
	}
	T CCND_Search_by_CNIC(T2 cnic)
	{
		if (CBID != NULL)
		{
			CCND_NODE* Data = CCND;
			T CBID_DATA_STRING = "";
			if (CCND != NULL)
			{
				while (Data != NULL)
				{
					if (stoi(Data->Cnic) == cnic)
					{
						CBID_NODE* curr = Data->CBID;
						CBID_DATA_STRING = CBID_DATA_STRING + curr->Name + " ";
						CBID_DATA_STRING = CBID_DATA_STRING + curr->FatherName + " ";
						CBID_DATA_STRING = CBID_DATA_STRING + curr->Gender + " " + curr->Address + " " + curr->Nationality;
						if (curr->CCID != NULL)
						{
							Crimes<T>* FetchCrime = (curr->CCID)->CrimeList;
							if (FetchCrime != NULL)
								CBID_DATA_STRING = CBID_DATA_STRING + " " + FetchCrime->crime + " " + FetchCrime->punish + " " + FetchCrime->fine;
						}
						Numbers<T>* FetchNum = (curr->CCND)->NumberList;
						if (FetchNum != NULL)
							CBID_DATA_STRING = CBID_DATA_STRING + " " + FetchNum->SimNo + " " + FetchNum->network + " " + FetchNum->activate + +" " + FetchNum->deactivate + +" " + FetchNum->status;
						break;
					}
					Data = Data->next;
				}
			}
			return CBID_DATA_STRING;
		}
	}
	bool updateCBIDName(T name, T2 cnic)
	{
		if (CBID != NULL)
		{
			CBID_NODE* curr = CBID;
			if (CBID != NULL)
			{
				while (curr != NULL)
				{
					if (stoi(curr->Cnic) == cnic)
					{
						curr->Name = name;
						return true;
					}
					curr = curr->next;
				}
				return false;
			}
		}
		else
			return false;
	}
	bool updateCBIDFName(T name, T2 cnic)
	{
		if (CBID != NULL)
		{
			CBID_NODE* curr = CBID;
			if (CBID != NULL)
			{
				while (curr != NULL)
				{
					if (stoi(curr->Cnic) == cnic)
					{
						curr->FatherName = name;
						return true;
					}
					curr = curr->next;
				}
				return false;
			}
		}
		else
			return false;
	}
	bool updateCBIDAddress(T adr, T2 cnic)
	{
		if (CBID != NULL)
		{
			CBID_NODE* curr = CBID;
			if (CBID != NULL)
			{
				while (curr != NULL)
				{
					if (stoi(curr->Cnic) == cnic)
					{
						curr->Address = adr;
						return true;
					}
					curr = curr->next;
				}
				return false;
			}
		}
		else
			return false;
	}
	bool updateCBIDNationality(T nation, T2 cnic)
	{
		CBID_NODE* curr = CBID;
		if (CBID != NULL)
		{
			while (curr != NULL)
			{
				if (stoi(curr->Cnic) == cnic)
				{
					T n = curr->Nationality;
					curr->Nationality = nation;
					if (nation == "Alien" && n!=nation)
					{
						Aliens.push(curr);
					}
					return true;
				}
				curr = curr->next;
			}
			return false;
		}
		else
		return false;
	}
	CBID_NODE* Alien_Pop()
	{
		return Aliens.pop();
	}
	bool addCrime(T2 cnic, T crime, T punishment, T fine)
	{
		bool CheckID = Search_CBID(to_string(cnic));
		bool CrimeExist = Search_CCID(to_string(cnic));
		if (CheckID)
		{
			//cout << cnic << " " << crime << " " << punishment << " " << fine << endl;
			if (CrimeExist)
			{
				Crimes<T>* NewCrime = new Crimes<T>(crime, punishment, fine);
				AddCrime(to_string(cnic), NewCrime);
				return true;
			}
			else
			{
				Crimes<T>* NewCrime = new Crimes<T>(crime, punishment, fine);
				CCID_NODE* Temp = new CCID_NODE(to_string(cnic));
				Temp->AddCrime(NewCrime);
				CBID_NODE* temp2 = GetCBID(to_string(cnic));
				(temp2->CCID) = Temp;
				AddCCID(Temp);
				return true;
			}
		}
		else
			return false;
	}
	T2 checkRegistred_No(T2 cnic)
	{
		if (Search_CBID(to_string(cnic)))
		{
			CBID_NODE* Temp = GetCBID(to_string(cnic));
			return (Temp->CCND)->ActiveNum;
		}
		else
			return 0;
	}
	bool deleteCrime(T2 cnic, T crime, T punishment, T fine)
	{
		if (Search_CCID(to_string(cnic)))
		{
			CBID_NODE* cbid = GetCBID(to_string(cnic));
			CCID_NODE* ccid = cbid->CCID;
			Crimes<T>* Temp3 = NULL;
			Crimes<T>* Temp2 = ccid->CrimeList;
			while (Temp2 != NULL)
			{
				if (Temp2->crime == crime && Temp2->punish == punishment && Temp2->fine == fine)
				{
					break;
				}
				Temp3 = Temp2;
				Temp2 = Temp2->next;
			}
			if (Temp2 != NULL)
			{
				CCID_NODE* Prev = ccid->previous;
				CCID_NODE* Next = ccid->next;
				if (ccid->NoCrimes == 1)
				{
					delete ccid->CrimeList;
					ccid->CrimeList = NULL;
					cbid->CCID = NULL;
					ccid->NoCrimes--;
					cout << countCCID << endl;
					//countCCID = 2;
					if (countCCID == 1)
					{
						delete CCID;
						CCID = NULL;
						countCCID--;
					}
					else if(countCCID==2)
					{
						Prev = ccid->previous;
						(Prev->previous) = Prev;
						delete ccid;
						CCID = Prev;
						countCCID--;
					}
					else
					{

						if (CCID->Cnic != ccid->Cnic) {
							Prev = ccid->previous;
							Next = ccid->next;
							if (Next == NULL)
							{
								CCID->previous = Prev;
								Prev->next = NULL;
							}
							else
							{
								delete ccid;
								Prev->next = Next;
								Next->previous = Prev;
							}
							countCCID--;
						}
						else
						{
							CCID_NODE* Prev = ccid->previous;
							CCID_NODE* Next = ccid->next;
							delete CCID;
							CCID = Next;
							Next->previous = Prev;
							Prev->next = NULL;
							countCCID--;
						}
					}
				}
				else
				{
					Temp3->next = Temp2->next;
					delete Temp2;
					(ccid->NoCrimes)--;
				}
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	void CCID_Debug()
	{
		if (CCID != NULL)
		{
			CCID_NODE* Curr = CCID;
			while (countCCID>0)
			{
				cout << Curr->Cnic << endl;
				Curr = Curr->previous;
				countCCID--;
			}
		}
	}
	int printcount()
	{
		int x = 0;
		CCND_NODE* Temp = CCND;
		while (Temp != NULL)
		{
			x += Temp->TotalNum;
			Temp = Temp->next;
		}
		return x;
	}
	bool updateCrime(T2 cnic, T crime, T punishment, T fine)
	{
		if (Search_CCID(to_string(cnic)))
		{
			CBID_NODE* cbid = GetCBID(to_string(cnic));
			CCID_NODE* ccid = cbid->CCID;
			Crimes<T>* Temp2 = ccid->CrimeList;
			if (Temp2 != NULL)
			{
				Temp2->crime = crime;
				Temp2->punish = punishment;
				Temp2->fine = fine;
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	int addNumber(T2 cnic, T2 num)
	{
		bool CheckExist = Search_CBID(to_string(cnic));
		bool NetExist = Search_CCND(to_string(cnic));
		if (CheckExist)
		{
			int x = 0;
			Numbers<T>* NewNet = new Numbers<T>;
			NewNet->SetNumber((to_string(num)), "-", "-", "-", "active");
			if (NetExist)
			{
				CBID_NODE* Temp = GetCBID(to_string(cnic));
				(Temp->CCND)->AddNumber(NewNet);
				x = (Temp->CCND)->TotalNum;
			}
			else
			{
				CCND_NODE* Temp = new CCND_NODE(to_string(cnic));
				Temp->AddNumber(NewNet);
				CBID_NODE* temp2 = GetCBID(to_string(cnic));
				(temp2->CCND) = Temp;
				Temp->CBID = temp2;
				AddCCND(Temp);
				Temp->CBID = temp2;
				x = Temp->TotalNum;
			}
			return x;
		}
		else
			return 0;
	}
	AD<CBID_NODE>* declareAlien(int cnic)
	{
		if (Search_CBID(to_string(cnic)))
		{
			updateCBIDNationality("Alien", cnic);
			RemoveCBID(to_string(cnic));
			AD<CBID_NODE>* Top = Aliens.top();
			return Top;
		}
		else
		{
			return NULL;
		}
	}
	void RemoveCBID(T cnic)
	{
		if (countCBID != 0)
		{
			CBID_NODE* NODE = GetCBID(cnic);
			if (NODE != NULL)
			{
				CCND_NODE* CNode = NODE->CCND;
				if (CNode != NULL)
				{
					Numbers<T>* Curr = CNode->NumberList;
					while (Curr != NULL)
					{
						Curr->status = "unactive";
						Curr = Curr->next;
					}
				}
				if (countCBID == 1)
				{
					CBID = NULL;
					countCBID--;
				}
				else
				{
					if (NODE->Cnic == CBID->Cnic)
					{
						CBID_NODE* NODE1 = CBID->next;
						CBID = NULL;
						CBID = NODE1;
						CBID->previous = NULL;
						countCBID--;
					}
					else
					{
						CBID_NODE* NODE2 = CBID;
						while (NODE2->next != NULL)
						{
							NODE2 = NODE2->next;
						}
						if (NODE2->Cnic == cnic)
						{
							NODE2 = NODE2->previous;
							NODE2->next = NULL;
							countCBID--;
						}
						else
						{
							CBID_NODE* NODE_N = NODE->next;
							CBID_NODE* NODE_P = NODE->previous;
							NODE_N->previous = NODE_P;
							NODE_P->next = NODE_N;
							countCBID--;
						}
					}
					
				}
			}
		}
	}
	bool verifyAlienDBUpdate(T2 cnic,AD<CBID_NODE> *AD_NODE, CBID_NODE* cbid)
	{
		bool a = !Search_CBID(to_string(cnic));
		bool b = AD_NODE->Data->Cnic == cbid->Cnic;
		bool d = AD_NODE->Data->Nationality == cbid->Nationality;
		bool t = true;
		if (AD_NODE->Data->CCND != NULL)
		{
			bool x = AD_NODE->Data->CCND->NumberList->status == cbid->CCND->NumberList->status;
			bool y = AD_NODE->Data->CCND->NumberList->SimNo == cbid->CCND->NumberList->SimNo;
			t = x && y;
		}
		return a && b && d && t;
	}
	void RemoveCBID_End()
	{
		if (countCBID != 0)
		{
			if (countCBID==1)
			{
				delete CBID;
				CBID = NULL;
				countCBID--;
			}
			else
			{
				CBID_NODE* cbid = CBID;
				CBID_NODE* Temp = NULL;
				while (cbid->next != NULL)
				{
					Temp = cbid;
					cbid = cbid->next;
				}
				delete cbid;
				Temp->next = NULL;
				countCBID--;
			}
		}
	}
	~Database()
	{
		/*while (countCBID != 0)
		{
			RemoveCBID_End();
		}*/
	}
	void SortCCID()
	{
			CCID_NODE* First = CCID;
			int i = countCCID;
			int x = 0;
			while (i > 0)
			{
				CCID_NODE* Second = CCID;
				int j = countCCID;
				while (j > 0)
				{
					if (stoi(First->Cnic) < stoi(Second->Cnic))
					{
						CBID_NODE* First_cbid = GetCBID(First->Cnic);
						CBID_NODE* Sec_cbid = GetCBID(Second->Cnic);
						SwapCCID(First, Second);
						First_cbid->CCID = Second;
						Sec_cbid->CCID = First;
					}
					Second = Second->next;
					j--;
				}
				i--;
				First = First->next;
			}
	}
	void SortCCND()
	{
		CCND_NODE* First = CCND;
		int i = countCCND;
		while (i > 0)
		{
			CCND_NODE* Second = CCND;
			int j = countCCND;
			while (j > 0)
			{
				if (stoi(First->Cnic) < stoi(Second->Cnic))
				{
					CBID_NODE* First_cbid = GetCBID(First->Cnic);
					CBID_NODE* Sec_cbid = GetCBID(Second->Cnic);
					SwapCCND(First, Second);
					First_cbid->CCND = Second;
					Sec_cbid->CCND = First;
				}
				Second = Second->next;
				j--;
			}
			i--;
			First = First->next;
		}
	}
	void SortCBID()
	{
		CBID_NODE* First = CBID;
		while (First != NULL)
		{
			CBID_NODE* Second = CBID;
			while (Second != NULL)
			{
				if (stoi(First->Cnic) < stoi(Second->Cnic))
				{
					SwapCBID(First,Second);
				}
				Second = Second->next;
			}
			First = First->next;
		}
	}
	void SwapCCID(CCID_NODE* ccid1, CCID_NODE* ccid2)
	{
		T Cnic = ccid1->Cnic;
		Crimes<T>* CrimeList = ccid1->CrimeList;
		int NoCrimes = ccid1->NoCrimes;
		CBID_NODE* CBID = ccid1->CBID;

		ccid1->Cnic = ccid2->Cnic;
		ccid1->CrimeList = ccid2->CrimeList;
		ccid1->NoCrimes = ccid2->NoCrimes;
		ccid1->CBID = ccid2->CBID;

		ccid2->Cnic = Cnic;
		ccid2->CrimeList = CrimeList;
		ccid2->NoCrimes = NoCrimes;
		ccid2->CBID = CBID;

	}
	void SwapCCND(CCND_NODE* ccnd1, CCND_NODE* ccnd2)
	{
		T Cnic = ccnd1->Cnic;
		Numbers<T>* NumberList = ccnd1->NumberList;
		int TotalNum = ccnd1->TotalNum;
		int ActiveNum = ccnd1->ActiveNum;
		CBID_NODE* CBID = ccnd1->CBID;

		ccnd1->Cnic = ccnd2->Cnic;
		ccnd1->NumberList = ccnd2->NumberList;
		ccnd1->TotalNum = ccnd2->TotalNum;
		ccnd1->ActiveNum = ccnd2->ActiveNum;
		ccnd1->CBID = ccnd2->CBID;

		ccnd2->Cnic = Cnic;
		ccnd2->NumberList = NumberList;
		ccnd2->TotalNum = TotalNum;
		ccnd2->ActiveNum = ActiveNum;
		ccnd2->CBID = CBID;
	}
	void SwapCBID(CBID_NODE* cbid1, CBID_NODE* cbid2)
	{

		CBID_NODE* N1 = GetCBID(cbid1->Cnic);
		CBID_NODE* N2 = GetCBID(cbid2->Cnic);
		CCID_NODE* C1 = N1->CCID;
		CCID_NODE* C2 = N2->CCID;
		if (C1 != NULL)
		{
			C1->CBID = cbid2;
		}
		if (C2 != NULL)
		{
			C2->CBID = cbid1;
		}

		CCND_NODE* C3 = N1->CCND;
		CCND_NODE* C4 = N2->CCND;
		if (C3 != NULL)
		{
			C3->CBID = cbid2;
		}
		if (C4 != NULL)
		{
			C4->CBID = cbid1;
		}
		/*
		if (C1 != NULL || C2!=NULL)
		{
			if (C1 == NULL && C2 != NULL)
			{
				N1->CCID = C2;
				N2->CCID = NULL;
			}
			else if (C1 != NULL && C2 == NULL)
			{
				N2->CCID = C1;
				N1->CCID = NULL;
			}
			else if (C1 != NULL && C2 != NULL)
			{
				N1->CCID = C2;
				N2->CCID = C1;
			}
		}
		*/
		T Cnic = cbid1->Cnic;
		T Address = cbid1->Address;
		T Name = cbid1->Name;
		T FatherName = cbid1->FatherName;
		T Gender = cbid1->Gender;
		T Nationality = cbid1->Nationality;
		CCID_NODE* CCID = cbid1->CCID;
		CCND_NODE* CCND = cbid1->CCND;

		cbid1->Cnic = cbid2->Cnic;
		cbid1->Address = cbid2->Address;
		cbid1->Name = cbid2->Name;
		cbid1->FatherName = cbid2->FatherName;
		cbid1->Gender = cbid2->Gender;
		cbid1->Nationality = cbid2->Nationality;
		cbid1->CCID = cbid2->CCID;
		cbid1->CCND = cbid2->CCND;

		cbid2->Cnic = Cnic;
		cbid2->Address = Address;
		cbid2->Name = Name;
		cbid2->FatherName = FatherName;
		cbid2->Gender = Gender;
		cbid2->Nationality = Nationality;
		cbid2->CCID = CCID;
		cbid2->CCND = CCND;
	}
	bool deleteNumber(T2 cnic, T num)
	{
		if (Search_CBID(to_string(cnic)))
		{
			
			CBID_NODE* cbid = GetCBID(to_string(cnic));
			CCND_NODE* ccnd = cbid->CCND;
			Numbers<T>* Temp3 = NULL;
			Numbers<T>* Temp2 = ccnd->NumberList;
			while (Temp2 != NULL)
			{
				if (Temp2->SimNo==num)
				{
					if (Temp2->status == "active")
					{
						ccnd->ActiveNum--;
					}
					break;
				}
				Temp3 = Temp2;
				Temp2 = Temp2->next;
			}
			if (Temp2 != NULL)
			{
				if (countCCND == 1)
				{
					if (ccnd->TotalNum == 1)
					{
						delete ccnd->NumberList;
						ccnd->NumberList = NULL;
						ccnd->TotalNum--;
						delete CCND;
						CCND = NULL;
						countCCND--;
						return true;
					}
					else
					{
						Temp3->next = Temp2->next;
						delete Temp2;
						ccnd->TotalNum--;
						return true;
					}
				}
				else
				{
					if (ccnd->TotalNum == 1)
					{
						delete ccnd->NumberList;
						ccnd->NumberList = NULL;
						ccnd->TotalNum--;
						if (countCCND == 2)
						{
							CCND_NODE* Prev = ccnd->previous;
							CCND_NODE* Next = ccnd->next;
							delete ccnd;
							if (Prev == NULL)
							{
								CCND = Next;
								Next->previous = NULL;
								Next->next = NULL;
							}
							else
							{
								CCND = Prev;
								Prev->previous = NULL;
								Prev->next = NULL;
							}
							countCCND--;
							return true;
						}
						else
						{
							if (CCND->Cnic == ccnd->Cnic)
							{
								ccnd = ccnd->next;
								delete CCND;
								CCND = ccnd;
								CCND->previous = NULL;
								countCCND--;
								return true;
							}
							else
							{
								CCND_NODE* Last = CCND;
								while (Last->next != NULL)
								{
									Last = Last->next;
								}
								if (Last->Cnic == ccnd->Cnic)
								{
									Last = Last->previous;
									delete ccnd;
									Last->next = NULL;
									countCCND--;
									return true;
								}
								else
								{
									CCND_NODE* Prev = ccnd->previous;
									CCND_NODE* Next = ccnd->next;
									Prev->next = Next;
									Next->previous = Prev;
									delete ccnd;
									countCCND--;
									return true;
								}
							}
						}
					}
					else
					{
						if (Temp3 == NULL)
						{
							ccnd->NumberList = Temp2->next;
							delete Temp2;
						}
						else
						{
							Temp3->next = Temp2->next;
							delete Temp2;
						}
						ccnd->TotalNum--;
						return true;
					}
				}
			}
			else
				return false;
		}
		else
			return false;


	}
	bool updateNumber(T2 cnic, T num)
	{
		if (Search_CBID(to_string(cnic)))
		{
			CBID_NODE* cbid = GetCBID(to_string(cnic));
			CCND_NODE* ccnd = cbid->CCND;
			if (ccnd == NULL)
			{
				return false;
			}
			else
			{
				ccnd->NumberList->SimNo = num;
				return true;
			}
		}
		else
			return false;
	}
	void swap(Numbers<T>* N1, Numbers<T>* N2)
	{
		T SimNo = N1->SimNo;
		T network = N1->network;
		T activate = N1->activate;
		T deactivate = N1->deactivate;
		T status = N1->status;

		N1->SimNo = N2->SimNo;
		N1->network = N2->network;
		N1->activate = N2->activate;
		N1->deactivate = N2->deactivate;
		N1->status = N2->status;

		N2->SimNo = SimNo;
		N2->network = network;
		N2->activate = activate;
		N2->deactivate = deactivate;
		N2->status = status;
	}
	bool swap(T2 cnic1, T2 cnic2,T num1,T num2)
	{
		if (Search_CBID(to_string(cnic1)) && Search_CBID(to_string(cnic2)))
		{
			CBID_NODE* N1 = GetCBID(to_string(cnic1));
			CBID_NODE* N2 = GetCBID(to_string(cnic2));
			if (N1->CCND == NULL || N2->CCND == NULL)
				return false;
			Numbers<T>* N1_Num = N1->CCND->NumberList;
			Numbers<T>* N2_Num = N2->CCND->NumberList;
			bool CheckFirst = false;
			bool CheckSec = false;
			while (N1_Num != NULL)
			{
				if (N1_Num->SimNo == num1 )
				{
					CheckFirst = true;
					break;
				}
				N1_Num = N1_Num->next;
			}
			while (N2_Num != NULL)
			{
				if (N2_Num->SimNo == num2)
				{
					CheckSec = true;
					break;
				}
				N2_Num = N2_Num->next;
			}
			if (CheckFirst && CheckSec)
			{
				if (N1_Num->status == "unactive" && N2_Num->status == "active")
				{
					N1->CCND->ActiveNum++;
					N2->CCND->ActiveNum--;
				}
				else if(N1_Num->status == "active" && N2_Num->status == "unactive")
				{
					N1->CCND->ActiveNum--;
					N2->CCND->ActiveNum++;
				}
				swap(N1_Num, N2_Num);
				return CheckFirst && CheckSec;
			}
			else
				return false;
		}
		else
			return false;
	}
		void Display_AD()
		{
			AlienQueue<CBID_NODE, int> Store;
			while (Aliens.NoItems > 0)
			{
				CBID_NODE* cbid = Aliens.pop();
				cout << cbid->Cnic << " " << cbid->Name << " " << cbid->Gender << " " << cbid->Address << " " << cbid->Nationality;
				if (cbid->CCID != NULL)
				{
					CCID_NODE* ccid = cbid->CCID;
					cout << " " << ccid->CrimeList->crime << " " << ccid->CrimeList->punish << ccid->CrimeList->fine;
				}
				if (cbid->CCND != NULL)
				{
					CCND_NODE* ccnd = cbid->CCND;
					cout << " " << ccnd->NumberList->SimNo << " " << ccnd->NumberList->network << " " << ccnd->NumberList->activate << " " << ccnd->NumberList->deactivate << " " << ccnd->NumberList->status;
				}
				cout << endl;
				Store.enqueue(cbid);
			}
			while (!Store.is_empty())
			{
				Aliens.push(Store.dequeue());
			}
		}
};
#define Database Database<string,int>

#endif