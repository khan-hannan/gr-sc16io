<p align="center">
<img src="https://github.com/gnuradio/gnuradio/blob/main/docs/gnuradio.png" width="75%" />
</p>

## GNURadio Complex File source

### Brief

GNURadio Complex File source, is a custom block made for creating file source which is able to read complex IQ interleaved samples in 8bit and 16bit directly from a file. 

Currently the file source block can only read 32bit IQ samples which need to be processed further in order to get proper 8bit or 16bit IQ samples. Conversion is a resource intensive process and is redundant if the data is accessed properly before hand.

Currently the block is tested on GNURadio 3.10 only.