# Force-Particle Interactions
This is an educational project to experiment with calculating less-commonly
calculated observables like the free energy from a time dependent simulation
of nearly ideal and nonideal gases.

Goals:

 - Simulate simple ideal and nonideal gases.
 - Use a O(N) force calculation algorithm (doesn't have to be the most optimized)
 - Output samples of various observables to a .csv file, including:
    - Energy, temperature, pressure.
    - Specific heat
    - Delta Q if and when we add energy to the system.
 - Compare the observables to explicit calculations, including the ideal gas and van der Waals gas.
 - Compare observables $\int dQ/T$ and $\iint C_V d\beta$ (thermodynamic integration to find the entropy) 
 - Create emscripten bindings and browser-based visualization.

Nice-to-haves:

 - Illustrate the issues with trying to find $S$ past a phase transition.
 - Create a constant pressure simulation using a piston 
 - Have a simple thermostat.
 

## Code Description

Helper classes:
- `class ParticleList` does particle loading and initialization
- `class VectorND` is an N-dimensional templated vectors of any type. 
- `class CSVData` is a simple csv saver.
- `class ImageUtil` is for simple debug output.

Core simulation code:
- `struct Particle`
- `class DenseGrid` -- contains a `std::vector<std::vector<std::vector<Particle*>>>` to have a resizable grid that contains a list of particles and some max interaction radius
- `class Simulation` -- handles timestepping of the particles, setting properties, updating DenseGrid, and adding energy. The force law we select should be handled via a constexpr so that the inner loops can be optimized though. 
- `class Statistics` -- handles gathering the statistics, counting, and saving.
- `main` and various run configurations: do the statistics, and output appropriately.

