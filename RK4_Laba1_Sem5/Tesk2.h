#pragma once
#include <iostream>
#include <cmath>

class Systems {
private:
	double x;
	double y;   // U'(0) = U0
	double Vn;  // U(0) = U0
	
	
public:
	Systems(double x, double y, double V) {
		this-> x= x;
		this->y = y;
		Vn = V;
	}
	Systems() : x(0), y(0), Vn(0) {}
	Systems operator=(const Systems& a) {
		return Systems(x = a.x, y = a.y, Vn = a.Vn);
	}
	friend std::ostream& operator<< (std::ostream& out, const Systems& test);
	double Func1(double _x, double _y, double _V) { 
		return _y;
	}
	double Func2(double _x, double _y, double _V) {
		double Res = -a * _y - b * sin(_V);
		return Res;
	}
	void PRINT(int i, Systems Z, Systems Zo, double S, int Plus, int Minus, double h);
	double a, b;
	Systems Shag(Systems A, double h);
	void MetodRK4(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::DataGridView^ dataGridView1, System::Windows::Forms::Label^ label8); //Метод
	void MetodRK44(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
};
std::ostream& operator<< (std::ostream& out, const Systems& test) {
	out << "(" << test.x << ", " << test.y << "," << test.Vn << ')';
	return out;
}
void Systems::PRINT(int i, Systems Z, Systems Zo, double S, int Plus, int Minus, double h) {
	std::cout << "\n" << i << "  " << h << "  ";
	std::cout << " Vn= " << Z;
	std::cout << " V2n= " << Zo;
	std::cout << " S=  " << S * 16.0 << " ";
	std::cout << "  Plus=  " << Plus << "  Minus=  " << Minus << "  ";
}
Systems Systems::Shag(Systems A, double h) {
	double k1v = Func1(A.x, A.y, A.Vn);
	double k1y = Func2(A.x, A.y, A.Vn);
	double k2v = Func1(A.x + h / 2.0, A.y + h / 2.0 * k1y, A.Vn + h / 2.0 * k1v);
	double k2y = Func2(A.x + h / 2.0, A.y + h / 2.0 * k1y, A.Vn + h / 2.0 * k1v);
	double k3v = Func1(A.x + h / 2.0, A.y + h / 2.0 * k2y, A.Vn + h / 2.0 * k2v);
	double k3y = Func2(A.x + h / 2.0, A.y + h / 2.0 * k2y, A.Vn + h / 2.0 * k2v);
	double k4v = Func1(A.x + h, A.y + h * k3y, A.Vn + h * k3v);
	double k4y = Func2(A.x + h, A.y + h * k3y, A.Vn + h * k3v);
	double V = A.Vn + h / 6.0 * (k1v + 2 * k2v + 2 * k3v + k4v);
	double Y = A.y + h / 6.0 * (k1y + 2 * k2y + 2 * k3y + k4y);
	double X = A.x + h;
	return Systems(X, Y, V);
}

void Systems::MetodRK4(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::DataGridView^ dataGridView1, System::Windows::Forms::Label^ label8) {
	int plusH = 0; //кол-во удвоений шага
	int minusH = 0; //кол-во уменьшений шаг
	this->a = a;
	this->b = b;
	Systems Z(a, Uo ,Uo);
	Systems Zeps;
	Systems Zo;
	bool Flag;
	int i = 0;
	//double Nmax = 0; 
	double OLP = 0;
	dataGridView1->ColumnCount = 9;
	dataGridView1->RowCount = Nmax + 1;
	while (i < Nmax) {
		int Minus = 0;
		int Plus = 0;
		long double S;
		do {
			Zeps = Z;
			Zo = Z;

			Z = Shag(Z, h);
			Flag = true;

			Zo = Shag(Zo, h / 2);
			Zo = Shag(Zo, h / 2);

			//GlobError = Solution(Z.x) - Z.Vn;
			S = sqrt(pow((Z.y - Zo.y), 2) + pow((Z.Vn - Zo.Vn), 2)) / 15.0;
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
		if (sqrt(pow((Z.y - Zo.y), 2) + pow((Z.Vn - Zo.Vn), 2)) > OLP) {
			OLP = sqrt(pow((Z.y - Zo.y), 2) + pow((Z.Vn - Zo.Vn), 2));
		}
		i++;
		plusH += Plus;
		minusH += Minus;
		if (Z.x < b - EpsGr) {
			//PRINT(i, Z, Zo ,S, Plus, Minus, h);
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
			//PRINT(i, Z, Zo,  S, Plus, Minus, h);
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

			//GlobError = Solution(Z.x) - Z.Vn;
			S = sqrt(pow((Z.y - Zo.y), 2) + pow((Z.Vn - Zo.Vn), 2)) / 15.0;
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
			//PRINT(i, Z, Zo, S, Plus, Minus, h);
			break;
		}
	}
	label8->Text = L" N= " + System::Convert::ToString(i + 1) + L"\n" + L"\n" +
		L" Количество удвоений: " + System::Convert::ToString(plusH) + L"\n" + L"\n" +
		L" Количество делений: " + System::Convert::ToString(minusH) + L"\n" + L"\n" +
		L" Максимальная ОЛП: " + System::Convert::ToString(OLP);
	//std::cout << "\n " << "Vsego shagov: " << " Vsego ymensheni: " << minusH << " Vsego yvelich: " << plusH;
}

void Systems::MetodRK44(double Eps, double EpsGr, int Nmax, double h, double a, double b, double Uo, System::Windows::Forms::DataVisualization::Charting::Chart^ chart) {
	int plusH = 0; //кол-во удвоений шага
	int minusH = 0; //кол-во уменьшений шаг
	this->a = a;
	this->b = b;
	Systems Z(a, Uo, Uo);
	Systems Zeps;
	Systems Zo;
	bool Flag;
	int i = 0;
	while (i < Nmax) {
		int Minus = 0;
		int Plus = 0;
		double S;
		do {
			Zeps = Z;
			Zo = Z;

			Z = Shag(Z, h);
			Flag = true;

			Zo = Shag(Zo, h / 2);
			Zo = Shag(Zo, h / 2);

			//GlobError = Solution(Z.x) - Z.Vn;
			S = sqrt(pow((Z.y - Zo.y), 2) + pow((Z.Vn - Zo.Vn), 2)) / 15.0;
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
		i++;
		plusH += Plus;
		minusH += Minus;
		if (Z.x < b - EpsGr) {
			//PRINT(i, Z, Zo ,S, Plus, Minus, h);
			/*chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);*/
			chart->Series[1]->Points->AddXY(Z.Vn, Z.y);
		}
		else if (Z.x < b) {
			//PRINT(i, Z, Zo, S, Plus, Minus, h);
			/*chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);*/
			chart->Series[1]->Points->AddXY(Z.Vn, Z.y);
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

			//GlobError = Solution(Z.x) - Z.Vn;
			S = sqrt(pow((Z.y - Zo.y), 2) + pow((Z.Vn - Zo.Vn), 2)) / 15.0;
			/*chart->Series[0]->Points->AddXY(Z.x, Z.Vn);
			chart->Series[1]->Points->AddXY(Zo.x, Zo.Vn);*/
			chart->Series[1]->Points->AddXY(Z.Vn, Z.y);
			//PRINT(i, Z, Zo, S, Plus, Minus, h);
			break;
		}
	}
}