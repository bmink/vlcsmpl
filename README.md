# vlcsmpl

vlcsmpl add <xx_name.wav>
vlcsmpl del <xx>

vlcsmpl reload <xx_name.wav> ...

Prints errors to stderr, output to stdout.

The output printed will be audio data that should be played back while the computer's "Audio Out" is connected to the Volca Sample's "Sync In". Be careful, the output sound is harsh / loud, DO NOT LISTEN WITH YOUR HEADPHONES ON LOUD

So either route the output into an .wav file, or for quick usage, use something like the below, which needs sox:

vcsmpl add <file> | play 
