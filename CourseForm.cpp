#include "CourseForm.h"
#include "Windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CursovaRobota::CourseForm form;
	Application::Run(% form);
    return 0;
}

CursovaRobota::CourseForm::CourseForm(void)
{
		InitializeComponent();
}

CursovaRobota::CourseForm::~CourseForm()
{
	if (components)
	{
		delete components;
	}
}

System::Void CursovaRobota::CourseForm::CourseForm_Load(System::Object^ sender, System::EventArgs^ e)  //при завантаженні
{
	Matrix->ColumnCount = 1;       //початкова матриця 1х1
	Matrix->RowCount = 1;
	Matrix->AutoResizeColumns();   //зміна розміру комірки, підігнана під значення
	fill_vertexes = false;         //розфарбування наразі не потрібне
	ofstream cleanFile("Outfile.txt");   //для нового запуску програми записуватимемо файл, очистивши попередню роботу
	cleanFile << "Start!\n";             //початковий нопис
	cleanFile.close();                   //закриття файлу
	return System::Void();
}

System::Void CursovaRobota::CourseForm::Dimension_ValueChanged(System::Object^ sender, System::EventArgs^ e) //зміна розмірності
{
	int dim = Convert::ToSingle(Dimension->Value);              //число з плаваючою крапкою приводимо до нижньої межі
	Matrix->ColumnCount = dim;                                  //зміна кількості стовпців відповідно до зміни розмірності
	Matrix->RowCount = dim;                                     //зміна кількості рядків відповідно до зміни розмірності
	Dimension->Value = Convert::ToDecimal(dim);                 //задаємо приведене число у розмірність
	Matrix->AutoResizeColumns();                                //зміна розміру комірки, підігнана під значення
	pictureBox->Invalidate();                                   //оновити малюнок
	return System::Void();
}

System::Void CursovaRobota::CourseForm::Matrix_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)  //натискання комірки матриці
{
	if (Matrix->CurrentCell->ColumnIndex != Matrix->CurrentCell->RowIndex) {                    //якщо не головна діагональ
		if (Convert::ToInt32(Matrix->CurrentCell->Value) == 1) {                                //якщо зараз значення дорівнює 1
			Matrix->CurrentCell->Value = 0;                                                     //змінити на 0 дану комірку
			Matrix[Matrix->CurrentCell->RowIndex, Matrix->CurrentCell->ColumnIndex]->Value = 0; //змінити на 0 симетричну комірку
		}
		else {                                                                                  //якщо зараз значення дорівнює 0
			Matrix->CurrentCell->Value = 1;                                                     //змінити на 1 дану комірку
			Matrix[Matrix->CurrentCell->RowIndex, Matrix->CurrentCell->ColumnIndex]->Value = 1; //змінити на 1 симетричну комірку
		}
	}
	pictureBox->Invalidate();     //оновити малюнок
	return System::Void();
}

System::Void CursovaRobota::CourseForm::AcceptButton_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) //переведення курсора на кнопку
{
	AcceptButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
		static_cast<System::Int32>(static_cast<System::Byte>(164)));   //зміна кольору кнопки
	AcceptButton->ForeColor = System::Drawing::Color::Black;           //зміна кольору напису
	return System::Void();
}

System::Void CursovaRobota::CourseForm::AcceptButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) //переведення курсора з кнопки
{
	AcceptButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
		static_cast<System::Int32>(static_cast<System::Byte>(52)));   //зміна кольору кнопки на початковий
	AcceptButton->ForeColor = System::Drawing::Color::WhiteSmoke;     //зміна кольору напису на початковий
	return System::Void();
}

