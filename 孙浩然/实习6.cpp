#include<iostream>

using namespace std;

class vehicle
{
      protected:
        int wheels;
        int weight;
      public:
         vehicle(int wh,int we)
         {
            wheels = wh;
            weight = we;
         }
         virtual void show()
         {
              cout<<"轮子数 "<<wheels<<endl;
              cout<<"重量 "<<weight<<endl;
         }
               
};

class car : public vehicle
{
      private:
         int passenger_load ;
      public:
             
      car(int pa,int wh,int we) : vehicle(wh,we)
      {
          passenger_load = pa;
      }

      virtual void show()
      {
           cout<<"轮子数 "<<wheels<<endl;
           cout<<"重量 "<<weight<<endl;
           cout<<"乘客量 "<<passenger_load<<endl;
      }
             
};

class truck : public vehicle
{
      private:
         int passenger_load ;
         int pay_load;
      public:
             
      truck(int pa,int p_load,int wh,int we) : vehicle(wh,we)
      {
          passenger_load = pa;
          pay_load = p_load;
      }
      
      virtual void show()
      {
          cout<<"轮子数 "<<wheels<<endl;
          cout<<"重量 "<<weight<<endl;
          cout<<"乘客量 "<<passenger_load<<endl;
          cout<<"载重 "<<pay_load<<endl; 
      }
};

 
              

int main()
{
    vehicle * ve = new car(5,4,1000);
    vehicle * ve2 = new truck(2,2500,8,6000);
    ve->show();
    ve2->show();
    
    delete ve;
    delete ve2;
    
    system("pause");
    return 0;
}
