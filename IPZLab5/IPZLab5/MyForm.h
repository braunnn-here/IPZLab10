#pragma once

namespace IPZLab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(392, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(417, 393);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(141, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обчислити Завдання 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(141, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(170, 48);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Обчислити Завдання 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1020, 498);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();

		array<double>^ forces = { 10.0, 20.0, 30.0, 40.0, 50.0 }; // Приклад значень F
		double charge = 5.0; // Значення q

		dataGridView1->ColumnCount = 2;
		dataGridView1->Columns[0]->Name = "Сила F (Н)";
		dataGridView1->Columns[1]->Name = "Напруженість E (Н/Кл)";

		for (int i = 0; i < forces->Length; i++)
		{
			double F = forces[i];
			double E = F / charge; // Обчислення напруженості

			// Додавання рядка до DataGridView
			dataGridView1->Rows->Add(gcnew cli::array<System::Object^> { F, E });
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const int N = 5; // Кількість рядків
		const int M = 4; // Кількість стовпців

		// Початкова матриця A
		array<array<int>^>^ A = gcnew array<array<int>^>(N);
		Random^ rand = gcnew Random();
		for (int i = 0; i < N; i++)
		{
			A[i] = gcnew array<int>(M);
			for (int j = 0; j < M; j++)
			{
				A[i][j] = rand->Next(-50, 50); // Генерація випадкових чисел
			}
		}

		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();

		dataGridView1->ColumnCount = M;
		for (int j = 0; j < M; j++)
		{
			dataGridView1->Columns[j]->Name = "Стовпець " + (j + 1).ToString();
		}

		// Впорядкування кожного стовпця за зростанням
		for (int j = 0; j < M; j++)
		{
			array<int>^ column = gcnew array<int>(N);
			for (int i = 0; i < N; i++)
			{
				column[i] = A[i][j];
			}
			Array::Sort(column);
		
			for (int i = 0; i < N; i++)
			{
				A[i][j] = column[i];
			}
		}
	
		for (int i = 0; i < N; i++)
		{
			array<System::Object^>^ row = gcnew array<System::Object^>(M);
			for (int j = 0; j < M; j++)
			{
				row[j] = A[i][j];
			}
			dataGridView1->Rows->Add(row);
		}
	}

};
}
