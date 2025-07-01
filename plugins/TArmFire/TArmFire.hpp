// PluginTArmFire.hpp
// Tristan Strange (tristan.strange@gmail.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace TArmFire {

class TArmFire : public SCUnit {
public:
    TArmFire();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
	bool armed;
	float prevArm;
	float prevFire;
};

} // namespace TArmFire
