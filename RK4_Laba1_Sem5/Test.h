#pragma once
#include <iostream>
#include <cmath>
#include "MyForm.h"

class Test {      //Наша тестовая задача и основная задача №1
private:
	double x; 
	double Vn;

public:
	Test(double _x, double _Un) {
		x = _x;
		Vn = _Un;
	}
	Test() : x(0), Vn(0) {}

	Test operator=(const Test& a) {
		return Test(x = a.x, Vn = a.Vn);
	}
	friend std::ostream& operator<< (std::ostream& out, const Test& test);

	double FuncTest(double X, double V) {    // dU/dx = U; U(a) = Uo  
		return V;
	}
	double a, b, Uo;
    double Solution(double x) {
		return Uo / exp(a) * exp(x); 
	}
	//Для метода:
	
	//Тестовая и основная 1
	Test Shag(Test A, double h); //Шаг метода 
	void PRINT(int i, Test Z, Test Zo, double Uo, double GlobError, double S, int Plus, int Minus, double h); // Для вывода Вывод в консоль 
	void MetodRK4(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::DataGridView^ dataGridView1, System::Windows::Forms::Label^ label8); //Метод
};          

std::ostream& operator<< (std::ostream& out, const Test& test){
	out << "(" << test.x << ", " << test.Vn <<  ')';
	return out;
}

Test Test::Shag(Test A, double h) {
	double k1 = FuncTest(A.x, A.Vn);
	double k2 = FuncTest(A.x + h / 2.0, A.Vn + h / 2.0 * k1);
	double k3 = FuncTest(A.x + h / 2.0, A.Vn + h / 2.0 * k2);
	double k4 = FuncTest(A.x + h, A.Vn + h * k3);
	double V = A.Vn + h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
	double X = A.x + h;
	return Test(X, V);
}

void Test::PRINT(int i, Test Z, Test Zo, double Un ,double GlobError, double S, int Plus, int Minus, double h) {
	std::cout << "\n" << i << "  " << h << "  ";
	std::cout << " Vn= "<< Z;
	std::cout << " V2n= " << Zo; 
	std::cout << " Un = " << Un;
	std::cout << " GloblError  " << abs(GlobError);
	std::cout << " S=  " << S * 16.0 << " ";
	std::cout << "  Plus=  " << Plus << "  Minus=  " << Minus << "  ";
}

