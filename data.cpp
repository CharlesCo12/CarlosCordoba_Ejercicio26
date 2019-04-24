#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 30.0/omega, 0.1/omega, omega, "euler_01.dat");
  solve_equation_euler(0.0, 30.0/omega, 0.01/omega, omega, "euler_001.dat");
  solve_equation_euler(0.0, 30.0/omega, 1.0/omega, omega, "euler_1.dat");
  return 0;
}

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){    
    outfile << t << " " << y  << " " << z << endl;
    float z_1=z;
    float y_1=y;
    z = z - delta_t * y_1*omega*omega;
    y = y + delta_t * omega  * z_1;    
    t = t + delta_t;
  }
  outfile.close();
}