/*
 */

#include <immintrin.h>
#include <arm_neon.h>

int main(int argc, char const *argv[]) {
    
    float a[4] = {1.0, 2.0, 3.0, 4.0};
    float b[4] = {5.0, 6.0, 7.0, 8.0};
    float resultado[4];

    float32x4_t avx_a = vld1q_f32(a);//carrega o vetor float para o float32x4_t
    float32x4_t avx_b = vld1q_f32(b);//carrega o vetor float para o ''
    float32x4_t avx_resultado = vmulq_f32(avx_a, avx_b);

    vst1q_f32(resultado, avx_resultado);// armazena o resultado de avx_resultado em resultado

    for (int i = 0; i < 4; ++i) {
        printf("%f ", resultado[i]);
    }
    printf("\n");
    return 0;
}