// PluginTArmFire.cpp
// Tristan Strange (tristan.strange@gmail.com)

#include "SC_PlugIn.hpp"
#include "TArmFire.hpp"

static InterfaceTable* ft;

namespace TArmFire {

TArmFire::TArmFire() {
	mCalcFunc = make_calc_function<TArmFire, &TArmFire::next>();

	armed = false;
	prevArm = 0.f;
	prevFire = 0.f;

	next(1);
}

void TArmFire::next(int nSamples) {
	const float* currArm = in(0);
	const float* currFire = in(1);
	float* outbuf = out(0);

	for (int i = 0; i < nSamples; ++i) {
		// check for upward transitions on inputs
		bool fired = currFire[i] > 0.f && prevFire <= 0.f;
		armed = armed || currArm[i] > 0.f && prevArm <= 0.f;

		if(armed && fired) {
			armed = false;
			outbuf[i] = 1.f;
		} else {
			outbuf[i] = 0.f;
		}

		prevArm = currArm[i];
		prevFire = currFire[i];
	}
}

} // namespace TArmFire

PluginLoad(TArmFireUGens) {
	// Plugin magic
	ft = inTable;
	registerUnit<TArmFire::TArmFire>(ft, "TArmFire", false);
}
