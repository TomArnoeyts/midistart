# midistart
A program that executes and stops midi servers (jack and fluidsynth).
Setting up midi on a linux machine can be quite a complicated task. First you have to take over the soundcard, and get PulseAudio out of the way, then you need to set up the JACK-server, then you have to start the soundfont-server (e.g. Fluidsynth), then you can start your midi-software, and make connections with patchage. After you are finished you need to stop the servers and exit the program. This midistart program does all these steps for you, provided you have all the right applications installed.
