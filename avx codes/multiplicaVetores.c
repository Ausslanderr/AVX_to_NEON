/**
 * Author: TripleZ<me@triplez.cn>
 * Date: 2018-08-21
 */

#include <immintrin.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    float a[4] = {1.0, 2.0, 3.0, 4.0};
    float b[4] = {5.0, 6.0, 7.0, 8.0};
    float resultado[4];

    __m256 avx_a = _mm256_loadu_ps(a);//carrega o vetor float para o m256
    __m256 avx_b = _mm256_loadu_ps(b);//carrega o vetor float para o m256
    __m256 avx_resultado = _mm256_mul_ps(avx_a, avx_b);

    _mm256_storeu_ps(resultado, avx_resultado);// armazena o resultado de avx_result em result

    for (int i = 0; i < 4; ++i) {
        printf("%f ", resultado[i]);
    }
    printf("\n");
    return 0;
}