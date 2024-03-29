#include<iostream>
#include<fstream>
#include<random>
using namespace std;
class RadioactiveDecaySimulation{
private:
double decay_constant; // declares decay constant in the class
int num_particles; //number of radioactive particles are declared in the class
public:
RadioactiveDecaySimulation(double decay_constant,int num_particles): decay_constant(decay_constant) , num_particles(num_particles) {}
void runSimulation(int simulation_duration,const string & filename) { // run simulation and save the data file
random_device rd;
mt19937 gen(rd());
