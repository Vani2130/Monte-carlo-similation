#include <iostream>
#include <random>
#include <cmath>
using namespace std;

// Function to generate random numbers in the range [0, 1]
double random_double() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<double> dis(0.0, 1.0);
    return dis(gen);
}

// Function to generate energy level of a particle based on radioactivity
double generate_energy(double radioactivity) {
    // Adjust the range of energy based on radioactivity
    // Higher radioactivity may imply higher average energy, but customize this function as needed
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> energy_distribution(0, radioactivity);
    return energy_distribution(gen);
}

// Function to estimate gamma ray/neutron attenuation using Monte Carlo method
double estimateAttenuation(double thickness, double radioactivity, int num_particles) {
    double transmitted_particles = 0.0;

    for (int i = 0; i < num_particles; ++i) {
        // Generate energy level of the particle
        double energy = generate_energy(radioactivity);

        // Calculate the attenuation coefficient based on energy
        // Customize this function as needed to calculate the attenuation coefficient
        double attenuation_coefficient = exp(-energy / thickness);

        // Generate random distance traveled by the particle in the absorber
        double distance = -thickness * log(random_double()) / attenuation_coefficient;

        // Check if the particle is transmitted through the absorber
        if (distance >= thickness) {
            ++transmitted_particles;
        }
    }

    // Calculate the fraction of transmitted particles
    double fraction_transmitted = transmitted_particles / num_particles;

    return fraction_transmitted;
}

int main() {
    // Thickness of the absorber (in cm)
    double absorber_thickness;

    // Get user input for the thickness of the absorber
    cout << "Enter the thickness of the absorber (in cm): ";
    cin >> absorber_thickness;

    // Radioactivity of the source (in arbitrary units)
    double radioactivity;
    // Get user input for the radioactivity of the source
   cout << "Enter the radioactivity of the source (in arbitrary units): ";
   cin >> radioactivity;

    // Number of particles for the Monte Carlo simulation
    int num_particles;
    // Get user input for the number of particles
    cout << "Enter the number of particles for the simulation: ";
    cin >> num_particles;

    // Estimate the attenuation using Monte Carlo method
    double attenuation = estimateAttenuation(absorber_thickness, radioactivity, num_particles);

    // Output the estimated attenuation
    cout << "Estimated attenuation: " << (1.0 - attenuation) * 100 << "%" << endl;

    return 0;
}
