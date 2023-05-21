#pragma once
#include "MyClass.h"

namespace CursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Threading;


	public ref class CourseForm : public System::Windows::Forms::Form
	{
	public:
		CourseForm(void);

	protected:
		~CourseForm();
	private: System::Windows::Forms::Panel^ Back;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	protected:

	private: System::Windows::Forms::RichTextBox^ ResultBox;
	private: System::Windows::Forms::GroupBox^ Choice;
	private: System::Windows::Forms::RadioButton^ DegreeButton;
	private: System::Windows::Forms::RadioButton^ MRVButton;
	private: System::Windows::Forms::RadioButton^ GreedyButton;
	private: System::Windows::Forms::Button^ AcceptButton;
	private: System::Windows::Forms::Label^ MatrixLabel;
	private: System::Windows::Forms::Label^ DimensionLabel;
	private: System::Windows::Forms::DataGridView^ Matrix;
	private: System::Windows::Forms::NumericUpDown^ Dimension;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CourseForm::typeid));
			this->Back = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->ResultBox = (gcnew System::Windows::Forms::RichTextBox());
			this->Choice = (gcnew System::Windows::Forms::GroupBox());
			this->DegreeButton = (gcnew System::Windows::Forms::RadioButton());
			this->MRVButton = (gcnew System::Windows::Forms::RadioButton());
			this->GreedyButton = (gcnew System::Windows::Forms::RadioButton());
			this->AcceptButton = (gcnew System::Windows::Forms::Button());
			this->MatrixLabel = (gcnew System::Windows::Forms::Label());
			this->DimensionLabel = (gcnew System::Windows::Forms::Label());
			this->Matrix = (gcnew System::Windows::Forms::DataGridView());
			this->Dimension = (gcnew System::Windows::Forms::NumericUpDown());
			this->Back->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->Choice->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dimension))->BeginInit();
			this->SuspendLayout();
			// 
			// Back
			// 
			this->Back->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(164)));
			this->Back->Controls->Add(this->pictureBox);
			this->Back->Controls->Add(this->ResultBox);
			this->Back->Controls->Add(this->Choice);
			this->Back->Controls->Add(this->AcceptButton);
			this->Back->Controls->Add(this->MatrixLabel);
			this->Back->Controls->Add(this->DimensionLabel);
			this->Back->Controls->Add(this->Matrix);
			this->Back->Controls->Add(this->Dimension);
			this->Back->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Back->Location = System::Drawing::Point(0, 0);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(941, 624);
			this->Back->TabIndex = 1;
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pictureBox->Location = System::Drawing::Point(320, 30);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(300, 300);
			this->pictureBox->TabIndex = 10;
			this->pictureBox->TabStop = false;
			this->pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CourseForm::pictureBox_Paint);
			// 
			// ResultBox
			// 
			this->ResultBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->ResultBox->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResultBox->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ResultBox->Location = System::Drawing::Point(636, 28);
			this->ResultBox->Name = L"ResultBox";
			this->ResultBox->Size = System::Drawing::Size(280, 534);
			this->ResultBox->TabIndex = 9;
			this->ResultBox->Text = L"";
			// 
			// Choice
			// 
			this->Choice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->Choice->Controls->Add(this->DegreeButton);
			this->Choice->Controls->Add(this->MRVButton);
			this->Choice->Controls->Add(this->GreedyButton);
			this->Choice->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Choice->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Choice->Location = System::Drawing::Point(319, 367);
			this->Choice->Name = L"Choice";
			this->Choice->Size = System::Drawing::Size(274, 202);
			this->Choice->TabIndex = 8;
			this->Choice->TabStop = false;
			this->Choice->Text = L"Choose a solution:";
			// 
			// DegreeButton
			// 
			this->DegreeButton->AutoSize = true;
			this->DegreeButton->Location = System::Drawing::Point(6, 151);
			this->DegreeButton->Name = L"DegreeButton";
			this->DegreeButton->Size = System::Drawing::Size(117, 44);
			this->DegreeButton->TabIndex = 2;
			this->DegreeButton->TabStop = true;
			this->DegreeButton->Text = L"Degree";
			this->DegreeButton->UseVisualStyleBackColor = true;
			// 
			// MRVButton
			// 
			this->MRVButton->AutoSize = true;
			this->MRVButton->Location = System::Drawing::Point(6, 100);
			this->MRVButton->Name = L"MRVButton";
			this->MRVButton->Size = System::Drawing::Size(107, 44);
			this->MRVButton->TabIndex = 1;
			this->MRVButton->TabStop = true;
			this->MRVButton->Text = L"MRV";
			this->MRVButton->UseVisualStyleBackColor = true;
			// 
			// GreedyButton
			// 
			this->GreedyButton->AutoSize = true;
			this->GreedyButton->Location = System::Drawing::Point(6, 54);
			this->GreedyButton->Name = L"GreedyButton";
			this->GreedyButton->Size = System::Drawing::Size(118, 44);
			this->GreedyButton->TabIndex = 0;
			this->GreedyButton->TabStop = true;
			this->GreedyButton->Text = L"Greedy";
			this->GreedyButton->UseVisualStyleBackColor = true;
			// 
			// AcceptButton
			// 
			this->AcceptButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->AcceptButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AcceptButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->AcceptButton->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AcceptButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->AcceptButton->Location = System::Drawing::Point(69, 529);
			this->AcceptButton->Name = L"AcceptButton";
			this->AcceptButton->Size = System::Drawing::Size(150, 57);
			this->AcceptButton->TabIndex = 6;
			this->AcceptButton->Text = L"Accept";
			this->AcceptButton->UseVisualStyleBackColor = false;
			this->AcceptButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CourseForm::AcceptButton_MouseClick);
			this->AcceptButton->MouseLeave += gcnew System::EventHandler(this, &CourseForm::AcceptButton_MouseLeave);
			this->AcceptButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CourseForm::AcceptButton_MouseMove);
			// 
			// MatrixLabel
			// 
			this->MatrixLabel->AutoSize = true;
			this->MatrixLabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 22.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MatrixLabel->Location = System::Drawing::Point(32, 147);
			this->MatrixLabel->Name = L"MatrixLabel";
			this->MatrixLabel->Size = System::Drawing::Size(115, 45);
			this->MatrixLabel->TabIndex = 5;
			this->MatrixLabel->Text = L"Matrix";
			// 
			// DimensionLabel
			// 
			this->DimensionLabel->AutoSize = true;
			this->DimensionLabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 22.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DimensionLabel->Location = System::Drawing::Point(32, 28);
			this->DimensionLabel->Name = L"DimensionLabel";
			this->DimensionLabel->Size = System::Drawing::Size(161, 45);
			this->DimensionLabel->TabIndex = 4;
			this->DimensionLabel->Text = L"Dimension";
			// 
			// Matrix
			// 
			this->Matrix->AllowUserToAddRows = false;
			this->Matrix->AllowUserToDeleteRows = false;
			this->Matrix->AllowUserToResizeColumns = false;
			this->Matrix->AllowUserToResizeRows = false;
			this->Matrix->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->Matrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Matrix->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(164)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->NullValue = L"0";
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)), static_cast<System::Int32>(static_cast<System::Byte>(52)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Matrix->DefaultCellStyle = dataGridViewCellStyle1;
			this->Matrix->GridColor = System::Drawing::Color::WhiteSmoke;
			this->Matrix->Location = System::Drawing::Point(12, 195);
			this->Matrix->MultiSelect = false;
			this->Matrix->Name = L"Matrix";
			this->Matrix->ReadOnly = true;
			this->Matrix->RowHeadersVisible = false;
			this->Matrix->RowHeadersWidth = 51;
			this->Matrix->RowTemplate->Height = 24;
			this->Matrix->Size = System::Drawing::Size(295, 305);
			this->Matrix->TabIndex = 3;
			this->Matrix->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CourseForm::Matrix_CellClick);
			// 
			// Dimension
			// 
			this->Dimension->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->Dimension->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Dimension->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Dimension->Location = System::Drawing::Point(69, 76);
			this->Dimension->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->Dimension->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Dimension->Name = L"Dimension";
			this->Dimension->Size = System::Drawing::Size(78, 45);
			this->Dimension->TabIndex = 2;
			this->Dimension->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Dimension->ValueChanged += gcnew System::EventHandler(this, &CourseForm::Dimension_ValueChanged);
			// 
			// CourseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(941, 624);
			this->Controls->Add(this->Back);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CourseForm";
			this->Text = L"CourseForm";
			this->Load += gcnew System::EventHandler(this, &CourseForm::CourseForm_Load);
			this->Back->ResumeLayout(false);
			this->Back->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->Choice->ResumeLayout(false);
			this->Choice->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dimension))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: bool fill_vertexes;   //чи потрібно додавати у малюнок кольори
private: System::Void CourseForm_Load(System::Object^ sender, System::EventArgs^ e);  //при завантаженні системи
private: System::Void Dimension_ValueChanged(System::Object^ sender, System::EventArgs^ e);  //зміна значення розмірності
private: System::Void Matrix_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e); //натискання комірки матриці
private: System::Void AcceptButton_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); //наведення мишею на кнопку Accept
private: System::Void AcceptButton_MouseLeave(System::Object^ sender, System::EventArgs^ e);  //після наведення мишею на кнопку Accept
private: System::Void AcceptButton_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);  //натискання на кнопку Accept
private: void find_solution(bool**, int);  //вирішення задачі розфарбування
private: void add_matrix(bool**, int);     //запис даних із матриці графічного інтерфейсу у створену структуру
private: void delete_matrix(bool**, int);  //видалення динамічної структури, створеної для збереження матриці суміжності
private: System::Void pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);  //перемальовка малюнку
};
}
