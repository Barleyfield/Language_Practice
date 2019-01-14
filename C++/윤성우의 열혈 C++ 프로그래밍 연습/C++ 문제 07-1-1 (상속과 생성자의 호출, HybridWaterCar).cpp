오후 11:52 2017-10-17
#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gas) : gasolineGauge(gas) { }
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec) : Car(gas), electricGauge(elec) { }
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water) { }
	void ShowCurrentGauge()
	{
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};


int main()
{
	Car c1(100);
	HybridCar c2(300, 400);
	HybridWaterCar c3(500, 600, 700);

	c3.ShowCurrentGauge();

	return 0;



}