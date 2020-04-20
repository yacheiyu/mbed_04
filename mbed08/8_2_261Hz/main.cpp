#include "mbed.h"

#include <cmath>

#include "DA7212.h"


int idC, i;

Thread t;

DA7212 audio;

InterruptIn button(SW2);

int16_t waveform[kAudioSampleFrequency];

EventQueue queue(32 * EVENTS_EVENT_SIZE);


void playNote(int freq)

{

  for (i = 0; i < kAudioSampleFrequency; i++)

  {

    waveform[i] = (int16_t) (sin((double)i * 2. * 3.1415926535 / (double) (kAudioSampleFrequency / freq)) * ((1<<16) - 1));

  }

  audio.spk.play(waveform, kAudioSampleFrequency);

}

void playNoteC(void) {idC = queue.call_every(1, playNote, 261);}

void stopPlayNoteC(void) {queue.cancel(idC);}


int main(void)

{

  t.start(callback(&queue, &EventQueue::dispatch_forever));

  button.fall(queue.event(playNoteC));

  button.rise(queue.event(stopPlayNoteC));

}