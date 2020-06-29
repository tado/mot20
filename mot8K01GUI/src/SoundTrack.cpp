#include "SoundTrack.h"

SoundTrack::SoundTrack() {
	sound.load("mix01.wav");
}

void SoundTrack::play() {
	sound.play();
}