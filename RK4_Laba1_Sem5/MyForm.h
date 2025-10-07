#pragma once

namespace RK4Laba1Sem5 {

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	protected:

	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBox_2;
	private: System::Windows::Forms::CheckBox^ checkBox_1;
	private: System::Windows::Forms::CheckBox^ checkBox_Test;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox6_B;

	private: System::Windows::Forms::TextBox^ textBox5_A;

	private: System::Windows::Forms::TextBox^ textBox4_EpsGr;
	private: System::Windows::Forms::TextBox^ textBox3_Eps;
	private: System::Windows::Forms::TextBox^ textBox2_h;






	private: System::Windows::Forms::TextBox^ textBox1_Nmax;
	private: System::Windows::Forms::TextBox^ textBox7_U;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;













	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выполнитьToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ очиститьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ фазовыйПортретдляСистемыToolStripMenuItem;







	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;







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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Test = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7_U = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6_B = (gcnew System::Windows::Forms::TextBox());
			this->textBox5_A = (gcnew System::Windows::Forms::TextBox());
			this->textBox4_EpsGr = (gcnew System::Windows::Forms::TextBox());
			this->textBox3_Eps = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_h = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_Nmax = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выполнитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->фазовыйПортретдляСистемыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(559, 31);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::Gold;
			series1->Legend = L"Legend1";
			series1->LegendText = L"Vn(x)";
			series1->Name = L"Series";
			series1->YValuesPerPoint = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Color = System::Drawing::Color::Blue;
			series2->Legend = L"Legend1";
			series2->LegendText = L"V2n(x)";
			series2->Name = L"Series1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series3->Color = System::Drawing::Color::Purple;
			series3->Legend = L"Legend1";
			series3->LegendText = L"U(x)";
			series3->Name = L"Series2";
			series3->YValuesPerPoint = 2;
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Series->Add(series3);
			this->chart->Size = System::Drawing::Size(740, 432);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart1";
			this->chart->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(559, 482);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(740, 343);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox_2);
			this->groupBox1->Controls->Add(this->checkBox_1);
			this->groupBox1->Controls->Add(this->checkBox_Test);
			this->groupBox1->Location = System::Drawing::Point(21, 109);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(515, 84);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Выбор задачи ";
			// 
			// checkBox_2
			// 
			this->checkBox_2->AutoSize = true;
			this->checkBox_2->Location = System::Drawing::Point(383, 27);
			this->checkBox_2->Name = L"checkBox_2";
			this->checkBox_2->Size = System::Drawing::Size(103, 20);
			this->checkBox_2->TabIndex = 2;
			this->checkBox_2->Text = L"Основная 2";
			this->checkBox_2->UseVisualStyleBackColor = true;
			// 
			// checkBox_1
			// 
			this->checkBox_1->AutoSize = true;
			this->checkBox_1->Location = System::Drawing::Point(187, 27);
			this->checkBox_1->Name = L"checkBox_1";
			this->checkBox_1->Size = System::Drawing::Size(103, 20);
			this->checkBox_1->TabIndex = 1;
			this->checkBox_1->Text = L"Основная 1";
			this->checkBox_1->UseVisualStyleBackColor = true;
			// 
			// checkBox_Test
			// 
			this->checkBox_Test->AutoSize = true;
			this->checkBox_Test->Location = System::Drawing::Point(6, 27);
			this->checkBox_Test->Name = L"checkBox_Test";
			this->checkBox_Test->Size = System::Drawing::Size(91, 20);
			this->checkBox_Test->TabIndex = 0;
			this->checkBox_Test->Text = L"Тестовая";
			this->checkBox_Test->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox7_U);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBox6_B);
			this->groupBox2->Controls->Add(this->textBox5_A);
			this->groupBox2->Controls->Add(this->textBox4_EpsGr);
			this->groupBox2->Controls->Add(this->textBox3_Eps);
			this->groupBox2->Controls->Add(this->textBox2_h);
			this->groupBox2->Controls->Add(this->textBox1_Nmax);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(12, 199);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(524, 306);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметры";
			// 
			// textBox7_U
			// 
			this->textBox7_U->Location = System::Drawing::Point(454, 177);
			this->textBox7_U->Name = L"textBox7_U";
			this->textBox7_U->Size = System::Drawing::Size(61, 22);
			this->textBox7_U->TabIndex = 13;
			this->textBox7_U->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(266, 183);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(165, 16);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Начальные условия, Uo:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(451, 114);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(11, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"]";
			// 
			// textBox6_B
			// 
			this->textBox6_B->Location = System::Drawing::Point(392, 111);
			this->textBox6_B->Name = L"textBox6_B";
			this->textBox6_B->Size = System::Drawing::Size(39, 22);
			this->textBox6_B->TabIndex = 10;
			this->textBox6_B->Text = L"5";
			// 
			// textBox5_A
			// 
			this->textBox5_A->Location = System::Drawing::Point(322, 111);
			this->textBox5_A->Name = L"textBox5_A";
			this->textBox5_A->Size = System::Drawing::Size(38, 22);
			this->textBox5_A->TabIndex = 9;
			this->textBox5_A->Text = L"1";
			this->textBox5_A->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox4_EpsGr
			// 
			this->textBox4_EpsGr->Location = System::Drawing::Point(22, 68);
			this->textBox4_EpsGr->Name = L"textBox4_EpsGr";
			this->textBox4_EpsGr->Size = System::Drawing::Size(212, 22);
			this->textBox4_EpsGr->TabIndex = 8;
			this->textBox4_EpsGr->Text = L"0,00001";
			// 
			// textBox3_Eps
			// 
			this->textBox3_Eps->Location = System::Drawing::Point(22, 133);
			this->textBox3_Eps->Name = L"textBox3_Eps";
			this->textBox3_Eps->Size = System::Drawing::Size(212, 22);
			this->textBox3_Eps->TabIndex = 7;
			this->textBox3_Eps->Text = L"0,0001";
			// 
			// textBox2_h
			// 
			this->textBox2_h->Location = System::Drawing::Point(22, 267);
			this->textBox2_h->Name = L"textBox2_h";
			this->textBox2_h->Size = System::Drawing::Size(212, 22);
			this->textBox2_h->TabIndex = 6;
			this->textBox2_h->Text = L"0,01";
			// 
			// textBox1_Nmax
			// 
			this->textBox1_Nmax->Location = System::Drawing::Point(22, 202);
			this->textBox1_Nmax->Name = L"textBox1_Nmax";
			this->textBox1_Nmax->Size = System::Drawing::Size(212, 22);
			this->textBox1_Nmax->TabIndex = 5;
			this->textBox1_Nmax->Text = L"1000";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(277, 114);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(22, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"X [";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 183);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(191, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Максимальное число шагов:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 248);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Начальный шаг:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Контроль локальной погрешности:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Точность выхода за границу:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->менюToolStripMenuItem,
					this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1446, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выполнитьToolStripMenuItem,
					this->очиститьToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->менюToolStripMenuItem->Text = L"Меню";
			this->менюToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::менюToolStripMenuItem_Click);
			// 
			// выполнитьToolStripMenuItem
			// 
			this->выполнитьToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->фазовыйПортретдляСистемыToolStripMenuItem });
			this->выполнитьToolStripMenuItem->Name = L"выполнитьToolStripMenuItem";
			this->выполнитьToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->выполнитьToolStripMenuItem->Text = L"Выполнить ";
			this->выполнитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выполнитьToolStripMenuItem_Click);
			// 
			// фазовыйПортретдляСистемыToolStripMenuItem
			// 
			this->фазовыйПортретдляСистемыToolStripMenuItem->Name = L"фазовыйПортретдляСистемыToolStripMenuItem";
			this->фазовыйПортретдляСистемыToolStripMenuItem->Size = System::Drawing::Size(316, 26);
			this->фазовыйПортретдляСистемыToolStripMenuItem->Text = L"Фазовый портрет (для системы)";
			this->фазовыйПортретдляСистемыToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::фазовыйПортретдляСистемыToolStripMenuItem_Click);
			// 
			// очиститьToolStripMenuItem
			// 
			this->очиститьToolStripMenuItem->Name = L"очиститьToolStripMenuItem";
			this->очиститьToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->очиститьToolStripMenuItem->Text = L"Очистить ";
			this->очиститьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::очиститьToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(67, 24);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(18, 714);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 16);
			this->label8->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(18, 546);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 16);
			this->label9->TabIndex = 8;
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1446, 888);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Runge-Kutta4";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: double Eps, EpsGr, h;
	private: double A, B, U; //Пределы 
	private: int Nmaxy;

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
    private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {}

    private: System::Void очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void выполнитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: void DefaultParams();

private: System::Void фазовыйПортретдляСистемыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   private: void Header();
	   private: void Header1();

	   private: void Show();
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void менюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
