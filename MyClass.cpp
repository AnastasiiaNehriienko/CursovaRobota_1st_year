#include "MyClass.h"
using namespace std;
Vertex::Vertex() {                            //конструктор
	neighbors_amount = 0;                     //початкове задання при створенні відсутності сусідів,
	color = -1;                               //кольору -- за рядом можливих для розфарбування кольорів,
	number = 0;                               //номеру вершини -- за рядом можливих заданих номерів,
	colored_neighbors = 0;                    //та відсутність зайнятих сусідніми вершинами кольорів
}
void Vertex::add_neighbor(Vertex* neighbor) { //додати сусіда
	neighbors.push_back(neighbor);            //додати в кунець вектору покажчик на вершину-сусіда
	neighbors_amount++;                       //інкрементувати кількість сусідів для даної вершини
}
int Vertex::get_color() {                     
	return color;                             //повернути значення кольору
}
int Vertex::get_amount() {
	return neighbors_amount;                  //повернути кількість вершин-сусідів
}
int Vertex::get_number() {
	return number;                            //повернути номер, приписаний цій вершині
}
void Vertex::set_color(int n) {
	color = n;                                //задати колір значенням параметру
}
void Vertex::set_number(int n) {
	number = n;                               //задати номер значенням параметру
}
void Vertex::add_colored_neighbor(int col) {  //додати зайнятий сусідами колір
	for (int i = 0; i < neighbors_amount; ++i) { //прохід по іншим сусідам
		if (neighbors[i]->get_color()!=col)      //якщо новий зайнятий колір-параметр ще не зустрічався серед сусідів:
			colored_neighbors++;                 //збільшити кількість зайнятих кольорів
	}
}
int Vertex::get_colored() { 
	return colored_neighbors;                 //повернути значення кількості зайнятих сусідами кольорів
}
Solution::Solution(int n) {                   //констуктор
	vert = new Vertex[n];                     //створення динамічного масиву вершин графа
	vert_size = n;                            //збереження кількості вершин, що передані як параметр
}
Solution::~Solution() {                       //деструктор
	delete[]vert;                             //звільнення пам'яті, зайнятої під динамічний масив
}
void Solution::enter_vertexes(bool** matrix) {//внесення даних про вершини
	for (int i = 0; i < vert_size; ++i) {
		for (int j = 0; j < vert_size; ++j) {
			if (matrix[i][j])                 //якщо значення комірки true (тобто 1), то вершини з'єднані,
				vert[i].add_neighbor(vert + j);       //отже додаємо для вершини i вершину j як сусіда
		}
		vert[i].set_number(i + 1);            //кожній вершині задаємо її номер
	}
}
void Solution::showBase() {                   //виведення даних у файл
	ofstream OutFile("Outfile.txt", ios::app);                               //відкриваємо файл для дозапису
	for (int i = 0; i < vert_size; ++i) {                           
		OutFile << "Vertex " << vert[i].get_number() << "\n";                //записуємо дані про вершину: номер,
		OutFile << "Amount of neighbors: " << vert[i].get_amount() << "\n";  //кількість сусідів
		OutFile << "Color: " << vert[i].get_color()+1 << "\n";               //та колір, (починаючи з номеру 1)
	}
	OutFile.close();                          //закриваємо файл
}
void Solution::paint(int i, int&change_col, bool set=true) { //фарбує обрану вершину
	int free_color=0;                         //вільний колір, у який можна пофарбувати вершину
	bool found = false;                       //змінна, що показує, чи знайдено ще не зайнятий колір
	int j = 0;                                //змінна для коду кольору
	while (j < vert_size && !found) {         //перегляд кольорів по черзі
		if(set)
			change_col++;                         //інкрементація статистичних даних щодо кількості змін кольору загалом
		found = true;                         //вважаємо, що колір підходить
		for (int x = 0; x < vert[i].get_amount(); ++x) {  //переглядаємо усіх сусідів
			if (vert[i].neighbors[x]->get_color() == j)   //якщо вершиною-сусідом колір зайнятий
				found = false;                            //вказуємо, що колір не підходить
		}
		free_color = j;                       //заносимо номер кольору як потрібний
		j++;                                  //обираємо наступний колір
	}
	if (set)
		vert[i].set_color(free_color);            //записуємо колір, що підходить, в обрану вершину i
	else                         //якщо set==false використовуємо функцію тільки для пошуку кольору, а не запису
		change_col = free_color; //використовуємо змінну для передачі кольору
}
void Solution::write_colors() {               //запис порядку кольорів для графічного розфарбування
	ofstream colors_info("Colors.txt", ios::binary); //відкриваємо файл у форматі бінарного доступу
	for (int i = 0; i < vert_size; ++i) {            
		int c = vert[i].get_color();                 //записуємо колір кожної вершини через цикл
		colors_info << c << ' ';                     //через пробіл записуємо дані у файл
	}
	colors_info.close();                             //закриваємо файл
}
Greedy::Greedy(int n) :Solution(n) {}         //конструктор
void Greedy::solve() {                        //вирішення задачі розфарбування
	ofstream Statistics("Statistics.txt");    //відкриваємо файл для запису статистичних даних
	Statistics << "Greedy. Range of colored vertexes is next:\n"; //пояснення до даних щодо порядку зафарбування вершин
	int changing_color = 0;                   //скільки разів програма обирала колір для перевірки, чи він підходить
	for (int i = 0; i < vert_size; ++i) {             //вершини фарбуватимуться по порядку
		if(i==vert_size-1)                            //якщо остання вершина, вкінці не буде виведено стрілку
			Statistics << "Vertex " << i + 1 << "\n"; //виведення номеру вершини
		else
			Statistics << "Vertex " << i + 1 << "->";
		paint(i, changing_color);                    //обрання для конкретної вершини кольору для фарбування
	}
	Statistics << "Amount of times we changed the color to try: " << changing_color << "\n"; //статистичні дані
	Statistics.close();                              //закриваємо файл
}
MRV::MRV(int n) :Solution(n) {}               //конструктор
void MRV::solve() {                           //вирішення задачі розфарбування
	int calls = 0;                            //скільки разів спрацьовує рекурсія
	int changing_less = 0;                    //скільки разів змінюється вершина, обрана як найконфліктніша
	int changing_color = 0;                   //скільки разів програма обирала колір для перевірки, чи він підходить
	vector<int> nums;                         //вектор з номерами вершин у масиві
	for (int i = 0; i < vert_size; ++i) {
		nums.push_back(i);                    //заповнення вектору
	}
	ofstream Statistics("Statistics.txt");    //відкриваємо файл для запису статистичних даних
	Statistics << "MRV. Range of colored vertexes is next:\n";  //пояснення до даних щодо порядку зафарбування вершин
	Statistics.close();                       //закриваємо файл
	recursive_solve(nums, calls, changing_less, changing_color);//викликаємо рекурсію для множини вершин першого параметру
	ofstream Stat("Statistics.txt", ios::app);//відкриваємо наново файл, тепер у режимі дозапису
	Stat << "Amount of recurses: " << calls << ", amount of times we changed vertex choice: " << changing_less;
	Stat << ", amount of times we changed the color to try: " << changing_color << "\n"; //статистичні дані
	Stat.close();                             //закриваємо файл
}
void MRV::recursive_solve(vector<int>& nums, int& calls, int& change, int& change_col) { //рекурсивне вирішення
	calls++;                                  //інкрементуємо кількість рекурсивних викликів
	ofstream Statistics("Statistics.txt", ios::app);            //відкриваємо для дозапису статистичний файл
	if (nums.size() == 1) {                   //якщо вершина для розгляду одна
		change++;                             //інкрементуємо обрання нової вершини, що підходить для розфарбування
		paint(nums[0], change_col);           //фарбуємо вершину, обираючи потрібний колір
		Statistics << "Vertex " << nums[0] + 1 << "\n"; //вносимо як останню зафарбовану вершину у порядок фарбування
		return;                               //виходимо із функції
	}
	else {
		int less_colored = 0;                 //беремо мінімальний номер вершини як потенційну для розфарбування
		change++;                             //інкрементуємо кількість обрань вершини під фарбування
		for (int i = 1; i < nums.size(); ++i) {
			if (vert[nums[i]].get_colored() > vert[nums[less_colored]].get_colored()) { //за кількістю сусідніх кольорів
				less_colored = i;             //якщо вершина має більше, задаємо їїї як потенційний вибір
				change++;                     //інкрементуємо кількість обрань вершини під фарбування
			}
		}
		int needed_amount = vert[nums[less_colored]].get_amount(); //кількість сусідів вершини, яку фарбуватимемо
		int needed_color;                                          //колір, у який фарбуватимемо
		paint(nums[less_colored], needed_color, false);//шукаємо колір, але не записуємо у вершину
		for (int i = 0; i < needed_amount; ++i) {                  //для кожного сусіда
			vert[nums[less_colored]].neighbors[i]->add_colored_neighbor(needed_color); //додаємо зайнятий колір сусіда
		}
		paint(nums[less_colored], change_col);                     //фарбуємо вершину
		Statistics << "Vertex " << nums[less_colored] + 1 << "->"; //вносимо у порядок фарбування
		nums.erase(nums.begin() + less_colored);                   //видалення з розгляду розфарбованої вершини
		Statistics.close();                                        //закриття файлу
		recursive_solve(nums, calls, change, change_col);          //рекурсивний виклик для нерозфарбованих вершин
	}
}
Degree::Degree(int n) :Solution(n) {}         //конструктор
void Degree::solve() {                        //вирішення задачі розфарбування
	vector<int> nums;                         //вектор з номерами вершин у масиві
	for (int i = 0; i < vert_size; ++i) {
		nums.push_back(i);                    //заповнення вектору
	}
	ofstream Statistics("Statistics.txt");    //відкриваємо файл для запису статистичних даних
	Statistics << "Degree. Range of colored vertexes is next:\n"; //пояснення до даних щодо порядку зафарбування вершин
	Statistics.close();                       //закриваємо файл
	int calls = 0;                            //скільки разів спрацьовує рекурсія
	int changing_max = 0;                     //скільки разів змінюється вершина, обрана як вершина з найбільшим степенем
	int changing_color = 0;                   //скільки разів програма обирала колір для перевірки, чи він підходить
	recursive_solve(nums, calls, changing_max, changing_color);   //рекурсивний виклик для нерозфарбованих вершин
	ofstream Stat("Statistics.txt", ios::app);//відкриваємо наново файл, тепер у режимі дозапису
	Stat << "Amount of recurses: " << calls << ", amount of times we changed vertex choice: " << changing_max;
	Stat << ", amount of times we changed the color to try: " << changing_color << "\n";   //статистичні дані
	Stat.close();                             //закриваємо файл
}
void Degree::recursive_solve(vector<int>& nums, int& calls, int& change, int&change_col) { //рекурсивне вирішення
	calls++;                                  //інкрементуємо кількість рекурсивних викликів
	ofstream Statistics("Statistics.txt", ios::app);     //відкриваємо для дозапису статистичний файл
	if (nums.size() == 1) {                   //якщо вершина для розгляду одна
		change++;                             //інкрементуємо обрання нової вершини, що підходить для розфарбування
		paint(nums[0], change_col);           //фарбуємо вершину, обираючи потрібний колір
		Statistics << "Vertex " << nums[0]+1 << "\n";    //вносимо як останню зафарбовану вершину у порядок фарбування
		return;                               //виходимо із функції
	}
	int max = 0;                              //беремо мінімальний номер вершини як потенційну для розфарбування
	change++;                                 //інкрементуємо кількість обрань вершини під фарбування
	for (int i = 1; i < nums.size(); ++i) {
		if (vert[nums[i]].get_amount() > vert[nums[max]].get_amount()) {  //за кількістю сусідів
			max = i;                          //якщо вершина має більше, задаємо їїї як потенційний вибір
			change++;                         //інкрементуємо кількість обрань вершини під фарбування
		}
	}
	paint(nums[max], change_col);             //фарбуємо вершину
	Statistics << "Vertex " << nums[max] + 1 << "->";   //вносимо у порядок фарбування
	nums.erase(nums.begin() + max);           //видалення з розгляду розфарбованої вершини
	Statistics.close();                       //закриття файлу
	recursive_solve(nums, calls, change, change_col);   //рекурсивний виклик для нерозфарбованих вершин
}
MyPoint::MyPoint(int x0, int y0) {    //конструктор
	x = x0;                           //задання х-координати
	y = y0;                           //задання у-координати
}
int MyPoint::get_x() {
	return x;                         //повернути х-координату
}
int MyPoint::get_y() {
	return y;                         //повернути у-координату
}
