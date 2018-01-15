#include<string>
#include<iostream>
#include<list>
#include<ctime>
#include<fstream>
#pragma warning(disable:4996)
using namespace std;
typedef unsigned long long int  INT;

class Time {
public:
	time_t rawtime = time(0);
	struct tm *timeinfo = localtime(&rawtime);
	int day = timeinfo->tm_mday;
	int month = timeinfo->tm_mon + 1;
	int year = timeinfo->tm_year + 1900;

	friend ostream& operator<<(ostream& os, const Time& dt);
};

ostream& operator<<(ostream& os, const Time& tm) {
	os << tm.month << "/" << tm.month << "/" << tm.year;
	return os;
}

class Student {
	INT id;
	string name;
	string surname;
	string phone_number;
	string group;
	bool payment;
public:
	Student(INT _id = 0, string _name = "", string _surname = "",
		string _phone_number = "", string _group = "", bool _payment = false) {
		id = _id;
		name = _name;
		surname = _surname;
		phone_number = _phone_number;
		group = _group;
		payment = _payment;
	}
	INT getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getSurname() {
		return surname;
	}
	string getPhone_number() {
		return phone_number;
	}
	string getGroup() {
		return group;
	}
	bool getPayment() {
		return payment;
	}

	Student* setName(string _name) {
		name = _name;
		return this;
	}
	Student* setId(INT _id) {
		id = _id;
		return this;
	}
	Student* setSurname(string _surname) {
		surname = _surname;
		return this;
	}
	Student* setPhone_number(string _phone_number) {
		phone_number = _phone_number;
		return this;
	}
	Student* setGroup(string _group) {
		group = _group;
		return this;
	}
	Student* setPayment(bool _payment) {
		payment = _payment;
		return this;
	}
};

class Teacher { // id,ad, soyad, mobil nomre, voen, maash, ayin maashi verilib / yoxsa yox
	INT id;
	string name;
	string surname;
	string phone_number;
	string voen;
	string salary;
	bool salary_payment;
public:
	Teacher(INT _id = 0, string _name = "", string _surname = "",
		string _phone_number = "", string _voen = "", string _salary = "", bool _salary_payment = false) {
		id = _id;
		name = _name;
		surname = _surname;
		phone_number = _phone_number;
		voen = _voen;
		salary = _salary;
		salary_payment = _salary_payment;
	}
	INT getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getSurname() {
		return surname;
	}
	string getPhone_Number() {
		return phone_number;
	}
	string getVoen() {
		return voen;
	}
	string getSalary() {
		return salary;
	}
	bool getSalary_payment() {
		return salary_payment;
	}
	Teacher* setId(INT _id) {
		id = _id;
		return this;
	}
	Teacher* setName(string _name) {
		name = _name;
		return this;
	}
	Teacher* setSurname(string _surname) {
		surname = _surname;
		return this;
	}
	Teacher* setPhone_Number(string _phone_number) {
		phone_number = _phone_number;
		return this;
	}
	Teacher* setVoen(string _voen) {
		voen = _voen;
		return this;
	}
	Teacher* setSalary(string _salary) {
		salary = _salary;
		return this;
	}
	Teacher* setSalary_payment(bool _salary_payment) {
		salary_payment = _salary_payment;
		return this;
	}
};

class Payment { //id,studentId, mebleg, tarix
	INT id, StudentID, amount;
	Time t;
public:
	Payment() {}
	Payment(Time _t, INT _id = 0, INT _StudentID = 0, INT _amount = 0) {
		id = _id;
		StudentID = _StudentID;
		amount = _amount;
		t = _t;
	}
	INT getID() {
		return id;
	}
	Time getTime() {
		return t;
	}
	Payment *setTime(Time _t) {
		t = _t;
		return this;
	}
	INT getStudentID() {
		return StudentID;
	}
	INT getAmount() {
		return amount;
	}
	Payment* setID(INT _id) {
		id = _id;
		return this;
	}
	Payment* setStudentID(INT _StudentID) {
		StudentID = _StudentID;
		return this;
	}
	Payment *setAmount(INT _amount) {
		amount = _amount;
		return this;
	}
};

class Salary {
	INT SalaryID;
	INT TeacherID;
	int amount;
	Time t;
public:
	Salary() {}
	Salary(Time _t, INT _SalaryID = 0, INT _TeacherID = 0, int _amount = 0) {
		SalaryID = _SalaryID;
		TeacherID = _TeacherID;
		amount = _amount;
		t = _t;
	}
	INT getSalaryID() {
		return SalaryID;
	}
	Time getTime() {
		return t;
	}
	Salary* setTime(Time _t) {
		t = _t;
		return this;
	}
	INT getTeacherID() {
		return TeacherID;
	}
	int getAmount() {
		return amount;
	}

	Salary* setSalaryId(INT _SalaryID) {
		SalaryID = _SalaryID;
		return this;
	}
	Salary* setTEacherId(INT _TeacherID) {
		TeacherID = _TeacherID;
		return this;
	}
	Salary* setAmoun(int _amount) {
		amount = _amount;
		return this;
	}
};

class StudentDAO {  //Singleton
	list<Student> ListStudents;
	static StudentDAO* instance;
	StudentDAO() {}
	StudentDAO(StudentDAO &oth) {}
	~StudentDAO() {};
	void operator=(StudentDAO &oth) {}
public:
	static StudentDAO* getInstance() {
		if (instance == nullptr) {
			instance = new StudentDAO();
		}
		return instance;
	}

