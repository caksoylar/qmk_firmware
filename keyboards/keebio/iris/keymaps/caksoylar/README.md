# Keymap Layout for Iris rev. 4

This is a layout for Iris rev. 4 with a single rotary encoder. Some additions
of interest are the encoder functionalities, a tmux layer, a gaming layer.
Mouse keys are enabled in `rules.mk` to use mouse wheel codes.

The encoder currently does the following:
- In the default layer, performs mouse wheel up and down, tap plays/pauses
- In EXTRA layer, turns volume up and down
- In FUNC layer, changes RGB hue if held with shift, otherwise activates
  [rotary lock functionality](https://gist.github.com/caksoylar/2b7396b7c3def3d5735fa5edbb6c98b0)
- In TMUX layer, switches tmux windows

The tmux layer on 5 sends a prefix (`Ctrl+Space`) before any pressed key.
