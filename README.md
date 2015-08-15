# HLSLTranslator #

Source code compiler/emitter, takes in DX11/12-style HLSL, outputs (at the moment) GLSL. Uses modified Mesa GLSL IR as an intermediate representation.

Optionally, optimizes the output code to reduce load on target platform shader compilers, and can provide reflection data on the emitted code (TODO).

### Usage ###
TODO

### Credits ###
[Mesa](http://www.mesa3d.org/) - backend base

[glsl-optimizer](https://github.com/aras-p/glsl-optimizer) - GLSL Optimizer, in which the IR->GLSL emitter is based on