System::Void CursovaRobota::CourseForm::AcceptButton_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)  //натискання кнопки
{
	int dim = Convert::ToInt32(Dimension->Value);   //розмірність
	bool** matrix = new bool* [dim];                //Покажчик на масив покажчиків
	for (int i = 0; i < dim; ++i) {
		matrix[i] = new bool[dim];                  //динамічні масиви
	}
	add_matrix(matrix, dim);       //запис даних із матриці графічного інтерфейсу у створену структуру
	find_solution(matrix, dim);    //вирішення задачі розфарбування
	delete_matrix(matrix, dim);    //видалення динамічної структури, створеної для збереження матриці суміжності
	pictureBox->Invalidate();      //оновити малюнок
	return System::Void();
}
void CursovaRobota::CourseForm::find_solution(bool** matr, int dim)  //вирішення задачі розфарбування
{
	if (GreedyButton->Checked) {                                     //якщо обрано жадібний метод
		ofstream OutFile("Outfile.txt", ios::app);                   //відкрити файл на дозапис
		OutFile << "Greedy:\n";                                      //інформуючий напис щодо обраного методу
		OutFile.close();                                             //закрити файл
		Greedy solving(dim);                                         //створення об'єкту
		solving.enter_vertexes(matr);                                //внесення вершин графа
		solving.solve();                                             //вирішити задачу розфарбування
		solving.showBase();                                          //виведення у файл даних
		StreamReader^ file = File::OpenText("Statistics.txt");       //відкрити файл
		ResultBox->Text = file->ReadToEnd();                         //читання з файлу у вікно користувацького інтерфейсу
		file->Close();                                               //закрити файл
		solving.write_colors();                                      //запис кольорів усіх вершин
		fill_vertexes = true;                                        //дозвіл на зафарбування вершин кольорами
	}
	else if (MRVButton->Checked) {                                   //якщо обрано MRV метод
		ofstream OutFile("Outfile.txt", ios::app);                   //відкрити файл на дозапис
		OutFile << "MRV:\n";                                         //інформуючий напис щодо обраного методу
		OutFile.close();                                             //закрити файл
		MRV solving(dim);                                            //створення об'єкту
		solving.enter_vertexes(matr);                                //внесення вершин графа
		solving.solve();                                             //вирішити задачу розфарбування
		solving.showBase();                                          //виведення у файл даних
		StreamReader^ file = File::OpenText("Statistics.txt");       //відкрити файл
		ResultBox->Text = file->ReadToEnd();                         //читання з файлу у вікно користувацького інтерфейсу
		file->Close();                                               //закрити файл
		solving.write_colors();                                      //запис кольорів усіх вершин
		fill_vertexes = true;                                        //дозвіл на зафарбування вершин кольорами
	}
	else if (DegreeButton->Checked) {                                //якщо обраностепеневий метод
		ofstream OutFile("Outfile.txt", ios::app);                   //відкрити файл на дозапис
		OutFile << "Degree:\n";                                      //інформуючий напис щодо обраного методу
		OutFile.close();                                             //закрити файл
		Degree solving(dim);                                         //створення об'єкту
		solving.enter_vertexes(matr);                                //внесення вершин графа
		solving.solve();                                             //вирішити задачу розфарбування
		solving.showBase();                                          //виведення у файл даних
		StreamReader^ file = File::OpenText("Statistics.txt");       //відкрити файл
		ResultBox->Text = file->ReadToEnd();                         //читання з файлу у вікно користувацького інтерфейсу
		file->Close();                                               //закрити файл
		solving.write_colors();                                      //запис кольорів усіх вершин
		fill_vertexes = true;                                        //дозвіл на зафарбування вершин кольорами
	}
	else {                                                           //якщо не обрано метод
		ResultBox->Text = "Choose a solution!";                      //вивести відповідне повідомлення
	}
}

void CursovaRobota::CourseForm::add_matrix(bool** matr, int dim)  //запис даних із матриці графічного інтерфейсу у створену структуру
{
	ofstream OutFile("Outfile.txt", ios::app);                              //відкрити файл
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			matr[i][j] = Convert::ToBoolean(Matrix[i, j]->Value); //занесення даних з матриці, введеної користувачем, у динамічну структуру
			OutFile << matr[i][j] << " ";                         //збереження матриці у файл
		}
		OutFile << endl;                                          //завершення введення у файл матриці
	}
	OutFile.close();                                              //закрити файл
}

void CursovaRobota::CourseForm::delete_matrix(bool** matr, int dim)
{   //видалення динамічної структури, створеної для збереження матриці суміжності
	for (int i = 0; i < dim; ++i)
		delete[]matr[i];
	delete[]matr;
}

