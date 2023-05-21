#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Vertex {                       //клас вершини графа
	int neighbors_amount;            //кількість сусідніх для неї вершин
	int color;                       //Номер її кольору
	int number;                      //її номер
	int colored_neighbors;           //кількість зафарбованих у різні кольори сусідніх вершин
	//останній атрибут використовується, якщо обирається метод розфарбовки MRV
public:
	vector <Vertex*> neighbors;      //вектор покажчиків на вершини, сусідні даній, у загальному масиві самих вершин
	Vertex();                        //конструктор за замовчуванням
	void add_neighbor(Vertex*);      //додати покажчик-сусіда, що переданий як параметр, для даної вершини
	void set_color(int);             //задати колір
	void set_number(int);            //задати номер вершини
	int get_color();                 //отримати значення кольору
	int get_amount();                //отримати значення кількості сусідів
	int get_number();                //отримати значення номеру
	int get_colored();               //отримати кількість зайнятих сусідами кольорів. Використовується для MRV
	void add_colored_neighbor(int);  //додати зайнятий колір, якщо ще немає сусіда з таким кольором. Для MRV
};
class Solution {                     //абстрактний класс для вирішення задачі розфарбування
protected:
	Vertex* vert;                    // покажчик на загальний масив вершин графа
	int vert_size;                   //розмір масиву, тобто кількість вершин графа
public:
	Solution(int);                   // конструктор з параметром - кількістю вершин
	~Solution();                     //деструктор
	void enter_vertexes(bool**);     //внесення вершин у вектор відповідно до матриці, переданої як параметр
	virtual void solve() = 0;        // абстрактна функція, що фарбує граф
	void showBase();                 // винесення даних у файл для подальшого розгляду
	void paint(int, int&, bool);     //шукає колір для розфарбування обраної, та переданої як перший параметр, вершини
	void write_colors();             //записує у файл порядок кольорів; використовується для графічного розфарбування
};
class Greedy : public Solution {     //жадібний алгоритм
public:
	Greedy(int);                     //конструктор
	void solve();                    //реалізація абстрактного методу базового класу
};
class MRV : public Solution {        //MRV алгоритм
public:
	MRV(int);                        //конструктор
	void solve();                    //реалізація абстрактного методу базового класу
	void recursive_solve(vector<int>&, int&, int&, int&);  //рекурсивний вибір наступної для фарбування вершини
};
class Degree : public Solution {     //степеневий алгоритм
public:
	Degree(int);                     //конструктор
	void solve();                    //реалізація абстрактного методу базового класу
	void recursive_solve(vector<int>&, int&, int&, int&);  //рекурсивний вибір наступної для фарбування вершини

};
class MyPoint {                      //клас вершин на графічному представленні
	int x, y;                        //координати
public:
	MyPoint(int, int);               //конструктор, що приймає координати як параметри
	int get_x();                     //отримати х-координату
	int get_y();                     //отримати у-координату
};
