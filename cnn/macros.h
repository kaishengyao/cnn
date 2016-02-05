#pragma once

namespace cnn {

#define ENCODER_LAYER 0
#define INTENTION_LAYER 1
#define DECODER_LAYER 2  
#define ALIGN_LAYER 3

#define INPUT_LAYER ENCODER_LAYER
#define HIDDEN_LAYER INTENTION_LAYER
#define OUTPUT_LAYER DECODER_LAYER


/// this is for ngram models
#define MIN_OCC_COUNT 20
};