	void addStudent(Student data) {
		ListStudents.push_back(data);
	}
	void deleteStudentByID(INT id) {
		for (auto iterator = ListStudents.begin(); iterator != ListStudents.end(); iterator++) {
			if (iterator->getId() == id) {
				iterator = ListStudents.erase(iterator);
				return;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	list<Student> ShowStudents() {
		if (ListStudents.size() == 0) {
			throw exception("List IS EMPTY ");
		}
		return ListStudents;
	}
	bool StudentPayment(INT id) {
		for (Student &s : ListStudents) {
			if (s.getId() == id && s.getPayment() == true) {
				return true;
			}
			else if (s.getId() == id && s.getPayment() == false) {
				return false;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	Student Find_Studnet_By_ID(INT id) {
		for (Student &s : ListStudents) {
			if (s.getId() == id) {
				return s;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	bool Set_Payment_True(INT id) {
		for (Student &s : ListStudents) {
			if (s.getId() == id) {
				s.setPayment(true);
				return true;
			}
		}
		return false;
	}
	list<Student> Find_Student_by_Name(string name) {
		list<Student> students;
		for (Student &s : ListStudents) {
			if (s.getName() == name) {

				students.push_back(s);
			}
		}
		return students;
	}
	void ExportStudent_List_to_CSV() {
		ofstream fout("Student.CSV");
		for (Student s : ListStudents) {
			fout << s.getId() << ";" << s.getName() << ";"
				<< s.getSurname() << ";" << s.getPhone_number() << ";"
				<< s.getGroup() << ";";
			if (s.getPayment() == true) {
				fout << "Payment is paid by  " << s.getName() << endl;
			}
			else {
				fout << "Payment is not paid by " << s.getName() << endl;;
			}

		}
	}
	void ImportStudent_List_to_CSV() {
		string id, name, surname, group, phone, payment;
		bool pay = false;
		ifstream fin("Student.CSV");
		if (!fin.is_open()) {
			throw exception("File not found");
		}
		while (!fin.eof()) {
			getline(fin, id, ';');
			if (id.empty()) {
				break;
			}
			getline(fin, name, ';');
			getline(fin, surname, ';');
			getline(fin, phone, ';');
			getline(fin, group, ';');
			getline(fin, payment, ';');
			INT _id = (INT)stoul(id);


			Student s;
			s.setId(_id);
			s.setName(name);
			s.setSurname(surname);
			s.setPhone_number(phone);
			s.setGroup(group);
			s.setPayment(pay);
			ListStudents.push_back(s);
		}
	}
	list<Student> StudentPayment_NotPaid() {
		list<Student> temp;
		for (Student &s : ListStudents) {
			if (s.getPayment() == false) {
				temp.push_back(s);
			}
		}
		return temp;
	}
};
StudentDAO* StudentDAO::instance = nullptr;

class TeacherDAO {
	list<Teacher> List_teachers;
	static TeacherDAO* instance;
	TeacherDAO() {}
	~TeacherDAO() {}
	TeacherDAO(TeacherDAO &other) {}
	void operator=(TeacherDAO &other) {}
public:
	static TeacherDAO *getInstance() {
		if (instance == nullptr) {
			instance = new TeacherDAO();
		}
		return instance;
	}
	void addTeacher(Teacher data) {
		List_teachers.push_back(data);
	}
	void deleteTeacher_ByID(INT id) {
		for (auto it = List_teachers.begin(); it != List_teachers.end(); it++) {
			if (it->getId() == id) {
				it = List_teachers.erase(it);
				return;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	list<Teacher> Print_Teachers_List() {
		if (List_teachers.size() == 0) {
			throw exception("List is EMPTY ");
		}
		return List_teachers;
	}
	bool Set_Teachers_SalaryPayment_True(INT id) {
		for (Teacher &t : List_teachers) {
			if (t.getId() == id) {
				t.setSalary_payment(true);
				return true;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	Teacher Find_Teacher_By_ID(INT id) {
		for (Teacher &t : List_teachers) {
			if (t.getId() == id) {
				return t;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	list<Teacher> Find_Teacher_By_Name(string name) {
		list<Teacher> tmp;
		for (Teacher &t : List_teachers) {
			if (t.getName() == name) {
				tmp.push_back(t);
			}
		}
		return tmp;
	}
	list<Teacher> Salary_was_Paid() {
		list<Teacher> temp;
		for (Teacher &t : List_teachers) {
			if (t.getSalary_payment() == true) {
				temp.push_back(t);
			}
		}
		return temp;
	}
	list<Teacher> Salary_Not_Paid() {
		list<Teacher> temp;
		for (Teacher &t : List_teachers) {
			if (t.getSalary_payment() == false) {
				temp.push_back(t);
			}
		}
		return temp;
	}
	bool Teachers_SalaryPayment(INT id) {
		for (Teacher &t : List_teachers) {
			if (t.getId() == id && t.getSalary_payment() == true) {
				return true;
			}
			else if (t.getId() == id && t.getSalary_payment() == false) {
				return false;
			}
		}
	}
	void Export_List_Of_Teachers_To_CSV() {

		ofstream fout("Teachers.CSV");
		for (Teacher s : List_teachers) {
			fout << s.getId() << ";" << s.getName() << ";"
				<< s.getSurname() << ";" << s.getPhone_Number() << ";"
				<< s.getVoen() << ";" << s.getSalary() << ";";
			if (s.getSalary_payment() == true) {
				fout << "Salary is paid " << ";" << endl;
			}
			else {
				fout << "Payment is not paid  " << ";" << endl;
			}
		}
	}
};
TeacherDAO* TeacherDAO::instance = nullptr;

class PaymentDAO {
	Student stud;
	list<Payment> payments;
	static PaymentDAO *instance;
	PaymentDAO() {}
	~PaymentDAO() {}
	PaymentDAO(PaymentDAO &other) {}
	void operator=(PaymentDAO &other) {}
public:
	static PaymentDAO *getInstance() {
		if (instance == nullptr) {
			instance = new PaymentDAO();
		}
		return instance;
	}
	void addPayment(Payment data) {
		payments.push_back(data);
	}
	void deletePayment(INT id) {
		for (auto it = payments.begin(); it != payments.end(); it++) {
			if (it->getID() == id) {
				it = payments.erase(it);
				return;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	Payment Find_Payment_by_ID(INT id) {

		for (Payment &p : payments) {
			if (p.getID() == id) {
				return p;
			}
		}
		throw exception("Wrong ID , try again ");
	}
	list<Payment> Show_List_of_Payments() {
		if (payments.size() == 0) {
			throw exception("List is EMPTY ");
		}
		return payments;
	}

	void ExportPayment_List_to_CSV() {
		ofstream fout("StudentPayment.CSV");
		for (Payment s : payments) {
			fout << s.getID() << ";" << s.getStudentID() << ";"
				<< s.getAmount() << ";" << s.getTime() << ";";
			if (stud.getPayment() == true) {
				fout << "Payment is paid by This " << stud.getName() << endl;
			}
			else {
				fout << "Payment is not paid by " << stud.getName() << endl;;
			}

		}
	}
};
PaymentDAO* PaymentDAO::instance = nullptr;

class SalaryDAO {
	list<Salary> salaries;
	static SalaryDAO* instance;
	SalaryDAO() {}
	~SalaryDAO() {}
	SalaryDAO(SalaryDAO &other) {}
	void operator= (SalaryDAO &other) {}
public:
	static SalaryDAO* getInstance() {
		if (instance == nullptr) {
			instance = new SalaryDAO();
		}
		return instance;
	}
	void addSalary(Salary data) {
		salaries.push_back(data);
	}
	void deleteSalary(INT id) {
		for (auto it = salaries.begin(); it != salaries.end(); it++) {
			if (it->getSalaryID() == id) {
				it = salaries.erase(it);
				return;
			}
		}
		throw exception("Wrong ID,Not Found");
	}
	Salary Find_Salary_by_ID(INT id) {
		for (Salary &s : salaries) {
			if (s.getSalaryID() == id) {
				return s;
			}
		}
	}
	list<Salary> Show_List_Of_Salary() {
		return salaries;
	}
};
SalaryDAO* SalaryDAO::instance = nullptr;

class StudentService { // Singleton
	StudentDAO *Students;
	static StudentService* instance;
	StudentService() {
		Students = StudentDAO::getInstance();
	}
	StudentService(StudentService &oth) {};
	~StudentService() {};
	void operator=(StudentService &oth) {};
public:
	static StudentService* getInstance() {
		if (instance == nullptr) {
			instance = new StudentService();
		}
		return instance;
	}

	void Student_add(Student data) {
		Students->addStudent(data);
	}
	void delete_Student_by_ID(INT id) {
		if (id == 0) {
			throw exception("Wrong ID , try again ");
		}
		Students->deleteStudentByID(id);
	}
	Student Find_Studnet_By_ID(INT id) {
		if (id == 0) {
			throw exception("Wrong ID , try again ");
		}
		else {
			return  Students->Find_Studnet_By_ID(id);

		}
	}
	void ImportStudent_List_to_CSV() {
		Students->ImportStudent_List_to_CSV();
	}
	list<Student> findStudent_by_name(string name) {
		if (name == "") {
			throw exception("this name not found");
		}
		list<Student> tmp = Students->Find_Student_by_Name(name);
		return tmp;
	}
	bool Student_Payment(INT id) {
		if (id == 0) throw exception("Wrong ID");

		else return Students->StudentPayment(id);
	}
	list<Student> PrintAllStudents() {
		list<Student> Stud = Students->ShowStudents();
		return Stud;
	}
	bool Set_Payment_True(INT id) {
		return Students->Set_Payment_True(id);
	}
	void ExportStudent_List_to_CSV() {
		Students->ExportStudent_List_to_CSV();
	}
	list<Student> StudentPayment_NotPaid() {
		return Students->StudentPayment_NotPaid();
	}
};
StudentService* StudentService::instance = nullptr;

class TeacherService {
	TeacherDAO *Teacher_service;
	static TeacherService *instance;
	TeacherService() {
		Teacher_service = TeacherDAO::getInstance();
	}
	~TeacherService() {}
	TeacherService(TeacherService &other) {}
	void operator=(TeacherService &other) {}
public:
	static TeacherService *getInstance() {
		if (instance == nullptr) {
			instance = new TeacherService();
		}
		return instance;
	}
	void Teacher_Add(Teacher data) {
		Teacher_service->addTeacher(data);
		return;
	}
	void deleteTeacher_by_ID(INT id) {

		if (id != 0) {
			Teacher_service->deleteTeacher_ByID(id);
		}
	}
	list<Teacher> Print_Teachers_List() {
		list<Teacher> temp = Teacher_service->Print_Teachers_List();
		return temp;
	}
	bool  Set_Teachers_SalaryPayment_True(INT id) {
		return Teacher_service->Set_Teachers_SalaryPayment_True(id);
	}
	list<Teacher> Find_Teacher_By_Name(string name) {
		if (name == " ") {
			throw exception("Wrong Name");
		}
		else {
			list<Teacher> temp = Teacher_service->Find_Teacher_By_Name(name);
			return temp;
		}
	}
	Teacher Find_Teacher_by_ID(INT id) {
		return Teacher_service->Find_Teacher_By_ID(id);
	}
	bool Teachers_SalaryPayment(INT id) {
		if (id == 0) {
			throw exception("Wrong ID");
		}
		else {
			return Teacher_service->Teachers_SalaryPayment(id);

		}
	}
	list<Teacher> Salary_was_Paid() {
		list<Teacher> Tmp = Teacher_service->Salary_was_Paid();
		return Tmp;
	}
	list<Teacher> Salary_Not_Paid() {
		list<Teacher> Tmp = Teacher_service->Salary_Not_Paid();
		return Tmp;
	}
	void Export_List_Of_Teachers_To_CSV() {
		Teacher_service->Export_List_Of_Teachers_To_CSV();
	}
};
TeacherService* TeacherService::instance = nullptr;

class PaymentService {
	PaymentDAO* paymentdao;
	StudentDAO* studentdao;
	static PaymentService* instance;
	PaymentService() {
		paymentdao = PaymentDAO::getInstance();
		studentdao = StudentDAO::getInstance();
	}
	~PaymentService() {}
	PaymentService(PaymentService &other) {}
	void operator=(PaymentService &other) {}
public:
	static PaymentService *getInstance() {
		if (instance == nullptr) {
			instance = new PaymentService();
		}
		return instance;
	}
	void addPayment(Payment data) {
		try {
			studentdao->Find_Studnet_By_ID(data.getStudentID());
		}
		catch (exception ex) {
			throw exception("NO_SUCH_STUDENT_ID");
		}
		paymentdao->addPayment(data);
	}
	void deletePayment(INT id) {
		if (id == 0) {
			throw exception("Wrong ID , try again ");
		}
		paymentdao->deletePayment(id);
	}
	Payment Find_Payment_by_ID(INT id) {
		return paymentdao->Find_Payment_by_ID(id);
	}
	list<Payment> Show_List_of_Payments() {
		return paymentdao->Show_List_of_Payments();
	}

	void ExportPayment_List_to_CSV() {
		paymentdao->ExportPayment_List_to_CSV();
	}
};
PaymentService* PaymentService::instance = nullptr;

class SalaryService {
	SalaryDAO* salary_dao;
	static SalaryService* instance;
	SalaryService() {
		salary_dao = SalaryDAO::getInstance();
	}
	~SalaryService() {}
	SalaryService(SalaryService &other) {}
	void operator=(SalaryService &other) { }
public:
	static SalaryService* getInstance() {
		if (instance == nullptr) {
			instance = new SalaryService();
		}
		return instance;
	}
	void addSalary(Salary data) {
		salary_dao->addSalary(data);
	}
	void deleteSalary(INT id) {
		if (id == 0) {
			throw exception("Wrong ID,Not Found");
		}
		salary_dao->deleteSalary(id);
	}
	Salary Find_Salary_by_ID(INT id) {
		if (id == 0) {
			throw exception("Wrong ID,Not Found");
		}
		return salary_dao->Find_Salary_by_ID(id);
	}
	list<Salary> Show_List_Of_Salary() {
		return salary_dao->Show_List_Of_Salary();
	}
};
SalaryService* SalaryService::instance = nullptr;

class StudentController { //Singleton
	StudentService* Student_Control;
	static StudentController* instance;
	StudentController() {
		Student_Control = StudentService::getInstance();
	}
	StudentController(StudentController &oth) {};
	~StudentController() {};
	void operator=(StudentController &oth) {};
public:
	static StudentController* getInstance() {
		if (instance == nullptr) {
			instance = new StudentController();
		}
		return instance;
	}

	void Student_Add() {
		Student s;
		INT id;
		cout << "Enter ID : " << endl;
		cin >> id;
		s.setId(id);
		string str;
		cout << "Enter Name : " << endl;
		cin >> str;
		s.setName(str);
		cout << "Enter Surname : " << endl;
		cin >> str;
		s.setSurname(str);
		cout << "Enter Phone Number : " << endl;
		cin >> str;
		s.setPhone_number(str);
		cout << "Enter Group : " << endl;
		cin >> str;
		s.setGroup(str);
		cout << "Enter Payment : " << endl;
		bool pay;
		cin >> pay;
		s.setPayment(pay);
		Student_Control->Student_add(s);
	}
	void Delete_Student_By_ID() {
		INT id;
		cout << "Enter Id for delete : " << endl;
		cin >> id;
		Student_Control->delete_Student_by_ID(id);
	}
	void ExportStudent_List_to_CSV() {
		Student_Control->ExportStudent_List_to_CSV();
	}
	void Find_Student_By_ID() {
		INT id;
		cout << "Enter Enter Id for find : " << endl;
		cin >> id;
		Student tmp = Student_Control->Find_Studnet_By_ID(id);

		cout << "{ Student ID       : " << tmp.getId() << endl;
		cout << "  Student Name     : " << tmp.getName() << endl;
		cout << "  Student Surname  : " << tmp.getSurname() << endl;
		cout << "  Student Group    : " << tmp.getGroup() << endl;
		cout << "  Phone Number     : " << tmp.getPhone_number() << endl;
		cout << "  Payment          : ";
		if (tmp.getPayment() == true) {
			cout << "Payment is paid by This " << tmp.getName() << endl;
		}
		else {
			cout << "Payment is not paid by This Student" << endl;
		}
		cout << " }" << endl << endl;
	}
	void ImportStudent_List_to_CSV() {
		Student_Control->ImportStudent_List_to_CSV();
	}
	void Find_Student_By_Name() {
		string name;
		cout << "Enter Name you wnat find : " << endl;
		cin >> name;
		list<Student> tmp = Student_Control->findStudent_by_name(name);
		for (Student s : tmp) {
			cout << "{ Student ID       : " << s.getId() << endl;
			cout << "  Student Name     : " << s.getName() << endl;
			cout << "  Student Surname  : " << s.getSurname() << endl;
			cout << "  Student Group    : " << s.getGroup() << endl;
			cout << "  Phone Number     : " << s.getPhone_number() << endl;
			cout << "  Payment          : ";
			if (s.getPayment() == true) {
				cout << "Payment is paid by This Student" << endl;
			}
			else {
				cout << "Payment is not paid by This Student" << endl;
			}
			cout << " }" << endl << endl;
		}
	}
	void Print_Student_List() {
		list<Student> std1 = Student_Control->PrintAllStudents();
		for (Student s : std1)
		{
			cout << "{ Student ID       : " << s.getId() << endl;
			cout << "  Student Name     : " << s.getName() << endl;
			cout << "  Student Surname  : " << s.getSurname() << endl;
			cout << "  Student Group    : " << s.getGroup() << endl;
			cout << "  Phone Number     : " << s.getPhone_number() << endl;
			cout << "  Payment          : ";
			if (s.getPayment() == true) {
				cout << "Payment is paid by " << s.getName() << endl;
			}
			else {
				cout << "Payment is NOT paid by " << s.getName() << endl;
			}
			cout << " }" << endl << endl;
		}
	}
	bool Student_Payment(INT id) {
		return  Student_Control->Student_Payment(id);

	}
	bool set_Student_Payment_True(INT id) {
		return Student_Control->Set_Payment_True(id);
	}
	void StudentPayment_NotPaid() {
		list<Student> s = Student_Control->StudentPayment_NotPaid();
		for (Student p : s)
		{
			cout << "  Student ID       : " << p.getId() << endl;
			cout << "  Student Name     : " << p.getName() << endl;
			cout << "  Student Surname  : " << p.getSurname() << endl;
			cout << "  Student Group    : " << p.getGroup() << endl;
			cout << "  Phone Number     : " << p.getPhone_number() << endl;
		}
	}
};
StudentController* StudentController::instance = nullptr;

class TeacherController {
	TeacherService *TeacControl;
	static TeacherController* instance;
	TeacherController() {
		TeacControl = TeacherService::getInstance();
	}
	~TeacherController() {}
	TeacherController(TeacherController &other) {}
	void operator=(TeacherController &other) {}
public:
	static TeacherController *getInstance() {
		if (instance == nullptr) {
			instance = new TeacherController();
		}
		return instance;
	}
	void addTeacher() {
		Teacher data;
		INT id;
		cout << "Enter ID : " << endl;
		cin >> id;
		data.setId(id);
		string str;
		cout << "Enter Teacher Name : " << endl;
		cin >> str;
		data.setName(str);
		cout << "Enter Teacher Surname : " << endl;
		cin >> str;
		data.setSurname(str);
		cout << "Enter Phone Number : " << endl;
		cin >> str;
		data.setPhone_Number(str);
		cout << "Enter Voen : " << endl;
		cin >> str;
		data.setVoen(str);
		cout << "Enter SAlary : " << endl;
		cin >> str;
		data.setSalary(str);
		cout << "Enter Salary Payment : " << endl;
		bool pay;
		cin >> pay;
		data.setSalary_payment(pay);

		TeacControl->Teacher_Add(data);
	}
	void delete_Teacher_by_ID() {
		INT id;
		cout << "Enter Teacher ID for delete : " << endl;
		cin >> id;
		TeacControl->deleteTeacher_by_ID(id);
	}
	void Print_Teachers_List() {
		list<Teacher> t = TeacControl->Print_Teachers_List();
		for (Teacher &s : t) {
			cout << "{ Teacher ID      : " << s.getId() << endl;
			cout << "  Teacher Name    : " << s.getName() << endl;
			cout << "  Teacher Surname : " << s.getSurname() << endl;
			cout << "  Phone Number    : " << s.getPhone_Number() << endl;
			cout << "  Voen            : " << s.getVoen() << endl;
			cout << "  Teacher Salary  : " << s.getSalary() << endl;
			cout << "  Salary Payment  : ";
			if (s.getSalary_payment() == true) {
				cout << "Salary was Paid" << endl;
			}
			else {
				cout << "Salary Not Paid" << endl;
			}
			cout << " } " << endl;
		}
	}
	void Find_Teacher_By_ID() {
		INT id;
		cout << "Enter ID :" << endl;
		cin >> id;
		Teacher t = TeacControl->Find_Teacher_by_ID(id);

		cout << "{ Teacher ID      : " << t.getId() << endl;
		cout << "  Teacher Name    : " << t.getName() << endl;
		cout << "  Teacher Surname : " << t.getSurname() << endl;
		cout << "  Phone Number    : " << t.getPhone_Number() << endl;
		cout << "  Voen            : " << t.getVoen() << endl;
		cout << "  Teacher Salary  : " << t.getSalary() << endl;
		cout << "  Salary Payment  : ";
		if (t.getSalary_payment() == true) {
			cout << "Salary Payment" << endl;
		}
		else {
			cout << "Salary Not Payment" << endl;
		}
		cout << " } " << endl;
	}
	void Find_Teacher_by_Name() {
		string name;
		cout << "Enter name :" << endl;
		cin >> name;
		list<Teacher> temp = TeacControl->Find_Teacher_By_Name(name);
		for (Teacher t : temp) {
			cout << "{ Teacher ID      : " << t.getId() << endl;
			cout << "  Teacher Name    : " << t.getName() << endl;
			cout << "  Teacher Surname : " << t.getSurname() << endl;
			cout << "  Phone Number    : " << t.getPhone_Number() << endl;
			cout << "  Voen            : " << t.getVoen() << endl;
			cout << "  Teacher Salary  : " << t.getSalary() << endl;
			cout << "  Salary Payment  : ";
			if (t.getSalary_payment() == true) {
				cout << "Salary Payment" << endl;
			}
			else {
				cout << "Salary Not Payment" << endl;
			}
			cout << " } " << endl;
		}
	}
	void Export_List_Of_Teachers_To_CSV() {
		TeacControl->Export_List_Of_Teachers_To_CSV();
	}
	bool Set_Teachers_SalaryPayment_True(INT id) {
		return TeacControl->Set_Teachers_SalaryPayment_True(id);
	}
	void Salary_was_Paid() {
		list<Teacher> temp = TeacControl->Salary_was_Paid();
		for (Teacher t : temp) {
			cout << "{ Teacher ID             : " << t.getId() << endl;
			cout << "  Teacher Name           : " << t.getName() << endl;
			cout << "  Teacher Surname        : " << t.getSurname() << endl;
			cout << "  Phone Number           : " << t.getPhone_Number() << endl;
			cout << "  Voen                   : " << t.getVoen() << endl;
			cout << "  Teacher Salary         : " << t.getSalary() << endl << endl;
		}
	}
	void Salary_Not_Paid() {
		list<Teacher> temp = TeacControl->Salary_Not_Paid();
		for (Teacher t : temp) {
			cout << "{ Teacher ID      : " << t.getId() << endl;
			cout << "  Teacher Name    : " << t.getName() << endl;
			cout << "  Teacher Surname : " << t.getSurname() << endl;
			cout << "  Phone Number    : " << t.getPhone_Number() << endl;
			cout << "  Voen            : " << t.getVoen() << endl;
			cout << "  Teacher Salary  : " << t.getSalary() << endl << endl;
		}
	}
	bool Teachers_SalaryPayment(INT id) {
		return TeacControl->Teachers_SalaryPayment(id);
	}
};
TeacherController* TeacherController::instance = nullptr;

class PaymentController {
	StudentController* stdc;
	PaymentService* payment_service;
	static PaymentController* instance;
	PaymentController() {
		payment_service = PaymentService::getInstance();
		stdc = StudentController::getInstance();
	}
	~PaymentController() {}
	PaymentController(PaymentController &other) {}
	void operator=(PaymentController &other) {}
public:
	static PaymentController* getInstance() {
		if (instance == nullptr) {
			instance = new PaymentController();
		}
		return instance;
	}
	void add_Payment() {
		Payment p;
		INT id;
		Time time;
		time.day;
		time.month;
		time.year;
		cout << "Enter Payment ID : " << endl;
		cin >> id;
		p.setID(id);
		cout << "Enter Student ID : " << endl;
		cin >> id;
		p.setStudentID(id);
		cout << "Enter amount : " << endl;
		cin >> id;
		if (id != 0) {
			p.setAmount(id);
		}
		else throw exception("Wrong Amount");
		p.setTime(time);
		stdc->set_Student_Payment_True(p.getStudentID());
		if (stdc->set_Student_Payment_True(p.getStudentID()) == true) {
			payment_service->addPayment(p);
		}
		else throw exception("WRong Student ID !!");
	}
	void deletePayment() {
		INT id;
		cout << "Enter Payment ID :" << endl;
		cin >> id;
		payment_service->deletePayment(id);
	}
	void  Find_Payment_by_ID() {
		INT id;
		cout << "Enter Payment ID :" << endl;
		cin >> id;
		payment_service->Find_Payment_by_ID(id);
	}
	void Show_List_of_Payments() {
		list<Payment> p = payment_service->Show_List_of_Payments();
		for (Payment t : p) {
			cout << "Payment ID      -->   " << t.getID() << endl;
			cout << "Student ID      -->   " << t.getStudentID() << endl;
			cout << "Amount          -->   " << t.getAmount() << endl;
			cout << "Payment status  -->   ";
			if (stdc->Student_Payment(t.getStudentID()) == true) {
				cout << "Payment is paid by " << endl;
			}
			else {
				cout << "Payment is not paid by " << endl;
			}
			cout << "Payment date    -->   " << t.getTime() << endl;
		}

	}

	void ExportPayment_List_to_CSV() {
		payment_service->ExportPayment_List_to_CSV();
	}
};
PaymentController* PaymentController::instance = nullptr;

class SalaryController {
	Time t;
	TeacherController* teaccont;
	SalaryService* salary_cont;
	static SalaryController* instance;
	SalaryController() {
		salary_cont = SalaryService::getInstance();
		teaccont = TeacherController::getInstance();
	}
	~SalaryController() {}
	SalaryController(SalaryController &other) {}
	void operator=(SalaryController &other) {}
public:
	static SalaryController* getInstance() {
		if (instance == nullptr) {
			instance = new SalaryController();
		}
		return instance;
	}
	void addSalary() {
		Salary data;
		INT id;
		int n;
		t.day;
		t.month;
		t.year;
		cout << "Enter Salary Id :" << endl;
		cin >> id;
		data.setSalaryId(id);
		cout << "Enter Teacher ID : " << endl;
		cin >> id;
		data.setTEacherId(id);
		cout << "Enter Amount : " << endl;
		cin >> n;
		if (n != 0) {
			data.setAmoun(n);
		}
		else throw exception("Wrong amount, amount < 0");

		if (teaccont->Set_Teachers_SalaryPayment_True(data.getTeacherID()) == true) {
			salary_cont->addSalary(data);
		}
		else throw exception("Wrong teacher ID!!");
	}
	void deleteSalary() {
		INT id;
		cout << " Enter ID for delete salary :" << endl;
		cin >> id;
		salary_cont->deleteSalary(id);
	}
	void Find_Salary_by_ID() {
		INT id;
		cout << "Enter Salary ID for find :" << endl;
		cin >> id;
		salary_cont->Find_Salary_by_ID(id);
	}
	void Show_List_Of_Salary() {
		list<Salary> temp = salary_cont->Show_List_Of_Salary();
		for (Salary s : temp) {
			cout << "Salary ID : " << s.getSalaryID() << endl;
			cout << "Teacher ID : " << s.getTeacherID() << endl;
			cout << "Amount : " << s.getAmount() << endl;
			cout << "Salary Payment Status : ";
			if (teaccont->Teachers_SalaryPayment(s.getTeacherID())) {
				cout << "Salary was Paid " << endl;
			}
			else cout << "Salary was not Paid " << endl;
			cout << "Date of Salary Pay: " << s.getTime() << endl;
		}
	}
};
SalaryController* SalaryController::instance = nullptr;

class StudentInterface {
	StudentController *Stud;
	PaymentController *StudentPay;
public:
	StudentInterface() {
		Stud = StudentController::getInstance();
		StudentPay = PaymentController::getInstance();
	}
	void menu() {
		int a;
		while (true) {

			cout << "///////////////////////////////" << endl;
			cout << "                               " << endl;
			cout << "------STUDENT INTERFACE--------" << endl;
			cout << "                               " << endl;
			cout << "///////////////////////////////" << endl << endl;
			cout << "CHOOSE 1 TO  PAY -----------------:" << endl;
			cout << "CHOOSE 2 TO SHOW STUDENTS LIST----:" << endl;
			cout << "CHOOSE 3 TO EXPORT CSV -----------:" << endl;
			cout << "CHOOSE 4 TO SHOW PAYMENT LIST-------:" << endl;
			cout << "CHOOSE 5 TO IMPORT CSV-------:" << endl;
			cout << "CHOOSE 0 TO RETURN ---------------:" << endl;
			cin >> a;
			switch (a) {
			case 1: system("cls"); StudentPay->add_Payment();
				break;
			case 2:system("cls"); Stud->Print_Student_List();
				break;
			case 3: Stud->ExportStudent_List_to_CSV();
				break;
			case 4: system("cls"); StudentPay->Show_List_of_Payments();
				break;
			case 5: system("cls"); Stud->ImportStudent_List_to_CSV();
				break;
			case 0: return;
			default:
				system("cls");
				cout << "Wrong Choose,Try Again!!" << endl;
				break;
			}
		}
	}
};
class SalaryInterface {
	SalaryController* Salarycont;
public:
	SalaryInterface() {
		Salarycont = SalaryController::getInstance();
	}
	void menu() {
		int a;
		cout << "///////////////////////////////" << endl;
		cout << "                               " << endl;
		cout << "------SALARY INTERFACE---------" << endl;
		cout << "                               " << endl;
		cout << "///////////////////////////////" << endl << endl;
		cout << "CHOOSE 1 TO SHOW SALARY LIST -------------:" << endl;
		cout << "CHOOSE 2 TO EXPORT SALARIES TO CSV -------:" << endl;
		cin >> a;
		switch (a) {
		case 1: system("cls"); Salarycont->Show_List_Of_Salary();
			menu();
			break;
		case 2:system("cls");
			menu();
			break;
		default:
			system("cls");
			cout << "Wrong Choose,Try Again!!" << endl;
			menu();
			break;
		}
	}
};


class TeacherInterface {
	TeacherController *Stud;
	SalaryController* salary_cont;


public:
	TeacherInterface() {
		Stud = TeacherController::getInstance();
		salary_cont = SalaryController::getInstance();

	}
	void menu() {
		while (true) {
			int a;
			cout << "*******************************" << endl;
			cout << "                               " << endl;
			cout << "*******TEACHER INTERFACE*******" << endl;
			cout << "                               " << endl;
			cout << "*******************************" << endl << endl;
			cout << "CHOOSE 1 TO SHOW TEACHER SALARY BY ID -------:" << endl;
			cout << "CHOOSE 2 TO EXPORT LIST OF TEACHER TO CSV ---:" << endl;
			cout << "CHOOSE 3 TO SHOW TEACHER LIST ---------------:" << endl;
			cout << "CHOOSE 4 TO FIND SALARY BY ID ---------------:" << endl;
			cout << "CHOOSE 0 TO RETURN --------------------------:" << endl;
			cin >> a;
			switch (a) {
			case 1:system("cls"); Stud->Find_Teacher_By_ID();
				break;
			case 2:system("cls"); Stud->Export_List_Of_Teachers_To_CSV();
				break;
			case 3:system("cls"); Stud->Print_Teachers_List();
				break;
			case 4:system("cls"); salary_cont->Find_Salary_by_ID();
				break;
			case 0: return;
			default:
				system("cls");
				cout << "Wrong Choose,Try Again!!" << endl;
				break;
			}
		}
	}
};
class PaymentInterface {
	PaymentController* payment_cont;
public:
	PaymentInterface() {
		payment_cont = PaymentController::getInstance();
	}
	void menu() {
		while (true) {
			int a;
			cout << "///////////////////////////////" << endl;
			cout << "                               " << endl;
			cout << "------PAYMENT INTERFACE--------" << endl;
			cout << "                               " << endl;
			cout << "///////////////////////////////" << endl << endl;
			cout << "Choose 1 TO PAY  --------------------:" << endl;
			cout << "CHOOSE 2 TO SHOW STUDENTS LIST-------:" << endl;
			cout << "CHOOSE 3 TO EXPORT PAYMENTS TO CSV --:" << endl;
			cout << "CHOOSE 4 TO SHOW PAYMENT LIST-------:" << endl;
			cout << "CHOOSE 0 TO RETURN ------------------:" << endl;
			cin >> a;
			switch (a) {
			case 1: system("cls"); payment_cont->add_Payment();
				break;
			case 2:system("cls"); payment_cont->Show_List_of_Payments();
				break;
			case 3: system("cls"); payment_cont->ExportPayment_List_to_CSV();
				break;
			case 4: system("cls"); payment_cont->Show_List_of_Payments();
				break;
			case 0: return;
			default:
				system("cls");
				cout << "Wrong Choose,Try Again!!" << endl;
				break;
			}
		}
	}
};


class AccountantInterface { //Muhasib Interfeysi
	StudentController *Stud;
	TeacherController *TCC;
	PaymentController *StudentPay;
	SalaryController *TeacherSalary;
public:
	AccountantInterface() {
		Stud = StudentController::getInstance();
		TCC = TeacherController::getInstance();
		StudentPay = PaymentController::getInstance();
		TeacherSalary = SalaryController::getInstance();
	}
	void menu() {
		int a;
		cout << "**********************************" << endl;
		cout << "                                  " << endl;
		cout << "------Accountant interface--------" << endl;
		cout << "                                  " << endl;
		cout << "**********************************" << endl << endl;
		cout << "CHOOSE 1 TO  ADD NEW STUDENT  ---------------------------------:" << endl;
		cout << "CHOOSE 2 TO  DELETE  STUDENT  ---------------------------------:" << endl;
		cout << "CHOOSE 3 TO ADD NEW TEACHER   ---------------------------------:" << endl;
		cout << "CHOOSE 4 TO DELETE  TEACHER   ---------------------------------:" << endl;
		cout << "CHOOSE 5 TO SHOW STUDENTS LIST --------------------------------:" << endl;
		cout << "CHOOSE 6 TO SHOW LIST OF UNPAID STUDENTS ----------------------:" << endl;
		cout << "CHOOSE 7 TO SHOW TEACHERS LIST --------------------------------:" << endl;
		cout << "CHOOSE 8 TO FIND TEACHER BY ID --------------------------------:" << endl;
		cout << "CHOOSE 9 TO FIND STUDENT ID ----------------------------------:" << endl;
		cout << "CHOOSE 0  TO RETURN -------------------------------------------:" << endl;
		cin >> a;
		switch (a) {
		case 1: system("cls"); Stud->Student_Add();
			break;
		case 2:system("cls"); Stud->Delete_Student_By_ID();
			break;
		case 3:system("cls"); TCC->addTeacher();
			break;
		case 4:system("cls"); TCC->delete_Teacher_by_ID();
			break;
		case 5:system("cls"); Stud->Print_Student_List();
			break;
		case 6:system("cls"); Stud->StudentPayment_NotPaid();
			break;
		case 7:system("cls"); TCC->Print_Teachers_List();
			break;
		case 8:system("cls"); TCC->Find_Teacher_By_ID();
			break;
		case 9:system("cls"); Stud->Find_Student_By_ID();
			break;
		case 0:  return;
		default:
			system("cls");
			cout << "Wrong Choose,Try Again!!" << endl;
			break;
		}
	}
};
class ControlInterface {
	TeacherInterface* teacinter;
	StudentInterface* studinter;
	AccountantInterface* accint;
public:
	ControlInterface() {
		teacinter = new TeacherInterface();
		studinter = new StudentInterface();
		accint = new AccountantInterface();
	}
	void Accmenu() {
		while (true) {
			int a;
			cout << "CHOOSE 1 TO STUDENT MENU     : " << endl;
			cout << "CHOOSE 2 TO TEACHER MENU     : " << endl;
			cout << "CHOOSE 3 TO ACCOUNTANT MENU : " << endl;
			cout << "CHOOSE 0 TO EXIT : " << endl;
			cin >> a;
			switch (a) {
			case 1: system("cls"); studinter->menu();

				break;
			case 2: system("cls"); teacinter->menu();

				break;
			case 3: system("cls"); accint->menu();

				break;
			case 0: exit(0);
				break;
			default:
				cout << "Wrong choice , try again !" << endl;
			}
		}

	}
};




int main() {

	try {
		ControlInterface i;
		while (true) {
			i.Accmenu();
		}

	}
	catch (exception &e) {
		cout << e.what();
	}
	system("pause");
}


