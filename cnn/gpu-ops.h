#ifndef CNN_GPU_OPS_H
#define CNN_GPU_OPS_H

namespace cnn {
namespace gpu {

    void vpairwise_rank_loss(int n, float margin, const float* xgood, const float* xbad, float* y);

    void set_to_value_of(int n, float* x0, float val);
    void set_to_value_of(int n, float* x0, float *val);

/// for convlution networks
    void conv1dwide(const int n, const int m, const float* xs, const int k, const float *fx, float *fy);
    void conv1dwide_backward(const int i, const int n, const int m, const float* xs, const int k, const float *fx, const float* dEdf, float *dEdx);

    /// add bias
    void addVectorToAllColumns(const int n, const float * xs, const int m, const float* fx, float *fy);
    void addVectorToAllColumns_backward(const int i, const int r, const int c, const float* dEdf, float *dEdxi);

    void foldRows(const int n, const int m, const float *xs, const int stride, const int orows, float *fy);
    void foldRows_backward(const int orows, const float* dEdf, const int n, const int m, float *fy);

    void kMaxPooling(const int n, const int m, const float *xs, const int k, float *fy, int* aux_mem);
    void kMaxPooling_backward(const int n, const int m, const float *xs, const int k, const float * dEdf, float *dEdxi, const int* aux_mem);

    void vpairwise_rank_loss(int n, float margin, const float* xgood, const float* xbad, float* y);
void vpairwise_rank_loss_backward(int n, bool d_wrt_correct, const float* fx, const float* dEdf, float* dEdx);
void vcwise_product(int n, const float* x0, const float* x1, float* y);
void vcwise_product_backward(int n, const float* dEdy, const float* x_other, float* dEdx);
void vcwise_quotient(int n, const float* x0, const float* x1, float* y);
void vcwise_quotient_backward(int n, const float* dEdy, const float* x_other, float* dEdx);
void vconstant_minusx(int n, float c, const float* x, float* y);
void vconstant_multiplyx(int n, float c, const float* x, float* y);
void vconstant_multiplyx_backward(int n, float c, const float* x, float* y);
void vnegate(int n, const float* x, float* y);
void vnegate_backward(int n, const float* dEdf, float* dEdx);
void vrelu(int n, const float* x, float* y);
void vrelu_backward(int n, const float* fx, const float* dEdf, float* dEdx);
void vexp(int n, const float* x, float* y);
void vtanh(int n, const float* x, float* y);
void vtanh_backward(int n, const float* fx, const float* dEdf, float* dEdx);
void vlog(int n, const float* x, float* y);
void vlog_backward(int n, const float* fx, const float* dEdf, float* dEdx);
void vlogistic(int n, const float* x, float* y);
void vlogistic_backward(int n, const float* fx, const float* dEdf, float* dEdx);
void l2_norm_reducer(int n, const float* x0, float* y, bool square, bool accumulate);
void sqeucdist(int n, const float* x0, const float *x1, float* y);
void sqeucdist_backward(int n, const float* dEdy, const float* x0, const float* x1, float* dEdx, int i);
void pnlsoftmax(int n, int elem_idx, const float* x0, float* y, float* logz);
void pnlsoftmax_backward(int n, int elem_idx, const float* x0, const float* dEdf, const float* logz, float* dEdx);
void logsoftmax(int row, int col, const float* x0, float* y);
void logsoftmax_backward(int row, int col, const float* fx, const float* dEdf, float* dEdx, float *softmax, float* row_sum_grd);
void softmax(int row, int col, const float* x0, float* y);
void softmax_backward(int row, int col, const float *fx, const float *dEdf, float *dEdx, float * tmp_one_row, float * gpu_gradient);
void sgd_update(int n, const float* g, float* x, float scale, float lambda);
void sgd_momentum_update(int n, const float* g, float* x, float * v, float scale, float lambda, float momentum);
void rmsprop_momentum_update(int n, const float* g, float* x, float* v, float *r, float scale, float lambda, float momentum, float rho, float epsilon);
} // namespace gpu
} // namespace cnn

#endif
