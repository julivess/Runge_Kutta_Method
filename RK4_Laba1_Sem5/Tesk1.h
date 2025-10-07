#pragma once
#include <iostream>
#include <cmath>
class Tesk {
private:
	double x;
	double Vn;
public:
	Tesk(double _x, double _Un) {
		x = _x;
		Vn = _Un;
	}
	Tesk() : x(0), Vn(0) {}

	Tesk operator=(const Tesk& a) {
		return Tesk(x = a.x, Vn = a.Vn);
	}
	friend std::ostream& operator<< (std::ostream& out, const Tesk& Tesk);

	double FuncTest(double X, double U) {    //dU/dx = (f(x)U^2 + U - U^3*sin(10))   (x/(1+x^2))
		double Res = X / (1 + pow(X, 2)) * pow(U, 2) + U - pow(U, 3) * sin(10);
		return Res;
	}
	double a, b;
	
	//Для метода:

	//Тестовая и основная 1
	Tesk Shag(Tesk A, double h); //Шаг метода 
	void PRINT(int i, Tesk Z, Tesk Zo, double S, int Plus, int Minus, double h); // Вывод в консоль 
	void MetodRK4(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::DataGridView^ dataGridView1, System::Windows::Forms::Label^ label8); //Метод
};
std::ostream& operator<< (std::ostream& out, const Tesk& test) {
	out << "(" << test.x << ", " << test.Vn << ')';
	return out;
}

Tesk Tesk::Shag(Tesk A, double h) {
	double k1 = FuncTest(A.x, A.Vn);
	double k2 = FuncTest(A.x + h / 2.0, A.Vn + h / 2.0 * k1);
	double k3 = FuncTest(A.x + h / 2.0, A.Vn + h / 2.0 * k2);
	double k4 = FuncTest(A.x + h, A.Vn + h * k3);
	double V = A.Vn + h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
	double X = A.x + h;
	return Tesk(X, V);
}


void Tesk::PRINT(int i, Tesk Z, Tesk Zo, double S, int Plus, int Minus, double h) {
	std::cout << "\n" << i << "  " << h << "  ";
	std::cout << " Vn= " << Z;
	std::cout << " V2n= " << Zo;
	std::cout << " S=  " << S * 16.0 << " ";
	std::cout << "  Plus=  " << Plus << "  Minus=  " << Minus << "  ";
}

void Tesk::MetodRK4(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::DataGridView^ dataGridView1, System::Windows::Forms::Label^ label8) {
	int plusH = 0; //кол-во удвоений шага
	int minusH = 0; //кол-во уменьшений шаг


	this->b = b;
	this->a = a;
	Tesk Z(a, Uo);
	Tesk Zeps;
	Tesk Zo;
	bool Flag;
	int i = 0;
	double OLP = 0;
	double pizda = 0;
	dataGridView1->ColumnCount = 9;
	dataGridView1->RowCount = Nmax + 1;

	while (i < Nmax) {
		int Minus = 0;
		int Plus = 0;
		//Smax = 0; 
		long double S;
		double Smax;
		do {
			Zeps = Z;
			Zo = Z;

			Z = Shag(Z, h);
			Flag = true;

			Zo = Shag(Zo, h / 2);
			Zo = Shag(Zo, h / 2);

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

		Zeps = Z;
		Zo = Z;

		Z = Shag(Z, h);
		Flag = true;

		Zo = Shag(Zo, h / 2);
		Zo = Shag(Zo, h / 2);

		if (abs(Z.Vn - Zo.Vn) > OLP) {
			OLP = abs(Z.Vn - Zo.Vn);
		}
		i++;
		plusH += Plus;
		minusH += Minus;
		if (Z.x < b - EpsGr) {
			//PRINT(i, Z, Zo, S, Plus, Minus, h);
			//таблица 
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = h;
			dataGridView1->Rows[i]->Cells[2]->Value = Z.x;
			dataGridView1->Rows[i]->Cells[3]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[4]->Value = Zo.Vn;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(S * 16);
			dataGridView1->Rows[i]->Cells[6]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[7]->Value = Minus;
			dataGridView1->Rows[i]->Cells[8]->Value = Plus;

			//график
			chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);
		}
		else if (Z.x < b) {
			//PRINT(i, Z, Zo, S, Plus, Minus, h);
			//таблица 
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = h;
			dataGridView1->Rows[i]->Cells[2]->Value = Z.x;
			dataGridView1->Rows[i]->Cells[3]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[4]->Value = Zo.Vn;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(S * 16);
			dataGridView1->Rows[i]->Cells[6]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[7]->Value = Minus;
			dataGridView1->Rows[i]->Cells[8]->Value = Plus;

			//график
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

			
			S = (Z.Vn - Zo.Vn) / 15.0;
			//PRINT(i, Z, Zo, S, Plus, Minus, h);
			//таблица 
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = h;
			dataGridView1->Rows[i]->Cells[2]->Value = Z.x;
			dataGridView1->Rows[i]->Cells[3]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[4]->Value = Zo.Vn;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(pizda);
			dataGridView1->Rows[i]->Cells[6]->Value = Z.Vn;
			dataGridView1->Rows[i]->Cells[7]->Value = Minus;
			dataGridView1->Rows[i]->Cells[8]->Value = Plus;

			//график
			chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);
			break;
		}
		label8->Text = L" N= " + System::Convert::ToString(i ) + L"\n" + L"\n" +
			L" Количество удвоений: " + System::Convert::ToString(plusH) + L"\n" + L"\n" +
			L" Количество делений: " + System::Convert::ToString(minusH) + L"\n" + L"\n" +
			L" Максимальная ОЛП: " + System::Convert::ToString(OLP);
	}
	//std::cout << "\n " << "Vsego shagov: " << " Vsego ymensheni: " << minusH << " Vsego yvelich: " << plusH;
}
