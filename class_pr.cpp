#include <iostream>
#include <string>
using namespace std;

class ProgrammingLanguage {
public: //public потому что используется метод вне класса --> getDate()
    int year;
    string tipiz;
    string creator;
    ProgrammingLanguage(int y, string t, string c) { //конструктор класса, определяет свойства, инициализирует значения(присвоение начального значения)
        year = y;
        tipiz = t;
        creator = c;
    }
    //инкапсуляция
    void getData() {
        cout << year << " " << "года выпуска" << ", " << tipiz << " " << "типизация" << ", " << "создал - " << creator << endl;
    }
    //полиморфизм | virtual позволяет переопределять функцию классам наследникам |одно имя-несколько разных действий|
    virtual void printInfo() {
        cout << "Это ЯП" << endl;
    }
};
//наследование :
class JavaScript : public ProgrammingLanguage {
public:
    JavaScript() : ProgrammingLanguage(1995, "динамическая", "Брендан Эйх") {}
    void printInfo() override { //override - явно переопределяем функцию
        cout << "Это JavaScript" << endl; //переопределение функции - полиморфизм
    }
};

class Java : public ProgrammingLanguage {
public:
    Java() : ProgrammingLanguage(1995, "строгая", "Джеймс Гослинг") {}
    void printInfo() override {
        cout << "Это Java" << endl;
    }
};

class Cpp : public ProgrammingLanguage {
public:
    Cpp() : ProgrammingLanguage(1983, "строгая", "Бьёрн Страуструп") {}
    void printInfo() override {
        cout << "Это C++" << endl;
    }
};

class TypeScript : public ProgrammingLanguage {
public:
    TypeScript() : ProgrammingLanguage(2012, "строгая", "Андерс Хейлсберг") {}
    void printInfo() override {
        cout << "Это TypeScript" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    ProgrammingLanguage* languages[] = { new JavaScript(), new TypeScript(), new Java(), new Cpp() }; //каждый элемент является указателем на объект своего класса, наследуемого от ProgrammingLanguage
    //new - создает новый экземпляр класса и возвращает указатель на него
    int size = sizeof(languages) / sizeof(languages[0]); // получаем количество элементов в массиве, путем деления общего размера на размер одного элемента

    for (int i = 0; i < size; i++) {
        languages[i]->printInfo(); //методы вызываются по указателям с помощью оператора ->
        languages[i]->getData();
    }
}