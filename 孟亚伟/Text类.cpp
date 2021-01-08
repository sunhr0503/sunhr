#include<iostream>
using namespace std;
class vehicle
{
protected:
	int wheels;
	float weight;
public:
	vehicle(int w1, float w2)
	{
		wheels = w1;
		weight = w2;
	}
	void printf()
	{
		cout << "wheels=" << wheels << "," << "weight=" << "weight" << endl;
	}
};
class car :private vehicle
{
	int passenger_load;
    public:
		car(int w1,float w2,int p1):vehicle(w1,w2)
        {
			passenger_load = p1;
        }
		void printf()
		{
			vehicle::printf();
			cout << "passenger_load=" << passenger_load << endl;
		}
};
class truck :private vehicle
{
	int passenger_load;
	float payload;
public:
truck(int w1,float w2,int p1,float p2):vehicle(w1,w2)
{
	passenger_load = p1;
	payload = p2;
}
void printf()
{
	vehicle::printf();
	cout << "passenger_load=" << passenger_load << "," << "payload=" << payload << endl;
}
};
void main()
{
	vehicle v(100, 530);
	v.printf();
	car c(120, 95, 42);
	c.printf();
	truck t(24,30,23,20);
	t.printf();
}