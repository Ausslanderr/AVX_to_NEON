#include <immintrin.h>
#include <stdio.h>

int main() {
    float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float escalar = 5.0;
    float result[8];
    __m256 avx_a = _mm256_loadu_ps(a);
    __m256 avx_scalar = _mm256_set1_ps(escalar);

    // Multiplica cada elemento do vetor por um escalar
    __m256 avx_result = _mm256_mul_ps(avx_a, avx_scalar);
    _mm256_storeu_ps(result, avx_result);

    printf("Resultado: ");
    for (int i = 0; i < 8; ++i) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}
