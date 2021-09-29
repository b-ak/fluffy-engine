import sys
import os
import argparse

def main(args):
    parser = argparse.ArgumentParser(description='Transcribe long audio files using webRTC VAD')
    parser.add_argument('--aggressive', type=int, choices=range(4), required=False,
                        help='Determines how aggressive filtering out non-speech is. (Interger between 0-3)')
    parser.add_argument('--audio', required=False,
                        help='Path to the audio file to run (WAV format)')
    parser.add_argument('--model', required=True,
                        help='Path to directory that contains all model files (output_graph, lm, trie and alphabet)')
    parser.add_argument('--stream', required=False, action='store_true',
                        help='To use deepspeech streaming interface')
    if len(sys.argv[1:])<2:

        parser.print_help()
        parser.exit()
    args = parser.parse_args()
    print("...........................")
    print(args)

    a, l = parser.parse_known_args() #['--stream', '--model']
    print("---------------------------------")
    print(a)
    print(l)


if __name__ == '__main__':
    main(sys.argv[1:])