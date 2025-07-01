TArmFire : UGen {
	*ar { |arm fire|
		^this.multiNew('audio', arm, fire);
	}
	*kr { |arm fire|
		^this.multiNew('control', arm, fire);
	}
	checkInputs {
		^this.checkValidInputs;
	}
}
