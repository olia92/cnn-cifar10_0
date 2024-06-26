#ifndef LAYERS_H
#define LAYERS_H

#include <stdio.h>
// Input Data
#define NUM_IMG 1 //Number of images
#define N_in 5//Input Width-Height
#define C_in 3//Colour Chanels

//Layer 1 : Convolutional
// in[32][32][3],out[32][32][16]
//     Filters[5][5][3]x(16), stride:1,pad:2
#define K1 3 //Filter Width Height
#define S1 2 //Stride
#define P1 1 //Padding
//Layer 1 Output
#define M1 2 //Output number of Feature Maps 

typedef struct conv_layer {
    int in_width;
    int in_height;
    int in_depth;

    int num_filters;
    int filter_width;
    int filter_height;
    int stride;
    int padding;

    int out_width;
    int out_height;
    int out_depth;

    float *weights;
    float *bias;

}ConvLayer;

typedef struct relu_layer {
    int in_width;
    int in_height;
    int in_depth;

    int out_width;
    int out_height;
    int out_depth;

}ReluLayer;

typedef struct pool_layer {
    int in_width;
    int in_height;
    int in_depth;

    int pool_width;
    int stride;
    int padding;

    int out_width;
    int out_height;
    int out_depth;

}PoolLayer;

ConvLayer * make_conv_layer(int W, int H, int D,int K, int M, int S, int P);
ReluLayer * make_relu_layer(int W, int H, int D);
PoolLayer * make_pool_layer(int W, int H, int D,int K, int S, int P);

void convLayer_forward(float* restrict X,ConvLayer * l,float* restrict Y);
void relu_forward(float* restrict X,ReluLayer * l,float * restrict Y);
void pool_forward(float * restrict X, PoolLayer * l,float * restrict Y);
#endif