System::Void CursovaRobota::CourseForm::pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)  //перемалювання малюнку
{
	int colors[10][3] = { {226, 15, 15}, {84, 243, 55}, {41, 12, 186}, {242, 7, 170}, {242, 239, 7}, {242, 112, 7}, {198, 7, 242}, {33, 238, 216}, {22, 81, 65}, {120, 29, 53} };
	                                                                      //кольори у форматі ARGB для розфарбування графу
	vector<MyPoint>points;                                                //вектор точок -- координат вершин на малюнку 
	vector<int> numbers;                                                  //вектор для запису номерів кольорів для вершин                               
	int amount = Convert::ToInt32(Dimension->Value);                      //кількість вершин
	double dif = 2 * 3.14 / amount;                                       //кут зсуву
	System::Drawing::Font^ fnt = gcnew System::Drawing::Font("Arial", 8); //шрифт для малювання написів
	Pen^ myPen = gcnew Pen(Color::Black);                                 //ручка для малювання
    SolidBrush^ brsh_ellipse = gcnew SolidBrush(Color::Black);            //замальовка для вершин
	SolidBrush^ brsh = gcnew SolidBrush(Color::Black);                    //замальовка прямих
	int x0 = 95, y0 = 110;                                                //координати початкової точки посередині
	double angle = 0;                                                     //початковий кут відхилення
	if(fill_vertexes){                                                    //якщо потрібно розфарбувати
		ifstream f("Colors.txt", ios::binary);                            //відкрити файл з даними про кольори
		int number;                                                       //змінна для запмсу номеру
		for (int i = 0; i < amount; ++i) {
			f >> number;                                                  //запис номеру
			numbers.push_back(number);                                    //додання у вектор
		}
		f.close();                                                        //закрити файл
}
	if (amount == 1) {                                                    //якщо вершина одна
		String^ str = "V1";                                               //текст підпису вершини
		e->Graphics->DrawEllipse(myPen, x0, y0, 20, 20);                  //намалювати посередині вершину
		e->Graphics->FillEllipse(brsh_ellipse, x0, y0, 20, 20);           //заповнити початковим(чорним) кольором
		e->Graphics->DrawString(str, fnt, brsh, Convert::ToSingle(x0 + 20), Convert::ToSingle(y0 + 20));  //зробити напис
		if (fill_vertexes) {                                              //якщо потрібно розфарбувати
			Thread::Sleep(150);
			brsh_ellipse = gcnew SolidBrush(Color::FromArgb(colors[numbers[0]][0], colors[numbers[0]][1], colors[numbers[0]][2])); //задання нового кольору
			e->Graphics->FillEllipse(brsh_ellipse, x0, y0, 20, 20);    //зафарбування новим кольором
		}
		MyPoint p(x0 + 10, y0 + 10);  //створення об'єкту з координатами центру кола як координат вершини
		points.push_back(p);          //додавання до вектору
	}
	else {                                                                //якщо вершин декілька
		for (int i = 0; i < amount; ++i) {
			String^ str = "V" + Convert::ToString(i + 1);                 //текст підпису вершини відповідно до номеру
			int x = x0 + 90 * cos(angle);                                 //координати із урахуванням кута
			int y = y0 + 90 * sin(angle);                                 //...
			e->Graphics->DrawEllipse(myPen, x, y, 20, 20);                //намалювати вершину
			e->Graphics->FillEllipse(brsh_ellipse, x, y, 20, 20);         //заповнити початковим(чорним) кольором
			e->Graphics->DrawString(str, fnt, brsh, Convert::ToSingle(x + 20), Convert::ToSingle(y + 20)); //зробити напис
			angle += dif;                                                 //змінити кут на різницю, задану відповідно до кількості
			if (fill_vertexes) {                                          //якщо потрібно розфарбувати
				brsh_ellipse = gcnew SolidBrush(Color::FromArgb(colors[numbers[i]][0], colors[numbers[i]][1], colors[numbers[i]][2])); //задання нового кольору
				e->Graphics->FillEllipse(brsh_ellipse, x, y, 20, 20);     //зафарбування новим кольором
				Thread::Sleep(150);
			}
			MyPoint p(x + 10, y + 10);   //створення об'єкту з координатами центру кола як координат вершини
			points.push_back(p);         //додавання до вектору
			Thread::Sleep(50);
		}
	}
	for (int i = 0; i < amount-1; ++i) {
		for (int j = i+1; j < amount; ++j) {    //перегляд тільки частини матриці, що знаходиться вище головної діагоналі
			if (Convert::ToBoolean(Matrix[i, j]->Value)) {     //якщо є з'єднання вершин
				e->Graphics->DrawLine(myPen, points[i].get_x(), points[i].get_y(), points[j].get_x(), points[j].get_y()); //намалювати пряму між ними
			}
		}
	}
	fill_vertexes = false;   //повернути до початкового значення
	return System::Void();
}

