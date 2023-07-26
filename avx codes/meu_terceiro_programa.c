#include <immintrin.h>
#include <stdio.h>

int main() {
    float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float b[8] = {8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
    float max_result[8];
    float min_result[8];

    __m256 avx_a = _mm256_loadu_ps(a);
    __m256 avx_b = _mm256_loadu_ps(b);

    // Calcula o máximo entre os elementos dos vetores
    __m256 avx_max_result = _mm256_max_ps(avx_a, avx_b);
    _mm256_storeu_ps(max_result, avx_max_result);

    // Calcula o mínimo entre os elementos dos vetores
    __m256 avx_min_result = _mm256_min_ps(avx_a, avx_b);
    _mm256_storeu_ps(min_result, avx_min_result);

    printf("Máximo: ");
    for (int i = 0; i < 8; ++i) {
        printf("%f ", max_result[i]);
    }
    printf("\n");

    printf("Mínimo: ");
    for (int i = 0; i < 8; ++i) {
        printf("%f ", min_result[i]);
    }
    printf("\n");

    return 0;
}