void Test::MetodRK4(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::DataGridView^ dataGridView1, System::Windows::Forms::Label^ label8){
	int plusH = 0; //кол-во удвоений шага
	int minusH = 0; //кол-во уменьшений шаг
	//array <String ^> ^row0 = { "N ", "h(n-1)" ,"x(n)", "v(n)", "v(2n)", "S*", "v(n)пр", "u(n)", "|u(n)-v(n)пр|" , "/2", "*2" };
	//dataGridView1->Rows->Add(row0);
	this->b = b;
	this->a = a;
	this->Uo = Uo;
	Test Z(a, Uo); 
	Test Zeps;
	Test Zo;
	bool Flag;
	int i = 0;
	double OLP = 0;
	dataGridView1->ColumnCount = 11;
	dataGridView1->RowCount = Nmax;
	
	for (double h = a; h < b; h += 0.01) {
		chart->Series[2]->Points->AddXY(h, Solution(h));
	}
	while (i < Nmax) {
		int Minus = 0;
		int Plus = 0;
		long double S;
		double GlobError;
		do {
			Zeps = Z;
			Zo = Z;

			Z = Shag(Z, h);
			Flag = true;
			
		    Zo = Shag(Zo, h / 2);
		    Zo = Shag(Zo, h / 2);
			
			GlobError = Solution(Z.x) - Z.Vn; 
			S = (Z.Vn - Zo.Vn) / 15.0;

			if (Eps / 32.0 <= abs(S) && Eps >= abs(S)) {
				Flag = true;
			}
			else
				if (abs(S) < Eps / 32.0) {
					h = 2.0 * h;
					Plus++;
					Flag = true;
				}
				else {
					h = h / 2.0;
					Minus++;
					Z = Zeps;
					Flag = false; 
				}
		} while (Flag == false);
		if (abs(Z.Vn - Zo.Vn) > OLP) {
			OLP = abs(Z.Vn - Zo.Vn);
		}
		i++;
		plusH += Plus;
		minusH += Minus;
		if (Z.x < b - EpsGr) {
			//PRINT(i, Z, Zo, Solution(Z.x), GlobError, S, Plus, Minus, h);
			//Таблица
			
			dataGridView1->Rows[i]->Cells[0]->Value = i ;
			dataGridView1->Rows[i]->Cells[1]->Value = h;
			dataGridView1->Rows[i]->Cells[2]->Value = Z.x;
			dataGridView1->Rows[i]->Cells[3]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[4]->Value = Zo.Vn;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(S * 16);
			dataGridView1->Rows[i]->Cells[6]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[7]->Value = Solution(Z.x);
			dataGridView1->Rows[i]->Cells[8]->Value = GlobError;
			dataGridView1->Rows[i]->Cells[9]->Value = Minus;
			dataGridView1->Rows[i]->Cells[10]->Value = Plus;

			//график
			chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);
		}
		else if (Z.x < b) { 
			//PRINT(i, Z, Zo, Solution(Z.x), GlobError, S, Plus, Minus, h);
			
			//Таблица
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = h;
			dataGridView1->Rows[i]->Cells[2]->Value = Z.x;
			dataGridView1->Rows[i]->Cells[3]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[4]->Value = Zo.Vn;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(S * 16);
			dataGridView1->Rows[i]->Cells[6]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[7]->Value = Solution(Z.x);
			dataGridView1->Rows[i]->Cells[8]->Value = GlobError;
			dataGridView1->Rows[i]->Cells[9]->Value = Minus;
			dataGridView1->Rows[i]->Cells[10]->Value = Plus;

			//График
			chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);
			break;
		}
		else {
			h = b - Zeps.x; 
			Z = Zeps;
			Zo = Zeps;
			Z = Shag(Z, h);
			Flag = true;
			Zo = Shag(Zo, h / 2);
			Zo = Shag(Zo, h / 2);
			
			GlobError = Solution(Z.x) - Z.Vn;
		
			S = (Z.Vn - Zo.Vn) / 15.0;


			//PRINT(i, Z, Zo, Solution(Z.x), GlobError, S, Plus, Minus, h);
			//Таблица
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = h;
			dataGridView1->Rows[i]->Cells[2]->Value = Z.x;
			dataGridView1->Rows[i]->Cells[3]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[4]->Value = Zo.Vn;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(S * 16);
			dataGridView1->Rows[i]->Cells[6]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[7]->Value = Solution(Z.x);
			dataGridView1->Rows[i]->Cells[8]->Value = GlobError;
			dataGridView1->Rows[i]->Cells[9]->Value = Minus;
			dataGridView1->Rows[i]->Cells[10]->Value = Plus;
			

			//График
			chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);
		    
			break;
		}
	}
	


	label8->Text = L" N= " + System::Convert::ToString(i + 1) + L"\n" + L"\n" +
		L" Количество удвоений: " + System::Convert::ToString(plusH) + L"\n" + L"\n" +
		L" Количество делений: " + System::Convert::ToString(minusH) + L"\n" + L"\n" +
		L" Максимальная ОЛП: " + System::Convert::ToString(OLP);
	/*label8->Text = L" Количество удвоений: ";
	label8->Text = System::Convert::ToString(plusH);
	label8->Text = L" Количество делений: ";
	label8->Text = System::Convert::ToString(minusH);
	label8->Text = L" Максимальная ОЛП: ";*/


	//std::cout << "\n " << "Vsego shagov: " << " Vsego ymensheni: " << minusH << " Vsego yvelich: " << plusH;
	
}








