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
random_device rd;//Intializing random number generator
mt19937 gen(rd());
exponential_distribution<double>decay_dist(decay_constant);
ofstream outputFile(filename);//intializing output file
if(!output_file.is_open()) {
cout<<"Unable to load the file"<<endl;
return;
}
//perform simulation and save data to decay file
int remaining_particles=num_particles;
for (int t=0;t<simulation duration;++t){
int decay_count=0;
for (int i=0;i<remaining particles;++i){
//generate random numbers from exponential distribution
double random_value = decay_dist(gen);
  

  
}
}
