/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

struct pair {
    char key[2];
    double value;
};

#define NO_OF_OCTAVES 8
#define NOTES_PER_OCTAVE 12

const uint buzzerPin = 18;
const uint errorPin = 25;

void playNote(char* note, int octave, int durationMicroSecs);

struct pair noteFreqMapping[NO_OF_OCTAVES][NOTES_PER_OCTAVE] = {
    {{"C", 16.35},{"D", 18.35},{"E", 20.6},{"F", 21.83},{"G", 24.5},{"A", 27.5},{"B", 30.87},{"C#", 17.32}, {"D#", 19.45}, {"F#", 23.12}, {"G#", 25.96}, {"A#", 29.14}},
    {{"C", 32.703},{"D", 36.708},{"E", 41.203},{"F", 43.654},{"G", 48.99},{"A", 55.0},{"B", 61.735},{"C#", 34.648}, {"D#", 38.891}, {"F#", 46.249}, {"G#", 51.913}, {"A#", 58.270}},
    {{"C", 65.406,},{"D", 73.416},{"E", 82.407},{"F", 87.307},{"G", 97.999},{"A", 110.000},{"B", 123.470},{"C#", 69.296}, {"D#", 77.782}, {"F#", 92.499}, {"G#", 103.830}, {"A#", 116.540}},
    {{"C", 130.810},{"D", 146.830},{"E", 164.81},{"F", 174.61},{"G", 196.0},{"A", 220.0},{"B", 246.940},{"C#", 138.590}, {"D#", 155.560}, {"F#", 185.000}, {"G#", 207.650}, {"A#", 233.080}},
    {{"C", 261.630},{"D", 293.660},{"E", 329.630},{"F", 349.230},{"G", 392.0},{"A", 440.0},{"B", 493.88},{"C#", 277.18}, {"D#", 311.13}, {"F#", 369.99}, {"G#", 415.3}, {"A#", 466.16}},
    {{"C", 523.250},{"D", 587.330},{"E", 659.250},{"F", 698.460},{"G", 783.99},{"A", 880.0},{"B", 987.77},{"C#", 554.37}, {"D#", 622.25}, {"F#", 739.99}, {"G#", 830.61}, {"A#", 932.33}},
    {{"C", 1046.5},{"D", 1174.7},{"E", 1318.5},{"F", 1396.9},{"G", 1568.0},{"A", 1760.0},{"B", 1979.5},{"C#", 1108.7}, {"D#", 1244.5}, {"F#", 1480.0}, {"G#", 1661.2}, {"A#", 1864.7}},
    {{"C", 2093.0},{"D", 2349.3},{"E", 2637.0},{"F", 2793.8},{"G", 3136.0},{"A", 3520.0},{"B", 3951.1},{"C#", 2217.5}, {"D#", 2489.0}, {"F#", 2960.0}, {"G#", 3322.4}, {"A#", 3729.3}}
};

double noteToFreq (char* key, int octave) {
    if(octave <= NO_OF_OCTAVES) {
        int i;
        for (i = 0; i < NOTES_PER_OCTAVE; i++) {
            if (strcmp(noteFreqMapping[octave][i].key, key) == 0) {
                return noteFreqMapping[octave][i].value;
            }
        }
    }
    // Invalid Key, play error tone and set error pin to high
    gpio_put(errorPin,1);
    return 4000.0;
}

int main() {
    gpio_init(buzzerPin);
    gpio_init(errorPin);
    gpio_set_dir(buzzerPin, GPIO_OUT);
    gpio_set_dir(errorPin, GPIO_OUT);

    playExample1();
}

void playNote(char* note, int octave, int durationMicroSecs) {
    double freq = noteToFreq(note, octave);
    
    // Write your solution here...
}

void playExample1() {
    playNote("C#", 2, 125000);

    playNote("G#", 2, 125000);
    playNote("C#", 3, 125000);
    playNote("E", 3, 125000);
    playNote("G#", 3, 125000);

    playNote("C#", 3, 125000);
    playNote("E", 3, 125000);
    playNote("G#", 3, 125000);
    playNote("C#", 4, 125000);

    playNote("E", 3, 125000);
    playNote("G#", 3, 125000);
    playNote("C#", 4, 125000);
    playNote("E", 4, 125000);

    playNote("G#", 3, 125000);
    playNote("C#", 4, 125000);
    playNote("E", 4, 125000);
    playNote("G#", 4, 125000);

    playNote("C#", 4, 125000);
    playNote("E", 4, 125000);
    playNote("G#", 4, 125000);
    playNote("C#", 5, 125000);

    playNote("E", 4, 125000);
    playNote("G#", 4, 125000);
    playNote("C#", 5, 125000);
    playNote("E", 5, 125000);

    playNote("G#", 4, 125000);
    playNote("C#", 5, 125000);
    playNote("E", 5, 125000);
    playNote("G#", 5, 125000);

    sleep_us(125000);
    playNote("G#", 5, 125000);
}

void playExample2() {
    // Write your own tune here...
}