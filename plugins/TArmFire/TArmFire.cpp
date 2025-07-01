// PluginTArmFire.cpp
// Tristan Strange (tristan.strange@gmail.com)

#include "SC_PlugIn.hpp"
#include "TArmFire.hpp"

static InterfaceTable* ft;

namespace TArmFire {

TArmFire::TArmFire() {
    mCalcFunc = make_calc_function<TArmFire, &TArmFire::next>();
    next(1);
}

void TArmFire::next(int nSamples) {

    // Audio rate input
    const float* input = in(0);

    // Control rate parameter: gain.
    const float gain = in0(1);

    // Output buffer
    float* outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain;
    }
}

} // namespace TArmFire

PluginLoad(TArmFireUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<TArmFire::TArmFire>(ft, "TArmFire", false);
}
