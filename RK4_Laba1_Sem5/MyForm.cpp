#include "MyForm.h"
#include "Test.h"
#include "Tesk1.h"
#include "Tesk2.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    RK4Laba1Sem5::MyForm form;
    Application::Run(% form);
}

System::Void RK4Laba1Sem5::MyForm::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    return System::Void();
}

System::Void RK4Laba1Sem5::MyForm::очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart->Series[0]->Points->Clear();
    this->chart->Series[1]->Points->Clear();
    this->chart->Series[2]->Points->Clear();
    this->dataGridView1->Rows->Clear();
    this->dataGridView1->Columns->Clear();
    return System::Void();
}

System::Void RK4Laba1Sem5::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
System::Void RK4Laba1Sem5::MyForm::фазовыйПортретдляСистемыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Eps = Convert::ToDouble(textBox3_Eps->Text);
    EpsGr = Convert::ToDouble(textBox4_EpsGr->Text);
    h = Convert::ToDouble(textBox2_h->Text);
    Nmaxy = Convert::ToInt32(textBox1_Nmax->Text);
    A = Convert::ToDouble(textBox5_A->Text);
    B = Convert::ToDouble(textBox6_B->Text);
    U = Convert::ToDouble(textBox7_U->Text);
    this->chart->Series[0]->Points->Clear();
    this->chart->Series[1]->Points->Clear();
    Systems Syst(A, U, U);
    Syst.MetodRK44(Eps, EpsGr, Nmaxy, h, A, B, U, this->chart);
    return System::Void();
}

void RK4Laba1Sem5::MyForm::Header() //Шапка таблицы
{
 
    DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
    c1->Name = "N";
    c1->HeaderText = "N";
    c1->Width = 100;
    dataGridView1->Columns->Add(c1);

    DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
    c2->Name = "h";
    c2->HeaderText = "h(n-1)";
    c2->Width = 100;
    dataGridView1->Columns->Add(c2);

    DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
    c3->Name = "Xn";
    c3->HeaderText = "Xn";
    c3->Width = 100;
    dataGridView1->Columns->Add(c3);

    DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
    c4->Name = "Vn";
    c4->HeaderText = "Vn";
    c4->HeaderCell->Value = "1";
    c4->Width = 100;
    dataGridView1->Columns->Add(c4);

    DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
    c5->Name = "V2n";
    c5->HeaderText = "V2n";
    c5->Width = 100;
    dataGridView1->Columns->Add(c5);

    DataGridViewTextBoxColumn^ c6 = gcnew DataGridViewTextBoxColumn();
    c6->Name = "S*";
    c6->HeaderText = "S*";
    c6->Width = 100;
    dataGridView1->Columns->Add(c6);

    DataGridViewTextBoxColumn^ c7 = gcnew DataGridViewTextBoxColumn();
    c7->Name = "Vnitog";
    c7->HeaderText = "Vn итог";
    c7->Width = 100;
    dataGridView1->Columns->Add(c7);

    DataGridViewTextBoxColumn^ c8 = gcnew DataGridViewTextBoxColumn();
    c8->Name = "Un";
    c8->HeaderText = "Un";
    c8->Width = 100;
    dataGridView1->Columns->Add(c8);

    DataGridViewTextBoxColumn^ c9 = gcnew DataGridViewTextBoxColumn();
    c9->Name = "GlobalError";
    c9->HeaderText = "Un - Vnitog";
    c9->Width = 100;
    dataGridView1->Columns->Add(c9);

    DataGridViewTextBoxColumn^ c10 = gcnew DataGridViewTextBoxColumn();
    c10->Name = "/2";
    c10->HeaderText = "/2";
    c10->Width = 100; 
    dataGridView1->Columns->Add(c10);

    DataGridViewTextBoxColumn^ c11 = gcnew DataGridViewTextBoxColumn();
    c11->Name = "*2";
    c11->HeaderText = "*2";
    c11->Width = 100;
    dataGridView1->Columns->Add(c11);

    dataGridView1->TopLeftHeaderCell->Value = "Данные тестовой задачи"; //Название таблицы 
    dataGridView1->AutoResizeColumns(); //Выравнивает текущие колонки
}

void RK4Laba1Sem5::MyForm::Header1()
{
    DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
    c1->Name = "N";
    c1->HeaderText = "N";
    c1->Width = 100;
    dataGridView1->Columns->Add(c1);

    DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
    c2->Name = "h";
    c2->HeaderText = "h(n-1)";
    c2->Width = 100;
    dataGridView1->Columns->Add(c2);

    DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
    c3->Name = "Xn";
    c3->HeaderText = "Xn";
    c3->Width = 100;
    dataGridView1->Columns->Add(c3);

    DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
    c4->Name = "Vn";
    c4->HeaderText = "Vn";
    c4->Width = 100;
    dataGridView1->Columns->Add(c4);

    DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
    c5->Name = "V2n";
    c5->HeaderText = "V2n";
    c5->Width = 100;
    dataGridView1->Columns->Add(c5);

    DataGridViewTextBoxColumn^ c6 = gcnew DataGridViewTextBoxColumn();
    c6->Name = "S*";
    c6->HeaderText = "S*";
    c6->Width = 100;
    dataGridView1->Columns->Add(c6);

    DataGridViewTextBoxColumn^ c7 = gcnew DataGridViewTextBoxColumn();
    c7->Name = "Vnitog";
    c7->HeaderText = "Vn итог";
    c7->Width = 100;
    dataGridView1->Columns->Add(c7);
    DataGridViewTextBoxColumn^ c8 = gcnew DataGridViewTextBoxColumn();
    c8->Name = "/2";
    c8->HeaderText = "/2";
    c8->Width = 100;
    dataGridView1->Columns->Add(c8);

    DataGridViewTextBoxColumn^ c9 = gcnew DataGridViewTextBoxColumn();
    c9->Name = "*2";
    c9->HeaderText = "*2";
    c9->Width = 100;
    dataGridView1->Columns->Add(c9);
}

