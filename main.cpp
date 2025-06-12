#include <iostream>
#include <vector>

#include "VectorND.h"

typedef VectorND<float, 2> vec2;
typedef VectorND<int, 2> ivec2;
typedef VectorND<float, 2> L;
struct Particle {
    vec2 pos;
    vec2 v;
    vec2 a;
    float m;
};

struct SimParams {

};

void timestep(