void RK4Laba1Sem5::MyForm::Show() { //вывод данных в таблицу
   

    for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
        //Вывод данных в ячейки
        dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);

        //dataGridView1->Rows[i]->Cells[0]->Value = Convert_string_to_string(_data[i].GetInitials().N);

    }
}

System::Void RK4Laba1Sem5::MyForm::выполнитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    this->chart->Series[0]->Points->Clear(); //Стереть график 
    if (checkBox_Test->Checked == false && checkBox_1->Checked == false && checkBox_2->Checked == false) {
        MessageBox::Show("Выберете задачу!", "Внимание!");
        return; 
    }
    int a = 0; 
    if ((checkBox_Test->Checked == true && checkBox_1->Checked == true) || (checkBox_Test->Checked == true && checkBox_2->Checked == true) || (checkBox_1->Checked == true && checkBox_2->Checked == true)) {
        MessageBox::Show("Выберете только одну задачу!", "Внимание!");
        return;
    }
    
    if ( textBox3_Eps->Text == "" || textBox1_Nmax->Text == "" || textBox2_h->Text == "" || textBox4_EpsGr->Text == "" || textBox5_A->Text == "" || textBox6_B->Text == "") { //Если какие то параметры не введены, то используем по умолчанию 
        MessageBox::Show("Параметры по умолчанию!", "Внимание!");
        DefaultParams();
        return; 
    }
    else { //Конвентируем параметры 
        Eps = Convert::ToDouble(textBox3_Eps->Text);
        EpsGr = Convert::ToDouble(textBox4_EpsGr->Text);
        h = Convert::ToDouble(textBox2_h->Text);
        Nmaxy = Convert::ToInt32(textBox1_Nmax->Text);
        A = Convert::ToDouble(textBox5_A->Text);
        B = Convert::ToDouble(textBox6_B->Text);
        U = Convert::ToDouble(textBox7_U->Text);
    }
    //тестовая задача
    if (checkBox_Test->Checked == true && checkBox_1->Checked == false && checkBox_2->Checked == false) {
        this->chart->Series[0]->Points->Clear();
        this->chart->Series[1]->Points->Clear();
        this->chart->Series[2]->Points->Clear();
        this->dataGridView1->Rows->Clear();
        this->dataGridView1->Columns->Clear();
        Test Testy(A, U);
        
        dataGridView1->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders);
        dataGridView1->AutoResizeColumns();
        Header();
        Testy.MetodRK4(Eps, EpsGr, Nmaxy, h, A, B, U, this->chart, this->dataGridView1, this->label8);
        dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders); //выравниваем
        dataGridView1->AutoResizeColumns(); //выравниваем
    }
    //основная задача 1
    if (checkBox_Test->Checked == false && checkBox_1->Checked == true && checkBox_2->Checked == false) {
        this->chart->Series[0]->Points->Clear();
        this->chart->Series[1]->Points->Clear();
        this->chart->Series[2]->Points->Clear();
        this->dataGridView1->Rows->Clear();
        this->dataGridView1->Columns->Clear();
        Tesk Tesk(A, U);
        dataGridView1->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders);
        dataGridView1->AutoResizeColumns();
        Header1();
        Tesk.MetodRK4(Eps, EpsGr, Nmaxy, h, A, B, U, this->chart, this->dataGridView1, this->label8);
        dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders); //выравниваем
        dataGridView1->AutoResizeColumns(); //выравниваем
    }
    //система
    if (checkBox_Test->Checked == false && checkBox_1->Checked == false && checkBox_2->Checked == true) {
        this->chart->Series[0]->Points->Clear();
        this->chart->Series[1]->Points->Clear();
        this->chart->Series[2]->Points->Clear();
        this->dataGridView1->Rows->Clear();
        this->dataGridView1->Columns->Clear();
        Systems System(A, U, U);
        dataGridView1->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders);
        dataGridView1->AutoResizeColumns();
        Header1();
        System.MetodRK4(Eps, EpsGr, Nmaxy, h, A, B, U, this->chart, this->dataGridView1, label8);
        dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders); //выравниваем
        dataGridView1->AutoResizeColumns(); //выравниваем
    }
}

void RK4Laba1Sem5::MyForm::DefaultParams()
{
    Eps = 0.0001;
    EpsGr = 0.00001;
    h = 0.01;
    Nmaxy = 1000;
    A = 0;
    B = 5;
    U = 0;
}


